#include "all.h"

using namespace GameLib;
using namespace system;
int count = 0;

extern float belt ;//ベルトコンベアーの強制移動
//void Garbage::init()
//{
//    position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
//    exist = true;
//    throwFlg = false;
//}

void Garbage::move(OBJ2D* obj)
{
//    count++;

    switch (obj->state)
    {
    case GARBAGE_INIT://初期設定
        obj->animeData = animeGarbage_Large;
        obj->size = VECTOR2(27, 64-2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->caughtFlg = false;

        obj->exist = true;
        obj->throwFlg = false;

        obj->state++;
        break;   

    case GARBAGE_MOVE:   
        switch ( (TRG(0) & PAD_TRG1) | (TRG(0) & PAD_TRG2))
        {
        case PAD_TRG1://持ち上げ

            lifted(obj);   

            break;
        case PAD_TRG2://投げる

            thrown(obj);
            
            break;
        default://何も押してないとき
            if (!obj->throwFlg)
            {
                if (rectHitCheck(obj->position-VECTOR2(32,64), 64, 64, VECTOR2(0,GROUND_POS_Y),SCREEN_WIDTH, SCREEN_HEIGHT))
                {
                    obj->position.y = GROUND_POS_Y;
                }

                //ベルトコンベアーの強制移動
                obj->speed.x = belt;
            }
            else //投げられてるとき
            {                
                if (obj->speed.y >= 20)
                {
                    obj->speed.y = 20;
                }
                else
                {
                    obj->speed.y += 0.9f;
                }
            }
            break;
        }
        break;
    }
    if (obj->caughtFlg)//持ち上げられているときプレイヤーの頭上にいる
    {
        obj->position = { player.position.x,player.position.y - player.size.y/*- */ };
    }
    else 
    {
        obj->position += obj->speed;
    }

    //アニメアップデート
    if (obj->animeData)
    {
        obj->animeUpdate(obj->animeData);
    }

    if (obj->position.y > SCREEN_HEIGHT)
    {
        obj->eraseAlg = &garbageErase;
    }

    debug::setString("count:%d", count);
}

//void Garbage::draw()
//{
//    if (data)
//    { data->draw(position, scale, angle, color); }
//}

void Garbage::lifted(OBJ2D* obj)//持ち上げるた時のゴミの動き
{
 obj->position = { player.position.x,player.position.y - player.size.y/*- */};
 obj->caughtFlg = true;
}; 
void Garbage::thrown(OBJ2D* obj) //投げた時のゴミの動き
{
    count++;

    int state_throw = 0;
    if (obj->caughtFlg)//プレイヤーの頭上にいるとき
    {
        switch (state_throw)
        {
        case 0:
            obj->initVelocity = {12 * player.xFlip,2 };
            obj->speed = obj->initVelocity;
            obj->throwFlg = true;
            obj->speed.y -= 14.0f;
            obj->caughtFlg = false;
            break;
        //case 1:
        //    speed.y -= 1.0f;
        //    position += speed;

        }
    }

};

void GarbageErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}
