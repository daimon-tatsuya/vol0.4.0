#include "all.h"

using namespace system;
static int GameModeCount=0;
void GameMode::init() 
{
    gamemode[0].data = &sprTitle_single;
    gamemode[1].data = &sprTitle_doubles;
    gamemode[2].data = &sprTitle_tutorial;
    twoPlayMode = false;
    position.y  = ( SCREEN_HEIGHT / 2.0f  ) -50 ;
    position.x  = ( SCREEN_WIDTH / 2.0f   )  ;
    gamemode[2].position = { SCREEN_WIDTH / 2.0f ,(SCREEN_HEIGHT / 2.0f)+100.0f };
    size  = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    exist = true;
    no = 0;
    gamemode[0].scale = { 0.75f,0.75f };
    gamemode[1].scale = { 0.45f,0.45f };
    gamemode[2].scale = { 0.45f,0.45f };
}
void GameMode::update() 
{

    if (TRG(0) & PAD_TRG2)//ゲームを開始
    {
        title_state = 2;
    }

    if (TRG(0) &  PAD_UP)
    {
        /* twoPlayMode = true
         gamemode[0].scale = { 0.45f,0.
         gamemode[1].scale = { 0.5f,0.5f };*/
        GameModeCount--;

    }

    if (TRG(0) &PAD_DOWN)
    {
        //twoPlayMode = false;
        //gamemode[0].scale = { 0.5f,0.5f };
        //gamemode[1].scale = { 0.45f,0.45f };

        GameModeCount++;
    }

    if (GameModeCount < 0 )
    {
        GameModeCount = 0;
    }
    if (GameModeCount > 2 )
    {
        GameModeCount = 2;
    }
     
    if (GameModeCount == 0)
    {
        twoPlayMode = false;
        tutorialMode = false;
        gamemode[0].scale = { 0.75f,0.75f };
        gamemode[1].scale = { 0.45f,0.45f }; 
        gamemode[2].scale = { 0.45f,0.45f };
    }

    if (GameModeCount == 1)
    {
        twoPlayMode = true;
        tutorialMode = false;
        gamemode[0].scale = { 0.45f,0.45f };
        gamemode[1].scale = { 0.75f,0.75f };
        gamemode[2].scale = { 0.45f,0.45f };
        gamemode[2].position = { SCREEN_WIDTH / 2.0f ,(SCREEN_HEIGHT / 2.0f) + 1000.0f };
    }

    if (GameModeCount == 2)
    {
        twoPlayMode = false;
        tutorialMode = true;
        gamemode[2].position = { SCREEN_WIDTH / 2.0f ,(SCREEN_HEIGHT / 2.0f)};
        gamemode[0].scale = { 0.45f,0.45f };
        gamemode[1].scale = { 0.45f,0.45f };
        gamemode[2].scale = { 0.75f,0.75f };
    }
    else
    {
        gamemode[2].position = { SCREEN_WIDTH / 2.0f ,(SCREEN_HEIGHT / 2.0f) + 100.0f };
    }
}
void GameMode::draw()
{
    if (data)
    {
        data->draw(position, scale, angle, color);
    }
}