#include "all.h"

void Effect::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        obj->animeData = animeEffect[obj->type];

        if (obj->type == 2)
        {
            obj->scale = VECTOR2(2.8f, 2);
        }

        obj->color = VECTOR4(1, 1, 1, 1);
        obj->exist = true;

        obj->state++;

        if (obj->type == 2) { obj->state = 2; }//煙のフラグはstateで行う。
        break;

    case 1:        

        obj->position = player[obj->no].position;
        obj->position.y += 8;
        
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        break;

    case 2:

        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->data == nullptr) { obj->eraseAlg = &effectErase; }

    }
}

void EffectErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}

OBJ2D* EffectManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type, int no)
{
    OBJ2D obj;                          // OBJ2Dを宣言する
    obj.mvAlg = mvAlg;                  // mvAlgに引数のmvalgを代入
    obj.position = pos;                 // positionに引数のposを代入
    obj.type = type;                    //type設定
    obj.no = no;                        //プレイヤー1か2か設定

    objList.push_back(obj);             // リストにobjを追加する
    return &(*objList.rbegin());        // 今追加したobjのアドレスを返す（何かで使えるように）
}
