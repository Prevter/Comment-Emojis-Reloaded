#include <Geode/modify/CommentCell.hpp>
#include "emojis.hpp"

std::string replaceEmojis(std::string_view text) {
    auto result = std::string(text);
    for (auto& [name, emoji] : EmojiReplacements) {
        findAndReplace(result, name, emoji);
    }
    return result;
}

// Testing stuff
// #include <Geode/modify/MenuLayer.hpp>
// class $modify(MenuLayer) {
//     bool init() override {
//         for (auto& [emoji, path] : EmojiSheet) {
//             if (!cocos2d::CCSpriteFrameCache::get()->spriteFrameByName(path)) {
//                 geode::log::warn("Emoji {} not found in '{}'", utf32_to_utf8(emoji), path);
//             }
//         }
//
//         if (!MenuLayer::init()) return false;
//
//         std::string buf;
//         for (auto& [name, emoji] : EmojiReplacements) {
//             buf += fmt::format("({}{}) ", name, emoji);
//         }
//         buf = replaceEmojis(buf);
//
//         auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
//
//         auto emojiLabel = Label::createWrapped("", "chatFont.fnt", 300);
//         emojiLabel->enableEmojis("EmojiSheet.png"_spr, &EmojiSheet);
//         emojiLabel->setString(buf);
//         emojiLabel->setPosition(winSize / 2);
//         emojiLabel->limitLabelWidth(winSize.width - 20.f, 0.7f, 0.1f);
//         this->addChild(emojiLabel, 100);
//
//         return true;
//     }
// };

class $modify(CommentCellHook, CommentCell) {
    static void onModify(auto& self) {
        (void) self.setHookPriority("CommentCell::loadFromComment", geode::Priority::LatePost);
    }

    void loadFromComment(GJComment* comment) {
        CommentCell::loadFromComment(comment);

        if (!comment || comment->m_isSpam) {
            return;
        }

        Label* newText;
        cocos2d::ccColor3B changedColor;
        auto commentString = replaceEmojis(comment->m_commentString);
        float maxWidth = 315.f;
        float defaultScale = 1.f;

        if (auto oldText = static_cast<TextArea*>(m_mainLayer->getChildByID("comment-text-area"))) {
            oldText->setVisible(false);
            changedColor = getTextAreaColor(oldText);

            // rescale very long comments
            auto length = commentString.size();
            float scale = length > 64 ? 1.f - std::min((length - 64) * 0.05f, 0.3f) : 1.f;

            newText = Label::createWrapped("", "chatFont.fnt", scale, 315.f);
            newText->setExtraLineSpacing(12.f);
            newText->setAnchorPoint({0.f, 0.5f});
            newText->setPosition({10.f, m_accountComment ? 37.f : 32.f});
            newText->setID("comment-text-area"_spr);
        }
        else if (auto oldLabel = static_cast<cocos2d::CCLabelBMFont*>(m_mainLayer->getChildByID("comment-text-label"))) {
            oldLabel->setVisible(false);
            changedColor = oldLabel->getColor();

            newText = Label::create("", "chatFont.fnt");
            newText->setAnchorPoint({0.f, 0.5f});
            newText->setPosition({10.f, 9.f});
            newText->setID("comment-text-label"_spr);
            maxWidth = 270.f;
            defaultScale = 0.7f;
        }
        else {
            return;
        }

        newText->setColor(changedColor);
        newText->enableCustomNodes(&CustomNodeSheet);
        newText->enableEmojis("EmojiSheet.png"_spr, &EmojiSheet);
        newText->setString(commentString);
        newText->limitLabelWidth(maxWidth, defaultScale, 0.1f);

        m_mainLayer->addChild(newText);
    }
};