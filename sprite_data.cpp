//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

//------< インクルード >----------------------------------------------------------
#include "all.h"
//------< マクロ >--------------------------------------------------------------
#define SPRITE_LEFT(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),0,0 }      // 画像の左上が中心
#define SPRITE_CENTER(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)/2 }  // 画像の真ん中が中心
#define SPRITE_BOTTOM(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)   }  // 画像の足元が中心
//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< データ >---------------------------------------------------------------
//下歩き
SpriteData sprPlayer_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 1, 96, 128);
SpriteData sprPlayer_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 1, 96, 128);
SpriteData sprPlayer_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 1, 96, 128);

//上歩き
SpriteData sprPlayer_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 2, 96, 128);
SpriteData sprPlayer_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 2, 96, 128);
SpriteData sprPlayer_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 2, 96, 128);

//左歩き
SpriteData sprPlayer_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 3, 96, 128);
SpriteData sprPlayer_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 3, 96, 128);
SpriteData sprPlayer_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 3, 96, 128);

//右歩き
SpriteData sprPlayer_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 4, 96, 128);
SpriteData sprPlayer_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 4, 96, 128);
SpriteData sprPlayer_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 4, 96, 128);

////大型
//SpriteData sprGarbage_Large0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 192 * 0, 0, 192, 192);
//SpriteData sprGarbage_Large1  = SPRITE_BOTTOM(TEXNO::GARBAGE, 192 * 1, 0, 192, 192);
//SpriteData sprGarbage_Large2  = SPRITE_BOTTOM(TEXNO::GARBAGE, 192 * 2, 0, 192, 192);
////中型
//SpriteData sprGarbage_Medium0 = SPRITE_BOTTOM(TEXNO::GARBAGE, 128 * 0, 192 , 128, 128);
//SpriteData sprGarbage_Medium1 = SPRITE_BOTTOM(TEXNO::GARBAGE, 128 * 1, 192 , 128, 128);
//SpriteData sprGarbage_Medium2 = SPRITE_BOTTOM(TEXNO::GARBAGE, 128 * 2, 192 , 128, 128);
////小型
//SpriteData sprGarbage_Small0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 320 * 0, 320 , 64, 64);
//SpriteData sprGarbage_Small1  = SPRITE_BOTTOM(TEXNO::GARBAGE, 320 * 1, 320 , 64, 64);
//SpriteData sprGarbage_Small2  = SPRITE_BOTTOM(TEXNO::GARBAGE, 320 * 2, 320 , 64, 64);
//大型
SpriteData sprGarbage_Large0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 0, 64, 64);
//SpriteData sprGarbage_Large1  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 0, 64, 64);
//SpriteData sprGarbage_Large2  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 0, 64, 64);
//中型
SpriteData sprGarbage_Medium0 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 0, 64, 64);
//SpriteData sprGarbage_Medium1 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 192, 64, 64);
//SpriteData sprGarbage_Medium2 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 192 ,64, 64);
//小型
SpriteData sprGarbage_Small0  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 0, 0, 64, 64);
//SpriteData sprGarbage_Small1  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 1, 128, 64, 64);
//SpriteData sprGarbage_Small2  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 2 ,128, 64, 64);

SpriteData sprGarbage_Gold = SPRITE_BOTTOM(TEXNO::GOLD, 64 * 0, 0, 64, 64);

//プレス機
SpriteData sprPressMachine = SPRITE_BOTTOM(TEXNO::PRESS, 0, 0, 275, 610);

//背景
SpriteData sprBG = SPRITE_LEFT(TEXNO::BG, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//コンベアー
SpriteData sprConveyor0 = SPRITE_LEFT(TEXNO::CONVEYOR, system::SCREEN_WIDTH * 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor1 = SPRITE_LEFT(TEXNO::CONVEYOR, system::SCREEN_WIDTH * 1, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor2 = SPRITE_LEFT(TEXNO::CONVEYOR, system::SCREEN_WIDTH * 2, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);


//柵
SpriteData sprBer = SPRITE_LEFT(TEXNO::BER, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//ダストボックス
SpriteData sprDustBox = SPRITE_CENTER(TEXNO::DUSTBOX, 387, 0, 173, 171);

//数字
SpriteData sprNumber0 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 0, 64, 64, 64);
SpriteData sprNumber1 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 1, 64, 64, 64);
SpriteData sprNumber2 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 2, 64, 64, 64);
SpriteData sprNumber3 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 3, 64, 64, 64);
SpriteData sprNumber4 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 4, 64, 64, 64);
SpriteData sprNumber5 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 5, 64, 64, 64);
SpriteData sprNumber6 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 6, 64, 64, 64);
SpriteData sprNumber7 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 7, 64, 64, 64);
SpriteData sprNumber8 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 8, 64, 64, 64);
SpriteData sprNumber9 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 9, 64, 64, 64);

//コンボ
SpriteData sprComb[] = {
    sprNumber0,
    sprNumber1,
    sprNumber2,
    sprNumber3,
    sprNumber4,
    sprNumber5,
    sprNumber6,
    sprNumber7,
    sprNumber8,
    sprNumber9,
};

//ランダムマーク
SpriteData sprRandoMark[] = {
    sprGarbage_Large0,
    sprGarbage_Medium0,
    sprGarbage_Small0,
    sprGarbage_Gold,
    sprItem0,
    sprItem1,
    sprItem2,
    sprItem3,
    sprHatena,
};

//ゴミ
SpriteData sprGarbage[] = {
    sprGarbage_Large0,
    sprGarbage_Medium0,
    sprGarbage_Small0,
};

//アイテム
SpriteData sprItem0 = SPRITE_BOTTOM(TEXNO::ITEM, 64 * 0, 128, 64, 64);
SpriteData sprItem1 = SPRITE_BOTTOM(TEXNO::ITEM, 64 * 0, 192, 64, 64);
SpriteData sprItem2 = SPRITE_BOTTOM(TEXNO::ITEM, 64 * 0, 64, 64, 64);
SpriteData sprItem3 = SPRITE_BOTTOM(TEXNO::ITEM2, 64 * 0,  0, 64, 64);

//はてなマーク
SpriteData sprHatena = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 3, 0, 64, 64);

//エフェクト
SpriteData sprEffect1_1 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 0, 0, 96, 128);
SpriteData sprEffect1_2 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 1, 0, 96, 128);
SpriteData sprEffect2_1 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 0, 128, 96, 128);
SpriteData sprEffect2_2 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 1, 128, 96, 128);

//プレート
SpriteData sprPlate1 = SPRITE_LEFT(TEXNO::PLATE1, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//******************************************************************************
// 2D画像ロードデータ
LoadTexture loadTexture[] = {
    { TEXNO::PLAYER,        L"./Data/Images/player.png",          1U },// プレイヤー
    { TEXNO::GARBAGE,       L"./Data/Images/item.png",          256U },//ゴミ
    { TEXNO::GOLD,          L"./Data/Images/golden wheel.png",    1U },//ゴミ
    { TEXNO::PRESS,         L"./Data/Images/obj_puresu.png",      1U },//プレス機
    { TEXNO::BG,            L"./Data/Images/wall.png",            1U },//背景
    { TEXNO::CONVEYOR,      L"./Data/Images/berutokonbea.png",    1U },//コンベアー
    { TEXNO::BER,           L"./Data/Images/obj_saku.png",        1U },//柵
    { TEXNO::DUSTBOX,       L"./Data/Images/obj_dakuto.png",      1U },//ダストボックス
    { TEXNO::NUMBER,        L"./Data/Images/font.png",            1U },//数字
    { TEXNO::ITEM,          L"./Data/Images/item.png",            1U },//アイテム
    { TEXNO::ITEM2,         L"./Data/Images/treasure box.png",    1U },
    { TEXNO::PLATE1,        L"./Data/Images/plate.png",           1U },
    { TEXNO::EFFECT,        L"./Data/Images/buff_ef.png",         1U },
    
    //アイテム
    //{ TEXNO::OBJ,           L"./Data/Images/garbage.png", },
    //{ TEXNO::MAP_BACK,      L"./Data/Maps/back_chip.png",       336U }, // マップ背景
    //{ TEXNO::MAP_TERRAIN,   L"./Data/Maps/terrain_chip.png",    336U }, // マップ地形
    //{ TEXNO::MAP_ITEM,      L"./Data/Maps/item_chip.png",       1U },   // アイテム描画
    //                                                                    //TODO_12
    //{ TEXNO::ENEMY0, L"./Data/Images/enemy00.png", 1U },
    //{ TEXNO::ENEMY1, L"./Data/Images/enemy01.png", 1U },
    //{ TEXNO::ENEMY2, L"./Data/Images/enemy02.png", 1U },
    //{ TEXNO::ENEMY3, L"./Data/Images/enemy03.png", 1U },
    //{ TEXNO::ENEMY4, L"./Data/Images/enemy04.png", 1U },
    //{ TEXNO::ENEMY5, L"./Data/Images/enemy05.png", 1U },
    { -1, nullptr }	// 終了フラグ
};



//------< プレイヤー >----------------------------------------------------------
//上方向
AnimeData animePlayer_Up[] = {
    { &sprPlayer_Up0, 10 },
    { &sprPlayer_Up1, 10 },
    { &sprPlayer_Up2, 10 },
    { &sprPlayer_Up1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//右方向
AnimeData animePlayer_Right[] = {
    { &sprPlayer_Right0, 10 },
    { &sprPlayer_Right1, 10 },
    { &sprPlayer_Right2, 10 },
    { &sprPlayer_Right1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//下方向
AnimeData animePlayer_Down[] = {
    { &sprPlayer_Down0, 10 },
    { &sprPlayer_Down1, 10 },
    { &sprPlayer_Down2, 10 },
    { &sprPlayer_Down1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//左方向
AnimeData animePlayer_Left[] = {
    { &sprPlayer_Left0, 10 },
    { &sprPlayer_Left1, 10 },
    { &sprPlayer_Left2, 10 },
    { &sprPlayer_Left1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//ゴミ\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//大型
//AnimeData animeGarbage_Large[] =
//{
//    {&sprGarbage_Large0,10},
//    {&sprGarbage_Large1,10},
//    {&sprGarbage_Large2,10},
//    { nullptr, -1 },// 終了フラグ
//};
//
////中型
//AnimeData animeGarbage_Medium[] =
//{
//    { &sprGarbage_Medium0,10 },
//    { &sprGarbage_Medium1,10 },
//    { &sprGarbage_Medium2,10 },
//    { nullptr, -1 },// 終了フラグ
//};
//
////小型
//
//AnimeData animeGarbage_Small[] =
//{
//    { &sprGarbage_Small0,10 },
//    { &sprGarbage_Small1,10 },
//    { &sprGarbage_Small2,10 },
//    { nullptr, -1 },// 終了フラグ
//};


//数字
//数字を時間で順番に出す場合秒数は0から表示する。

AnimeData animeTimer1[] =
{
    { &sprNumber0,60 },
    { &sprNumber9,60 },
    { &sprNumber8,60 },
    { &sprNumber7,60 },
    { &sprNumber6,60 },
    { &sprNumber5,60 },
    { &sprNumber4,60 },
    { &sprNumber3,60 },
    { &sprNumber2,60 },
    { &sprNumber1,60 },
    { nullptr, -1 },// 終了フラグ
};

AnimeData animeTimer10[] =
{
    { &sprNumber0,60 },
    { &sprNumber5,600 },
    { &sprNumber4,600 },
    { &sprNumber3,600 },
    { &sprNumber2,600 },
    { &sprNumber1,600 },
    { &sprNumber0,540 }, //最後10の単位が0になった時は1秒分だけ短くする。
    { nullptr, -1 },// 終了フラグ
};

AnimeData animeTimer100[] =
{    
    { &sprNumber3,60 }, //最初だけ1秒間
    { &sprNumber2,3600 },
    { &sprNumber1,3600 },
    { &sprNumber0,3600 },
    { nullptr, -1 },// 終了フラグ
};

AnimeData* animeTimer[] =
{
    animeTimer1,
    animeTimer10,
    animeTimer100,
};

//ランダムマーク
AnimeData animeRandoMark[] =
{
    { &sprGarbage_Large0, 20 },
    { &sprGarbage_Medium0, 20 },
    { &sprGarbage_Small0, 20 },
    { &sprGarbage_Gold, 20 },
    { &sprItem0, 20 },
    { &sprItem1, 20 },
    { &sprItem2, 20 },
    { &sprItem3, 20 },
    { &sprHatena, 20 },
    { nullptr, -1 },// 終了フラグ
};

//ベルトコンベア
AnimeData animeConveyor[] = {
    { &sprConveyor0, 10},
    { &sprConveyor1, 10 },
    { &sprConveyor2, 10 },
    { nullptr, -1 },// 終了フラグ
};

//エフェクト
AnimeData animeEffect1[] = {
    { &sprEffect1_1, 10 },
    { &sprEffect1_2, 10 },    
    { nullptr, -1 },// 終了フラグ
};

AnimeData animeEffect2[] = {
    { &sprEffect2_1, 10 },
    { &sprEffect2_2, 10 },
    { nullptr, -1 },// 終了フラグ
};
