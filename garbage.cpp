#include "all.h"

using namespace GameLib;
using namespace system;
int count = 0;

extern float belt ;//�x���g�R���x�A�[�̋����ړ�
//void Garbage::init()
//{
//    position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
//    exist = true;
//    throwFlg = false;
//}

void Garbage::move(OBJ2D* obj)
{
//    count++;

    switch (obj->state)
    {
    case GARBAGE_INIT://�����ݒ�
        obj->animeData = animeGarbage_Large;
        obj->size = VECTOR2(27, 64-2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->caughtFlg = false;

        obj->exist = true;
        obj->throwFlg = false;

        obj->state++;
        break;   

    case GARBAGE_MOVE:   
        switch ( (TRG(0) & PAD_TRG1) | (TRG(0) & PAD_TRG2))
        {
        case PAD_TRG1://�����グ

            lifted(obj);   

            break;
        case PAD_TRG2://������

            thrown(obj);
            
            break;
        default://���������ĂȂ��Ƃ�
            if (!obj->throwFlg)
            {
                if (rectHitCheck(obj->position-VECTOR2(32,64), 64, 64, VECTOR2(0,GROUND_POS_Y),SCREEN_WIDTH, SCREEN_HEIGHT))
                {
                    obj->position.y = GROUND_POS_Y;
                }

                //�x���g�R���x�A�[�̋����ړ�
                obj->speed.x = belt;
            }
            else //�������Ă�Ƃ�
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
            break;
        }
        break;
    }
    if (obj->caughtFlg)//�����グ���Ă���Ƃ��v���C���[�̓���ɂ���
    {
        obj->position = { player.position.x,player.position.y - player.size.y/*- */ };
    }
    else 
    {
        obj->position += obj->speed;
    }

    //�A�j���A�b�v�f�[�g
    if (obj->animeData)
    {
        obj->animeUpdate(obj->animeData);
    }

    if (obj->position.y > SCREEN_HEIGHT)
    {
        obj->eraseAlg = &garbageErase;
    }

    debug::setString("count:%d", count);
}

//void Garbage::draw()
//{
//    if (data)
//    { data->draw(position, scale, angle, color); }
//}

void Garbage::lifted(OBJ2D* obj)//�����グ�邽���̃S�~�̓���
{
 obj->position = { player.position.x,player.position.y - player.size.y/*- */};
 obj->caughtFlg = true;
}; 
void Garbage::thrown(OBJ2D* obj) //���������̃S�~�̓���
{
    count++;

    int state_throw = 0;
    if (obj->caughtFlg)//�v���C���[�̓���ɂ���Ƃ�
    {
        switch (state_throw)
        {
        case 0:
            obj->initVelocity = {12 * player.xFlip,2 };
            obj->speed = obj->initVelocity;
            obj->throwFlg = true;
            obj->speed.y -= 14.0f;
            obj->caughtFlg = false;
            break;
        //case 1:
        //    speed.y -= 1.0f;
        //    position += speed;

        }
    }

};

void GarbageErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}
