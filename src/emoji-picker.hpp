#pragma once
#include "label.hpp"
#include "scroll-layer.hpp"

class EmojiPicker final : public geode::Popup<CCTextInputNode*> {
protected:
    CCTextInputNode* m_originalField = nullptr;
    ScrollLayer* m_scrollLayer = nullptr;
    ScrollLayer* m_sidebarPanel = nullptr;
    geode::Scrollbar* m_scrollbar = nullptr;
    CCLayer* m_inputLayer = nullptr;
    bool m_isClosing = false;

public:
    static EmojiPicker* create(CCTextInputNode* input);

protected:
    bool setup(CCTextInputNode* input) override;

    struct EmojiCategory {
        std::string name;
        std::vector<std::string> emojis;
    };

    static CCNode* createEmojiSprite(const std::string& emoji);
    static CCNode* encloseInContainer(CCNode* node, float size);

    static std::vector<EmojiCategory> const& getEmojiCategories();
    static std::vector<std::string> getFrequentlyUsedEmojis();
    static std::vector<std::string> getFavoriteEmojis();

    static void incrementEmojiUsage(std::string const& emoji);
    static void toggleFavoriteEmoji(std::string const& emoji);

    void recreateGroups() const;

    CCNode* appendGroup(EmojiCategory const& category) const;
    void updateScrollLayer() const;

    void beginClose();
    void endClose() { this->onClose(nullptr); }

    bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
};