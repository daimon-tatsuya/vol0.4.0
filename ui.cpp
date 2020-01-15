#include <stdio.h>
#include "all.h"

int combNum[2] = { 0, 0 };
int combKeta[2] = { 0, 0 };
int timerNum = 10800;
int timerKeta = 0;



void UI::combMove(OBJ2D* obj)//プレイヤーのコンボ処理
{
    switch (obj->state)
    {
    case 0:
        //obj->data = &spr
        obj->color = VECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
        obj->size = VECTOR2(32, 32);
        if (combKeta[obj->type] == combKeta[obj->type]) { obj->position.x -= obj->size.x * combKeta[obj->type]; } 
        //if (combKeta[obj->type] == 2) { obj->position.x -= obj->size.x * 2; }//3桁目
        //if (combKeta[obj->type] == 3) { obj->position.x -= obj->size.x * 3; }//4桁目
        obj->no = combKeta[obj->type];
        combKeta[obj->type]++;
        obj->data = &sprComb[0];
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

//void UI::comb2Move(OBJ2D* obj)
//{
//    switch (obj->state)
//    {
//    case 0:
//        //obj->data = &spr
//        obj->color = VECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
//        obj->size = VECTOR2(32, 32);
//        if (combKeta[1] == 1) { obj->position.x -= obj->size.x; }    //2桁目
//        if (combKeta[1] == 2) { obj->position.x -= obj->size.x * 2; }//3桁目
//        if (combKeta[1] == 3) { obj->position.x -= obj->size.x * 3; }//4桁目
//        obj->type = combKeta[1];
//        combKeta[1]++;
//        obj->data = &sprComb[0];
//        obj->state++;
//        break;
//
//    case 1:
//
//        if (obj->type == 0)
//        {
//            obj->data = &sprComb[combNum[1] % 10];
//            obj->bWork[COMB::COMB_ANIME] = true;
//        }
//        else if (obj->type == 1)
//        {
//            int num = combNum[1] / 10;
//            obj->data = &sprComb[num % 10];
//        }
//        else if (obj->type == 2)
//        {
//            int num = combNum[1] / 100;
//            num = num % 10;
//            obj->data = &sprComb[num % 10];
//        }
//
//        if (obj->bWork[COMB::COMB_ANIME])
//        {
//            obj->timer++;
//            if (obj->timer < 20)
//            {
//                obj->speed.x += 2;
//            }
//            else if (obj->timer < 40)
//            {
//                obj->speed.x -= 2;
//            }
//            else
//            {
//                obj->speed.x = 0;
//                obj->timer = 0;
//                obj->bWork[COMB::COMB_ANIME] = false;
//            }
//        }
//
//        obj->position.x += obj->speed.x;
//        break;
//    }
//}

void UI::timerMove(OBJ2D* obj)//タイマー表示＆処理
{
    switch (obj->state)
    {
    case 0:
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->size = VECTOR2(48, 32);
        //obj->scale = VECTOR2(0.5f, 0.5f);
        obj->animeData = animeTimer[timerKeta];
        obj->position.x -= obj->size.x * timerKeta;

        //if (timerKeta == 0)
        //{
        //    obj->animeData = animeTimer[0];
        //}
        //if (timerKeta == 1) //2桁目
        //{ 
        //    obj->position.x -= obj->size.x + 16;
        //    obj->animeData = animeTimer10;
        //}
        //
        //if (timerKeta == 2)//3桁目
        //{
        //    obj->position.x -= obj->size.x * 2 + 32;
        //    obj->animeData = animeTimer100;
        //}
        //if (timerKeta == 3) //4桁目
        //{
        //    obj->position.x -= obj->size.x * 3 + 48; 
        //    obj->animeData = animeTimer100;
        //}
        
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

        //int num = timerNum / 60;
        //
        //if (timerKetaID == 0) 
        //{ 
        //    num = num % 10;
        //    //obj->data = animeNum[num];
        //}
        //
        //if (timerKetaID == 1)
        //{
        //    num = num / 10;
        //    num = num % 10;
        //    //obj->data = animeNum[num];
        //}
        //
        //if (timerKetaID == 2)
        //{
        //    num = num / 100;
        //    num = num % 10;
        //    //obj->data = animeNum[num];
        //}
        //
        //if (timerKetaID == 3)
        //{
        //    num = num / 1000;
        //    num = num % 10;
        //    //obj->data = animeNum[num];
        //}
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

        obj->state++;
        break;

    case  1:

        //絵が次々に代わるアニメーションをしてaddするタイミングになったらアニメーションを止める。
        if (obj->timer < 360)
        {
            obj->animeData = animeRandoMark;
            obj->timer++;
        }
        else if(obj->timer < 540)
        {
            obj->timer++;
            
            if (obj->count == 0)
            {                
                int no = rand() % 10;
                if (no < 8)
                {
                    no = rand() % 3;
                    GarbageManager_.add(&garbage, obj->position, no);
                }
                else
                {
                    no = rand() % 4 + 1;
                    ItemManager_.add(&item, obj->position, no);
                    no += 2;
                }
                obj->data = &sprRandoMark[no];
                
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

}