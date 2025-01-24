#pragma once

class FrameAnimation : public cocos2d::CCSprite {
public:
    static FrameAnimation* create(const char* frame_prefix, size_t frame_count, float delay);

    void play() { m_playing = true; }
    void pause() { m_playing = false; }
    void stop() { m_playing = false; setFrame(0); }

    void setPlaying(bool playing) { m_playing = playing; }
    void setDelay(float delay) { m_delay = delay; }
    void setFrame(size_t frame) { m_current_frame = frame; refreshFrame(); }

protected:
    bool init(const char* frame_prefix, size_t frame_count, float delay);
    void update(float delta) override;
    void refreshFrame();

protected:
    std::vector<cocos2d::CCSpriteFrame*> m_frames;
    std::string m_frame_prefix;
    size_t m_frame_count = 0;
    size_t m_current_frame = 0;
    float m_delay = 0;
    float m_elapsed = 0;
    bool m_playing = false;
};