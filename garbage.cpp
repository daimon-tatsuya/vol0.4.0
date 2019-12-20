#include "all.h"

using namespace GameLib;
using namespace system;
extern float belt ;//�x���g�R���x�A�[�̋����ړ�
void Garbage::init()
{
    position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
    exist = true;
}

void Garbage::update()
{
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
        switch ( (STATE(0) & PAD_TRG1) | (STATE(0) & PAD_TRG2))
        {
        case PAD_TRG1://�����グ��

            position = { player.position.x,player.position.y - player.size.y/*- */};
            caughtFlg = true;
            break;
        case PAD_TRG2://������
            if (caughtFlg)
            {
                initVelocity = { 12* player.xFlip,2  };
                speed = initVelocity;
                caughtFlg = false;
            }
            
            break;
        default://���������ĂȂ��Ƃ�
                //�x���g�R���x�A�[�̋����ړ�
            speed.x = belt;
            break;
        }
        break;
    }
    if (caughtFlg)
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
