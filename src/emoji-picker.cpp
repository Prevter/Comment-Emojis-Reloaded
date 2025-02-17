#include "emoji-picker.hpp"
#include "emojis.hpp"

constexpr float ScrollViewHeight = 200.f;
constexpr float ScrollViewWidth = 300.f;

EmojiPicker* EmojiPicker::create(CCTextInputNode* input) {
    auto ret = new EmojiPicker();
    if (ret->initAnchored(360.f, ScrollViewHeight + 10.f, input, "geode.loader/GE_square01.png")) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool EmojiPicker::setup(CCTextInputNode* input) {
    m_originalField = input;

    m_scrollLayer = ScrollLayer::create({ ScrollViewWidth, ScrollViewHeight });
    m_scrollLayer->setID("scroll-layer"_spr);
    m_mainLayer->addChildAtPosition(m_scrollLayer, geode::Anchor::BottomLeft, { 40.f, 5.f });

    m_sidebarPanel = ScrollLayer::create({ 40.f, ScrollViewHeight });
    m_sidebarPanel->setID("sidebar-panel"_spr);
    m_mainLayer->addChildAtPosition(m_sidebarPanel, geode::Anchor::BottomLeft, { 0.f, 5.f });

    auto sidebarMenu = cocos2d::CCMenu::create();
    sidebarMenu->setAnchorPoint({ 0, 0 });
    sidebarMenu->setPosition({ 0, 0 });
    sidebarMenu->ignoreAnchorPointForPosition(true);

    for (auto& category : getEmojiCategories()) {
        if (category.emojis.empty()) {
            continue;
        }

        auto first = createEmojiSprite(category.emojis.front());
        if (!first) { continue; }
        first = encloseInContainer(first, 24.f);

        auto groupTop = appendGroup(category);
        auto btn = geode::cocos::CCMenuItemExt::createSpriteExtra(
            first, [this, groupTop](auto) {
                m_scrollLayer->scrollTo(groupTop);
            }
        );
        sidebarMenu->addChild(btn);
    }

    // calculate required height
    float height = 0.f;
    for (auto child : geode::cocos::CCArrayExt<CCNode*>(m_scrollLayer->m_contentLayer->getChildren())) {
        height += child->getContentSize().height + 5.f;
    }
    m_scrollLayer->m_contentLayer->setContentHeight(std::max(height, ScrollViewHeight));

    height = 0.f;
    for (auto child : geode::cocos::CCArrayExt<CCNode*>(sidebarMenu->getChildren())) {
        height += child->getContentSize().height + 5.f;
    }
    sidebarMenu->setContentSize({ 40, std::max(height, ScrollViewHeight) });

    sidebarMenu->setLayout(
        geode::ColumnLayout::create()
            ->setAxisReverse(true)
            ->setAutoScale(false)
            ->setAxisAlignment(geode::AxisAlignment::End)
            ->setCrossAxisAlignment(geode::AxisAlignment::Center)
            ->setCrossAxisLineAlignment(geode::AxisAlignment::Center)
            ->setCrossAxisOverflow(false)
    );

    m_sidebarPanel->m_contentLayer->setContentHeight(std::max(height, ScrollViewHeight));
    m_sidebarPanel->m_contentLayer->addChild(sidebarMenu);

    m_scrollLayer->m_contentLayer->setLayout(
        geode::ColumnLayout::create()
            ->setAxisReverse(true)
            ->setAutoScale(false)
            ->setAxisAlignment(geode::AxisAlignment::End)
            ->setCrossAxisAlignment(geode::AxisAlignment::Center)
            ->setCrossAxisLineAlignment(geode::AxisAlignment::Center)
            ->setCrossAxisOverflow(false)
    );

    m_sidebarPanel->scrollToTop();
    m_scrollLayer->scrollToTop();

    m_scrollbar = geode::Scrollbar::create(m_scrollLayer);
    m_scrollbar->setID("scrollbar"_spr);
    m_mainLayer->addChildAtPosition(m_scrollbar, geode::Anchor::Right, { -10.f, 0.f });

    m_buttonMenu->setVisible(false);
    m_mainLayer->setPositionY(m_mainLayer->getPositionY() - 50.f);

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

cocos2d::CCNode* EmojiPicker::encloseInContainer(CCNode* node, float size) {
    auto contentSize = node->getContentSize();
    if (contentSize.width != size || contentSize.height != size) {
        // scale to fit
        auto scale = size / std::max(contentSize.width, contentSize.height);
        node->setScale(scale);

        // enclose in a container if not square
        if (contentSize.width != contentSize.height) {
            auto container = CCNode::create();
            container->setContentSize({ size, size });
            container->addChild(node);
            node->setPosition(size / 2, size / 2);
            return container;
        }
    }
    return node;
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
                // People
                ":heart_eyes:", ":face_with_raised_eyebrow:", ":nerd:", ":sunglasses:", ":sob:",
                ":exploding_head:", ":scream:", ":shushing_face:", ":smiling_imp:", ":clown:",
                ":ghost:", ":skull:", ":alien:", ":robot:", ":middle_finger:",
                ":pray:", ":tongue:", ":speaking_head:", ":baby:", ":deaf_person:",
                ":deaf_woman:", ":deaf_man:", ":person_in_steamy_room:", ":crown:",

                // Nature
                ":dog:", ":cat:", ":fox:", ":bear:", ":pig:",
                ":monkey_face:", ":see_no_evil:", ":hear_no_evil:", ":speak_no_evil:", ":fish:",
                ":sun_with_face:", ":full_moon_with_face:", ":new_moon_with_face:", ":last_quarter_moon:", ":new_moon:",
                ":sparkles:", ":fire:", ":snowflake:",

                // Food
                ":eggplant:",

                // Travel
                ":moyai:",

                // Objects
                ":gun:", ":sleeping_accommodation:", ":party_popper:",

                // Symbols
                ":heart:", ":broken_heart:", ":radioactive:", ":100:", ":question:",
                ":bangbang:", ":zero:",":one:", ":two:", ":three:",
                ":four:", ":five:", ":six:", ":seven:", ":eight:",
                ":nine:",
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
            "Custom Emojis",
            {
                ":eyesShock:", ":trollskull:", ":slight_smile:", ":trolleyzoom:"
            }
        },
        {
            "Cube Emotes (By @cyanflower)",
            {
                ":cubeballin:", ":cubeconfused:", ":cubecool:", ":cubehappy:", ":cubeletsgo:",
                ":cubepog:", ":cubescared:", ":cubestare:", ":cubethink:", ":cubeview:",
                ":cubewink:", ":defaultangry:", ":eeyikes:", ":fumocube:", ":robtoppixel:",
                ":boshytime:", ":smugzero:", ":cubedance:", ":cubespeen:", ":cubehyperthink:"
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

cocos2d::CCNode* EmojiPicker::appendGroup(EmojiCategory const& category) const {
    auto contentLayer = m_scrollLayer->m_contentLayer;

    auto title = Label::create(category.name, "chatFont.fnt");
    title->setID("emoji-category-title"_spr);
    title->setAnchorPoint({ 0.f, 0.f });

    auto titleMenu = cocos2d::CCMenu::create();
    titleMenu->setContentSize({ ScrollViewWidth - 20.f, title->getContentHeight() });
    titleMenu->setAnchorPoint({ 0, 1 });

    auto menu = cocos2d::CCMenu::create();
    menu->setPosition(0, 0);
    menu->setAnchorPoint({ 0, 0 });
    menu->ignoreAnchorPointForPosition(true);
    menu->setContentSize({ ScrollViewWidth, 200.f });

    for (auto& emoji : category.emojis) {
        auto sprite = createEmojiSprite(emoji);
        if (!sprite) {
            geode::log::warn("Emoji {} not found", emoji);
            continue;
        }

        sprite = encloseInContainer(sprite, 18.f);

        auto item = geode::cocos::CCMenuItemExt::createSpriteExtra(
            sprite, [this, emoji](auto) {
                m_originalField->setString(m_originalField->getString() + emoji);
            }
        );
        item->setID(emoji);
        menu->addChild(item);
    }

    auto isCollapsed = geode::Mod::get()->getSavedValue<bool>(fmt::format("collapsed/{}", category.name), false);
    auto collapseBtnSprite = cocos2d::CCSprite::createWithSpriteFrameName("edit_downBtn_001.png");
    collapseBtnSprite->setScale(0.7f);

    auto collapseBtnNode = CCNode::create();
    collapseBtnNode->setContentSize({
        collapseBtnSprite->getContentSize().width + title->getContentSize().width,
        title->getContentSize().height
    });

    collapseBtnNode->addChild(title);
    collapseBtnNode->addChild(collapseBtnSprite);

    collapseBtnNode->setLayout(
        geode::RowLayout::create()
            ->setAutoScale(false)
            ->setAxisAlignment(geode::AxisAlignment::Start)
            ->setCrossAxisAlignment(geode::AxisAlignment::Center)
            ->setCrossAxisLineAlignment(geode::AxisAlignment::Center)
            ->setGrowCrossAxis(false)
    );

    auto menuContainer = CCNode::create();

    auto collapseBtn = geode::cocos::CCMenuItemExt::createSpriteExtra(
        collapseBtnNode, [this, menu, menuContainer, collapseBtnSprite, category = category.name](auto) {
            bool visible = !menu->isVisible();
            geode::Mod::get()->setSavedValue(fmt::format("collapsed/{}", category), !visible);
            menu->setVisible(visible);
            collapseBtnSprite->runAction(cocos2d::CCRotateTo::create(0.1f, visible ? 0.f : -90.f));
            menuContainer->setContentHeight(visible ? menu->getContentHeight() : 0.f );
            this->updateScrollLayer();
        }
    );
    collapseBtn->m_scaleMultiplier = 1.1f;
    collapseBtn->setPosition(collapseBtn->getContentSize() * 0.5f);
    collapseBtn->setID("collapse-btn"_spr);
    titleMenu->addChild(collapseBtn);

    menu->setLayout(
        geode::RowLayout::create()
            ->setAutoScale(false)
            ->setAxisAlignment(geode::AxisAlignment::Start)
            ->setCrossAxisAlignment(geode::AxisAlignment::Even)
            ->setCrossAxisLineAlignment(geode::AxisAlignment::Even)
            ->setGrowCrossAxis(true)
    );

    menuContainer->addChild(menu);
    menuContainer->setContentSize(menu->getContentSize());

    if (isCollapsed) {
        menu->setVisible(false);
        collapseBtnSprite->setRotation(-90.f);
        menuContainer->setContentHeight(0.f);
    }

    contentLayer->addChild(titleMenu);
    contentLayer->addChild(menuContainer);

    return titleMenu;
}

void EmojiPicker::updateScrollLayer() const {
    auto oldHeight = m_scrollLayer->m_contentLayer->getContentHeight();

    // calculate required height
    float height = 0.f;
    for (auto child : geode::cocos::CCArrayExt<CCNode*>(m_scrollLayer->m_contentLayer->getChildren())) {
        height += child->getContentSize().height + 5.f;
    }

    m_scrollLayer->m_contentLayer->setContentHeight(std::max(height, ScrollViewHeight));

    auto diff = -m_scrollLayer->m_contentLayer->getContentHeight() + oldHeight;

    m_scrollLayer->m_contentLayer->updateLayout();
    m_scrollLayer->scrollLayer(diff);
    m_scrollbar->setTarget(m_scrollLayer);
}
