#include "all.h"

void RankingNum::move(OBJ2D* obj)
{
    rankingMove(obj);
}

void RankingNumErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}

OBJ2D* RankingNumManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type, int no)// objList�ɐV����OBJ2D��ǉ�����
{
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����
    obj.type = type;                    //�X�R�A�̌��̎�ސݒ�
    obj.no = no;                        //�X�R�A�̎�ސݒ�

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}
