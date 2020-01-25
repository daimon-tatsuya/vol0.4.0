#include <stdio.h>
#include "all.h"

int combNum[2] = { 0, 0 };
int combKeta[2] = { 0, 0 };
int timerNum = 7200;
int timerKeta = 0;

//int UI::resultKeta[] = { 0 };
//int UI::resultScore[] = { 0 };

void UI::combMove(OBJ2D* obj)//プレイヤーのコンボ処理
{
    switch (obj->state)
    {
    case 0:
        //obj->data = &spr
        obj->color = VECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
        obj->size = VECTOR2(40, 32);
        obj->position.x -= obj->size.x * combKeta[obj->type]; 
        //if (combKeta[obj->type] == 2) { obj->position.x -= obj->size.x * 2; }//3桁目
        //if (combKeta[obj->type] == 3) { obj->position.x -= obj->size.x * 3; }//4桁目
        obj->no = combKeta[obj->type];
        combKeta[obj->type]++;
        obj->data = &sprComb[0];
        obj->bWork[COMB::COMB_ANIME] = false;
        obj->state++;
        break;
        
    case 1:

        if (obj->no == 0)
        {
            obj->data = &sprComb[combNum[obj->type] % 10];
            
        }
        else if (obj->no == 1)
        {
            int num = combNum[obj->type] / 10;
            obj->data = &sprComb[num % 10];
        }
        else if (obj->no == 2)
        {
            int num = combNum[obj->type] / 100;
            num = num % 10;
            obj->data = &sprComb[num % 10];
        }     

        if (obj->bWork[COMB::COMB_ANIME])
        {
            obj->timer++;
            if (obj->timer <= 5)
            {
                obj->speed.x = 4;
            }
            else if(obj->timer <= 10)
            {
                obj->speed.x = -4;
            }
            else
            {
                obj->speed.x = 0;
                obj->timer = 0;
                obj->bWork[COMB::COMB_ANIME] = false;
            }
        }

        obj->position.x += obj->speed.x;
        break;
    }
}

void UI::timerMove(OBJ2D* obj)//タイマー表示＆処理
{
    switch (obj->state)
    {
    case 0:
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->size = VECTOR2(48, 32);
        //obj->scale = VECTOR2(0.5f, 0.5f);
        obj->animeData = animeTimer[timerKeta]; //単位のアニメーション設定
        obj->position.x -= obj->size.x * timerKeta;
        
        timerKeta++;
        obj->state++;
        break;

    case 1:

        if (timerNum < 0) 
        {
            obj->eraseAlg = &timerErase; 
        }

        //アニメアップデート
        if (obj->animeData)
        {
            obj->animeUpdate(obj->animeData);
        }
        break;
    }
}

void UI::randoMark(OBJ2D* obj)//ランダムに表示が切り替わる処理
{
    switch (obj->state)
    {
    case 0:

        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->size = VECTOR2(32, 32);
        obj->iWork[RandoManager::RandoMark::TIMER_MAX1] = 180;
        obj->iWork[RandoManager::RandoMark::TIMER_MAX2] = 240;
        obj->timer = 0;
        obj->count = 0;

        obj->state++;
        break;

    case  1:

        //絵が次々に代わるアニメーションをしてaddするタイミングになったらアニメーションを止める。
        if (obj->timer < obj->iWork[RandoManager::RandoMark::TIMER_MAX1])
        {
            obj->animeData = animeRandoMark;
            obj->timer++;
        }
        else if(obj->timer < obj->iWork[RandoManager::RandoMark::TIMER_MAX2])
        {
            obj->timer++;
            
            if (obj->count == 0)
            {                
                int no = rand() % 10;
                if (no < 8)
                {
                    no = rand() % 30;
                    if (no == 3) { GarbageManager_.add(&garbage, obj->position, no); }
                    else
                    {
                        no = rand() % 3;
                        GarbageManager_.add(&garbage, obj->position, no);
                    }                    
                }
                else
                {
                    no = rand() % 4 + 1;
                    ItemManager_.add(&item, obj->position, no);
                    no += 3;
                }
                //int no = 3;
                //GarbageManager_.add(&garbage, obj->position, no);
                //no += 2;
                obj->data = &sprRandoMark[no];
                if (timerNum < 3600)//時間が残り1分半になるとはてなマークが3分の1の確率で出る。
                {
                    int hatenaRandom = rand() % 3;
                    if (hatenaRandom == 1)
                    {
                        obj->data = &sprRandoMark[8];
                    }
                }

                EffectManager_.add(&effect, VECTOR2(obj->position.x, obj->position.y + 158), 2, 0);

                obj->count++;
            }
            obj->animeData = nullptr;
            
        }
        else
        {
            obj->count = 0;
            obj->timer = 0;
        }
        
        if (obj->animeData)
        {
            obj->animeUpdate(obj->animeData);
        }
        
        break;
    }
}

void UI::rankingMove(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        if (obj->no < 3)
        {
            obj->color = VECTOR4(1.0f, 1.0f, 0.0f, 1.0f);
            obj->scale = VECTOR2(1.2f, 1.2f);
            obj->size = VECTOR2(48, 38.4f);
            obj->position.x -= obj->size.x * obj->type;
        }
        else
        {
            obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
            obj->scale = VECTOR2(1, 1);
            obj->size = VECTOR2(40, 32);
            obj->position.x -= obj->size.x * obj->type;            
        }        
        
        if (over.mode)
        {
            obj->position.x -= obj->size.x * obj->type * 2;
            obj->scale = VECTOR2(3, 3);
        }

        obj->iWork[RankingNumManager::COPY] = ranking.result[obj->no];
        for (int i = 0; i < obj->type; i++)
        {            
            obj->iWork[RankingNumManager::COPY] = obj->iWork[RankingNumManager::COPY] / 10;
        }
        obj->iWork[RankingNumManager::COPY] %= 10;
        obj->state++;
        break;

    case 1:

        obj->data = &sprComb[obj->iWork[RankingNumManager::COPY]];

        //if (obj->no == 0)
        //{
        //    obj->data = &sprComb[resultScore[obj->type] % 10];
        //
        //}
        //else if (obj->no == 1)
        //{
        //    int num = resultScore[obj->type] / 10;
        //    obj->data = &sprComb[num % 10];
        //}
        //else if (obj->no == 2)
        //{
        //    int num = resultScore[obj->type] / 100;
        //    num = num % 10;
        //    obj->data = &sprComb[num % 10];
        //}
        break;
    }
}

