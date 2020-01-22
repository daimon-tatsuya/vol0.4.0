#include "all.h"

using namespace system;
static int PauseCount = 0;
void Pause::init()
{
    pause[0].data = &sprTitle_single;
    pause[1].data = &sprTitle_doubles;
    pause[2].data = &sprTitle_doubles;
    position.y = (SCREEN_HEIGHT / 2.0f);
    position.x = (SCREEN_WIDTH / 2.0f);
    size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    exist = true;
    no = 0;
    pause[0].scale = { 0.5f,0.5f };
    pause[1].scale = { 0.45f,0.45f };
    pause[2].scale = { 0.45f,0.45f };
}
void Pause::update()
{

    if (TRG(0) & PAD_TRG2)//ゲームを開始
    {
        title_state = 2;
    }

    if (TRG(0) &  PAD_UP)
    {
        PauseCount--;
    }

    if (TRG(0) &PAD_DOWN)
    {
        PauseCount++;
    }

    if (PauseCount < 0)
    {
        PauseCount = 0;
    }
    if (PauseCount > 2)
    {
        PauseCount = 2;
    }

    if (PauseCount == 0)
    {        
        pause[0].scale = { 0.75f,0.75f };
        pause[1].scale = { 0.45f,0.45f };
        pause[2].scale = { 0.45f,0.45f };
    }

    if (PauseCount == 1)
    {
        
        pause[0].scale = { 0.45f,0.45f };
        pause[1].scale = { 0.75f,0.75f };
        pause[2].scale = { 0.45f,0.45f };
    }

    if (PauseCount == 2)
    {
       

        pause[0].scale = { 0.45f,0.45f };
        pause[1].scale = { 0.45f,0.45f };
        pause[2].scale = { 0.75f,0.75f };
    }
}
void Pause::draw()
{
    if (data)
    {
        data->draw(position, scale, angle, color);
    }
}