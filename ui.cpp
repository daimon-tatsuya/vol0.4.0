#include "all.h"

int combNum[2] = { 0, 0 };
int combKeta[2] = { 0, 0 };
int timerNum = 10800;
int timerKeta = 0;

void UI::combMove(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        //obj->data = &spr
        obj->color = VECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
        obj->size = VECTOR2(32, 32);
        if (combKeta[0] == 1) { 
            obj->position.x -= obj->size.x;
        }    //2桁目
        if (combKeta[0] == 2) { obj->position.x -= obj->size.x * 2; }//3桁目
        if (combKeta[0] == 3) { obj->position.x -= obj->size.x * 3; }//4桁目
        obj->type = combKeta[0];
        combKeta[0]++;
        obj->data = &sprComb[0];
        obj->state++;
        break;

    case 1:

        if (obj->type == 0)
        {
            obj->data = &sprComb[combNum[0] % 10];
        }
        else if (obj->type == 1)
        {
            int num = combNum[0] / 10;
            obj->data = &sprComb[num % 10];
        }
        else if (obj->type == 2)
        {
            int num = combNum[0] / 100;
            num = num % 10;
            obj->data = &sprComb[num % 10];
        }        
        break;
    }
}

void UI::comb2Move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        //obj->data = &spr
        obj->color = VECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
        obj->size = VECTOR2(32, 32);
        if (combKeta[1] == 1) { obj->position.x -= obj->size.x; }    //2桁目
        if (combKeta[1] == 2) { obj->position.x -= obj->size.x * 2; }//3桁目
        if (combKeta[1] == 3) { obj->position.x -= obj->size.x * 3; }//4桁目
        obj->type = combKeta[1];
        combKeta[1]++;
        obj->data = &sprComb[0];
        obj->state++;
        break;

    case 1:

        if (obj->type == 0)
        {
            obj->data = &sprComb[combNum[1] % 10];
        }
        else if (obj->type == 1)
        {
            int num = combNum[1] / 10;
            obj->data = &sprComb[num % 10];
        }
        else if (obj->type == 2)
        {
            int num = combNum[1] / 100;
            num = num % 10;
            obj->data = &sprComb[num % 10];
        }
        break;
    }
}

void UI::timerMove(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->size = VECTOR2(32, 32);
        //obj->scale = VECTOR2(0.5f, 0.5f);
        if (timerKeta == 0)
        {
            obj->animeData = animeTimer1;
        }
        if (timerKeta == 1) //2桁目
        { 
            obj->position.x -= obj->size.x + 16;
            obj->animeData = animeTimer10;
        }

        if (timerKeta == 2)//3桁目
        {
            obj->position.x -= obj->size.x * 2 + 32;
            obj->animeData = animeTimer100;
        }
        if (timerKeta == 3) //4桁目
        {
            obj->position.x -= obj->size.x * 3 + 48; 
            obj->animeData = animeTimer100;
        }
        
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