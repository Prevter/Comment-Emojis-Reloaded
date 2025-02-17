#include "emoji-picker.hpp"
#include "emojis.hpp"

EmojiPicker* EmojiPicker::create(CCTextInputNode* input) {
    auto ret = new EmojiPicker();
    if (ret->initAnchored(360.f, 200.f, input, "GJ_square04.png")) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool EmojiPicker::setup(CCTextInputNode* input) {
    m_originalField = input;

    m_scrollLayer = geode::ScrollLayer::create({ 360.f, 200.f });
    m_scrollLayer->setID("scroll-layer"_spr);
    m_mainLayer->addChildAtPosition(m_scrollLayer, geode::Anchor::BottomLeft);

    for (auto& category : getEmojiCategories()) {
        if (category.emojis.empty()) {
            continue;
        }

        appendGroup(category);
    }

    // calculate required height
    float height = 0.f;
    for (auto child : geode::cocos::CCArrayExt<CCNode*>(m_scrollLayer->m_contentLayer->getChildren())) {
        height += child->getContentSize().height + 5.f;
    }

    m_scrollLayer->m_contentLayer->setContentHeight(height);
    m_scrollLayer->m_contentLayer->setLayout(
        geode::ColumnLayout::create()
            ->setAxisReverse(true)
            ->setAutoScale(false)
            ->setAxisAlignment(geode::AxisAlignment::End)
            ->setCrossAxisAlignment(geode::AxisAlignment::Center)
            ->setCrossAxisLineAlignment(geode::AxisAlignment::Center)
            ->setCrossAxisOverflow(false)
    );

    return true;
}

cocos2d::CCNode* EmojiPicker::createEmojiSprite(const std::string& emoji) {
    std::string_view emojiView;
    bool found = false;
    for (auto& [name, content] : EmojiReplacements) {
        if (name == emoji) {
            emojiView = content;
            found = true;
            break;
        }
    }

    if (!found) {
        return nullptr;
    }

    auto utf32 = utf8_to_utf32(emojiView);

    // check for custom emojis
    auto chr = utf32.front();
    auto utf32_raw = std::u32string_view(
        utf32.data(),
        utf32.size() - (chr >= 0x1c000 && chr <= 0x1cfff)
    );

    if (auto it = EmojiSheet.find(utf32_raw); it != EmojiSheet.end()) {
        return cocos2d::CCSprite::createWithSpriteFrameName(it->second);
    }

    if (auto it = CustomNodeSheet.find(utf32_raw); it != CustomNodeSheet.end()) {
        uint32_t index = 0;
        return it->second(U"", index);
    }

    return nullptr;
}

std::vector<EmojiPicker::EmojiCategory> const& EmojiPicker::getEmojiCategories() {
    static std::vector<EmojiCategory> categories = {
        { "Favorite", {} },
        { "Frequently Used", {} },
        {
            "Geometry Dash",
            {
                ":na:", ":auto:", ":easy:", ":normal:",
                ":hard:", ":harder:", ":insane:",
                ":easydemon:", ":mediumdemon:", ":harddemon:",
                ":insanedemon:", ":extremedemon:", ":casual:",
                ":tough:", ":cruel:", ":creul:",
                ":orb:", ":orbs:", ":diamond:", ":diamonds:",
                ":locked:", ":lockedgray:", ":unlocked:",
                ":goldcoin:", ":uncollectedusercoin:", ":usercoinunverified:",
                ":usercoin:", ":points:", ":mod:", ":eldermod:", ":leaderboardmod:",
                ":star:", ":moon:", ":check:", ":cross:", ":like:", ":dislike:",
            }
        },
        {
            "Twemoji",
            {
                ":100:", ":shushing_face:", ":deaf_person:", ":deaf_man:", ":deaf_woman:",
                ":bear:", ":broken_heart:", ":cat:", ":dog:", ":fox:",
                ":gun:", ":face_with_raised_eyebrow:", ":middle_finger:", ":moyai:", ":fire:",
                ":nerd:", ":radioactive:", ":scream:", ":skull:", ":smiling_imp:",
                ":speaking_head:", ":sob:", ":eggplant:", ":clown:", ":tongue:",
                ":alien:", ":baby:", ":robot:", ":heart:", ":ghost:",
                ":exploding_head:", ":snowflake:", ":sleeping_accommodation:", ":person_in_steamy_room:", ":fish:",
                ":sparkles:", ":party_popper:", ":pig:", ":new_moon_with_face:", ":last_quarter_moon:",
                ":new_moon:", ":sun_with_face:", ":full_moon_with_face:", ":monkey_face:", ":see_no_evil:",
                ":hear_no_evil:", ":speak_no_evil:", ":crown:", ":pray:", ":bangbang:",
                ":question:", ":sunglasses:", ":heart_eyes:",
                ":one:", ":two:", ":three:",  ":four:", ":five:",
                ":six:", ":seven:", ":eight:", ":nine:", ":zero:",
            }
        },
        {
            "Legacy Set",
            {
                ":amongus:", ":amogus:", ":bruh:", ":carlos:", ":clueless:",
                ":despair:", ":despair2:", ":ned:", ":pusab?:", ":robsmile:",
                ":sip:", ":splat:", ":teehee:", ":trollface:", ":true:",
                ":walter:", ":wha:", ":whadahell:", ":youshould:", ":car:",
                ":zoink:", ":shocked:", ":poppinbottles:", ":party:", ":potbor:",
                ":dabmeup:", ":fireinthehole:", ":finger:", ":soggy:", ":mayo:",
                ":divine:", ":bueno:", ":rattledash:", ":gd:", ":geode:",
                ":boar:", ":mewhen:", ":changetopic:", ":touchgrass:", ":gggggggg:",
                ":gdok:", ":hug:", ":angy:", ":lewd:", ":headpat:",
                ":transcat:", ":transcat2:", ":skillissue:", ":yes:", ":gunleft:",
                ":gunright:", ":edge:", ":cologne:", ":globed:", ":levelthumbnails:",
                ":oh:", ":holymoly:", ":1000yardstare:", ":spunchbob:", ":freakbob:",
                ":nuhuh:", ":yuhuh:", ":shiggy:", ":hype:", ":petmaurice:",
                ":bonk:", ":partying:", ":ned_explosion:", ":polarbear:", ":colonthreecat:",
            }
        },
        {
            "Cube Emotes (By @cyanflower)",
            {
                ":boshytime:", ":cubeballin:", ":cubeconfused:", ":cubecool:", ":cubehappy:",
                ":cubeletsgo:", ":cubepog:", ":cubescared:", ":cubestare:", ":cubethink:",
                ":cubeview:", ":cubewink:", ":defaultangry:", ":eeyikes:", ":fumocube:",
                ":robtoppixel:", ":smugzero:", ":cubedance:", ":cubespeen:", ":cubehyperthink:"
            }
        },
        {
            "Cat Emotes (C# Discord Server)",
            {
                ":catbless:", ":catcash:", ":catcomf:", ":catcool:", ":catcop:",
                ":catcorn:", ":catderp:", ":catfacepalm:", ":catfine:", ":catgasm:",
                ":catgasp:", ":catgift:", ":catgrump:", ":catgun:", ":cathammer:",
                ":cathi:", ":cathype:", ":catlaugh:", ":catlick:", ":catloser:",
                ":catlost:", ":catlove:", ":catlul:", ":catlurk:", ":catmusik:",
                ":catok:", ":catpat:", ":catpls:", ":catpog:", ":catpout:",
                ":catree:", ":catshrug:", ":catshy:", ":catsimp:", ":catsip:",
                ":catsleep:", ":catsmart:", ":catsweat:", ":catthinking:",
            }
        },
        {
            "Player Icons",
            {
                ":default:", ":sdslayer:", ":evw:", ":tride:", ":colon:",
                ":robtop:", ":wulzy:", ":juniper:", ":riot:", ":cyclic:",
                ":thesillydoggo:", ":uproxide:",
            }
        },
        {
            "Custom Emojis",
            {
                ":eyesShock:", ":trollskull:", ":slight_smile:", ":trolleyzoom:"
            }
        }
    };

    categories[0].emojis = std::move(getFavoriteEmojis());
    categories[1].emojis = std::move(getFrequentlyUsedEmojis());

    return categories;
}

std::vector<std::string> EmojiPicker::getFrequentlyUsedEmojis() {
    return {};
}

std::vector<std::string> EmojiPicker::getFavoriteEmojis() {
    return {};
}

void EmojiPicker::appendGroup(EmojiCategory const& category) const {
    auto contentLayer = m_scrollLayer->m_contentLayer;

    auto title = Label::create(category.name, "chatFont.fnt");
    title->setID("emoji-category-title"_spr);
    title->setAnchorPoint({ 0.f, 0.5f });
    title->setContentWidth(340.f);
    contentLayer->addChild(title);

    auto menu = cocos2d::CCMenu::create();
    menu->setContentSize({ 340.f, 200.f });

    for (auto& emoji : category.emojis) {
        auto sprite = createEmojiSprite(emoji);
        if (!sprite) {
            geode::log::warn("Emoji {} not found", emoji);
            continue;
        }

        // check if sprite is not 18x18
        auto size = sprite->getContentSize();
        if (size.width != 18.f || size.height != 18.f) {
            // scale to fit
            auto scale = 18.f / std::max(size.width, size.height);
            sprite->setScale(scale);

            // enclose in a container
            auto container = CCNode::create();
            container->setContentSize({ 18.f, 18.f });
            container->addChild(sprite);
            sprite->setPosition({ 9.f, 9.f });
            sprite = container;
        }

        auto item = geode::cocos::CCMenuItemExt::createSpriteExtra(
            sprite, [this, emoji](auto) {
                m_originalField->setString(m_originalField->getString() + emoji);
            }
        );
        item->setID(emoji);
        menu->addChild(item);
    }

    menu->setLayout(
        geode::RowLayout::create()
            ->setAutoScale(false)
            ->setAxisAlignment(geode::AxisAlignment::Start)
            ->setCrossAxisAlignment(geode::AxisAlignment::Even)
            ->setCrossAxisLineAlignment(geode::AxisAlignment::Even)
            ->setGrowCrossAxis(true)
    );

    contentLayer->addChild(menu);
}
