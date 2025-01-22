#pragma once
#include "label.hpp"
#include "utils.hpp"

namespace custom {
    // Level difficulties
    constexpr custom_emoji<":na:", 0x1c000> DiffNA;
    constexpr custom_emoji<":auto:", 0x1c001> DiffAuto;
    constexpr custom_emoji<":easy:", 0x1c002> DiffEasy;
    constexpr custom_emoji<":normal:", 0x1c003> DiffNormal;
    constexpr custom_emoji<":hard:", 0x1c004> DiffHard;
    constexpr custom_emoji<":harder:", 0x1c005> DiffHarder;
    constexpr custom_emoji<":insane:", 0x1c006> DiffInsane;
    constexpr custom_emoji<":easydemon:", 0x1c007> DiffEasyDemon;
    constexpr custom_emoji<":mediumdemon:", 0x1c008> DiffMediumDemon;
    constexpr custom_emoji<":harddemon:", 0x1c009> DiffHardDemon;
    constexpr custom_emoji<":insanedemon:", 0x1c00a> DiffInsaneDemon;
    constexpr custom_emoji<":extremedemon:", 0x1c00b> DiffExtremeDemon;

    // Currency
    constexpr custom_emoji<":orb:", 0x1c00c> Orb;
    constexpr custom_emoji<":orbs:", 0x1c00d> Orbs;
    constexpr custom_emoji<":diamond:", 0x1c00e> Diamond;
    constexpr custom_emoji<":diamonds:", 0x1c00f> Diamonds;

    // Locks
    constexpr custom_emoji<":locked:", 0x1c010> Locked;
    constexpr custom_emoji<":lockedgray:", 0x1c011> LockedGray;
    constexpr custom_emoji<":unlocked:", 0x1c012> Unlocked;
}

static std::initializer_list<Emoji> EmojiReplacements = {
    // Geometry Dash icons
    custom::DiffNA, custom::DiffAuto, custom::DiffEasy,
    custom::DiffNormal, custom::DiffHard, custom::DiffHarder,
    custom::DiffInsane, custom::DiffEasyDemon, custom::DiffMediumDemon,
    custom::DiffHardDemon, custom::DiffInsaneDemon, custom::DiffExtremeDemon,
    custom::Orb, custom::Orbs, custom::Diamond, custom::Diamonds,
    custom::Locked, custom::LockedGray, custom::Unlocked,
    Emoji{":star:", "⭐"}, Emoji{":moon:", "🌙"},
    Emoji{":check:", "✔️"}, Emoji{":cross:", "❌"},
    Emoji{":like:", "👍"}, Emoji{":dislike:", "👎"},

    // twemoji pack (Emojis in Comments)
    Emoji{":100:", "💯"},
    Emoji{":shushing_face:", "🤫"},
    Emoji{":deaf_person:", "🧏"},
    Emoji{":deaf_man:", "🧏‍♂️"},
    Emoji{":deaf_woman:", "🧏‍♀️"},
    Emoji{":bear:", "🐻"},
    Emoji{":broken_heart:", "💔"},
    Emoji{":cat:", "🐱"},
    Emoji{":dog:", "🐶"},
    Emoji{":fox:", "🦊"},
    Emoji{":gun:", "🔫"},
    Emoji{":face_with_raised_eyebrow:", "🤨"},
    Emoji{":middle_finger:", "🖕"},
    Emoji{":moyai:", "🗿"},
    Emoji{":fire:", "🔥"},
    Emoji{":nerd:", "🤓"},
    Emoji{":radioactive:", "☢️"},
    Emoji{":scream:", "😱"},
    Emoji{":skull:", "💀"},
    Emoji{":smiling_imp:", "😈"},
    Emoji{":speaking_head:", "🗣️"},
    Emoji{":sob:", "😭"},
    Emoji{":eggplant:", "🍆"},
    Emoji{":clown:", "🤡"},
    Emoji{":tongue:", "👅"},

    // twemoji pack (Extended)
    Emoji{":alien:", "👽"},
    Emoji{":baby:", "👶"},
    Emoji{":robot:", "🤖"},
    Emoji{":heart:", "❤️"},
    Emoji{":ghost:", "👻"},
    Emoji{":exploding_head:", "🤯"},
    Emoji{":snowflake:", "❄️"},
    Emoji{":sleeping_accommodation:", "🛌"},
    Emoji{":person_in_steamy_room:", "🧖"},
    Emoji{":fish:", "🐟"},
    Emoji{":sparkles:", "✨"},
    Emoji{":party_popper:", "🎉"},
    Emoji{":pig:", "🐷"},
    Emoji{":new_moon_with_face:", "🌚"},
    Emoji{":last_quarter_moon:", "🌗"},
    Emoji{":new_moon:", "🌑"},
    Emoji{":sun_with_face:", "🌞"},
    Emoji{":full_moon_with_face:", "🌝"},
    Emoji{":monkey_face:", "🐵"},
    Emoji{":see_no_evil:", "🙈"},
    Emoji{":hear_no_evil:", "🙉"},
    Emoji{":speak_no_evil:", "🙊"},
    Emoji{":crown:", "👑"},
    Emoji{":pray:", "🙏"},
    Emoji{":bangbang:", "‼️"},
    Emoji{":question:", "❓"},

    // Regional Indicators
    Emoji{":zero:", "0️⃣"}, Emoji{":one:", "1️⃣"},
    Emoji{":two:", "2️⃣"}, Emoji{":three:", "3️⃣"},
    Emoji{":four:", "4️⃣"}, Emoji{":five:", "5️⃣"},
    Emoji{":six:", "6️⃣"}, Emoji{":seven:", "7️⃣"},
    Emoji{":eight:", "8️⃣"}, Emoji{":nine:", "9️⃣"},

    // alt names
    Emoji{":shocked_face:", "😱"},
    Emoji{":folded_hands:", "🙏"},
};

static Label::EmojiMap EmojiSheet = {
    // Geometry Dash icons
    custom::DiffNA, custom::DiffAuto, custom::DiffEasy,
    custom::DiffNormal, custom::DiffHard, custom::DiffHarder,
    custom::DiffInsane, custom::DiffEasyDemon, custom::DiffMediumDemon,
    custom::DiffHardDemon, custom::DiffInsaneDemon, custom::DiffExtremeDemon,
    custom::Orb, custom::Orbs, custom::Diamond, custom::Diamonds,
    custom::Locked, custom::LockedGray, custom::Unlocked,
    U"⭐"_emoji, U"🌙"_emoji,
    U"✔️"_emoji, U"❌"_emoji,
    U"👍"_emoji, U"👎"_emoji,

    // twemoji pack (Emojis in Comments)
    U"💯"_emoji, U"🤫"_emoji, U"🧏"_emoji, U"🧏‍♂️"_emoji, U"🧏‍♀️"_emoji,
    U"🐻"_emoji, U"💔"_emoji, U"🐱"_emoji, U"🐶"_emoji, U"🦊"_emoji,
    U"🔫"_emoji, U"🤨"_emoji, U"🖕"_emoji, U"🗿"_emoji, U"🔥"_emoji,
    U"🤓"_emoji, U"☢️"_emoji, U"😱"_emoji, U"💀"_emoji, U"😈"_emoji,
    U"🗣️"_emoji, U"😭"_emoji, U"🍆"_emoji, U"🤡"_emoji, U"👅"_emoji,

    // twemoji pack (Extended)
    U"👽"_emoji, U"👶"_emoji, U"🤖"_emoji, U"❤️"_emoji, U"👻"_emoji,
    U"🤯"_emoji, U"❄️"_emoji, U"🛌"_emoji, U"🧖"_emoji, U"🐟"_emoji,
    U"✨"_emoji, U"🎉"_emoji, U"🐷"_emoji, U"🌚"_emoji, U"🌗"_emoji,
    U"🌑"_emoji, U"🌞"_emoji, U"🌝"_emoji, U"🐵"_emoji, U"🙈"_emoji,
    U"🙉"_emoji, U"🙊"_emoji, U"👑"_emoji, U"🙏"_emoji, U"‼️"_emoji,
    U"❓"_emoji,

    // Regional Indicators
    U"0️⃣"_emoji, U"1️⃣"_emoji, U"2️⃣"_emoji, U"3️⃣"_emoji,
    U"4️⃣"_emoji, U"5️⃣"_emoji, U"6️⃣"_emoji, U"7️⃣"_emoji,
    U"8️⃣"_emoji, U"9️⃣"_emoji,
};