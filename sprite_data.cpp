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

//上歩き
SpriteData sprPlayer_Up0 = SPRITE_BOTTOM(
    TEXNO::PLAYER,
    48 * 0, 64 * 0,
    48, 64);
SpriteData sprPlayer_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 1, 64 * 0, 48, 64);
SpriteData sprPlayer_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 2, 64 * 0, 48, 64);

//右歩き
SpriteData sprPlayer_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 0, 64 * 1, 48, 64);
SpriteData sprPlayer_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 1, 64 * 1, 48, 64);
SpriteData sprPlayer_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 2, 64 * 1, 48, 64);

//下歩き
SpriteData sprPlayer_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 0, 64 * 2, 48, 64);
SpriteData sprPlayer_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 1, 64 * 2, 48, 64);
SpriteData sprPlayer_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 2, 64 * 2, 48, 64);

//左歩き
SpriteData sprPlayer_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 0, 64 * 3, 48, 64);
SpriteData sprPlayer_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 1, 64 * 3, 48, 64);
SpriteData sprPlayer_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER, 48 * 2, 64 * 3, 48, 64);

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
SpriteData sprGarbage_Large0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 0, 0, 64, 64);
SpriteData sprGarbage_Large1  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 0, 64, 64);
SpriteData sprGarbage_Large2  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 0, 64, 64);
//中型
SpriteData sprGarbage_Medium0 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 0, 64, 128, 128);
SpriteData sprGarbage_Medium1 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 64, 128, 128);
SpriteData sprGarbage_Medium2 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 64 , 128, 128);
//小型
SpriteData sprGarbage_Small0  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 0, 128, 192, 192);
SpriteData sprGarbage_Small1  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 1, 128, 192, 192);
SpriteData sprGarbage_Small2  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 2 ,128, 192, 192);

//プレス機
SpriteData sprPressMachine = SPRITE_BOTTOM(TEXNO::PRESS, 0, 0, 275, 610);

//背景
SpriteData sprBG = SPRITE_LEFT(TEXNO::BG, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//コンベアー
SpriteData sprConveyor = SPRITE_LEFT(TEXNO::CONVEYOR, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//柵
SpriteData sprBer = SPRITE_LEFT(TEXNO::BER, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);



//******************************************************************************
// 2D画像ロードデータ
LoadTexture loadTexture[] = {
    { TEXNO::PLAYER,        L"./Data/Images/player.png",          1U },// プレイヤー
    { TEXNO::GARBAGE,       L"./Data/Images/garbage.png",       256U },//ゴミ
    { TEXNO::PRESS,         L"./Data/Images/obj_puresu.png",      1U },//プレス機
    { TEXNO::BG,            L"./Data/Images/wall.png",            1U },//背景
    { TEXNO::CONVEYOR,      L"./Data/Images/obj_konbea.png",      1U },//コンベアー
    { TEXNO::BER,           L"./Data/Images/obj_saku.png",        1U },//柵
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
AnimeData animeGarbage_Large[] =
{
    {&sprGarbage_Large0,10},
    {&sprGarbage_Large1,10},
    {&sprGarbage_Large2,10},
    { nullptr, -1 },// 終了フラグ
};

//中型
AnimeData animeGarbage_Medium[] =
{
    { &sprGarbage_Medium0,10 },
    { &sprGarbage_Medium1,10 },
    { &sprGarbage_Medium2,10 },
    { nullptr, -1 },// 終了フラグ
};

//小型

AnimeData animeGarbage_Small[] =
{
    { &sprGarbage_Small0,10 },
    { &sprGarbage_Small1,10 },
    { &sprGarbage_Small2,10 },
    { nullptr, -1 },// 終了フラグ
};
