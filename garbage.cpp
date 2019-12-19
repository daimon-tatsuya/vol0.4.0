#include "all.h"

using namespace GameLib;
using namespace system;
extern float belt ;//�x���g�R���x�A�[�̋����ړ�
void Garbage::init()
{
}

void Garbage::update()
{
    switch (state)
    {
    case GARBAGE_INIT://�����ݒ�
        animeData = animeGarbage_Large;
       
            state++;
        break;
    case GARBAGE_MOVE:
        switch ( (STATE(0) & PAD_TRG1) | (STATE(0) & PAD_TRG2))
        {
        case PAD_TRG1://�����グ��
            speed = { player.position.x,player.position.y - player.size.y/*- */};
            break;
        case PAD_TRG2://������
             initVelocity = { -12,2*player.xFlip };

            break;
        default://���������ĂȂ��Ƃ�
                //�x���g�R���x�A�[�̋����ړ�
            speed.x = belt;
            break;
        }
        break;
    }

    position += speed;

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
