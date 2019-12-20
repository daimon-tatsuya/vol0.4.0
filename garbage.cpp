#include "all.h"

using namespace GameLib;
using namespace system;
extern float belt ;//ベルトコンベアーの強制移動
void Garbage::init()
{
}

void Garbage::update()
{
    switch (state)
    {
    case GARBAGE_INIT://初期設定
        animeData = animeGarbage_Large;
        position = { 0,0 };
        size = VECTOR2(24 / 2, 64 - 2);
        color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        caughtFlg = false;
            state++;
        break;
    case GARBAGE_MOVE:
        switch ( (STATE(0) & PAD_TRG1) | (STATE(0) & PAD_TRG2))
        {
        case PAD_TRG1://持ち上げる

            position = { player.position.x,player.position.y - player.size.y/*- */};
            caughtFlg = true;
            break;
        case PAD_TRG2://投げる
            if (caughtFlg)
            {
                initVelocity = { 12* player.xFlip,2  };
                speed = initVelocity;
                caughtFlg = false;
            }
            
            break;
        default://何も押してないとき
                //ベルトコンベアーの強制移動
            speed.x = belt;
            break;
        }
        break;
    }
    if (caughtFlg)
    {
        position = { player.position.x,player.position.y - player.size.y/*- */ };
    }
    else
    {
        position += speed;
    }
    //アニメアップデート
    if (animeData)
    {
        animeUpdate(animeData);
    }
}

void Garbage::draw()
{

    if (data)
    { data->draw(position, scale, angle, color); }
}
