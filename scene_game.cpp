//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include <list>
#include "all.h"

//------< 変数 >----------------------------------------------------------------
int game_state;     // 状態
int game_timer;     // タイマー

Player player;

//std::list<Garbage> garbageList;

//GarbageManager GarbageManager_;

// 別のファイルの変数を使用する宣言
extern int nextScene;

//--------------------------------
// 初期設定
//--------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
 
}

//--------------------------------
// ゲーム中
//--------------------------------
void game_common()
{
    if (TRG(0) & PAD_START)
    {
        nextScene = SCENE_TITLE;
    }

    bg.update();
    conveyor.update();
    player.update();
    //garbage.update();
    GarbageManager_.update();
    press_machine.update();
   
    for ( auto& it : dustBox)
    {     
        it.update();
    }

    if (TRG(0) & PAD_R1) //ゴミ生成
    {
        GarbageManager_.add(&garbage, VECTOR2(0, 0));
    }
}

//--------------------------------
// 更新処理
//--------------------------------
void game_update()
{
    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////

        // スプライトのロード
        //sprite_load(&sprPlayer, L"./Data/Images/player.png");       // プレイヤースプライト

        GameLib::setBlendMode(Blender::BS_ALPHA);

        texture::load(loadTexture);

        bg.init();

        conveyor.init();

        ber.init();

        player.init();

        //garbage.init();

        GarbageManager_.init();

        GarbageManager_.add(&garbage, VECTOR2(0, 0));

        press_machine.init();

        for (auto& it : dustBox)
        {            
            it.init();

            it.no += 263;
        }

        dustBox[0].no = 0;
        
        game_state++;
        break;

    case 1:
        //////// 通常時 ////////
        game_common();

        break;
    }
    game_timer++;
}

//--------------------------------
// 描画処理
//--------------------------------
void game_draw()
{
    // 画面を白で塗りつぶす
    GameLib::clear(1, 1, 1);

    bg.draw();

    conveyor.draw();

    ber.draw();

    player.draw();
    
    //存在してる時だけ
    //if (garbage.exist) { garbage.draw(); }
    GarbageManager_.draw();

    press_machine.draw();

    for (auto& it : dustBox)
    {
        it.draw();
    }
}

//--------------------------------
// 終了処理
//--------------------------------
void game_end()
{
    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
    {
        music::stop(i);
    }

    // スプライトの破棄 
    //SAFE_DELETE(sprPlayer); // プレイヤースプライトの破棄
}
