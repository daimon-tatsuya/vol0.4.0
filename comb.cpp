#include "all.h "

void Comb::move(OBJ2D* obj)
{
    combMove(obj);
}

void CombErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}

OBJ2D* CombManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type)
{
    OBJ2D obj;                          // OBJ2Dを宣言する
    obj.mvAlg = mvAlg;                  // mvAlgに引数のmvalgを代入
    obj.position = pos;                 // positionに引数のposを代入
    obj.type = type;                    //type設定

    objList.push_back(obj);             // リストにobjを追加する
    return &(*objList.rbegin());        // 今追加したobjのアドレスを返す（何かで使えるように）
}