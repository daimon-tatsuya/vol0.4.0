#include "all.h"

using namespace system;

extern float belt;//�x���g�R���x�A�[�̋����ړ�

void Fukidasi::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case GARBAGE_INIT://�����ݒ�                       
        
        obj->GROUND_POS_Y = 546.0f;//��
        obj->scale = VECTOR2(0.4f, 0.4f);
        
    // obj->animeData = animeGarbage_Large;
    //  obj->size = VECTOR2(27, 64 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
    //  obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    //obj->position = { SCREEN_WIDTH / 2,obj->GROUND_POS_Y };
    obj->data = &sprFukidasi[obj->type];

    //obj->animeData = animeGarbage_Large;
    obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
    obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);   
    obj->speed.y = 4;
    obj->exist = true;    
    obj->no = 0;

    obj->state++;
    break;

    case GARBAGE_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case GARBAGE_MOVE:
        
        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        obj->speed.x = belt;//�x���g�R���x�A�̋����ړ��B

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//��1092�̓R���x�A�[�̉E�[
        {
            obj->state++;
        }

        break;
    case GARBAGE_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &fukidasiErase;
        }
        obj->position += obj->speed;
        break;
    }


    if (obj->position.y > SCREEN_HEIGHT)
    {
        obj->eraseAlg = &garbageErase;
        if (!tutorial.nextFlag)
        {
            FukidasiManager_.add(&fukidasi, VECTOR2(400, 84), obj->type);
            if (tutorial.mode > 0) { GarbageManager_.add(&garbage, VECTOR2(653, 105), 0); }
        }
    }

}

void FukidasiErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}

OBJ2D* FukidasiManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type)
{
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����
    obj.type = type;                    //type�ݒ�

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}
