#include "all.h"
#include "ctime"
using namespace GameLib;
using namespace system;
extern float belt;//�x���g�R���x�A�[�̋����ړ�
int count = 0;



void Garbage::move(OBJ2D* obj)
{
    switch (obj->state)
    {
    case GARBAGE_INIT://�����ݒ�  
        //�����ł��݂̗����n�ʂ����߂�
    {
        int groundPosY = rand() % 3;//�����p
        while (groundPosYKeep_Garbage == groundPosY)
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
        groundPosYKeep_Garbage = groundPosY;
    }
    // obj->animeData = animeGarbage_Large;
   //  obj->size = VECTOR2(27, 64 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
   //  obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
     //obj->position = { SCREEN_WIDTH / 2,obj->GROUND_POS_Y };
    if (obj->type == 0) { obj->data = &sprGarbage_Large0; }
    if (obj->type == 1) { obj->data = &sprGarbage_Medium0; }
    if (obj->type == 2) { obj->data = &sprGarbage_Small0; }


    //obj->animeData = animeGarbage_Large;
    obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
    obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    obj->caughtFlg = false;
    obj->speed.y = 4;
    obj->exist = true;
    obj->throwFlg = false;

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
        for (int i = 0; i < 2; i++)
        {
            switch ((TRG(i) & PAD_TRG1) | (TRG(i) & PAD_TRG2))
            {
            case PAD_TRG1://�����グ

                if (rectHitCheck(obj->position - VECTOR2(32, 64), obj->size.x * 2, obj->size.y * 2, player[i].position, player[i].size.x * 2, player[i].size.y * 2) && !obj->caughtFlg && player[i].liftedCount < player[i].iWork[PLAYER::LIFTED_MAX])
                {
                    lifted(obj, i);
                }


                break;
            case PAD_TRG2://������
                if (i==obj->no)
                {
                    thrown(obj, i);
                }
               

                break;
            }
        }

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
        else if (obj->throwFlg)//�������Ă�Ƃ�
        {
            if (obj->speed.y >= 20)
            {
                obj->speed.y = 20;
            }
            else
            {
                obj->speed.y += 0.9f;
            }
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
            garbageErase.erase(obj);

        }
        obj->position += obj->speed;
        break;
    }


    if (obj->position.y > SCREEN_HEIGHT)
    {
        obj->eraseAlg = &garbageErase;
    }

    debug::setString("count:%d", count);
}



void Garbage::lifted(OBJ2D* obj, int playerType)//�����グ�邽���̃S�~�̓���
{
    obj->position = { player[playerType].position.x + (64 * -1),player[playerType].position.y - player[playerType].size.y - (40 * player[playerType].liftedCount) };
    obj->no = playerType;
    // obj->position = { player.position.x+(98*player.xFlip),player.position.y - player.size.y/*- */};
    obj->caughtFlg = true;
    player[playerType].liftedCount++;

};




void Garbage::thrown(OBJ2D* obj, int playerType) //���������̃S�~�̓���

{
    count++;

    int state_throw = 0;

    if (obj->caughtFlg)//�v���C���[�̓���ɂ���Ƃ�
    {
        switch (state_throw)
        {
        case 0:
            obj->initVelocity = { 12 * player[playerType].xFlip,2 };
            obj->speed = obj->initVelocity;
            obj->throwFlg = true;
            obj->speed.y -= 14.0f;
            obj->caughtFlg = false;
            break;
        }
    }
    player[playerType].liftedCount = 0;
};

void GarbageErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}


OBJ2D* GarbageManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type)
{
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����
    obj.type = type;                    //type�ݒ�

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}
