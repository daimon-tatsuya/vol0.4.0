#include "all.h"
using namespace GameLib;
using namespace system;
static int GameModeCount=0;
void GameMode::init() 
{
    gamemode[0].data = &sprTitle_single;
    gamemode[1].data = &sprTitle_doubles;
    twoPlayMode = false;
    position.y  = ( SCREEN_HEIGHT / 2.0f ) ;
    position.x  = ( SCREEN_WIDTH / 2.0f ) ;
    size  = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    exist = true;
    no = 0;
    gamemode[0].scale = { 0.5f,0.5f };
    gamemode[1].scale = { 0.45f,0.45f };
}
void GameMode::update() 
{

    if (TRG(0) & PAD_START)//ゲームを開始
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
       
    }

    if (GameModeCount == 1)
    {
        twoPlayMode = true;
        tutorialMode = false;
        gamemode[0].scale = { 0.45f,0.45f };
        gamemode[1].scale = { 0.75f,0.75f };
    }

    if (GameModeCount == 2)
    {
        twoPlayMode = false;
        tutorialMode = true;

        gamemode[0].scale = { 0.45f,0.45f };
        gamemode[1].scale = { 0.45f,0.45f };

    }
}
void GameMode::draw()
{
    if (data)
    {
        data->draw(position, scale, angle, color);
    }
}