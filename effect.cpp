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

        if (obj->type == 2) { obj->state = 2; }//���̃t���O��state�ōs���B
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
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����
    obj.type = type;                    //type�ݒ�
    obj.no = no;                        //�v���C���[1��2���ݒ�

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}
