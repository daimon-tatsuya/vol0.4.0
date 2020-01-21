//******************************************************************************
//
//
//      scene_title
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
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

    texture::load(loadTexture);

    bg.init();

    conveyor.init();

    ber.init();

    press_machine.init();

    DustBoxManager_.init();

    DustBoxManager_.add(&dustBox, VECTOR2(400, 84));

    DustBoxManager_.add(&dustBox, VECTOR2(663, 84));

    DustBoxManager_.add(&dustBox, VECTOR2(926, 84));

<<<<<<< HEAD
=======
    gamemode[0].init();
    gamemode[1].init();
>>>>>>> ab36ded76762e8d98f4221a73f58acdce2941067

    for ( int i = 0; i < 2; i++ )
    {
        gamemode[i].init();
    }
<<<<<<< HEAD

=======
>>>>>>> ab36ded76762e8d98f4221a73f58acdce2941067
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
        title_state++;
        break;

    case 1: //ゲームモードを決める
       
<<<<<<< HEAD
=======
        //1人プレイ
        //if (TRG(0) & PAD_START)
        //{
        //    title_state = 2;
        //}
        //if (TRG(0) & PAD_UP)
        //{
        //    game_mode++;
        //    if (game_mode > 0) { game_mode = 2; }
        //}
        //else if (TRG(0) & PAD_DOWN)
        //{
        //    game_mode--;
        //    if (game_mode < 0) { game_mode = 0; }
        //}
>>>>>>> ab36ded76762e8d98f4221a73f58acdce2941067

        gamemode[0].update();
        break;
  
    case 2:
        //////// フェードアウト ////////
        fadeOut += 0.0167f;
        if (fadeOut >= 1.0f)
        {
            nextScene = SCENE_GAME;
        }

        //if (game_mode == 0) { twoPlayMode = false; tutorialMode = true;}
        //if (game_mode == 1) { twoPlayMode = false; }
        //if (game_mode == 2) { twoPlayMode = true; }

        break;
    }
    title_timer++;

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

<<<<<<< HEAD
=======
    gamemode[0].draw();
    gamemode[1].draw();
>>>>>>> ab36ded76762e8d98f4221a73f58acdce2941067

    for (int i = 0; i < 2; i++)
    {
        gamemode[i].draw();
    }

}

//--------------------------------
// 終了処理
//--------------------------------
void title_end()
{
}
