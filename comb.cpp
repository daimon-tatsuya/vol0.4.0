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
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����
    obj.type = type;                    //type�ݒ�

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}