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
int game_mode = 0;
// �t�F�[�h�A�E�g�p�ϐ��̐錾
float fadeOut;
bool twoPlayMode = false;//true�̎��Q�l�v���C
bool tutorialMode = false;//true�̎��Q�l�v���C
// �ʂ̃t�@�C���̕ϐ����g�p����錾
extern int nextScene;

//--------------------------------
// �����ݒ�
//--------------------------------
void title_init()
{
    title_state = 0;
    title_timer = 0;
    game_mode = 0;
    twoPlayMode = false;
    tutorialMode = false;

    // �t�F�[�h�A�E�g�p�ϐ��̏����ݒ�
    fadeOut = 0.0f;

    texture::load(loadTexture);

    bg.init();
    conveyor.init();
    ber.init();

    press_machine.init();

    DustBoxManager_.init();

    DustBoxManager_.add(&dustBox, VECTOR2(400, 84));

    DustBoxManager_.add(&dustBox, VECTOR2(663, 84));

    DustBoxManager_.add(&dustBox, VECTOR2(926, 84));

    for ( int i = 0; i < 2; i++ )
    {
        gamemode[i].init();
    }
}

//--------------------------------
// �X�V����
//--------------------------------
void title_update()
{
    bg.update();
    conveyor.update();
    GarbageManager_.update();
    press_machine.update();
    DustBoxManager_.update();

    switch (title_state)
    {
    case 0:
        //////// �����ݒ� ////////

        twoPlayMode = false;
        title_state++;
        break;

    case 1: //�Q�[�����[�h�����߂�
       
        //1�l�v���C
        //if (TRG(0) & PAD_START)
        //{
        //    title_state = 2;
        //}
        //if (TRG(0) & PAD_UP)
        //{
        //    game_mode++;
        //    if (game_mode > 0) { game_mode = 2; }
        //}
        //else if (TRG(0) & PAD_DOWN)
        //{
        //    game_mode--;
        //    if (game_mode < 0) { game_mode = 0; }
        //}

        gamemode[0].update();
        break;
    //case 2:
    //    //�Q�l�v���C
    //    if (TRG(0) & PAD_START)
    //    {
    //        title_state = 3;
    //    }
    //    if ((TRG(0) & PAD_UP) | (TRG(0) & PAD_DOWN))
    //    {
    //        twoPlayMode = true;
    //        title_state = 1;
    //    }
    //    break;
    // �t�F�[�h�A�E�g�p��case 3:������
    case 2:
        //////// �t�F�[�h�A�E�g ////////
        fadeOut += 0.0167f;
        if (fadeOut >= 1.0f)
        {
            nextScene = SCENE_GAME;
        }

        //if (game_mode == 0) { twoPlayMode = false; tutorialMode = true;}
        //if (game_mode == 1) { twoPlayMode = false; }
        //if (game_mode == 2) { twoPlayMode = true; }

        break;
    }
    title_timer++;

    // �f�o�b�O�p������̐ݒ�
    debug::setString("TITLE_STATE:%d", game_mode);
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
    bg.draw();

    conveyor.draw();

    ber.draw();

    press_machine.draw();

    DustBoxManager_.draw();    

    for (int i = 0; i < 2; i++)
    {
        gamemode[i].draw();
    }
}

//--------------------------------
// �I������
//--------------------------------
void title_end()
{
}
