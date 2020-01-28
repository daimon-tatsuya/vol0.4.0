#include "all.h"

using namespace system;

extern float belt;//ベルトコンベアーの強制移動

//int groundPosYKeep_Item = 0;
void Item::move(OBJ2D* obj)
{
    if (obj->state == 0)
    {
        int groundPosY = rand() % 3;//乱数用

        while (1)
        {
            if (groundPosYKeep_Item != groundPosY) { break; }
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
        groundPosYKeep_Item = groundPosY;
    }
    switch (obj->type)
    {
    case 1:

        itemMove1(obj);
        break;

    case 2:

        itemMove2(obj);
        break;

    case 3:

        itemMove3(obj);
        break;

    case 4:

        itemMove4(obj);
        break;
    }
}

void itemMove1(OBJ2D* obj) //コンベアースピードアップ
{
    switch (obj->state)
    {
    case ITEM_INIT://初期設定

        obj->data = &sprItem0;
        obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        // obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed = VECTOR2(0, 4);

        obj->state++;
        break;

    case ITEM_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case ITEM_MOVE:
        for (int i = 0; i < 2; i++)
        {
            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }
           
            //アニメアップデート
            //if (obj->animeData) { obj->animeUpdate(obj->animeData); }

            if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player[i].position.x - player[i].size.x, player[i].position.y - player[i].size.y), player[i].size.x, player[i].size.y))
            {
                music::play(4);
                if (player[i].exist)
                {
                    
                    //ここにアイテム効果の処理のフラグを立てる。
                    player[i].bWork[PLAYER_STATUS::CONVEYORUP] = true;
                    conveyor.animeData = animeConveyor[1];
                    belt = 3.5f;
                    obj->eraseAlg = &itemErase;
                }
               
            }
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//ｘ1200はコンベアーの右端
        {
            obj->state++;
        }
        break;
    case ITEM_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &itemErase;
        }
        obj->position += obj->speed;
        break;
    }
}

void itemMove2(OBJ2D* obj)//足の速さが上がるアイテム処理。
{
    switch (obj->state)
    {
    case ITEM_INIT://初期設定
        obj->data = &sprItem1;
        obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed = VECTOR2(0, 4);

        obj->state++;
        break;

    case ITEM_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case ITEM_MOVE:
        for (int i = 0; i < 2; i++)
        {

            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }

            //アニメアップデート
            if (obj->animeData) { obj->animeUpdate(obj->animeData); }

            if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }
                          
            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player[i].position.x - player[i].size.x, player[i].position.y - player[i].size.y), player[i].size.x, player[i].size.y))
            {
                music::play(4);
                //ここにアイテム効果の処理のフラグを立てる。
                if (player[i].exist)
                {
                    if (player[i].bWork[PLAYER_STATUS::SPEEDUP] == true) //同じ効果のエフェクトが出てる場合はいったん消す。
                    {
                        for (auto& efe : *EffectManager_.getList())
                        {
                            if (efe.exist && efe.type == 1)
                            {
                                efe.eraseAlg = &effectErase;
                                break;
                            }
                        }
                    }
                    player[i].bWork[PLAYER_STATUS::SPEEDUP] = true;
                    EffectManager_.add(&effect, player[i].position, 1, i);
                    obj->eraseAlg = &itemErase;
                }
            }
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//ｘ1200はコンベアーの右端
        {
            obj->state++;
        }
        break;
    case ITEM_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &itemErase;
        }
        obj->position += obj->speed;
        break;
    }
}

void itemMove3(OBJ2D* obj)//持てる量増えるアイテム処理。
{
    switch (obj->state)
    {
    case ITEM_INIT://初期設定
        obj->data = &sprItem2;
        obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed = VECTOR2(0, 4);

        obj->state++;
        break;

    case ITEM_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case ITEM_MOVE:
        for (int i = 0; i < 2; i++)
        {
            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }

            //アニメアップデート
            if (obj->animeData) { obj->animeUpdate(obj->animeData); }

            if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player[i].position.x - player[i].size.x, player[i].position.y - player[i].size.y), player[i].size.x, player[i].size.y))
            {
                music::play(4);
                if (player[i].exist)
                {
                    //ここにアイテム効果の処理のフラグを立てる。
                    if (player[i].bWork[PLAYER_STATUS::POWERUP] == true) //同じ効果のエフェクトが出てる場合はいったん消す。
                    {
                        for (auto& efe : *EffectManager_.getList())
                        {
                            if (efe.exist && efe.type == 0)
                            {
                                efe.eraseAlg = &effectErase;
                                break;
                            }
                        }
                    }
                    player[i].bWork[PLAYER_STATUS::POWERUP] = true;
                    player[i].iWork[PLAYER::LIFTED_MAX] = 4;
                    EffectManager_.add(&effect, player[i].position, 0, i);
                    obj->eraseAlg = &itemErase;
                }
            }
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//ｘ1200はコンベアーの右端
        {
            obj->state++;
        }

        break;
    case ITEM_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &itemErase;
        }
        obj->position += obj->speed;
        break;
    }
}

void itemMove4(OBJ2D* obj)//アイテム出現時間短縮
{
    switch (obj->state)
    {
    case ITEM_INIT://初期設定
        obj->data = &sprItem3;
        obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed = VECTOR2(0, 4);

        obj->state++;
        break;

    case ITEM_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case ITEM_MOVE:
        for (int i = 0; i < 2; i++)
        {

            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }

            //アニメアップデート
            if (obj->animeData) { obj->animeUpdate(obj->animeData); }

            if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player[i].position.x - player[i].size.x, player[i].position.y - player[i].size.y), player[i].size.x, player[i].size.y))
            {
                music::play(4);
                if (player[i].exist)
                {
                    //ここにアイテム効果の処理のフラグを立てる。
                    for (auto& it : *RandoManager_.getList())
                    {
                        it.iWork[RandoManager::RandoMark::TIMER_MAX1] = 120;
                        it.iWork[RandoManager::RandoMark::TIMER_MAX2] = 240;
                    }
                    player[i].bWork[PLAYER_STATUS::ITEMADD] = true;
                    obj->eraseAlg = &itemErase;
                }
            }
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//ｘ1200はコンベアーの右端
        {
            obj->state++;
        }
        break;
    case ITEM_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &itemErase;
        }
        obj->position += obj->speed;
        break;
    }
}

void ItemErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}

OBJ2D* ItemManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type) // objListに新たなOBJ2Dを追加する
{
    OBJ2D obj;                          // OBJ2Dを宣言する
    obj.mvAlg = mvAlg;                  // mvAlgに引数のmvalgを代入
    obj.position = pos;                 // positionに引数のposを代入
    obj.type = type;                    //type設定

    objList.push_back(obj);             // リストにobjを追加する
    return &(*objList.rbegin());        // 今追加したobjのアドレスを返す（何かで使えるように）
}