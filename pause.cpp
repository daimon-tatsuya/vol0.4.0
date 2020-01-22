#include "all.h"

using namespace system;
int PauseCount = 0;
int pause_state = 0;
extern int nextScene;

void Pause::init()
{
    pause[0].data = &sprPause;
    pause[0].position.x = (SCREEN_WIDTH / 2.0f);
    pause[0].position.y = 90.0f;
    pause[0].scale = { 0.8f, 0.8f };

    pause[1].data = &sprPause_continue;
    pause[1].position.x = (SCREEN_WIDTH / 2.0f);
    pause[1].position.y = 220.0f;
    pause[1].scale = { 0.75f,0.75f };

    pause[2].data = &sprPause_goItiran;
    pause[2].position.x = (SCREEN_WIDTH / 2.0f);
    pause[2].position.y = 350.0f;
    pause[2].scale = { 0.45f,0.45f };

    pause[3].data = &sprPause_goTitle;
    pause[3].position.x = (SCREEN_WIDTH / 2.0f);
    pause[3].position.y = 480.0f; 
    pause[3].scale = { 0.45f,0.45f };

    pause[4].data = &sprpause_itiran;
    pause[4].position.x = (SCREEN_WIDTH  / 2.0f);
    pause[4].position.y = (SCREEN_HEIGHT / 2.0f);
    pause[4].scale = { 1.0f,1.0f };

    pause[5].data = &sprPause_bg;
    pause[5].position.x = (SCREEN_WIDTH / 2.0f);
    pause[5].position.y = (SCREEN_HEIGHT / 2.0f);
    pause[5].scale = { 1.0f,1.0f };
    size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    exist = true;
    no = 0;
}
void Pause::update()
{
    switch (pause_state)
    {

    case 0:
      
        if (TRG(0) &  PAD_UP)
        {
            PauseCount--;
        }

        if (TRG(0) &PAD_DOWN)
        {
            PauseCount++;
        }

        if (PauseCount < 0)
        {
            PauseCount = 0;
        }
        if (PauseCount > 2)
        {
            PauseCount = 2;
        }
        if (TRG(0)& PAD_TRG2)//����
        {
            pause_state++;
        }
        if (PauseCount == 0)//�Q�[���𑱂���
        {
            pause[1].scale = { 0.75f,0.75f };
            pause[2].scale = { 0.45f,0.45f };
            pause[3].scale = { 0.45f,0.45f };
        }
//
//<<<<<<< HEAD
//    if (PauseCount == 0)
//    {        
//        pause[0].scale = { 0.75f,0.75f };
//        pause[1].scale = { 0.45f,0.45f };
//        pause[2].scale = { 0.45f,0.45f };
//    }
//=======
        if (PauseCount == 1)//�A�C�e���ꗗ
        {
            pause[1].scale = { 0.45f,0.45f };
            pause[2].scale = { 0.75f,0.75f };
            pause[3].scale = { 0.45f,0.45f };
        }
//>>>>>>> cdbd4dbf8d9a727bcaa944d248d7886330721de7

        if (PauseCount == 2)//�^�C�g���֌������@
        {
            pause[1].scale = { 0.45f,0.45f };
            pause[2].scale = { 0.45f,0.45f };
            pause[3].scale = { 0.75f,0.75f };
        }
        break;
    case 1:
        if (PauseCount == 0)//�Q�[���𑱂���
        {
            pauseFlg = false;
            pause_state = 0;
            pause[1].scale = { 0.75f,0.75f };
            pause[2].scale = { 0.45f,0.45f };
            pause[3].scale = { 0.45f,0.45f };
           
        }

        if (PauseCount == 1)//�A�C�e���ꗗ
        {
            pause_ItiranFlg = true;
            pause[1].scale = { 0.45f,0.45f };
            pause[2].scale = { 0.75f,0.75f };
            pause[3].scale = { 0.45f,0.45f };
        }

        if (PauseCount == 2)//�^�C�g���֌������@
        {
            nextScene = SCENE_TITLE;
            pause[1].scale = { 0.45f,0.45f };
            pause[2].scale = { 0.45f,0.45f };
            pause[3].scale = { 0.75f,0.75f };
        }
        break;
   //case 1:

    }
}
void Pause::draw()
{
    if (data)
    {
        data->draw(position, scale, angle, color);
    }
}