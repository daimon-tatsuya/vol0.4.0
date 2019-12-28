#include "all.h"

using namespace GameLib;
using namespace system;
extern float belt ;//ベルトコンベアーの強制移動
void Garbage::init()
{
    position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
    exist = true;
    throwFlg = false;
}

void Garbage::update()
{
    /*if (rectHitCheck(position-VECTOR2(32,64), 64, 64, VECTOR2(0,GROUND_POS_Y),SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        position.y = GROUND_POS_Y;
    }*/

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
      
        switch ( (TRG(0) & PAD_TRG1) | (TRG(0) & PAD_TRG2))
        {
        case PAD_TRG1://持ち上げ

            lifted();   

            break;
        case PAD_TRG2://投げる

            thrown();
            
            break;
        default://何も押してないとき
            if (!throwFlg)
            {
                //ベルトコンベアーの強制移動
                speed.x = belt;
            }
            break;
        }
        break;
    }
    if (caughtFlg)//持ち上げられているときプレイヤーの頭上にいる
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

void Garbage::lifted()//持ち上げるた時のゴミの動き
{
 position = { player.position.x,player.position.y - player.size.y/*- */};
 caughtFlg = true;
}; 
void Garbage::thrown() //投げた時のゴミの動き
{
    int state_throw = 0;
    if (caughtFlg)//プレイヤーの頭上にいるとき
    {

        switch (state_throw)
        {
        case 0:
            initVelocity = { 12 * player.xFlip,2 };
            speed = initVelocity;
            throwFlg = true;
            speed.y -= 1.0f;
            caughtFlg = false;
            break;
        //case 1:
        //    speed.y -= 1.0f;
        //    position += speed;

        }
    }

};
