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

    // Coins
    constexpr char32_t CoinBase = 0x1c020;
    constexpr custom_emoji<":goldcoin:", CoinBase> GoldCoin;
    constexpr custom_emoji<":uncollectedusercoin:", CoinBase + 1> UncollectedUserCoin;
    constexpr custom_emoji<":usercoinunverified:", CoinBase + 2> UserCoinUnverified;
    constexpr custom_emoji<":usercoin:", CoinBase + 3> UserCoin;
    constexpr custom_emoji<":points:", CoinBase + 4> Points;

    // Mod badges
    constexpr char32_t ModBase = 0x1c02a;
    constexpr custom_emoji<":mod:", ModBase> Mod;
    constexpr custom_emoji<":eldermod:", ModBase + 1> ElderMod;
    constexpr custom_emoji<":leaderboardmod:", ModBase + 2> LeaderboardMod;

    // Legacy set
    constexpr char32_t LegacyBase = 0x1c030;
    constexpr custom_emoji<":amongus:", LegacyBase> AmongUs;
    constexpr custom_emoji<":amogus:", LegacyBase + 1> Amogus;
    constexpr custom_emoji<":bruh:", LegacyBase + 2> Bruh;
    constexpr custom_emoji<":carlos:", LegacyBase + 3> Carlos;
    constexpr custom_emoji<":clueless:", LegacyBase + 4> Clueless;
    constexpr custom_emoji<":despair:", LegacyBase + 5> Despair;
    constexpr custom_emoji<":despair2:", LegacyBase + 6> Despair2;
    constexpr custom_emoji<":ned:", LegacyBase + 7> Ned;
    constexpr custom_emoji<":pusab?:", LegacyBase + 8> Pusab;
    constexpr custom_emoji<":robsmile:", LegacyBase + 9> RobSmile;
    constexpr custom_emoji<":sip:", LegacyBase + 10> Sip;
    constexpr custom_emoji<":splat:", LegacyBase + 11> Splat;
    constexpr custom_emoji<":teehee:", LegacyBase + 12> Teehee;
    constexpr custom_emoji<":trollface:", LegacyBase + 13> Trollface;
    constexpr custom_emoji<":true:", LegacyBase + 14> True;
    constexpr custom_emoji<":walter:", LegacyBase + 15> Walter;
    constexpr custom_emoji<":wha:", LegacyBase + 16> Wha;
    constexpr custom_emoji<":whadahell:", LegacyBase + 17> Whadahell;
    constexpr custom_emoji<":youshould:", LegacyBase + 18> YouShould;
    constexpr custom_emoji<":car:", LegacyBase + 19> Car;
    constexpr custom_emoji<":zoink:", LegacyBase + 20> Zoink;
    constexpr custom_emoji<":shocked:", LegacyBase + 21> Shocked;
    constexpr custom_emoji<":poppinbottles:", LegacyBase + 22> PoppinBottles;
    constexpr custom_emoji<":party:", LegacyBase + 23> Party;
    constexpr custom_emoji<":potbor:", LegacyBase + 24> Potbor;
    constexpr custom_emoji<":dabmeup:", LegacyBase + 25> DabMeUp;
    constexpr custom_emoji<":fireinthehole:", LegacyBase + 26> FireInTheHole;
    constexpr custom_emoji<":finger:", LegacyBase + 27> Finger;
    constexpr custom_emoji<":soggy:", LegacyBase + 28> Soggy;
    constexpr custom_emoji<":mayo:", LegacyBase + 29> Mayo;
    constexpr custom_emoji<":divine:", LegacyBase + 30> Divine;
    constexpr custom_emoji<":bueno:", LegacyBase + 31> Bueno;
    constexpr custom_emoji<":rattledash:", LegacyBase + 32> RattleDash;
    constexpr custom_emoji<":gd:", LegacyBase + 33> GD;
    constexpr custom_emoji<":geode:", LegacyBase + 34> Geode;
    constexpr custom_emoji<":boar:", LegacyBase + 35> Boar;
    constexpr custom_emoji<":mewhen:", LegacyBase + 36> MeWhen;
    constexpr custom_emoji<":changetopic:", LegacyBase + 37> ChangeTopic;
    constexpr custom_emoji<":touchgrass:", LegacyBase + 38> TouchGrass;
    constexpr custom_emoji<":gggggggg:", LegacyBase + 39> GGGGGGGG;
    constexpr custom_emoji<":gdok:", LegacyBase + 40> GDOK;
    constexpr custom_emoji<":hug:", LegacyBase + 41> Hug;
    constexpr custom_emoji<":angy:", LegacyBase + 42> Angy;
    constexpr custom_emoji<":lewd:", LegacyBase + 43> Lewd;
    constexpr custom_emoji<":headpat:", LegacyBase + 44> Headpat;
    constexpr custom_emoji<":transcat:", LegacyBase + 45> Transcat;
    constexpr custom_emoji<":transcat2:", LegacyBase + 46> Transcat2;
    constexpr custom_emoji<":skillissue:", LegacyBase + 47> SkillIssue;
    constexpr custom_emoji<":yes:", LegacyBase + 48> Yes;
    constexpr custom_emoji<":gunleft:", LegacyBase + 49> GunLeft;
    constexpr custom_emoji<":gunright:", LegacyBase + 50> GunRight;
    constexpr custom_emoji<":edge:", LegacyBase + 51> Edge;
    constexpr custom_emoji<":cologne:", LegacyBase + 52> Cologne;
    constexpr custom_emoji<":globed:", LegacyBase + 53> Globed;
    constexpr custom_emoji<":levelthumbnails:", LegacyBase + 54> LevelThumbnails;
    constexpr custom_emoji<":oh:", LegacyBase + 55> Oh;
    constexpr custom_emoji<":holymoly:", LegacyBase + 56> HolyMoly;
    constexpr custom_emoji<":1000yardstare:", LegacyBase + 57> ThousandYardStare;
    constexpr custom_emoji<":spunchbob:", LegacyBase + 58> SpunchBob;
    constexpr custom_emoji<":freakbob:", LegacyBase + 59> FreakBob;
    constexpr custom_emoji<":nuhuh:", LegacyBase + 60> Nuhuh;
    constexpr custom_emoji<":yuhuh:", LegacyBase + 61> Yuhuh;

    // Cube Emotes (By @cyanflower)
    constexpr char32_t CubeBase = 0x1c070;
    constexpr custom_emoji<":boshytime:", CubeBase> BoshyTime;
    constexpr custom_emoji<":cubeballin:", CubeBase + 1> CubeBallin;
    constexpr custom_emoji<":cubeconfused:", CubeBase + 2> CubeConfused;
    constexpr custom_emoji<":cubecool:", CubeBase + 3> CubeCool;
    constexpr custom_emoji<":cubehappy:", CubeBase + 4> CubeHappy;
    constexpr custom_emoji<":cubeletsgo:", CubeBase + 5> CubeLetsGo;
    constexpr custom_emoji<":cubepog:", CubeBase + 6> CubePog;
    constexpr custom_emoji<":cubescared:", CubeBase + 7> CubeScared;
    constexpr custom_emoji<":cubestare:", CubeBase + 8> CubeStare;
    constexpr custom_emoji<":cubethink:", CubeBase + 9> CubeThink;
    constexpr custom_emoji<":cubeview:", CubeBase + 10> CubeView;
    constexpr custom_emoji<":cubewink:", CubeBase + 11> CubeWink;
    constexpr custom_emoji<":defaultangry:", CubeBase + 12> DefaultAngry;
    constexpr custom_emoji<":eeyikes:", CubeBase + 13> EeYikes;
    constexpr custom_emoji<":fumocube:", CubeBase + 14> FumoCube;
    constexpr custom_emoji<":robtoppixel:", CubeBase + 15> RobTopPixel;
    constexpr custom_emoji<":smugzero:", CubeBase + 16> SmugZero;

    // Cat Emotes (C# Discord Server)
    constexpr char32_t CatBase = 0x1c090;
    constexpr custom_emoji<":catbless:", CatBase> CatBless;
    constexpr custom_emoji<":catcash:", CatBase + 1> CatCash;
    constexpr custom_emoji<":catcomf:", CatBase + 2> CatComf;
    constexpr custom_emoji<":catcool:", CatBase + 3> CatCool;
    constexpr custom_emoji<":catcop:", CatBase + 4> CatCop;
    constexpr custom_emoji<":catcorn:", CatBase + 5> CatCorn;
    constexpr custom_emoji<":catderp:", CatBase + 6> CatDerp;
    constexpr custom_emoji<":catfacepalm:", CatBase + 7> CatFacepalm;
    constexpr custom_emoji<":catfine:", CatBase + 8> CatFine;
    constexpr custom_emoji<":catgasm:", CatBase + 9> CatGasm;
    constexpr custom_emoji<":catgasp:", CatBase + 10> CatGasp;
    constexpr custom_emoji<":catgift:", CatBase + 11> CatGift;
    constexpr custom_emoji<":catgrump:", CatBase + 12> CatGrump;
    constexpr custom_emoji<":catgun:", CatBase + 13> CatGun;
    constexpr custom_emoji<":cathammer:", CatBase + 14> CatHammer;
    constexpr custom_emoji<":cathi:", CatBase + 15> CatHi;
    constexpr custom_emoji<":cathype:", CatBase + 16> CatHype;
    constexpr custom_emoji<":catlaugh:", CatBase + 17> CatLaugh;
    constexpr custom_emoji<":catlick:", CatBase + 18> CatLick;
    constexpr custom_emoji<":catloser:", CatBase + 19> CatLoser;
    constexpr custom_emoji<":catlost:", CatBase + 20> CatLost;
    constexpr custom_emoji<":catlove:", CatBase + 21> CatLove;
    constexpr custom_emoji<":catlul:", CatBase + 22> CatLul;
    constexpr custom_emoji<":catlurk:", CatBase + 23> CatLurk;
    constexpr custom_emoji<":catmusik:", CatBase + 24> CatMusik;
    constexpr custom_emoji<":catok:", CatBase + 25> CatOK;
    constexpr custom_emoji<":catpat:", CatBase + 26> CatPat;
    constexpr custom_emoji<":catpls:", CatBase + 27> CatPls;
    constexpr custom_emoji<":catpog:", CatBase + 28> CatPog;
    constexpr custom_emoji<":catpout:", CatBase + 29> CatPout;
    constexpr custom_emoji<":catree:", CatBase + 30> CatRee;
    constexpr custom_emoji<":catshrug:", CatBase + 31> CatShrug;
    constexpr custom_emoji<":catshy:", CatBase + 32> CatShy;
    constexpr custom_emoji<":catsimp:", CatBase + 33> CatSimp;
    constexpr custom_emoji<":catsip:", CatBase + 34> CatSip;
    constexpr custom_emoji<":catsleep:", CatBase + 35> CatSleep;
    constexpr custom_emoji<":catsmart:", CatBase + 36> CatSmart;
    constexpr custom_emoji<":catsweat:", CatBase + 37> CatSweat;
    constexpr custom_emoji<":catthinking:", CatBase + 38> CatThinking;

    // Player Icons
    constexpr char32_t PlayersBase = 0x1c0c0;
    constexpr custom_emoji<":default:", PlayersBase> PlayerDefault;
    constexpr custom_emoji<":sdslayer:", PlayersBase + 1> PlayerSdslayer;
    constexpr custom_emoji<":evw:", PlayersBase + 2> PlayerEVW;
    constexpr custom_emoji<":tride:", PlayersBase + 3> PlayerTride;
    constexpr custom_emoji<":colon:", PlayersBase + 4> PlayerColon;
    constexpr custom_emoji<":robtop:", PlayersBase + 5> PlayerRobTop;
    constexpr custom_emoji<":wulzy:", PlayersBase + 6> PlayerWulzy;
    constexpr custom_emoji<":juniper:", PlayersBase + 7> PlayerJuniper;
    constexpr custom_emoji<":riot:", PlayersBase + 8> PlayerRiot;
    constexpr custom_emoji<":cyclic:", PlayersBase + 9> PlayerCyclic;
    constexpr custom_emoji<":thesillydoggo:", PlayersBase + 10> PlayerTheSillyDoggo;
    constexpr custom_emoji<":uproxide:", PlayersBase + 11> PlayerUproxide;
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

    // Coins
    custom::GoldCoin, custom::UncollectedUserCoin, custom::UserCoinUnverified,
    custom::UserCoin, custom::Points,

    // Mod badges
    custom::Mod, custom::ElderMod, custom::LeaderboardMod,

    // Legacy set
    custom::AmongUs, custom::Amogus, custom::Bruh, custom::Carlos,
    custom::Clueless, custom::Despair, custom::Despair2, custom::Ned,
    custom::Pusab, custom::RobSmile, custom::Sip, custom::Splat,
    custom::Teehee, custom::Trollface, custom::True, custom::Walter,
    custom::Wha, custom::Whadahell, custom::YouShould, custom::Car,
    custom::Zoink, custom::Shocked, custom::PoppinBottles, custom::Party,
    custom::Potbor, custom::DabMeUp, custom::FireInTheHole, custom::Finger,
    custom::Soggy, custom::Mayo, custom::Divine, custom::Bueno,
    custom::RattleDash, custom::GD, custom::Geode, custom::Boar,
    custom::MeWhen, custom::ChangeTopic, custom::TouchGrass, custom::GGGGGGGG,
    custom::GDOK, custom::Hug, custom::Angy, custom::Lewd,
    custom::Headpat, custom::Transcat, custom::Transcat2, custom::SkillIssue,
    custom::Yes, custom::GunLeft, custom::GunRight, custom::Edge,
    custom::Cologne, custom::Globed, custom::LevelThumbnails, custom::Oh,
    custom::HolyMoly, custom::ThousandYardStare, custom::SpunchBob,
    custom::FreakBob, custom::Nuhuh, custom::Yuhuh,

    // Cube Emotes
    custom::BoshyTime, custom::CubeBallin, custom::CubeConfused,
    custom::CubeCool, custom::CubeHappy, custom::CubeLetsGo,
    custom::CubePog, custom::CubeScared, custom::CubeStare,
    custom::CubeThink, custom::CubeView, custom::CubeWink,
    custom::DefaultAngry, custom::EeYikes, custom::FumoCube,
    custom::RobTopPixel, custom::SmugZero,

    // Cat Emotes
    custom::CatBless, custom::CatCash, custom::CatComf,
    custom::CatCool, custom::CatCop, custom::CatCorn,
    custom::CatDerp, custom::CatFacepalm, custom::CatFine,
    custom::CatGasm, custom::CatGasp, custom::CatGift,
    custom::CatGrump, custom::CatGun, custom::CatHammer,
    custom::CatHi, custom::CatHype, custom::CatLaugh,
    custom::CatLick, custom::CatLoser, custom::CatLost,
    custom::CatLove, custom::CatLul, custom::CatLurk,
    custom::CatMusik, custom::CatOK, custom::CatPat,
    custom::CatPls, custom::CatPog, custom::CatPout,
    custom::CatRee, custom::CatShrug, custom::CatShy,
    custom::CatSimp, custom::CatSip, custom::CatSleep,
    custom::CatSmart, custom::CatSweat, custom::CatThinking,

    // Player Icons
    custom::PlayerDefault, custom::PlayerSdslayer, custom::PlayerEVW,
    custom::PlayerTride, custom::PlayerColon, custom::PlayerRobTop,
    custom::PlayerWulzy, custom::PlayerJuniper, custom::PlayerRiot,
    custom::PlayerCyclic, custom::PlayerTheSillyDoggo, custom::PlayerUproxide,

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

    // Coins
    custom::GoldCoin, custom::UncollectedUserCoin, custom::UserCoinUnverified,
    custom::UserCoin, custom::Points,

    // Mod badges
    custom::Mod, custom::ElderMod, custom::LeaderboardMod,

    // Legacy set
    custom::AmongUs, custom::Amogus, custom::Bruh, custom::Carlos,
    custom::Clueless, custom::Despair, custom::Despair2, custom::Ned,
    custom::Pusab, custom::RobSmile, custom::Sip, custom::Splat,
    custom::Teehee, custom::Trollface, custom::True, custom::Walter,
    custom::Wha, custom::Whadahell, custom::YouShould, custom::Car,
    custom::Zoink, custom::Shocked, custom::PoppinBottles, custom::Party,
    custom::Potbor, custom::DabMeUp, custom::FireInTheHole, custom::Finger,
    custom::Soggy, custom::Mayo, custom::Divine, custom::Bueno,
    custom::RattleDash, custom::GD, custom::Geode, custom::Boar,
    custom::MeWhen, custom::ChangeTopic, custom::TouchGrass, custom::GGGGGGGG,
    custom::GDOK, custom::Hug, custom::Angy, custom::Lewd,
    custom::Headpat, custom::Transcat, custom::Transcat2, custom::SkillIssue,
    custom::Yes, custom::GunLeft, custom::GunRight, custom::Edge,
    custom::Cologne, custom::Globed, custom::LevelThumbnails, custom::Oh,
    custom::HolyMoly, custom::ThousandYardStare, custom::SpunchBob,
    custom::FreakBob, custom::Nuhuh, custom::Yuhuh,

    // Cube Emotes
    custom::BoshyTime, custom::CubeBallin, custom::CubeConfused,
    custom::CubeCool, custom::CubeHappy, custom::CubeLetsGo,
    custom::CubePog, custom::CubeScared, custom::CubeStare,
    custom::CubeThink, custom::CubeView, custom::CubeWink,
    custom::DefaultAngry, custom::EeYikes, custom::FumoCube,
    custom::RobTopPixel, custom::SmugZero,

    // Cat Emotes
    custom::CatBless, custom::CatCash, custom::CatComf,
    custom::CatCool, custom::CatCop, custom::CatCorn,
    custom::CatDerp, custom::CatFacepalm, custom::CatFine,
    custom::CatGasm, custom::CatGasp, custom::CatGift,
    custom::CatGrump, custom::CatGun, custom::CatHammer,
    custom::CatHi, custom::CatHype, custom::CatLaugh,
    custom::CatLick, custom::CatLoser, custom::CatLost,
    custom::CatLove, custom::CatLul, custom::CatLurk,
    custom::CatMusik, custom::CatOK, custom::CatPat,
    custom::CatPls, custom::CatPog, custom::CatPout,
    custom::CatRee, custom::CatShrug, custom::CatShy,
    custom::CatSimp, custom::CatSip, custom::CatSleep,
    custom::CatSmart, custom::CatSweat, custom::CatThinking,

    // Player Icons
    custom::PlayerDefault, custom::PlayerSdslayer, custom::PlayerEVW,
    custom::PlayerTride, custom::PlayerColon, custom::PlayerRobTop,
    custom::PlayerWulzy, custom::PlayerJuniper, custom::PlayerRiot,
    custom::PlayerCyclic, custom::PlayerTheSillyDoggo, custom::PlayerUproxide,

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