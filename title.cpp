#include "all.h"
#include "ctime"
using namespace GameLib;
using namespace system;
extern float belt;//ベルトコンベアーの強制移動

void Title::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case TITLE_INIT://初期設定  
        
                      //ここでtitleの文字の流れる地面を決める
    {
        int groundPosY = rand() % 3;//乱数用
        while (groundPosYKeep_Title == groundPosY)
        {
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
        groundPosYKeep_Title = groundPosY;
    }
   
    obj->size = VECTOR2(27, 32 - 2); //スケールは当たり判定の値なので実際の大きさの半分を入れる
    obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    obj->caughtFlg = false;
    obj->exist = true;
    obj->throwFlg = false;
    obj->no = 0;
    obj->position.y = SCREEN_HEIGHT / 2.0f;
    srand((unsigned int)time(NULL));//乱数を更新する
    if ((TRG(0)&PAD_TRG1) | (TRG(0)&PAD_TRG2))
    {
        obj->state++;
        obj->speed.y = 4;
    }
   
    break;

    case TITLE_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }

        break;

    case TITLE_MOVE:
  
       
            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }
        //ベルトコンベアーの強制移動
            obj->speed.x = belt;
        
      
       
            obj->position += obj->speed;
       

        if (obj->position.x > 1092.0f)//ｘ1092はコンベアーの右端
        {
            obj->state++;
        }

        break;
    case TITLE_DELETE:

        obj->speed.y = 3;
        obj->speed.x = 1;
      
        obj->position += obj->speed;
        break;
    }

    if (obj->position.y > SCREEN_HEIGHT+64.0f)
    {
        obj->eraseAlg = &titleErase;
    }
}

void TitleErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}


OBJ2D* TitleManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type)
{
    OBJ2D obj;                          // OBJ2Dを宣言する
    obj.mvAlg = mvAlg;                  // mvAlgに引数のmvalgを代入
    obj.position = pos;                 // positionに引数のposを代入
    obj.type = type;                    //type設定

    objList.push_back(obj);             // リストにobjを追加する
    return &(*objList.rbegin());        // 今追加したobjのアドレスを返す（何かで使えるように）
}

