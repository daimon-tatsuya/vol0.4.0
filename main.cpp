//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< 変数 >----------------------------------------------------------------
// シーン切り替え用変数の宣言
int curScene;
int nextScene;

//--------------------------------
//  WinMain（エントリポイント）
//--------------------------------
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    // ゲームライブラリの初期設定
    GameLib::init(L"ゲームプログラミングⅠ　制作用ひな型", 
        (int)system::SCREEN_WIDTH, (int)system::SCREEN_HEIGHT, FALSE);

    // ブレンドモードの設定
    GameLib::setBlendMode(Blender::BS_ALPHA);

    // ゲームシーンの設定
    curScene  = SCENE_TITLE;
    nextScene = SCENE_TITLE;

    // 音楽・効果音の初期設定を行う関数を呼ぶ
    audio_init();

    // タイトルの初期設定を行う
    title_init();

    // ゲームループ
    while (GameLib::gameLoop())
    {
        // 入力処理
        input::update();

        // ゲームシーン切り替え
        if (nextScene != curScene)  // 次フレームでシーン変更があれば
        {
            switch (curScene)       // 現シーンの終了処理を行う
            {
            case SCENE_TITLE:
                title_end();
                break;
            case SCENE_GAME:
                game_end();
                break;
            }
            switch (nextScene)      // 次シーンの初期設定を行う
            {
            case SCENE_TITLE:
                title_init();
                break;
            case SCENE_GAME:
                game_init();
                break;
            }
            curScene = nextScene;   // 現シーンに次シーンを代入する
        }

        // 現在のシーンに応じた更新処理
        switch (curScene)
        {
        case SCENE_TITLE:
            title_update();
            break;
        case SCENE_GAME:
            game_update();
            break;
        }

        // 現在のシーンに応じた描画処理
        switch (curScene)
        {
        case SCENE_TITLE:
            title_draw();
            break;
        case SCENE_GAME:
            game_draw();
            break;
        }

        // デバッグ文字列の描画
        debug::display(1, 0, 0, 1, 1);
        debug::setString("GP1_PROTO_TYPE");

        // バックバッファの内容を表示
        GameLib::present(1, 0);
    }

    // 現在のシーンに応じた終了処理
    switch (curScene)
    {
    case SCENE_TITLE:
        title_end();
        break;
    case SCENE_GAME:
        game_end();
        break;
    }

    // 音楽・効果音の終了処理を呼んでおく
    audio_uninit();

    // 終了処理
    GameLib::uninit();

    return 0;
}

//******************************************************************************
