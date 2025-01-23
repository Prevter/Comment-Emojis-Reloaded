#pragma once

inline cocos2d::ccColor3B getTextAreaColor(const TextArea* textArea) {
    auto lines = textArea->m_label->m_lines;
    if (!lines || lines->count() == 0) {
        return cocos2d::ccc3(255, 255, 255);
    }

    auto lineChars = static_cast<cocos2d::CCLabelBMFont*>(lines->objectAtIndex(0))->getChildren();
    if (!lineChars || lineChars->count() == 0) {
        return cocos2d::ccc3(255, 255, 255);
    }

    return static_cast<cocos2d::CCSprite*>(lineChars->objectAtIndex(0))->getColor();
}

inline void findAndReplace(std::string& str, std::string_view find, std::string_view replace) {
    size_t pos = 0;
    while ((pos = str.find(find, pos)) != std::string::npos) {
        str.replace(pos, find.length(), replace);
        pos += replace.length();
    }
}

template <size_t N>
struct StringLiteral {
    char value[N]{};
    constexpr StringLiteral(const char (&str)[N]) { std::copy_n(str, N, value); }
    constexpr operator std::string_view() const { return { value, N - 1 }; }
};

template <size_t N>
struct StringLiteralUTF32 {
    char32_t value[N]{};
    constexpr StringLiteralUTF32(const char32_t (&str)[N]) { std::copy_n(str, N, value); }
    constexpr StringLiteralUTF32(char32_t chr) { value[0] = chr; }
    constexpr operator std::u32string_view() const { return { value, N - 1 }; }
};

template <size_t N>
struct EmojiToHexConverter {
    static constexpr size_t length = N - 1;
    static constexpr size_t modIdSize = sizeof(GEODE_MOD_ID) - 1;

    char32_t value[length]{};
    char filename[modIdSize + (length * 6 + 4) + 1]{};

    constexpr EmojiToHexConverter(char32_t const (&str)[N]) {
        std::copy_n(str, N - 1, value);

        constexpr char hex[] = "0123456789abcdef";
        size_t index = 0;
        // add the mod id
        for (size_t i = 0; i < modIdSize; ++i) {
            filename[index++] = GEODE_MOD_ID[i];
        }
        filename[index++] = '/';

        // expand the emoji to hex
        for (size_t i = 0; i < length; ++i) {
            int c = str[i];

            // if last char is 0xfe0f, skip it
            if (c == 0xfe0f) {
                // if this was a last char, remove the dash
                if (filename[index - 1] == '-' && i == length - 1) {
                    index--;
                }
                continue;
            }

            if (c >= 0x10000) filename[index++] = hex[(c >> 16) & 0xF];
            if (c >= 0x1000) filename[index++] = hex[(c >> 12) & 0xF];
            if (c >= 0x100) filename[index++] = hex[(c >> 8) & 0xF];
            if (c >= 0x10) filename[index++] = hex[(c >> 4) & 0xF];
            filename[index++] = hex[c & 0xF];
            if (i < length - 1) filename[index++] = '-';
        }

        // add the extension
        filename[index++] = '.';
        filename[index++] = 'p';
        filename[index++] = 'n';
        filename[index++] = 'g';
        filename[index] = '\0';
    }
};

template <EmojiToHexConverter S>
constexpr std::pair<std::u32string_view, const char*> operator""_emoji() {
    return { std::u32string_view(S.value, S.length), S.filename };
}

template <char32_t C>
constexpr auto SingleEmoji = EmojiToHexConverter(StringLiteralUTF32<2>{C}.value);

template <char32_t C>
constexpr std::pair<std::u32string_view, const char*> Sprite = {
    std::u32string_view(SingleEmoji<C>.value, SingleEmoji<C>.length),
    SingleEmoji<C>.filename
};

constexpr auto test = Sprite<0x1F1E6>;

struct Emoji {
    std::string_view name;
    std::string_view emoji;

    constexpr Emoji(std::string_view name, std::string_view emoji) : name(name), emoji(emoji) {}
};

template <char32_t C>
struct UTF32ToUTF8 {
    static_assert(C >= 0x1C000 && C <= 0x1CFFF, "Custom emojis must be in the range 0x1C000-0x1CFFF");
    static constexpr char32_t value = C;
    static constexpr std::array<char, 5> utf8 = {
        static_cast<char>(0xF0 | C >> 18),
        static_cast<char>(0x80 | ((C >> 12) & 0x3F)),
        static_cast<char>(0x80 | ((C >> 6) & 0x3F)),
        static_cast<char>(0x80 | (C & 0x3F)),
        '\0'
    };
    static constexpr std::string_view utf8_view = { utf8.data(), utf8.size() };
};

template <StringLiteral Name, char32_t C>
static constexpr auto CustomEmoji = Emoji{ Name, UTF32ToUTF8<C>::utf8_view };

template <StringLiteral Name, char32_t C>
struct custom_emoji {
    static constexpr auto emoji = CustomEmoji<Name, C>;
    static constexpr auto sprite = Sprite<C>;
    static constexpr char32_t value = C;

    constexpr operator Label::EmojiMap::value_type() const { return sprite; }
    constexpr operator Emoji() const { return emoji; }
};