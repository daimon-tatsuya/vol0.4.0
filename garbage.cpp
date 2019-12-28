#include "all.h"

using namespace GameLib;
using namespace system;
extern float belt ;//�x���g�R���x�A�[�̋����ړ�
void Garbage::init()
{
    position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
    exist = true;
    throwFlg = false;
}

void Garbage::update()
{
    /*if (rectHitCheck(position-VECTOR2(32,64), 64, 64, VECTOR2(0,GROUND_POS_Y),SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        position.y = GROUND_POS_Y;
    }*/

    switch (state)
    {
    case GARBAGE_INIT://�����ݒ�
        animeData = animeGarbage_Large;
        size = VECTOR2(27, 64-2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        caughtFlg = false;

            state++;
        break;
   

    case GARBAGE_MOVE: 
      
        switch ( (TRG(0) & PAD_TRG1) | (TRG(0) & PAD_TRG2))
        {
        case PAD_TRG1://�����グ

            lifted();   

            break;
        case PAD_TRG2://������

            thrown();
            
            break;
        default://���������ĂȂ��Ƃ�
            if (!throwFlg)
            {
                //�x���g�R���x�A�[�̋����ړ�
                speed.x = belt;
            }
            break;
        }
        break;
    }
    if (caughtFlg)//�����グ���Ă���Ƃ��v���C���[�̓���ɂ���
    {
        position = { player.position.x,player.position.y - player.size.y/*- */ };
    }
    else 
    {
        position += speed;
    }

    if (TRG(0) & PAD_L1) //L1�{�^���Ń��Z�b�g
    {
        exist = true;

        init();
    }

    //�A�j���A�b�v�f�[�g
    if (animeData)
    {
        animeUpdate(animeData);
    }
}

void Garbage::draw()
{
    if (data)
    { data->draw(position, scale, angle, color); }
}

void Garbage::lifted()//�����グ�邽���̃S�~�̓���
{
 position = { player.position.x,player.position.y - player.size.y/*- */};
 caughtFlg = true;
}; 
void Garbage::thrown() //���������̃S�~�̓���
{
    int state_throw = 0;
    if (caughtFlg)//�v���C���[�̓���ɂ���Ƃ�
    {

        switch (state_throw)
        {
        case 0:
            initVelocity = { 12 * player.xFlip,2 };
            speed = initVelocity;
            throwFlg = true;
            speed.y -= 1.0f;
            caughtFlg = false;
            break;
        //case 1:
        //    speed.y -= 1.0f;
        //    position += speed;

        }
    }

};
