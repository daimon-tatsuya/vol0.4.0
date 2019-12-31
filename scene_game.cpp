//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include <list>
#include "all.h"

//------< �ϐ� >----------------------------------------------------------------
int game_state;     // ���
int game_timer;     // �^�C�}�[

Player player;

//std::list<Garbage> garbageList;

//GarbageManager GarbageManager_;

// �ʂ̃t�@�C���̕ϐ����g�p����錾
extern int nextScene;

//--------------------------------
// �����ݒ�
//--------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
 
}

//--------------------------------
// �Q�[����
//--------------------------------
void game_common()
{
    if (TRG(0) & PAD_START)
    {
        nextScene = SCENE_TITLE;
    }

    bg.update();
    conveyor.update();
    player.update();
    //garbage.update();
    GarbageManager_.update();
    press_machine.update();
   
    for ( auto& it : dustBox)
    {     
        it.update();
    }

    if (TRG(0) & PAD_R1) //�S�~����
    {
        GarbageManager_.add(&garbage, VECTOR2(0, 0));
    }
}

//--------------------------------
// �X�V����
//--------------------------------
void game_update()
{
    switch (game_state)
    {
    case 0:
        //////// �����ݒ� ////////

        // �X�v���C�g�̃��[�h
        //sprite_load(&sprPlayer, L"./Data/Images/player.png");       // �v���C���[�X�v���C�g

        GameLib::setBlendMode(Blender::BS_ALPHA);

        texture::load(loadTexture);

        bg.init();

        conveyor.init();

        ber.init();

        player.init();

        //garbage.init();

        GarbageManager_.init();

        GarbageManager_.add(&garbage, VECTOR2(0, 0));

        press_machine.init();

        for (auto& it : dustBox)
        {            
            it.init();

            it.no += 263;
        }

        dustBox[0].no = 0;
        
        game_state++;
        break;

    case 1:
        //////// �ʏ펞 ////////
        game_common();

        break;
    }
    game_timer++;
}

//--------------------------------
// �`�揈��
//--------------------------------
void game_draw()
{
    // ��ʂ𔒂œh��Ԃ�
    GameLib::clear(1, 1, 1);

    bg.draw();

    conveyor.draw();

    ber.draw();

    player.draw();
    
    //���݂��Ă鎞����
    //if (garbage.exist) { garbage.draw(); }
    GarbageManager_.draw();

    press_machine.draw();

    for (auto& it : dustBox)
    {
        it.draw();
    }
}

//--------------------------------
// �I������
//--------------------------------
void game_end()
{
    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
    {
        music::stop(i);
    }

    // �X�v���C�g�̔j�� 
    //SAFE_DELETE(sprPlayer); // �v���C���[�X�v���C�g�̔j��
}
