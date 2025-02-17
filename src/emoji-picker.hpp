#pragma once
#include "label.hpp"

class EmojiPicker final : public geode::Popup<CCTextInputNode*> {
protected:
    CCTextInputNode* m_originalField = nullptr;
    geode::ScrollLayer* m_scrollLayer = nullptr;

public:
    static EmojiPicker* create(CCTextInputNode* input);

protected:
    bool setup(CCTextInputNode* input) override;

    struct EmojiCategory {
        std::string name;
        std::vector<std::string> emojis;
    };

    static CCNode* createEmojiSprite(const std::string& emoji);

    static std::vector<EmojiCategory> const& getEmojiCategories();
    static std::vector<std::string> getFrequentlyUsedEmojis();
    static std::vector<std::string> getFavoriteEmojis();

    void appendGroup(EmojiCategory const& category) const;
};
