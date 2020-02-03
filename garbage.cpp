#include "all.h"
#include "ctime"
using namespace GameLib;
using namespace system;
extern float belt;//ベルトコンベアーの強制移動
int count = 0;



void Garbage::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case GARBAGE_INIT://初期設定  
        //ここでごみの流れる地面を決める
    {
        int groundPosY = rand() % 3;//乱数用
        while (groundPosYKeep_Garbage == groundPosY)
        {
            groundPosY = rand() % 3;
        }

        switch (groundPosY)
        {
        case 0:
            obj->GROUND_POS_Y = 448.0f;//上
            obj->scale = VECTOR2(0.9f, 0.9f);
            KageManager_.add(&kage, VECTOR2(obj->position.x, obj->GROUND_POS_Y + 32));
            break;
        case 1:
            obj->GROUND_POS_Y = 546.0f;//中
            obj->scale = VECTOR2(0.95f, 0.95f);
            KageManager_.add(&kage, VECTOR2(obj->position.x, obj->GROUND_POS_Y));
            break;
        case 2:
            obj->GROUND_POS_Y = 610.0f;//下
            KageManager_.add(&kage, VECTOR2(obj->position.x, obj->GROUND_POS_Y));
            break;
        }
        groundPosYKeep_Garbage = groundPosY;
    }
    // obj->animeData = animeGarbage_Large;
   //  obj->size = VECTOR2(27, 64 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
   //  obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
     //obj->position = { SCREEN_WIDTH / 2,obj->GROUND_POS_Y };
    if (obj->type == 0) { obj->data = &sprGarbage_Large0; }
    if (obj->type == 1) { obj->data = &sprGarbage_Medium0; }
    if (obj->type == 2) { obj->data = &sprGarbage_Small0; }
    if (obj->type == 3) { obj->data = &sprGarbage_Gold; }


    //obj->animeData = animeGarbage_Large;
    obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
    obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);    
    obj->caughtFlg = false;
    obj->speed.y = 4;
    obj->exist = true;
    obj->throwFlg = false;
    obj->no = 0;
    obj->bWork[GarbageManager::BACK] = false;

    srand((unsigned int)time(NULL));//乱数を更新する


    obj->state++;
    break;

    case GARBAGE_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }

        break;

    case GARBAGE_MOVE:
        for (int i = 0; i < 2; i++)
        {
            switch ((TRG(i) & PAD_TRG1) | (TRG(i) & PAD_TRG2))
            {
            case PAD_TRG1://持ち上げ

                if (rectHitCheck(obj->position - VECTOR2(32, 64), obj->size.x * 2, obj->size.y * 2, player[i].position, player[i].size.x * 2, player[i].size.y * 2) && !obj->caughtFlg && player[i].liftedCount < player[i].iWork[PLAYER::LIFTED_MAX])
                {
                    if (player[i].exist)
                    {
                        lifted(obj, i);
                    }                    
                }

                break;
            case PAD_TRG2://投げる
                if (i == obj->no && player[i].exist)
                {
                    thrown(obj, i);
                }
               
                break;
            }
        }

        //何も押してないとき
        if (!obj->throwFlg&&!obj->caughtFlg)
        {
            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }

            //ベルトコンベアーの強制移動
            obj->speed.x = belt;
        }
        else if (obj->throwFlg)//投げられてるとき
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


        if (!obj->caughtFlg)//持ち上げられているときプレイヤーの頭上にいる
        {
            obj->position += obj->speed;
        }
        else if (obj->caughtFlg)
        {                   
            obj->scale = player[obj->no].scale;
            if (STATE(obj->no) & PAD_UP) //後ろに描画
            {
                obj->position.x = player[obj->no].position.x;                
                obj->bWork[GarbageManager::BACK] = true;
            }           

            if (STATE(obj->no) & PAD_RIGHT) //右
            {                
                obj->position.x = player[obj->no].position.x + 48;                
                obj->bWork[GarbageManager::BACK] = false;
            }

            if (STATE(obj->no) & PAD_DOWN) //下
            {
                obj->position.x = player[obj->no].position.x;
                obj->bWork[GarbageManager::BACK] = false;
            }

            if (STATE(obj->no) & PAD_LEFT) //左
            {
                obj->position.x = player[obj->no].position.x - 64;
                obj->bWork[GarbageManager::BACK] = false;
            }

            obj->position += player[obj->no].speed;
        }        
        if (obj->position.x > 1100.0f )//ｘ1092はコンベアーの右端
        {
            obj->state++;
        }

        break;
    case GARBAGE_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
    
        obj->position += obj->speed;
        break;

    }


    if (obj->position.y > SCREEN_HEIGHT+64.0f)
    {
        obj->eraseAlg = &garbageErase;
    }

    //debug::setString("count:%d", count);
}



void Garbage::lifted(OBJ2D* obj, int playerType)//持ち上げるた時のゴミの動き
{
    obj->position = { player[playerType].position.x + (64 * -1),player[playerType].position.y - player[playerType].size.y - (40 * player[playerType].liftedCount) };
    obj->no = playerType;
    // obj->position = { player.position.x+(98*player.xFlip),player.position.y - player.size.y/*- */};
    obj->caughtFlg = true;
    player[playerType].liftedCount++;
    player[playerType].liftFlg = true;

};




void Garbage::thrown(OBJ2D* obj, int playerType) //投げた時のゴミの動き

{
    count++;

    int state_throw = 0;

    if (obj->caughtFlg)//プレイヤーの頭上にいるとき
    {
        switch (state_throw)
        {
        case 0:

            obj->initVelocity = { 12 * player[playerType].xFlip,2 };
            obj->speed = obj->initVelocity;
            obj->throwFlg = true;
            obj->speed.y -= 14.0f;
            obj->caughtFlg = false;
            break;
        }
    }
    player[playerType].liftedCount = 0;
    player[playerType].liftFlg = false;
};

void GarbageErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}

void GarbageManager::frontDraw()
{
    for (auto& it : objList)            // objListの全ての要素をループし、itという名前で各要素にアクセス 
    {
        if (it.mvAlg && !it.bWork[GarbageManager::BACK])
        {
            it.draw();                      // itのdrawメソッドを呼ぶ
        }
    }
}

void GarbageManager::backDraw()
{
    for (auto& it : objList)            // objListの全ての要素をループし、itという名前で各要素にアクセス 
    {
        if (it.mvAlg && it.bWork[GarbageManager::BACK])
        {
            it.draw();                      // itのdrawメソッドを呼ぶ
        }
    }
}

OBJ2D* GarbageManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type)
{
    OBJ2D obj;                          // OBJ2Dを宣言する
    obj.mvAlg = mvAlg;                  // mvAlgに引数のmvalgを代入
    obj.position = pos;                 // positionに引数のposを代入
    obj.type = type;                    //type設定

    objList.push_back(obj);             // リストにobjを追加する
    return &(*objList.rbegin());        // 今追加したobjのアドレスを返す（何かで使えるように）
}
