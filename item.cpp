#include "all.h"

using namespace system;

extern float belt;//ベルトコンベアーの強制移動

//int groundPosYKeep_Item = 0;
void Item::move(OBJ2D* obj)
{
    if(obj->state == 0)
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
            obj->GROUND_POS_Y = 482.0f;//上
            break;
        case 1:
            obj->GROUND_POS_Y = 546.0f;//中
            break;
        case 2:
            obj->GROUND_POS_Y = 610.0f;//下
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

void itemMove1(OBJ2D* obj) //スピードアップ
{
    switch (obj->state)
    {
    case 0://初期設定


        obj->data = &sprItem0;
        obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        // obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed.y = 4;

        obj->state++;
        break;

    case 1:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case 2:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;


        //アニメアップデート
        //if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player.position.x - player.size.x, player.position.y - player.size.y), player.size.x, player.size.y))
        {
            //ここにアイテム効果の処理のフラグを立てる。
            player.bWork[PLAYER_STATUS::SPEEDUP] = true;
            belt = 3.5f;
            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void itemMove2(OBJ2D* obj)//スピードダウン
{
    switch (obj->state)
    {
    case 0://初期設定
        obj->data = &sprItem1;
        obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed.y = 4;

        obj->state++;
        break;

    case 1:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case 2:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        //アニメアップデート
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player.position.x - player.size.x, player.position.y - player.size.y), player.size.x, player.size.y))
        {
            //ここにアイテム効果の処理のフラグを立てる。
            player.bWork[PLAYER_STATUS::SPEEDDOWN] = true;
            belt = 0.5f;
            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void itemMove3(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0://初期設定
        obj->data = &sprItem2;
        obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed.y = 4;

        obj->state++;
        break;

    case 1:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case 2:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        //アニメアップデート
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player.position.x - player.size.x, player.position.y - player.size.y), player.size.x, player.size.y))
        {
            //ここにアイテム効果の処理のフラグを立てる。

            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void itemMove4(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0://初期設定
        obj->data = &sprItem3;
        obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed.y = 4;

        obj->state++;
        break;

    case 1:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case 2:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        //アニメアップデート
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player.position.x - player.size.x, player.position.y - player.size.y), player.size.x, player.size.y))
        {
            //ここにアイテム効果の処理のフラグを立てる。
            obj->eraseAlg = &itemErase;
        }

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