#include "all.h"

extern int nextScene;

void PlayerUI::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:

        if (obj->type == 0) { obj->data = &sprP1; }
        if (obj->type == 1) { obj->data = &sprP2; }
        obj->color = VECTOR4(1, 1, 1, 1);
        obj->state++;
        break;

    case 1:
        
        if(nextScene == SCENE_GAME)
        {
            obj->position = player[obj->type].position;
            obj->position.y -= 160;
        }        

        break;
    }
}

void PlayerUIErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}

OBJ2D* PlayerUIManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type)// objListに新たなOBJ2Dを追加する
{
    OBJ2D obj;                          // OBJ2Dを宣言する
    obj.mvAlg = mvAlg;                  // mvAlgに引数のmvalgを代入
    obj.position = pos;                 // positionに引数のposを代入
    obj.type = type;                    //スコアの桁の種類設定   

    objList.push_back(obj);             // リストにobjを追加する
    return &(*objList.rbegin());        // 今追加したobjのアドレスを返す（何かで使えるように）
}
