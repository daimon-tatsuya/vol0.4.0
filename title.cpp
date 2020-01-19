#include "all.h"
#include "ctime"
using namespace GameLib;
using namespace system;
extern float belt;//�x���g�R���x�A�[�̋����ړ�

void Title::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case GARBAGE_INIT://�����ݒ�  
                      //�����ł��݂̗����n�ʂ����߂�
    {
        int groundPosY = rand() % 3;//�����p
        while (groundPosYKeep_Title == groundPosY)
        {
            groundPosY = rand() % 3;
        }

        switch (groundPosY)
        {
        case 0:
            obj->GROUND_POS_Y = 482.0f;//��
            break;
        case 1:
            obj->GROUND_POS_Y = 546.0f;//��
            break;
        case 2:
            obj->GROUND_POS_Y = 610.0f;//��
            break;
        }
        groundPosYKeep_Title = groundPosY;
    }
  
    obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
    obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    obj->caughtFlg = false;
    obj->speed.y = 4;
    obj->exist = true;
    obj->throwFlg = false;
    obj->no = 0;

    srand((unsigned int)time(NULL));//�������X�V����

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
  
        //���������ĂȂ��Ƃ�
        if (!obj->throwFlg&&!obj->caughtFlg)
        {
            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }
        //�x���g�R���x�A�[�̋����ړ�
            obj->speed.x = belt;
        }
      
        if (!obj->caughtFlg)//�����グ���Ă���Ƃ��v���C���[�̓���ɂ���
        {
            obj->position += obj->speed;
        }
        else if (obj->caughtFlg)
        {
            obj->position += player[obj->no].speed;
        }

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
            titleErase.erase(obj);

        }
        obj->position += obj->speed;
        break;
    }

    if (obj->position.y > SCREEN_HEIGHT)
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
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����
    obj.type = type;                    //type�ݒ�

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}
