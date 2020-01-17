#ifndef INCLUDED_SPRITE_DATA
#define	INCLUDED_SPRITE_DATA
//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

#include "GameLib\texture.h"



#if 11
//******************************************************************************
// TODO:11 敵テクスチャ用ラベルの定義
//------------------------------------------------------------------------------
/*
課題）
敵用のテクスチャを識別するラベルを定義する。

下記のTEXNO内に、ENEMY0からENEMY5まで追加せよ。
*/
//******************************************************************************
#endif
// ラベル定義
enum TEXNO
{
    // ゲーム
    PLAYER,
    GARBAGE,
    GOLD,
    ITEM2,
    PRESS,
    BG,
    CONVEYOR,
    BER,
    DUSTBOX,
    NUMBER,
    ITEM,
    OBJ,
    /*MAP_BACK,
    MAP_TERRAIN,
    MAP_ITEM,
    //TODO_11
    ENEMY0,
    ENEMY1,
    ENEMY2,
    ENEMY3,
    ENEMY4,
    ENEMY5,*/
};

extern GameLib::LoadTexture loadTexture[];

// ------< プレイヤー >----------------------------------------------------------

//アニメーション
extern GameLib::AnimeData animePlayer_Up[];
extern GameLib::AnimeData animePlayer_Right[];
extern GameLib::AnimeData animePlayer_Down[];
extern GameLib::AnimeData animePlayer_Left[];
extern GameLib::AnimeData animeTimer1[];
extern GameLib::AnimeData animeTimer10[];
extern GameLib::AnimeData animeTimer100[];
extern GameLib::AnimeData animeRandoMark[];
extern GameLib::AnimeData animeConveyor[];
extern GameLib::AnimeData* animeTimer[];

//上歩き
extern GameLib::SpriteData sprPlayer_Up0;
extern GameLib::SpriteData sprPlayer_Up1;
extern GameLib::SpriteData sprPlayer_Up2;

//右歩き
extern GameLib::SpriteData sprPlayer_Right0;
extern GameLib::SpriteData sprPlayer_Right1;
extern GameLib::SpriteData sprPlayer_Right2;

//下歩き
extern GameLib::SpriteData sprPlayer_Down0;
extern GameLib::SpriteData sprPlayer_Down1;
extern GameLib::SpriteData sprPlayer_Down2;

//左歩き
extern GameLib::SpriteData sprPlayer_Left0;
extern GameLib::SpriteData sprPlayer_Left1;
extern GameLib::SpriteData sprPlayer_Left2;

//ゴミ\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//アニメーション\\AnimeData animeGarbage_Large[]

extern GameLib::AnimeData animeGarbage_Large[];
extern GameLib::AnimeData animeGarbage_Medium[];
extern GameLib::AnimeData animeGarbage_Small[];


//大型
extern GameLib::SpriteData sprGarbage_Large0;
extern GameLib::SpriteData sprGarbage_Large1;
extern GameLib::SpriteData sprGarbage_Large2;

//中型                     
extern GameLib::SpriteData sprGarbage_Medium0;
extern GameLib::SpriteData sprGarbage_Medium1;
extern GameLib::SpriteData sprGarbage_Medium2;

//小型                      
extern GameLib::SpriteData sprGarbage_Small0;
extern GameLib::SpriteData sprGarbage_Small1;
extern GameLib::SpriteData sprGarbage_Small2;

//ゴールドゴミ
extern GameLib::SpriteData sprGarbage_Gold;

//はてなマーク
extern GameLib::SpriteData sprHatena;

//プレス機
extern GameLib::SpriteData sprPressMachine;

//背景
extern GameLib::SpriteData sprBG;

//コンベアー
extern GameLib::SpriteData sprConveyor0;
extern GameLib::SpriteData sprConveyor1;
extern GameLib::SpriteData sprConveyor2;

//柵
extern GameLib::SpriteData sprBer;

//ダストボックス
extern SpriteData sprDustBox;

//数字
extern GameLib::SpriteData sprNumber0;
extern GameLib::SpriteData sprNumber1;
extern GameLib::SpriteData sprNumber2;
extern GameLib::SpriteData sprNumber3;
extern GameLib::SpriteData sprNumber4;
extern GameLib::SpriteData sprNumber5;
extern GameLib::SpriteData sprNumber6;
extern GameLib::SpriteData sprNumber7;
extern GameLib::SpriteData sprNumber8;
extern GameLib::SpriteData sprNumber9;

//コンボ
extern GameLib::SpriteData sprComb[];

//ランダムマーク
extern GameLib::SpriteData sprRandoMark[];

//アイテム
extern GameLib::SpriteData sprItem0;
extern GameLib::SpriteData sprItem1;
extern GameLib::SpriteData sprItem2;
extern GameLib::SpriteData sprItem3;
#endif // !INCLUDED_SPRITE_DATA
