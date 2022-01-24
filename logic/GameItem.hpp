#pragma once

#include <string>

enum struct GameItem : uint8_t
{
    HeartDrop = 0x00,
    GreenRupee,
    BlueRupee,
    YellowRupee,
    RedRupee,
    PurpleRupee,
    OrangeRupee,
    PieceOfHeart,
    HeartContainer,
    SmallMagicDrop,
    LargeMagicDrop,
    FiveBombs,
    TenBombs,
    TwentyBombs,
    ThirtyBombs,
    SilverRupee,
    TenArrows,
    TwentyArrows,
    ThirtyArrows,
    DRCSmallKey,
    DRCBigKey,
    SmallKey,
    Fairy,

    NOTHING, //not an item, uses a free space to represent no item (but not invalid)

    YellowRupee2 = 0x1A, //joke message
    DRCDungeonMap,
    DRCCompass,
    FWSmallKey,
    ThreeHearts,
    JoyPendant,
    Telescope,
    TingleBottle,
    WindWaker,
    ProgressivePictoBox,
    SpoilsBag,
    GrapplingHook,
    DeluxePicto,
    ProgressiveBow,
    PowerBracelets,
    IronBoots,
    MagicArmor,

    BaitBag = 0x2C,
    Boomerang,

    Hookshot = 0x2F,
    DeliveryBag,
    Bombs,
    HerosClothes,
    SkullHammer,
    DekuLeaf,
    FireIceArrows,
    LightArrow,
    HerosNewClothes,
    ProgressiveSword,
    MasterSwordPowerless,
    MasterSwordHalf,
    ProgressiveShield,
    MirrorShield,
    RecoveredHerosSword,
    MasterSwordFull,
    PieceOfHeart2, //alternate message
    FWBigKey,
    FWDungeonMap,
    PiratesCharm,
    HerosCharm,

    SkullNecklace = 0x45,
    BokoBabaSeed,
    GoldenFeather,
    KnightsCrest,
    RedChuJelly,
    GreenChuJelly,
    BlueChuJelly,
    DungeonMap,
    Compass,
    BigKey,

    EmptyBottle = 0x50,
    RedPotion,
    GreenPotion,
    BluePotion,
    ElixirSoupHalf,
    ElixirSoup,
    BottledWater,
    FairyInBottle,
    ForestFirefly,
    ForestWater,
    FWCompass,
    TotGSmallKey,
    TotGBigKey,
    TotGDungeonMap,
    TotGCompass,
    FFDungeonMap,
    FFCompass,
    TriforceShard1,
    TriforceShard2,
    TriforceShard3,
    TriforceShard4,
    TriforceShard5,
    TriforceShard6,
    TriforceShard7,
    TriforceShard8,
    NayrusPearl,
    DinsPearl,
    FaroresPearl,

    WindsRequiem = 0x6D,
    BalladOfGales,
    CommandMelody,
    EarthGodsLyric,
    WindGodsAria,
    SongOfPassing,
    ETSmallKey,
    ETBigKey,
    ETDungeonMap,
    ETCompass,
    SwiftSail,
    BoatsSail,
    TriforceChart1Deciphered,
    TriforceChart2Deciphered,
    TriforceChart3Deciphered,
    TriforceChart4Deciphered,
    TriforceChart5Deciphered,
    TriforceChart6Deciphered,
    TriforceChart7Deciphered,
    TriforceChart8Deciphered,
    WTSmallKey,
    AllPurposeBait,
    HyoiPear,
    WTBigKey,
    WTDungeonMap,
    WTCompass,

    TownFlower = 0x8C,
    SeaFlower,
    ExoticFlower,
    HerosFlag,
    BigCatchFlag,
    BigSaleFlag,
    Pinwheel,
    SickleMoonFlag,
    SkullTowerIdol,
    FountainIdol,
    PostmanStatue,
    ShopGuruStatue,
    FathersLetter,
    NoteToMom,
    MaggiesLetter,
    MoblinsLetter,
    CabanaDeed,
    ComplimentaryID,
    FillUpCoupon,
    LegendaryPictograph,

    DragonTingleStatue = 0xA3,
    ForbiddenTingleStatue,
    GoddessTingleStatue,
    EarthTingleStatue,
    WindTingleStatue,

    HurricaneSpin = 0xAA,
    ProgressiveWallet,
    FiveThousandWallet,
    ProgressiveBombBag,
    NinetyNineBombBag,
    ProgressiveQuiver,
    NinetyNineQuiver,

    MagicMeterUpgrade = 0xB2,
    FiftyRupees,
    HundredRupees,
    HundredFiftyRupees,
    TwoHundredRupees,
    TwoHundredFiftyRupees,
    RainbowRupee,

    SubmarineChart = 0xC2,
    BeedlesChart,
    PlatformChart,
    LightRingChart,
    SecretCaveChart,
    SeaHeartsChart,
    IslandHeartsChart,
    GreatFairyChart,
    OctoChart,
    INcredibleChart,
    TreasureChart7,
    TreasureChart27,
    TreasureChart21,
    TreasureChart13,
    TreasureChart32,
    TreasureChart19,
    TreasureChart41,
    TreasureChart26,
    TreasureChart8,
    TreasureChart37,
    TreasureChart25,
    TreasureChart17,
    TreasureChart36,
    TreasureChart22,
    TreasureChart9,
    GhostShipChart,
    TinglesChart,
    TreasureChart14,
    TreasureChart10,
    TreasureChart40,
    TreasureChart3,
    TreasureChart4,
    TreasureChart28,
    TreasureChart16,
    TreasureChart18,
    TreasureChart34,
    TreasureChart29,
    TreasureChart1,
    TreasureChart35,
    TreasureChart12,
    TreasureChart6,
    TreasureChart24,
    TreasureChart39,
    TreasureChart38,
    TreasureChart2,
    TreasureChart33,
    TreasureChart31,
    TreasureChart23,
    TreasureChart5,
    TreasureChart20,
    TreasureChart30,
    TreasureChart15,
    TreasureChart11,
    TreasureChart46,
    TreasureChart45,
    TreasureChart44,
    TriforceChart3,
    TreasureChart43,
    TriforceChart2,
    TreasureChart42,
    TriforceChart1,

    INVALID
};

GameItem nameToGameItem(const std::string& name);

std::string gameItemToName(GameItem item);

GameItem idToGameItem(uint8_t id);

GameItem nameToGameItem(const std::string& name);

uint32_t maxItemCount(GameItem item);

class Item
{
public:
    Item() = default;
    Item(GameItem gameItemId_, int worldId_);

    void setWorldId(int newWorldId);
    int getWorldId() const;
    GameItem getGameItemId() const;
    std::string getName() const;
    bool operator==(const Item& rhs) const;
    bool isMajorItem() const;

private:
    GameItem gameItemId = GameItem::INVALID;
    int worldId = -1; // The world that this item is *FOR*
};

// Hash function for Item class, copied from
// https://en.cppreference.com/w/cpp/utility/hash
template<>
struct std::hash<Item>
{
    size_t operator()(Item const& i) const noexcept
    {
        size_t h1 = std::hash<GameItem>{}(i.getGameItemId());
        size_t h2 = std::hash<int>{}(i.getWorldId());
        return h1 ^ (h2 << 1);
    }
};
