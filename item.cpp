#include "all.h"

using namespace system;

extern float belt;//ベルトコンベアーの強制移動

void Item::move(OBJ2D* obj)
{
    if (obj->state == 0) 
    { 
        obj->no = rand() % 4 + 1;
    }

    switch (obj->no)
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

void itemMove1(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0://初期設定
        obj->data = &sprItem0;
        obj->size = VECTOR2(27, 64 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };

        obj->state++;
        break;

    case 1:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = GROUND_POS_Y;
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;


        //アニメアップデート
        //if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(obj->position, obj->size.x, obj->size.y, player.position, player.size.x, player.size.y))
        {
            //ここにアイテム効果の処理を描く。
            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void itemMove2(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0://初期設定
        obj->data = &sprItem1;
        obj->size = VECTOR2(27, 64 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };

        obj->state++;
        break;

    case 1:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = GROUND_POS_Y;
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        //アニメアップデート
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(obj->position, obj->size.x, obj->size.y, player.position, player.size.x, player.size.y))
        {
            //ここにアイテム効果の処理を描く。
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
        obj->size = VECTOR2(27, 64 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };

        obj->state++;
        break;

    case 1:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = GROUND_POS_Y;
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        //アニメアップデート
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(obj->position, obj->size.x, obj->size.y, player.position, player.size.x, player.size.y))
        {
            //ここにアイテム効果の処理を描く。
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
        obj->size = VECTOR2(27, 64 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };

        obj->state++;
        break;

    case 1:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = GROUND_POS_Y;
        }

        //ベルトコンベアーの強制移動
        obj->speed.x = belt;

        obj->position += obj->speed;

        //アニメアップデート
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(obj->position, obj->size.x, obj->size.y, player.position, player.size.x, player.size.y))
        {
            //ここにアイテム効果の処理を描く。
            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void ItemErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}
