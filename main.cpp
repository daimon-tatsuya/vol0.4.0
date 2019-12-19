//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

//------< �ϐ� >----------------------------------------------------------------
// �V�[���؂�ւ��p�ϐ��̐錾
int curScene;
int nextScene;

//--------------------------------
//  WinMain�i�G���g���|�C���g�j
//--------------------------------
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    // �Q�[�����C�u�����̏����ݒ�
    GameLib::init(L"�Q�[���v���O���~���O�T�@����p�ЂȌ^", 
        (int)system::SCREEN_WIDTH, (int)system::SCREEN_HEIGHT, FALSE);

    // �u�����h���[�h�̐ݒ�
    GameLib::setBlendMode(Blender::BS_ALPHA);

    // �Q�[���V�[���̐ݒ�
    curScene  = SCENE_TITLE;
    nextScene = SCENE_TITLE;

    // ���y�E���ʉ��̏����ݒ���s���֐����Ă�
    audio_init();

    // �^�C�g���̏����ݒ���s��
    title_init();

    // �Q�[�����[�v
    while (GameLib::gameLoop())
    {
        // ���͏���
        input::update();

        // �Q�[���V�[���؂�ւ�
        if (nextScene != curScene)  // ���t���[���ŃV�[���ύX�������
        {
            switch (curScene)       // ���V�[���̏I���������s��
            {
            case SCENE_TITLE:
                title_end();
                break;
            case SCENE_GAME:
                game_end();
                break;
            }
            switch (nextScene)      // ���V�[���̏����ݒ���s��
            {
            case SCENE_TITLE:
                title_init();
                break;
            case SCENE_GAME:
                game_init();
                break;
            }
            curScene = nextScene;   // ���V�[���Ɏ��V�[����������
        }

        // ���݂̃V�[���ɉ������X�V����
        switch (curScene)
        {
        case SCENE_TITLE:
            title_update();
            break;
        case SCENE_GAME:
            game_update();
            break;
        }

        // ���݂̃V�[���ɉ������`�揈��
        switch (curScene)
        {
        case SCENE_TITLE:
            title_draw();
            break;
        case SCENE_GAME:
            game_draw();
            break;
        }

        // �f�o�b�O������̕`��
        debug::display(1, 0, 0, 1, 1);
        debug::setString("GP1_PROTO_TYPE");

        // �o�b�N�o�b�t�@�̓��e��\��
        GameLib::present(1, 0);
    }

    // ���݂̃V�[���ɉ������I������
    switch (curScene)
    {
    case SCENE_TITLE:
        title_end();
        break;
    case SCENE_GAME:
        game_end();
        break;
    }

    // ���y�E���ʉ��̏I���������Ă�ł���
    audio_uninit();

    // �I������
    GameLib::uninit();

    return 0;
}

//******************************************************************************
