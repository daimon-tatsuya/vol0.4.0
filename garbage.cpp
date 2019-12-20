#include "all.h"

using namespace GameLib;
using namespace system;
extern float belt ;//ベルトコンベアーの強制移動
void Garbage::init()
{
    position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
    exist = true;
}

void Garbage::update()
{
    switch (state)
    {
    case GARBAGE_INIT://初期設定
        animeData = animeGarbage_Large;
        size = VECTOR2(27, 64-2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
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

    if (TRG(0) & PAD_L1) //L1ボタンでリセット
    {
        exist = true;

        init();
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
