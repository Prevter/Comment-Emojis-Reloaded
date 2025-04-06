#include <Geode/modify/CommentCell.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/ShareCommentLayer.hpp>

#include <Geode/binding/GJComment.hpp>
#include <Geode/Enums.hpp>

#include "emoji-picker.hpp"
#include "emojis.hpp"

std::string replaceEmojis(std::string_view text) {
    auto result = std::string(text);
    for (auto& [name, emoji] : EmojiReplacements) {
        findAndReplace(result, name, emoji);
    }
    return result;
}

class $modify(ClearFontCacheHook, GameManager) {
    void reloadAllStep5() {
        GameManager::reloadAllStep5();
        BMFontConfiguration::purgeCachedData();
    }
};

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
            newText->setBreakWords(48);
            newText->setAnchorPoint({0.f, 0.5f});
            newText->setPosition({11.f, m_accountComment ? 38.f : 33.f});
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

void createPickerButton(ShareCommentLayer* layer) {
    auto btnSprite = cocos2d::CCSprite::create("picker_icon.png"_spr);
    btnSprite->setScale(0.75f);
    btnSprite->setColor({ 0, 0, 0 });
    btnSprite->setOpacity(105);

    auto btn = geode::cocos::CCMenuItemExt::createSpriteExtra(
        btnSprite, [layer](auto) {
            EmojiPicker::create(layer->m_commentInput)->show();
        }
    );
    btn->setID("emoji-picker"_spr);
    btn->setPosition(175.f, 36.5f);
    layer->m_buttonMenu->addChild(btn);
}

#ifndef GEODE_IS_IOS
class $modify(ShareCommentLayerHook, ShareCommentLayer) {
    bool init(gd::string title, int charLimit, CommentType type, int ID, gd::string desc) {
        if (!ShareCommentLayer::init(title, charLimit, type, ID, desc)) {
            return false;
        }
        createPickerButton(this);
        return true;
    }
};
#else
constexpr uintptr_t ShareCommentLayer_init_addr = 0x1d53f0;
static_assert(GEODE_COMP_GD_VERSION == 22074, "GD version mismatch");

// Due to some weirdness with CommentType define on iOS, this function is not hookable via normal means
// So we're manually hooking the init function instead :P
bool ShareCommentLayer_init(ShareCommentLayer* self, gd::string title, int charLimit, int type, int ID, gd::string desc) {
    using init_t = bool(*)(ShareCommentLayer*, gd::string, int, int, int, gd::string);
    static auto init = (init_t) geode::base::get() + ShareCommentLayer_init_addr;
    if (!init(self, title, charLimit, type, ID, desc)) {
        return false;
    }
    createPickerButton(self);
    return true;
}

$execute {
    geode::Mod::get()->hook(
        (void*) geode::base::get() + ShareCommentLayer_init_addr,
        &ShareCommentLayer_init,
        "ShareCommentLayer::init",
        tulip::hook::TulipConvention::Thiscall
    );
}
#endif
