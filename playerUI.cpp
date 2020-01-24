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

OBJ2D* PlayerUIManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type)// objList�ɐV����OBJ2D��ǉ�����
{
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����
    obj.type = type;                    //�X�R�A�̌��̎�ސݒ�   

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}
