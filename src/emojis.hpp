#pragma once
#include "label.hpp"
#include "utils.hpp"

namespace custom {
    // Level difficulties
    constexpr char32_t DiffBase = 0x1c000;
    constexpr custom_emoji<":na:", DiffBase> DiffNA;
    constexpr custom_emoji<":auto:", DiffBase + 1> DiffAuto;
    constexpr custom_emoji<":easy:", DiffBase + 2> DiffEasy;
    constexpr custom_emoji<":normal:", DiffBase + 3> DiffNormal;
    constexpr custom_emoji<":hard:", DiffBase + 4> DiffHard;
    constexpr custom_emoji<":harder:", DiffBase + 5> DiffHarder;
    constexpr custom_emoji<":insane:", DiffBase + 6> DiffInsane;
    constexpr custom_emoji<":easydemon:", DiffBase + 7> DiffEasyDemon;
    constexpr custom_emoji<":mediumdemon:", DiffBase + 8> DiffMediumDemon;
    constexpr custom_emoji<":harddemon:", DiffBase + 9> DiffHardDemon;
    constexpr custom_emoji<":insanedemon:", DiffBase + 10> DiffInsaneDemon;
    constexpr custom_emoji<":extremedemon:", DiffBase + 11> DiffExtremeDemon;
    constexpr custom_emoji<":casual:", DiffBase + 12> DiffCasual;
    constexpr custom_emoji<":tough:", DiffBase + 13> DiffTough;
    constexpr custom_emoji<":cruel:", DiffBase + 14> DiffCruel;
    constexpr custom_emoji<":creul:", DiffBase + 14> DiffCreul; // typo from original mod

    // Currency
    constexpr char32_t CurrencyBase = 0x1c010;
    constexpr custom_emoji<":orb:", CurrencyBase> Orb;
    constexpr custom_emoji<":orbs:", CurrencyBase + 1> Orbs;
    constexpr custom_emoji<":diamond:", CurrencyBase + 2> Diamond;
    constexpr custom_emoji<":diamonds:", CurrencyBase + 3> Diamonds;

    // Locks
    constexpr char32_t LockBase = 0x1c01a;
    constexpr custom_emoji<":locked:", LockBase> Locked;
    constexpr custom_emoji<":lockedgray:", LockBase + 1> LockedGray;
    constexpr custom_emoji<":unlocked:", LockBase + 2> Unlocked;
}

static std::initializer_list<Emoji> EmojiReplacements = {
    // Level difficulties
    custom::DiffNA, custom::DiffAuto, custom::DiffEasy,
    custom::DiffNormal, custom::DiffHard, custom::DiffHarder,
    custom::DiffInsane, custom::DiffEasyDemon, custom::DiffMediumDemon,
    custom::DiffHardDemon, custom::DiffInsaneDemon, custom::DiffExtremeDemon,
    custom::DiffCasual, custom::DiffTough, custom::DiffCruel, custom::DiffCreul,

    // Currency
    custom::Orb, custom::Orbs, custom::Diamond, custom::Diamonds,

    // Locks
    custom::Locked, custom::LockedGray, custom::Unlocked,

    // Geometry Dash icons
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
    // Level difficulties
    custom::DiffNA, custom::DiffAuto, custom::DiffEasy,
    custom::DiffNormal, custom::DiffHard, custom::DiffHarder,
    custom::DiffInsane, custom::DiffEasyDemon, custom::DiffMediumDemon,
    custom::DiffHardDemon, custom::DiffInsaneDemon, custom::DiffExtremeDemon,
    custom::DiffCasual, custom::DiffTough, custom::DiffCruel, custom::DiffCreul,

    // Currency
    custom::Orb, custom::Orbs, custom::Diamond, custom::Diamonds,

    // Locks
    custom::Locked, custom::LockedGray, custom::Unlocked,

    // Geometry Dash icons
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