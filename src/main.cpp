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
//         std::string buf;
//         size_t counter = 0;
//
//         for (auto& [emoji, path] : EmojiSheet) {
//             if (!cocos2d::CCSpriteFrameCache::get()->spriteFrameByName(path)) {
//                 geode::log::warn("Emoji {} not found in '{}'", utf32_to_utf8(emoji), path);
//             } else {
//                 buf += utf32_to_utf8(emoji);
//                 if (++counter % 16 == 0) {
//                     buf += '\n';
//                 }
//             }
//         }
//
//         if (!MenuLayer::init()) return false;
//
//         auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
//
//         auto emojiLabel = Label::create("", "chatFont.fnt");
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

        Label* newText;
        cocos2d::ccColor3B changedColor;
        auto commentString = replaceEmojis(comment->m_commentString);
        bool isWrapped = false;

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
            isWrapped = true;
        }
        else if (auto oldLabel = static_cast<cocos2d::CCLabelBMFont*>(m_mainLayer->getChildByID("comment-text-label"))) {
            oldLabel->setVisible(false);
            changedColor = oldLabel->getColor();

            newText = Label::create("", "chatFont.fnt");
            newText->setAnchorPoint({0.f, 0.5f});
            newText->setPosition({10.f, 9.f});
            newText->setID("comment-text-label"_spr);
        }
        else {
            return;
        }

        newText->setColor(changedColor);
        newText->enableEmojis("EmojiSheet.png"_spr, &EmojiSheet);
        newText->setString(commentString);

        if (!isWrapped) {
            newText->limitLabelWidth(270.f, 0.7f, 0.1f);
        }

        m_mainLayer->addChild(newText);
    }
};