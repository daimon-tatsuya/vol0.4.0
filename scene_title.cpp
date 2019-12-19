//******************************************************************************
//
//
//      scene_title
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

//------< �ϐ� >----------------------------------------------------------------
int title_state;    // ���
int title_timer;    // �^�C�}�[
// �t�F�[�h�A�E�g�p�ϐ��̐錾
float fadeOut;

// �ʂ̃t�@�C���̕ϐ����g�p����錾
extern int nextScene;

//--------------------------------
// �����ݒ�
//--------------------------------
void title_init()
{
    title_state = 0;
    title_timer = 0;

    // �t�F�[�h�A�E�g�p�ϐ��̏����ݒ�
    fadeOut = 0.0f;
}

//--------------------------------
// �X�V����
//--------------------------------
void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// �����ݒ� ////////

        title_state++;
        break;

    case 1:
        //////// �ʏ펞 ////////
        // �L�[���͂ŃV�[���؂�ւ�
        if (TRG(0) & PAD_START)
        {
            title_state++;
        }
        break;

    // �t�F�[�h�A�E�g�p��case 2:������
    case 2:
        //////// �t�F�[�h�A�E�g ////////
        fadeOut += 0.0167f;
        if (fadeOut >= 1.0f)
        {
            nextScene = SCENE_GAME;
        }
        break;
    }
    title_timer++;

    // �f�o�b�O�p������̐ݒ�
    //debug::setString("title_state:%d", title_state);
    //debug::setString("title_timer:%d", title_timer);
}

//--------------------------------
// �`�揈��
//--------------------------------
void title_draw()
{
    // ��ʂ����œh��Ԃ�
    GameLib::clear(0, 0, 0);

    // �����\���@�\
    font::textOut(2, "ECC COMP", 50, 100, 2, 2, 1, 1, 0);
    font::textOut(2, "Shooting Game", 40, 250, 1.3f, 1.3f, 0, 1, 1);

    // ������_�ł�����
    if (title_timer / 32 % 2)
        font::textOut(3, "Push Start", 100, 500, 3, 3);

    // �^�C�g����ʂ̃t�F�[�h�A�E�g
    if (fadeOut > 0.0f)
    {
        primitive::rect(0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT, 
            0, 0, 0, 0, 0, 0, fadeOut);
    }
}

//--------------------------------
// �I������
//--------------------------------
void title_end()
{
}
