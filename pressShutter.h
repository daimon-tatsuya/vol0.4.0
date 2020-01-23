#pragma once
//#include "./GameLib/game_lib.h"
//#include "./GameLib/obj2d_data.h"
//#include "work.h"

class Shutter
{
public:
    GameLib::SpriteData* data = nullptr;// スプライトデータ

    VECTOR2 position = VECTOR2(0, 0);
    VECTOR2 scale = { 1, 1 };           // スケール
    float   angle = 0;                  // 角度
    VECTOR4 color = VECTOR4(0, 0, 0, 0);//色
    int     type = 0;                  //スクロールアップかダウンかを識別するための変数。

    void init();
    // void update();
    bool scrollUp();
    bool scrollDown();
    void draw();
};

EXTERN Shutter shutter;