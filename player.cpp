#include "all.h"

using namespace GameLib;
using namespace system;

float belt = 2.0f;//�x���g�R���x�A�[�̋����ړ�


void Player::init()
{
    //position = {SCREEN_WIDTH / 2,GROUND_POS_Y};
    //scale = VECTOR2(1.0f, 1.0f);//1.0f,1.0f
    //color = VECTOR4(1, 1, 1, 1);
    //
    //state = 0;
    //inversion = 1;
    //angle =1;
    //
    //exist = TRUE; // �v���C���[�����݂��Ă���
    //
    //onGround = true;
}

void Player::update()
{
    using namespace input;
   
    animeData = nullptr;

    switch (state)
    {
    case PLAYER_INIT://�����ݒ� 1

        animeData = animePlayer_Down;

        // �T�C�Y�ݒ�i���������S�ł��邽�߁A���͂�����Ƃ��Ďg�p���锼���E�c�͂��̂܂܂������₷���j
        size = VECTOR2(24 / 2, 32 - 2);
        color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        GROUND_POS_Y = 570.0f;
        position = { SCREEN_WIDTH / 2,GROUND_POS_Y };

        if (animeData)
        {
            animeUpdate(animeData);
        }

        state++;
        break;

    case PLAYER_MOVE://����

        //�X�s�[�h�A�b�v�A�C�e�����Ƃ�������莞�ԃR���x�A�[�̃X�s�[�h�A�b�v�B
        if (player.bWork[PLAYER_STATUS::SPEEDUP] && player.timer < 360) { player.timer++; }
        else if(player.bWork[PLAYER_STATUS::SPEEDUP])
        {
            player.bWork[PLAYER_STATUS::SPEEDUP] = false;
            player.timer = 0;
            belt = 2.0f;
        }

        //�X�s�[�h�_�E���A�C�e�����Ƃ�������莞�ԃR���x�A�[�̃X�s�[�h�_�E���B
        if (player.bWork[PLAYER_STATUS::SPEEDDOWN] && player.timer < 360) {
            player.timer++; }
        else if (player.bWork[PLAYER_STATUS::SPEEDDOWN])
        {
            player.bWork[PLAYER_STATUS::SPEEDDOWN] = false;
            player.timer = 0;
            belt = 2.0f;
        }


        //�x���g�R���x�A�[�̋����ړ�
        speed = { 0,0 };
        speed.x = belt;
        
       

            if (STATE(0) & PAD_LEFT)//���ړ�
            {
                animeData = animePlayer_Left;
                speed.x += -4;
                xFlip = -1.0f;
            }
            if (STATE(0) & PAD_RIGHT)//�E�ړ�
            {
                animeData = animePlayer_Right;
                speed.x += 3;
                xFlip = 1.0f;
            }
            if (STATE(0) & PAD_UP) //��ړ�
            {
                animeData = animePlayer_Up;
                speed.y = -1;
            }
            if (STATE(0) & PAD_DOWN) //���ړ�
            {
                animeData = animePlayer_Down;
                speed.y = 1;
            }
       
            
       
        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        //�ړ�\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        
        position += speed;
       

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