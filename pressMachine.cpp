#include "all.h"

using namespace GameLib;
using namespace system;

void PressMachine::init()
{
    data = &sprPressMachine;

    position = VECTOR2(108, 610);

    timer = 0;

    size = VECTOR2(105, 94);
}

void PressMachine::update()
{
    if (position.y >= 610) { speed.y = -5; }

    else if (position.y <= 370) { speed.y = 5; }

    position.y += speed.y;

    for (auto& it : *GarbageManager_.getList()) //ここでのイテレータの中身はポインタなのでアローを使う
    {
        if (rectHitCheck(VECTOR2(position.x - size.x, position.y - (size.y * 2)), size.x, size.y / 2, VECTOR2(it.position.x - it.size.x, it.position.y - (it.size.y * 2)), it.size.x, it.size.y) && it.exist)
        {
            it.eraseAlg = &garbageErase;

            //ここにプレイヤー1か2が投げたかを分けて処理する方法を記述する。
            if (it.type == 0) { combNum[0] += 3; } //large
            if (it.type == 1) { combNum[0] += 2; } //middle
            if (it.type == 2) { combNum[0]++; }    //small
           
            for ( auto& comb : *CombManager_.getList())
            {
                if (comb.type == 0)
                {
                    comb.bWork[COMB::COMB_ANIME] = true;
                }
            }
            
            count++;
            shakeFlag = true;
        }
    }

    //for  ( auto it = GarbageManager_.getList()->begin(); it != GarbageManager_.getList()->end(); it++) //ここでのイテレータの中身はポインタなのでアローを使う
    //{        
    //    if (rectHitCheck(VECTOR2(position.x - size.x, position.y - (size.y * 2)), size.x, size.y / 2, VECTOR2(it->position.x - it->size.x, it->position.y - (it->size.y * 2)), it->size.x, it->size.y) && it->exist)
    //    {
    //        it->eraseAlg = &garbageErase;
    //
    //        //ここにプレイヤー1か2が投げたかを分けて処理する方法を記述する。
    //        combNum[0]++;
    //
    //        shakeFlag = true;
    //    }
    //}

    //if (rectHitCheck(VECTOR2(position.x - size.x, position.y - (size.y * 2)), size.x, size.y / 2, VECTOR2(GarbageManager_.getList()-> - garbage.size.x, garbage.position.y - (garbage.size.y * 2)), garbage.size.x, garbage.size.y) && garbage.exist)
    //{
    //    garbage.exist = false;
    //
    //    shakeFlag = true;
    //}

    if (shakeFlag && count != 0) //破壊したときの挙動
    {
        speed.y = 32.8f;

        timer++;

        if (timer >= 5)
        {
            count--;
            shakeFlag = false;
            timer = 0;
        }
    }
}

void PressMachine::draw()
{
    if (data) { data->draw(position); }
}
