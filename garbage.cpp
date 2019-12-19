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
       
            state++;
        break;
    case GARBAGE_MOVE:
        switch ( (STATE(0) & PAD_TRG1) | (STATE(0) & PAD_TRG2))
        {
        case PAD_TRG1://持ち上げる
            speed = { player.position.x,player.position.y - player.size.y/*- */};
            break;
        case PAD_TRG2://投げる
             initVelocity = { -12,2*player.xFlip };

            break;
        default://何も押してないとき
                //ベルトコンベアーの強制移動
            speed.x = belt;
            break;
        }
        break;
    }

    position += speed;

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
