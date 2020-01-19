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

Player player[2];

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
    PlateManager_.update();
    conveyor.update();
    player[0].update(); 
    if (twoPlayMode)
    {
        player[1].update();
    }
   
    EffectManager_.update();
    GarbageManager_.update();
    press_machine.update();
    DustBoxManager_.update();
    TimerManager_.update();
    CombManager_.update();
    RandoManager_.update();
    ItemManager_.update();

    timerNum--;

    if (TRG(0) & PAD_R1) //ゴミ生成
    {
        GarbageManager_.add(&garbage, VECTOR2(0, 0), 0);
    }

    if (TRG(0) & PAD_L1)//アイテム生成
    {
        ItemManager_.add(&item, VECTOR2(0, 0), 0);
    }

    //コンボ桁生成
    for ( int i = 0; i < 2; i++)
    {
        if (combNum[i] >= 10 && combKeta[i] == 1)
        {
            if (i == 0) { CombManager_.add(&comb, VECTOR2(890, 350), i); }
            else { CombManager_.add(&comb, VECTOR2(1060, 350), i); }            
        }

        if (combNum[i] >= 100 && combKeta[i] == 2)
        {
            if (i == 0) { CombManager_.add(&comb, VECTOR2(890, 350), i); }
            else { CombManager_.add(&comb, VECTOR2(1060, 350), i); }            
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
        PlateManager_.init();
        PlateManager_.add(&plate, VECTOR2(0, 0));
        conveyor.init();
        ber.init();

        player[0].init();
        player[0].type = 0;

        if (twoPlayMode)
        {
            player[1].init();
            player[1].type = 1;
        }
       
        //player[1].init();
        //player[1].type = 1;
        EffectManager_.init();
        //garbage.init();

        GarbageManager_.init();

        GarbageManager_.add(&garbage, VECTOR2(0, 0), 0);

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
        CombManager_.add(&comb, VECTOR2(890, 350), 0);
        if (twoPlayMode)
        {
            CombManager_.add(&comb, VECTOR2(1060, 350), 1);
        }        

        RandoManager_.init();
        RandoManager_.add(&randomMark, VECTOR2(390, 105));
        RandoManager_.add(&randomMark, VECTOR2(653, 105));
        RandoManager_.add(&randomMark, VECTOR2(916, 105));

        ItemManager_.init();

        game_state++;
        break;

    case 1:
        //////// 通常時 ////////
        game_common();

        if (timerNum < 0)
        {
            game_state++;
        }

        break;

    case 2:
        combNum[0] = 0;
        combNum[1] = 0;
        combKeta[0] = 0;
        combKeta[1] = 0;
        timerNum = 10800;
        timerKeta = 0;
        nextScene = SCENE_TITLE;

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

    PlateManager_.draw();

    conveyor.draw();

    ber.draw();

    player[0].draw();
    if (twoPlayMode)
    {
        player[1].draw();
    }
   
    //player[1].draw();

    EffectManager_.draw();

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

    ItemManager_.draw();
}

//--------------------------------
// 終了処理
//--------------------------------
void game_end()
{
    for ( int i = 0; i < 2; i++ )
    {
        player[i].mvAlg = nullptr;
    }

    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
    {
        music::stop(i);
    }

    // スプライトの破棄 
    //SAFE_DELETE(sprPlayer); // プレイヤースプライトの破棄
}
