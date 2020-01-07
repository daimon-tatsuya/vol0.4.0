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
//
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
        combNum[0] = 0;
        combNum[1] = 0;
        combKeta[0] = 0;
        combKeta[1] = 0;
        timerNum = 10800;
        timerKeta = 0;
        nextScene = SCENE_TITLE;
    }

    bg.update();
    conveyor.update();
    player.update();    
    GarbageManager_.update();
    press_machine.update();
    DustBoxManager_.update();
    TimerManager_.update();
    CombManager_.update();
    RandoManager_.update();

    timerNum--;

    if (TRG(0) & PAD_R1) //ゴミ生成
    {
        GarbageManager_.add(&garbage, VECTOR2(0, 0));
    }

    //コンボ桁生成
    for (auto it : combKeta)
    {
        if (combNum[it] >= 10 && combKeta[it] == 1)
        {
            CombManager_.add(&comb, VECTOR2(1060, 350));
        }

        if (combNum[it] >= 100 && combKeta[it] == 2)
        {
            CombManager_.add(&comb, VECTOR2(1060, 350));
        }
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

        DustBoxManager_.init();

        DustBoxManager_.add(&dustBox, VECTOR2(400, 84));

        DustBoxManager_.add(&dustBox, VECTOR2(663, 84));

        DustBoxManager_.add(&dustBox, VECTOR2(926, 84));

        TimerManager_.init();

        TimerManager_.add(&timer, VECTOR2(640, 350));
        TimerManager_.add(&timer, VECTOR2(640, 350));
        TimerManager_.add(&timer, VECTOR2(600, 350));

        CombManager_.init();
        CombManager_.add(&comb, VECTOR2(1060, 350));

        RandoManager_.init();
        RandoManager_.add(&randomMark, VECTOR2(390, 105));
        RandoManager_.add(&randomMark, VECTOR2(653, 105));
        RandoManager_.add(&randomMark, VECTOR2(916, 105));

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
      
    GarbageManager_.draw();

    press_machine.draw();

    DustBoxManager_.draw();

    TimerManager_.draw();

    if (timerNum > 0) //タイマーのコンマ
    {
        texture::begin(TEXNO::NUMBER);
        texture::draw(TEXNO::NUMBER,
            550, 350, 1.0f, 1.0f,
            64 * 12, 64, 64, 64,
            32, 32, 0,
            1.0f, 1.0f, 1.0f, 1.0f);
        texture::end(TEXNO::NUMBER);
    }

    CombManager_.draw();

    RandoManager_.draw();
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
