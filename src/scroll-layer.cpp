#include "scroll-layer.hpp"
#include <algorithm>
#include <cmath>
#include <Geode/loader/Mod.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <Geode/utils/cocos.hpp>

// all thanks to https://github.com/CallocGD/GD-2.205-Decompiled
// and also from https://github.com/geode-sdk/geode

void ScrollLayer::scrollWheel(float pointX, float pointY) {
    if (pointX != 0.0) {
        CCScrollLayerExt::scrollLayer(pointX);
    }
}

bool ScrollLayer::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event) {
    if (!geode::cocos::nodeIsVisible(this)) {
        return false;
    }

    if (CCScrollLayerExt::ccTouchBegan(touch, event)) {
        m_touchStart = touch;
        auto touchPos = cocos2d::CCDirector::get()->convertToGL(m_touchStart->getLocationInView());
        m_touchStartPosition2 = touchPos;
        m_touchPosition2 = touchPos;
        m_touchLastY = m_touchPosition2.y;
        return true;
    }

    return false;
}

void ScrollLayer::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent *event) {
    if (m_cancellingTouches) return;
    if (!m_touchMoved) return;
    CCScrollLayerExt::ccTouchCancelled(touch, event);
    touchFinish(touch);
}

void ScrollLayer::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event) {
    CCScrollLayerExt::ccTouchEnded(touch, event);
    touchFinish(touch);
    m_cancellingTouches = false;
}

void ScrollLayer::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event) {
    CCScrollLayerExt::ccTouchMoved(touch, event);
    m_touchMoved = true;
    auto touchPoint = cocos2d::CCDirector::get()->convertToGL(touch->getLocationInView());
    if (touch == m_touchStart) {
        m_touchPosition2 = m_touchPosition2 - touchPoint;
    }
    if (fabsf(touchPoint.y - m_touchLastY) >= 10.F) {
        m_touchLastY = touchPoint.y;
        cancelAndStoleTouch(touch, event);
    }
}

void ScrollLayer::claimTouch(cocos2d::CCTouch* touch) {
    auto touchDispatcher = cocos2d::CCTouchDispatcher::get();
    if (auto handler = static_cast<cocos2d::CCTargetedTouchHandler*>(touchDispatcher->findHandler(this))) {
        cocos2d::CCSet* claimedTouches = handler->getClaimedTouches();
        if (!claimedTouches->containsObject(touch)) {
            claimedTouches->addObject(touch);
        }
    }
}

void ScrollLayer::cancelAndStoleTouch(cocos2d::CCTouch *touch, cocos2d::CCEvent *event) {
    auto* set = new cocos2d::CCSet();
    set->addObject(touch);
    m_cancellingTouches = true;
    cocos2d::CCTouchDispatcher::get()->touchesCancelled(set, event);
    m_cancellingTouches = false;
    claimTouch(touch);
    delete set;
}

ScrollLayer::ScrollLayer(cocos2d::CCRect const& rect, bool scrollWheelEnabled, bool vertical) : CCScrollLayerExt(rect) {
    m_scrollWheelEnabled = scrollWheelEnabled;

    m_disableVertical = !vertical;
    m_disableHorizontal = vertical;
    m_cutContent = true;

    m_contentLayer->removeFromParent();
    m_contentLayer = geode::GenericContentLayer::create(rect.size.width, rect.size.height);
    m_contentLayer->setID("content-layer");
    m_contentLayer->setAnchorPoint({ 0, 0 });
    this->CCNode::addChild(m_contentLayer);

    m_touchStartPosition2 = cocos2d::CCPointMake(0.f, 0.f);
    m_touchPosition2 = cocos2d::CCPointMake(0.f, 0.f);

    this->setID("ScrollLayerExt"_spr);

    this->CCLayer::setMouseEnabled(true);
    this->CCLayer::setTouchEnabled(true);

    cocos2d::CCTouchDispatcher::get()->registerForcePrio(this, 2);
}

ScrollLayer::~ScrollLayer() {
    cocos2d::CCTouchDispatcher::get()->unregisterForcePrio(this);
}

void ScrollLayer::visit() {
    int previousRect[4];
    bool previousScissor = glIsEnabled(GL_SCISSOR_TEST);

    if (m_cutContent && this->isVisible()) {
        if (previousScissor) {
            glGetIntegerv(GL_SCISSOR_BOX, previousRect);
        } else {
            glEnable(GL_SCISSOR_TEST);
        }

        if (this->getParent()) {
            auto const bottomLeft = this->convertToWorldSpace(ccp(0, 0));
            auto const topRight = this->convertToWorldSpace(this->getContentSize());
            cocos2d::CCSize const size = topRight - bottomLeft;

            cocos2d::CCEGLView::get()->setScissorInPoints(bottomLeft.x, bottomLeft.y, size.width, size.height);
        }
    }

    CCNode::visit();

    if (m_cutContent && this->isVisible()) {
        if (previousScissor) {
            glScissor(previousRect[0], previousRect[1], previousRect[2], previousRect[3]);
        } else {
            glDisable(GL_SCISSOR_TEST);
        }
    }
}

void ScrollLayer::scrollToTop() const {
    auto listTopScrollPos = -m_contentLayer->getContentHeight() + this->getContentHeight();
    m_contentLayer->setPositionY(listTopScrollPos);
}

void ScrollLayer::scrollTo(CCNode* node) const {
    // check if node is in the content layer
    if (node->getParent() != m_contentLayer) return;

    // calculate the position of the node
    auto nodeOffset = m_contentLayer->getContentHeight() - node->getPositionY();
    auto top = -m_contentLayer->getContentHeight() + this->getContentHeight();

    // limit the position to the scrollable area
    auto pos = std::clamp(top + nodeOffset, -m_contentLayer->getContentHeight() + this->getContentHeight(), 0.0f);

    m_contentLayer->setPositionY(pos);
}

ScrollLayer* ScrollLayer::create(cocos2d::CCRect const& rect, bool scrollWheelEnabled, bool vertical) {
    auto ret = new ScrollLayer(rect, scrollWheelEnabled, vertical);
    ret->autorelease();
    return ret;
}

ScrollLayer* ScrollLayer::create(cocos2d::CCSize const& size, bool scrollWheelEnabled, bool vertical) {
    return ScrollLayer::create({ 0, 0, size.width, size.height }, scrollWheelEnabled, vertical);
}

void ScrollLayer::touchFinish(cocos2d::CCTouch* touch) {
    m_touchStartPosition2 = m_touchPosition2;
    m_touchMoved = false;
}

void ScrollLayer::registerWithTouchDispatcher() {
    cocos2d::CCTouchDispatcher::get()->addPrioTargetedDelegate(this, -500, false);
}