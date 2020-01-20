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
SpriteData sprPlayer1_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 1, 96, 128);
SpriteData sprPlayer1_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 1, 96, 128);
SpriteData sprPlayer1_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 1, 96, 128);

//上歩き
SpriteData sprPlayer1_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 2, 96, 128);
SpriteData sprPlayer1_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 2, 96, 128);
SpriteData sprPlayer1_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 2, 96, 128);

//左歩き
SpriteData sprPlayer1_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 3, 96, 128);
SpriteData sprPlayer1_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 3, 96, 128);
SpriteData sprPlayer1_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 3, 96, 128);

//右歩き
SpriteData sprPlayer1_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 4, 96, 128);
SpriteData sprPlayer1_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 4, 96, 128);
SpriteData sprPlayer1_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 4, 96, 128);
//playerブリキ
//下歩き
SpriteData sprPlayer2_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 1, 96, 128);
SpriteData sprPlayer2_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 1, 96, 128);
SpriteData sprPlayer2_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 1, 96, 128);
                   
//上歩き            
SpriteData sprPlayer2_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 2, 96, 128);
SpriteData sprPlayer2_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 2, 96, 128);
SpriteData sprPlayer2_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 2, 96, 128);
                  
//左歩き           
SpriteData sprPlayer2_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 3, 96, 128);
SpriteData sprPlayer2_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 3, 96, 128);
SpriteData sprPlayer2_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 3, 96, 128);
                 
//右歩き          
SpriteData sprPlayer2_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 4, 96, 128);
SpriteData sprPlayer2_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 4, 96, 128);
SpriteData sprPlayer2_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 4, 96, 128);
//大型
SpriteData sprGarbage_Large0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 0, 64, 64);
//中型
SpriteData sprGarbage_Medium0 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 0, 64, 64);
//小型
SpriteData sprGarbage_Small0  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 0, 0, 64, 64);

SpriteData sprGarbage_Gold = SPRITE_BOTTOM(TEXNO::GOLD, 64 * 0, 0, 64, 64);

//プレス機
SpriteData sprPressMachine = SPRITE_BOTTOM(TEXNO::PRESS, 0, 0, 275, 610);

//背景
SpriteData sprBG = SPRITE_LEFT(TEXNO::BG, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//コンベアー
SpriteData sprConveyor1_0 = SPRITE_LEFT(TEXNO::CONVEYOR1, system::SCREEN_WIDTH * 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor1_1 = SPRITE_LEFT(TEXNO::CONVEYOR1, system::SCREEN_WIDTH * 1, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor1_2 = SPRITE_LEFT(TEXNO::CONVEYOR1, system::SCREEN_WIDTH * 2, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

SpriteData sprConveyor2_0 = SPRITE_LEFT(TEXNO::CONVEYOR2, system::SCREEN_WIDTH * 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor2_1 = SPRITE_LEFT(TEXNO::CONVEYOR2, system::SCREEN_WIDTH * 1, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor2_2 = SPRITE_LEFT(TEXNO::CONVEYOR2, system::SCREEN_WIDTH * 2, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

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
//ゲームモード
SpriteData sprTitle_single  = SPRITE_CENTER(TEXNO::SINGLE, 0, 0, 1188, 648);
SpriteData sprTitle_doubles = SPRITE_CENTER(TEXNO::DOUDLE, 0, 0, 1188, 648);

//タイトル
//SpriteData sprTitle=SPRITE_BOTTOM(TEXNO::TITLE,,,,);
//SpriteData sprTitle[] =
//{ };

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

//吹き出し
SpriteData sprFukidasi1 = SPRITE_BOTTOM(TEXNO::FUKIDASI, 600 * 0, 0, 600, 400);
SpriteData sprFukidasi2 = SPRITE_BOTTOM(TEXNO::FUKIDASI, 600 * 1, 0, 600, 400);
SpriteData sprFukidasi3 = SPRITE_BOTTOM(TEXNO::FUKIDASI, 600 * 2, 0, 600, 400);

//アイテム一覧
SpriteData sprItiran = SPRITE_LEFT(TEXNO::ITIRAN, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

SpriteData sprFukidasi[] = {
    sprFukidasi1,
    sprFukidasi2,
    sprFukidasi3,
};

//******************************************************************************
// 2D画像ロードデータ
LoadTexture loadTexture[] = {
<<<<<<< HEAD
    { TEXNO::PLAYER1,       L"./Data/Images/player1.png",         1U },// プレイヤー
    { TEXNO::PLAYER2,       L"./Data/Images/player2.png",         1U },// プレイヤー
    { TEXNO::GARBAGE,       L"./Data/Images/item.png",            1U },//ゴミ
=======
    { TEXNO::PLAYER,        L"./Data/Images/player1.png",          1U },// プレイヤー
    { TEXNO::GARBAGE,       L"./Data/Images/item.png",          256U },//ゴミ
>>>>>>> ecc2ab94230981ab212257c9f78a22047a811bfe
    { TEXNO::GOLD,          L"./Data/Images/golden wheel.png",    1U },//ゴミ
    { TEXNO::PRESS,         L"./Data/Images/obj_puresu.png",      1U },//プレス機
    { TEXNO::BG,            L"./Data/Images/wall.png",            1U },//背景
    { TEXNO::CONVEYOR1,     L"./Data/Images/berutokonbea.png",    1U },//コンベアー
    { TEXNO::CONVEYOR2,     L"./Data/Images/berutokonbea2.png",   1U },//コンベアー
    { TEXNO::BER,           L"./Data/Images/obj_saku.png",        1U },//柵
    { TEXNO::DUSTBOX,       L"./Data/Images/obj_dakuto.png",      1U },//ダストボックス
    { TEXNO::NUMBER,        L"./Data/Images/font.png",            1U },//数字
    { TEXNO::ITEM,          L"./Data/Images/item.png",            1U },//アイテム
    { TEXNO::ITEM2,         L"./Data/Images/treasure box.png",    1U },//アイテム
    { TEXNO::FUKIDASI,      L"./Data/Images/hukidasi.png",        1U },//吹き出し
    { TEXNO::ITIRAN ,       L"./Data/Images/item_itiran.png",     1U },//一覧
    //{ TEXNO::TITLE,         L"./Data/Images/title.png",           1U },//タイトル
    { TEXNO::SINGLE ,       L"./Data/Images/single.png",          1U },//１人モード
    { TEXNO::DOUDLE,        L"./Data/Images/doubles.png",         1U },//2人モード
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
AnimeData animePlayer1_Up[] = {
    { &sprPlayer1_Up0, 10 },
    { &sprPlayer1_Up1, 10 },
    { &sprPlayer1_Up2, 10 },
    { &sprPlayer1_Up1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//右方向
AnimeData animePlayer1_Right[] = {
    { &sprPlayer1_Right0, 10 },
    { &sprPlayer1_Right1, 10 },
    { &sprPlayer1_Right2, 10 },
    { &sprPlayer1_Right1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//下方向
AnimeData animePlayer1_Down[] = {
    { &sprPlayer1_Down0, 10 },
    { &sprPlayer1_Down1, 10 },
    { &sprPlayer1_Down2, 10 },
    { &sprPlayer1_Down1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//左方向
AnimeData animePlayer1_Left[] = {
    { &sprPlayer1_Left0, 10 },
    { &sprPlayer1_Left1, 10 },
    { &sprPlayer1_Left2, 10 },
    { &sprPlayer1_Left1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//
//上方向
AnimeData animePlayer2_Up[] = {
    { &sprPlayer2_Up0, 10 },
    { &sprPlayer2_Up1, 10 },
    { &sprPlayer2_Up2, 10 },
    { &sprPlayer2_Up1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//右方向
AnimeData animePlayer2_Right[] = {
    { &sprPlayer2_Right0, 10 },
    { &sprPlayer2_Right1, 10 },
    { &sprPlayer2_Right2, 10 },
    { &sprPlayer2_Right1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//下方向
AnimeData animePlayer2_Down[] = {
    { &sprPlayer2_Down0, 10 },
    { &sprPlayer2_Down1, 10 },
    { &sprPlayer2_Down2, 10 },
    { &sprPlayer2_Down1, 10 },
    { nullptr, -1 },// 終了フラグ
};
//左方向
AnimeData animePlayer2_Left[] = {
    { &sprPlayer2_Left0, 10 },
    { &sprPlayer2_Left1, 10 },
    { &sprPlayer2_Left2, 10 },
    { &sprPlayer2_Left1, 10 },
    { nullptr, -1 },// 終了フラグ
};
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
AnimeData animeConveyor1[] = {
    { &sprConveyor1_0, 10},
    { &sprConveyor1_1, 10 },
    { &sprConveyor1_2, 10 },
    { nullptr, -1 },// 終了フラグ
};

AnimeData animeConveyor2[] = {
    { &sprConveyor2_0, 10 },
    { &sprConveyor2_1, 10 },
    { &sprConveyor2_2, 10 },
    { nullptr, -1 },// 終了フラグ
};

AnimeData* animeConveyor[] = {
    animeConveyor1,
    animeConveyor2,
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

AnimeData*animePlayer[2][4]=
{
    {animePlayer1_Down,animePlayer1_Up,animePlayer1_Left,animePlayer1_Right },
    { animePlayer2_Down,animePlayer2_Up,animePlayer2_Left,animePlayer2_Right },
};

