#include "all.h"
#include "ctime"
using namespace GameLib;
using namespace system;
extern float belt;//�x���g�R���x�A�[�̋����ړ�
bool titleDropFlg=false;
bool titleScaleDownFlg=false;
void Title::init()
{
    //{
    //    int groundPosY = rand() % 2;//�����p
    //    while (groundPosYKeep_Title == groundPosY)
    //    {
    //        groundPosY = rand() % 2;
    //    }

    //    switch (groundPosY)
    //    {
    //    //case 0:
    //    //    GROUND_POS_Y = 482.0f;//��
    //    //    break;
    //    case 0:
    //        GROUND_POS_Y = 546.0f;//��
    //        break;
    //    case 1:
    //        GROUND_POS_Y = 610.0f;//��
    //        break;
    //    }
    //    groundPosYKeep_Title = groundPosY;
    //}
    GROUND_POS_Y = 610.0f;//��
    data = &sprTitle;
    size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
   // caughtFlg = false;
    exist = true;
   // throwFlg = false;
    no = 0;
    position.y = SCREEN_HEIGHT ;
    position.x = SCREEN_WIDTH / 2.0f;
    scale = { 0.8f,0.8f };
    srand((unsigned int)time(NULL));//�������X�V����


}
void Title::update()
{
    switch (state)
    {
    case TITLE_DROP:
        if (TRG(0)&PAD_TRG2)
        {
            //titleDropFlg = true;//�^�C�g�������Ƃ�
            titleScaleDownFlg = true;
            // speed.y = 4;
        }
        if (titleScaleDownFlg)
        {

            if (scale.x > 0.3f && scale.y > 0.3f)
            {
                scale -= {0.1f, 0.1f};
            }
            // speed.y = 4;
            if (scale.x <= 0.3f && scale.y <= 0.3f)
            {
                titleDropFlg = true;//�^�C�g�������Ƃ�
                state++;
            }
        }
        position.y += speed.y;

        if (rectHitCheck(position - VECTOR2(32, 64), 64, 64, VECTOR2(0, GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            position.y = GROUND_POS_Y;

        }

        break;

    case TITLE_MOVE:


        if (rectHitCheck(position - VECTOR2(32, 64), 64, 64, VECTOR2(0, GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            position.y = GROUND_POS_Y;
        }
        //�x���g�R���x�A�[�̋����ړ�
        speed.x = belt;

        position += speed;


        if (position.x > 1092.0f)//��1092�̓R���x�A�[�̉E�[
        {
            state++;
        }

        break;
    case TITLE_DELETE://�E�[�ŗ����Ă���

        speed.y = 3;
        speed.x = 1;

        position += speed;
        break;
    }
        //������Ƃ�
        if (position.y > SCREEN_HEIGHT + 64.0f)
        {
            position = { 0,-200 };
            state = 0;
        }
    }

void Title::draw()
{
    if (data)
    {
        data->draw(position, scale, angle, color);
    }

}

