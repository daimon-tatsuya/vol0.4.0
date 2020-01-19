#include "all.h"

void Effect::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        if (obj->type == 0) { obj->animeData = animeEffect1; }
        if (obj->type == 1) { obj->animeData = animeEffect2; }
        obj->color = VECTOR4(1, 1, 1, 1);

        obj->state++;
        break;

    case 1:

        obj->position = player[obj->no].position;
        
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        break;
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
