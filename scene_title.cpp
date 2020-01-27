//******************************************************************************
//
//
//      scene_title
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
//#include "pressShutter.h"
#include "all.h"


//------< 変数 >----------------------------------------------------------------
int title_state;    // 状態
int title_timer;    // タイマー
int game_mode = 0;
// フェードアウト用変数の宣言
float fadeOut;
bool twoPlayMode = false;//trueの時２人プレイ
bool tutorialMode = false;//trueの時２人プレイ
// 別のファイルの変数を使用する宣言
extern int nextScene;

//--------------------------------
// 初期設定
//--------------------------------
void title_init()
{
    title_state = 0;
    title_timer = 0;
    game_mode = 0;
    twoPlayMode = false;
    tutorialMode = false;

    // フェードアウト用変数の初期設定
    fadeOut = 0.0f;

    //shutter.type = 0;
    shutter.init();

    texture::load(loadTexture);

    bg.init();

    player[0].exist = false;
    player[1].exist = false;

    conveyor.init();

    ber.init();

    press_machine.init();

    DustBoxManager_.init();

    DustBoxManager_.add(&dustBox, VECTOR2(400, 84));

    DustBoxManager_.add(&dustBox, VECTOR2(663, 84));

    DustBoxManager_.add(&dustBox, VECTOR2(926, 84));

    title.init();
  
    pushbotton_B.init();

    for ( int i = 0; i < 3; i++ )
    {
        gamemode[i].init();
    }
}

//--------------------------------
// 更新処理
//--------------------------------
void title_update()
{
    bg.update();
    conveyor.update();
    GarbageManager_.update();
    press_machine.update();
    DustBoxManager_.update();
  
    switch (title_state)
    {
    case 0:
        //////// 初期設定 ////////
      
        twoPlayMode = false;
        
      
        if (shutter.scrollUp() && titleDropFlg)
        { title_state++; }
        
        break;

    case 1: //ゲームモードを決める
      
        gamemode[0].update();
        break;
  
    case 2:
        //////// フェードアウト ////////
        if (shutter.scrollDown()) { nextScene = SCENE_GAME; }
        
        //fadeOut += 0.0167f;

        //if (fadeOut >= 1.0f)
        //{
        //    nextScene = SCENE_GAME;
        //}

        //if (game_mode == 0) { twoPlayMode = false; tutorialMode = true;}
        //if (game_mode == 1) { twoPlayMode = false; }
        //if (game_mode == 2) { twoPlayMode = true; }

        break;
    }
   title_timer++;

   title.update();
    // デバッグ用文字列の設定
    debug::setString("TITLE_STATE:%d", game_mode);
    //debug::setString("title_state:%d", title_state);
    //debug::setString("title_timer:%d", title_timer);
}

//--------------------------------
// 描画処理
//--------------------------------
void title_draw()
{
    // 画面を黒で塗りつぶす
    GameLib::clear(0, 0, 0);

    // 文字表示機能
    font::textOut(2, "ECC COMP", 50, 100, 2, 2, 1, 1, 0);
    font::textOut(2, "Shooting Game", 40, 250, 1.3f, 1.3f, 0, 1, 1);

    // 文字を点滅させる
    if (title_timer / 32 % 2)
        font::textOut(3, "Push Start", 100, 500, 3, 3);

    // タイトル画面のフェードアウト
    if (fadeOut > 0.0f)
    {
        primitive::rect(0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT, 
            0, 0, 0, 0, 0, 0, fadeOut);
    }
    bg.draw();

    conveyor.draw();

    ber.draw();

    press_machine.draw();

    DustBoxManager_.draw();    

    title.draw();

    if (titleDropFlg)
    {
        for (int i = 0; i < 3; i++)
        {
            gamemode[i].draw();
        }
    }
    else
    {
        if (title_timer&0x20)
        {
            pushbotton_B.draw();
        }
    }
    shutter.draw();

     
}

//--------------------------------
// 終了処理
//--------------------------------
void title_end()
{
}
