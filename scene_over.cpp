#include "all.h"

extern int nextScene;

static int over_timer = 0;//scene_over.cppで使う

//win,lose
void OVER::init()
{
    ranking.result[5] = combNum[0];
    ranking.result[6] = combNum[1];
    position = { 0, 0};
    scale    = { 1.0f,1.0f }; 
    state = 0;
    mode = true;
    player1Win = false;
    data = nullptr;

    for (int i = 0; i < RESULT_MAX + 1; i++)
    {
        ranking.KetaCount[i] = 0;
    }

    posComp[OVER_STATE::OVER_SCORE]   = VECTOR2(0, 0);
    posComp[OVER_STATE::OVER_NUMBER1] = VECTOR2(600, 350);
    posComp[OVER_STATE::OVER_NUMBER2] = VECTOR2(1100, 250);
    posComp[OVER_STATE::OVER_WIN]     = VECTOR2(300, 100);
    posComp[OVER_STATE::OVER_LOSE]    = VECTOR2(300, 100);
    posComp[OVER_STATE::OVER_PLAYER1] = VECTOR2(1000, 450);
    posComp[OVER_STATE::OVER_PLAYER2] = VECTOR2(300, 450);    

    //ranking.result[5] = 20;
    //ranking.result[6] = 0;

    ranking.KetaCountMove();

    if (twoPlayMode)
    {
        if (ranking.result[5] > ranking.result[6])
        {
            player1Win = true;
            posComp[OVER_STATE::OVER_PLAYER1] = VECTOR2(300, 450);
            posComp[OVER_STATE::OVER_PLAYER2] = VECTOR2(1000, 450);
            posComp[OVER_STATE::OVER_NUMBER1] = VECTOR2(300, 250);//スコア数字座標設定
            posComp[OVER_STATE::OVER_NUMBER2] = VECTOR2(1100, 250);//スコア数字座標設定
        }

        else if (ranking.result[5] < ranking.result[6])
        {
            posComp[OVER_STATE::OVER_PLAYER1] = VECTOR2(1000, 450);
            posComp[OVER_STATE::OVER_PLAYER2] = VECTOR2(300, 450);
            posComp[OVER_STATE::OVER_NUMBER1] = VECTOR2(1100, 250);//スコア数字座標設定
            posComp[OVER_STATE::OVER_NUMBER2] = VECTOR2(300, 250);//スコア数字座標設定
        }

        posComp[OVER_STATE::OVER_SCORE] = VECTOR2(465, 150);//スコア座標設定
        mode = false;        
        scale = VECTOR2(0.5f, 0.5f);

        for ( int i = 0; i < 2; i++)
        {
            for (int j = 0; j < ranking.KetaCount[i+ 5]; j++)
            {
                RankingNumManager_.add(&rankingNum, VECTOR2(posComp[OVER_STATE::OVER_NUMBER1 + i].x, posComp[OVER_STATE::OVER_NUMBER1 + i].y), j, 5 + i);
            }
        }
    }
    else
    {
        scale = VECTOR2(0.8f, 0.8f);

        for (int i = 0; i < ranking.KetaCount[5]; i++)
        {
            RankingNumManager_.add(&rankingNum, posComp[OVER_STATE::OVER_NUMBER1], i, 5);
        }
    }
    
    //for (int i = 0; i < OVER_MAX; i++)
    //{
    //    posComp[i] = VECTOR2(0, 0);
    //}
}
void OVER::update()
{
    
    //if (twoPlayMode) { mode = true; }
}

void OVER::draw()
{
    data = &sprScore;
    data->draw(posComp[OVER_STATE::OVER_SCORE], scale);

    if (player1Win  && !mode || mode) { data = &sprPlayer1_Down0; }
    else if(!mode && !player1Win){ data = &sprPlayer1_Damaged; }    
    data->draw(posComp[OVER_STATE::OVER_PLAYER1], VECTOR2(1, 1), 0, VECTOR4(1, 1, 1, 1));

    if (!mode)
    {
        if (player1Win) { data = &sprPlayer2_Damaged; }
        else { data = &sprPlayer2_Down0; }
        data->draw(posComp[OVER_STATE::OVER_PLAYER2], VECTOR2(1, 1), 0, VECTOR4(1, 1, 1, 1));

        data = &sprwin;
        data->draw(VECTOR2(150, 300), VECTOR2(0.5f, 0.5f));

        data = &sprlose;
        data->draw(VECTOR2(500, 300), VECTOR2(0.5f, 0.5f));
    }
}

void over_init()
{    
    over_timer = 0;
    RankingNumManager_.init();
    over.init();
    PlayerUIManager_.init();
    PlayerUIManager_.add(&playerUI, VECTOR2(over.posComp[OVER_STATE::OVER_PLAYER1].x, over.posComp[OVER_STATE::OVER_PLAYER1].y - 160), 0);
    if (twoPlayMode) { PlayerUIManager_.add(&playerUI, VECTOR2(over.posComp[OVER_STATE::OVER_PLAYER2].x, over.posComp[OVER_STATE::OVER_PLAYER2].y - 160), 1); }
    shutter.init();
}
void over_update()
{        
    switch (over.state)
    {
    case 0:

        if (shutter.scrollUp()) { over.state++; }
        break;

    case 1:
        over_timer++;

        over.update();
        RankingNumManager_.update();
        PlayerUIManager_.update();

        if ((TRG(0) & PAD_TRG2) || over_timer >= 1200)
        {
            if (twoPlayMode) { over.state++; }
            else { nextScene = SCENE_RANKING; }            
        }
        break;
    case 2:

        if (shutter.scrollDown()) { nextScene = SCENE_TITLE; }
        break;
    }

}
void over_draw()
{
    // 画面を白で塗りつぶす
    GameLib::clear(1, 1, 1);

    bg.draw();
    conveyor.draw();    

    over.draw();
    RankingNumManager_.draw();
    PlayerUIManager_.draw();

    shutter.draw();
}
void over_end()
{
    over.mode = false;

    for (int i = 0; i < 2; i++)
    {
        player[i].mvAlg = nullptr;
    }

    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
    {
        music::stop(i);
    }
}



