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
// フェードアウト用変数の宣言
float fadeOut;

// 別のファイルの変数を使用する宣言
extern int nextScene;

//--------------------------------
// 初期設定
//--------------------------------
void title_init()
{
    title_state = 0;
    title_timer = 0;

    // フェードアウト用変数の初期設定
    fadeOut = 0.0f;
}

//--------------------------------
// 更新処理
//--------------------------------
void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// 初期設定 ////////

        title_state++;
        break;

    case 1:
        //////// 通常時 ////////
        // キー入力でシーン切り替え
        if (TRG(0) & PAD_START)
        {
            title_state++;
        }
        break;

    // フェードアウト用のcase 2:をつくる
    case 2:
        //////// フェードアウト ////////
        fadeOut += 0.0167f;
        if (fadeOut >= 1.0f)
        {
            nextScene = SCENE_GAME;
        }
        break;
    }
    title_timer++;

    // デバッグ用文字列の設定
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
}

//--------------------------------
// 終了処理
//--------------------------------
void title_end()
{
}
