#include "animated-sprite.hpp"
#include <fmt/format.h>

FrameAnimation* FrameAnimation::create(const char* frame_prefix, size_t frame_count, float delay) {
    auto ret = new FrameAnimation();
    if (ret->init(frame_prefix, frame_count, delay)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool FrameAnimation::init(const char* frame_prefix, size_t frame_count, float delay) {
    m_frame_prefix = frame_prefix;
    m_frame_count = frame_count;
    m_delay = delay;
    m_playing = true;

    for (size_t i = 1; i <= frame_count; i++) {
        auto frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
            fmt::format("{}_{:03}.png", frame_prefix, i).c_str()
        );
        if (frame) {
            m_frames.push_back(frame);
        }
    }

    if (m_frames.empty()) {
        return false;
    }

    if (!CCSprite::init()) {
        return false;
    }

    this->refreshFrame();
    this->scheduleUpdate();

    return true;
}

void FrameAnimation::update(float delta) {
    if (!m_playing) { return; }

    m_elapsed += delta;
    if (m_elapsed >= m_delay) {
        int frames = m_elapsed / m_delay;
        m_elapsed -= frames * m_delay;
        m_current_frame = (m_current_frame + frames) % m_frame_count;
        refreshFrame();
    }
}

void FrameAnimation::refreshFrame() {
    auto frame = m_frames[m_current_frame];
    this->setDisplayFrame(frame);
}
