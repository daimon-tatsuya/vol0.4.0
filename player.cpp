#include "all.h"

using namespace GameLib;
using namespace system;

float belt = 2.0f;//�x���g�R���x�A�[�̋����ړ�

float deltaY = 0;

void Player::init()
{
    animeData = animePlayer[type][0];

    exist = true;

    // �T�C�Y�ݒ�i���������S�ł��邽�߁A���͂�����Ƃ��Ďg�p���锼���E�c�͂��̂܂܂������₷���j
    size = VECTOR2(24 / 2, 32 - 2);
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    GROUND_POS_Y = 570.0f;
    speed = VECTOR2(0, 0);
    player[0].position = { SCREEN_WIDTH / 2 , 410.0f };
    player[1].position = { SCREEN_WIDTH / 2 , 570.0f };
    iWork[PLAYER::CONVETIMER] = 0;
    iWork[PLAYER::ITEMADDTIMER] = 0;
    iWork[PLAYER::POWERTIMER] = 0;
    iWork[PLAYER::SPEEDTIMER] = 0;
    iWork[PLAYER::LIFTED_MAX] = 3;
    bWork[PLAYER_STATUS::CONVEYORUP] = false;
    bWork[PLAYER_STATUS::ITEMADD] = false;
    bWork[PLAYER_STATUS::POWERUP] = false;
    bWork[PLAYER_STATUS::SPEEDUP] = false;
    itemSpeed = 0;
    belt = 2.0f;

    if (animeData)
    {
        animeUpdate(animeData);
    }
}

void Player::update()
{
    using namespace input;
   
    animeData = nullptr;

    switch (state)
    {
    case PLAYER_INIT://�����ݒ� 1

        animeData = animePlayer[type][0];
      
        // �T�C�Y�ݒ�i���������S�ł��邽�߁A���͂�����Ƃ��Ďg�p���锼���E�c�͂��̂܂܂������₷���j
        size = VECTOR2(24 / 2, 32 - 2);
        color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        GROUND_POS_Y = 570.0f;
        speed = VECTOR2(0, 0);
        player[0].position = { SCREEN_WIDTH / 2 , 410.0f };
        player[1].position = { SCREEN_WIDTH / 2 , 570.0f };
        iWork[PLAYER::CONVETIMER]   = 0;
        iWork[PLAYER::ITEMADDTIMER] = 0;
        iWork[PLAYER::POWERTIMER]   = 0;
        iWork[PLAYER::SPEEDTIMER]   = 0;
        iWork[PLAYER::LIFTED_MAX]   = 3;
        bWork[PLAYER_STATUS::CONVEYORUP] = false;
        bWork[PLAYER_STATUS::ITEMADD]    = false;
        bWork[PLAYER_STATUS::POWERUP]    = false;
        bWork[PLAYER_STATUS::SPEEDUP]    = false;
        itemSpeed = 0;
        belt = 2.0f;

        if (animeData)
        {
            animeUpdate(animeData);
        }

        state++;
        break;

    case PLAYER_MOVE://����        

        //�X�s�[�h�A�b�v�A�C�e�����Ƃ�������莞�ԃR���x�A�[�̃X�s�[�h�A�b�v�B
        if (player[type].bWork[PLAYER_STATUS::CONVEYORUP] && player[type].iWork[PLAYER::CONVETIMER] < 360) { player[type].iWork[PLAYER::CONVETIMER]++; }
        else if(player[type].bWork[PLAYER_STATUS::CONVEYORUP])
        {
            player[type].bWork[PLAYER_STATUS::CONVEYORUP] = false;
            conveyor.animeData = animeConveyor[0];
            player[type].iWork[PLAYER::CONVETIMER] = 0;
            belt = 2.0f;
        }

        //���̃X�s�[�h�A�b�v�A�C�e�����Ƃ�������莞�ԃv���C���[�̃X�s�[�h�A�b�v�B
        if (player[type].bWork[PLAYER_STATUS::SPEEDUP] && player[type].iWork[PLAYER::SPEEDTIMER] < 360)
        {
            player[type].iWork[PLAYER::SPEEDTIMER]++;
            player[type].itemSpeed = 2;
        }
        else if (player[type].bWork[PLAYER_STATUS::SPEEDUP])
        {
            player[type].bWork[PLAYER_STATUS::SPEEDUP] = false;
            player[type].itemSpeed = 0;
            player[type].iWork[PLAYER::SPEEDTIMER] = 0;
            for ( auto& efe : *EffectManager_.getList() )
            {
                if (efe.exist && efe.type == 1)
                {
                    efe.eraseAlg = &effectErase;
                    break;
                }
            }
        }

        //��莞�Ԏ��Ă�ʑ��₷
        if (player[type].bWork[PLAYER_STATUS::POWERUP] && player[type].iWork[PLAYER::POWERTIMER] < 720)
        {
            player[type].iWork[PLAYER::POWERTIMER]++;
        }
        else if (player[type].bWork[PLAYER_STATUS::POWERUP])
        {
            player[type].bWork[PLAYER_STATUS::POWERUP] = false;
            player[type].iWork[PLAYER::LIFTED_MAX] = 3;
            player[type].iWork[PLAYER::POWERTIMER] = 0;
            for (auto& efe : *EffectManager_.getList())
            {
                if (efe.exist && efe.type == 0)
                {
                    efe.eraseAlg = &effectErase;
                    break;
                }
            }
        }

        //��莞�ԃA�C�e���o���ʃA�b�v
        if (player[type].bWork[PLAYER_STATUS::ITEMADD] && player[type].iWork[PLAYER::ITEMADDTIMER] < 600)
        {
            player[type].iWork[PLAYER::ITEMADDTIMER]++;
        }
        else if (player[type].bWork[PLAYER_STATUS::ITEMADD])
        {
            player[type].bWork[PLAYER_STATUS::ITEMADD] = false;            
            player[type].iWork[PLAYER::ITEMADDTIMER] = 0;

            for (auto& it : *RandoManager_.getList())
            {
                it.iWork[RandoManager::RandoMark::TIMER_MAX1] = 180;
                it.iWork[RandoManager::RandoMark::TIMER_MAX2] = 240;
            }
        }


        //�x���g�R���x�A�[�̋����ړ�
        speed.y = 0;
        speed.x = belt;
               

            if (STATE(type) & PAD_LEFT)//���ړ�
            {
                player[type].animeData = animePlayer[type][2];
                speed.x += -4 - itemSpeed;
                player[type].xFlip = -1.0f;
            }
            if (STATE(type) & PAD_RIGHT)//�E�ړ�
            {
                player[type].animeData = animePlayer[type][3];
                speed.x += 3 + itemSpeed;
                player[type].xFlip = 1.0f;
            }
            if (STATE(type) & PAD_UP) //��ړ�
            {
                player[type].animeData = animePlayer[type][1];
                speed.y += -1 - itemSpeed;
            }
            if (STATE(type) & PAD_DOWN) //���ړ�
            {
                player[type].animeData = animePlayer[type][0];
                speed.y = 1 + itemSpeed;
            }
       
            
       
        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        //�ړ�\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        
        position += speed;
       
        if (delta.y < position.y)
        {
            scale += VECTOR2(0.001f, 0.001f);
            if (scale.x >= 1)
            {
                scale = VECTOR2(1, 1);
            }
        }
        else if (delta.y > position.y)
        {
            scale -= VECTOR2(0.001f, 0.001f);
            if (scale.x <= 0.8f)
            {
                scale = VECTOR2(0.8f, 0.8f);
            }
        }

        delta.y = position.y;
        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        ////�W�����v\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

        //if (onGround && TRG(0)&PAD_TRG3)
        //{
        //    jumpTimer = 10;
        //}
        //if (jumpTimer > 0)
        //{
        //    if (STATE(0) & PAD_TRG3)
        //    {
        //        speed.y += jump;
        //        jumpTimer -= 1;
        //    }
        //}
        //else
        //{
        //    jumpTimer = 0;
        //}

        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        //�ړ�����\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        
        if (position.x < 330)
        {
            position.x = 330;
            speed.x = 0;
        }

        if (position.x > system::SCREEN_WIDTH - (size.x*8.0f)/* / 2*/)
        {
            position.x = system::SCREEN_WIDTH - (size.x*8.0f) /*/ 2*/;
            speed.x = 0;
        }

        if (position.y < 432)
        {
            position.y = 432;
            speed.y = 0;
        }

        if (position.y > 610)
        {
            position.y = 610;
            speed.y = 0;
        }
        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
      
        break;

    }
    //�A�j���A�b�v�f�[�g
    if (animeData)
    { animeUpdate(animeData); }

}
     


void Player::draw()
{
    if (data)
    { data->draw(position, scale, angle, color); }

}