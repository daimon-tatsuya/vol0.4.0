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
#include "pressShutter.h"

//------< �ϐ� >----------------------------------------------------------------
int game_state;     // ���
int game_timer;     // �^�C�}�[
bool pauseFlg = false;
//int result
Player player[2];
bool pause_ItiranFlg = false;

const int GAME_INIT = 0;
const int GAME_ISEN = 1;
const int GAME_UPDATE = 2;
const int GAME_DRAW = 3;

//std::list<Garbage> garbageList;
//
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
    combNum[0] = 0;
    combNum[1] = 0;
    combKeta[0] = 0;
    combKeta[1] = 0;
    timerNum = 7200;////
    timerKeta = 0;
}

//--------------------------------
// �Q�[����
//--------------------------------
void game_common()
{

    if (TRG(0) & PAD_START)
    {
        /* combNum[0] = 0;
         combNum[1] = 0;
         combKeta[0] = 0;
         combKeta[1] = 0;
         timerNum = 10800;
         timerKeta = 0;
         nextScene = SCENE_TITLE;*/
        pauseFlg = true;
    }

    bg.update();
    PlateManager_.update();
    conveyor.update();
    player[0].update();
    if (twoPlayMode)
    {
        player[1].update();
    }

    EffectManager_.update();
    GarbageManager_.update();
    press_machine.update();
    DustBoxManager_.update();

    if (!tutorialMode)//�`���[�g���A���ɓ����ĂȂ��Ƃ��B
    {
        TimerManager_.update();
        RandoManager_.update();
        ItemManager_.update();
        timerNum--;
    }
    else
    {
        tutorial.update();
        FukidasiManager_.update();
    }

    CombManager_.update();
    //    
    //if (TRG(0) & PAD_R1) //�S�~����
    //{
    //    GarbageManager_.add(&garbage, VECTOR2(0, 0), 0);
    //}
    //
    //if (TRG(0) & PAD_L1)//�A�C�e������
    //{
    //    ItemManager_.add(&item, VECTOR2(0, 0), 0);
    //}

    PlayerUIManager_.update();

    //�R���{������
    for (int i = 0; i < 2; i++)
    {
        if (combNum[i] >= 10 && combKeta[i] == 1)
        {
            if (i == 0) { CombManager_.add(&comb, VECTOR2(890, 350), i); }
            else { CombManager_.add(&comb, VECTOR2(1060, 350), i); }
        }

        if (combNum[i] >= 100 && combKeta[i] == 2)
        {
            if (i == 0) { CombManager_.add(&comb, VECTOR2(890, 350), i); }
            else { CombManager_.add(&comb, VECTOR2(1060, 350), i); }
        }
    }
}
//--------------------------------
// �|�[�Y��
//--------------------------------
void game_pause()
{
    pause[0].update();
    if (pause_ItiranFlg && (TRG(0)&PAD_TRG2))
    {
        pause_ItiranFlg = false;
        pause_state = 0;
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
        PauseCount = 0;
        // �X�v���C�g�̃��[�h
        //sprite_load(&sprPlayer, L"./Data/Images/player.png");       // �v���C���[�X�v���C�g

        GameLib::setBlendMode(Blender::BS_ALPHA);

        texture::load(loadTexture);

        bg.init();
        PlateManager_.init();
        PlateManager_.add(&plate, VECTOR2(0, 0));
        conveyor.init();
        ber.init();

        player[0].init();
        player[0].type = 0;

        if (twoPlayMode)
        {
            player[1].init();
            player[1].type = 1;
        }

        player[1].data = &sprPlayer2_Down0;

        //player[1].init();
        //player[1].type = 1;
        EffectManager_.init();
        //garbage.init();

        GarbageManager_.init();

        //GarbageManager_.add(&garbage, VECTOR2(0, 0), 0);

        press_machine.init();

        DustBoxManager_.init();

        DustBoxManager_.add(&dustBox, VECTOR2(400, 84));

        DustBoxManager_.add(&dustBox, VECTOR2(663, 84));

        DustBoxManager_.add(&dustBox, VECTOR2(926, 84));

        TimerManager_.init();

        pause[0].init();
        pause[1].init();
        pause[2].init();
        pause[3].init();
        pause[4].init();
        pause[5].init();
        if (!tutorialMode)//�`���[�g���A���ɓ����ĂȂ��Ƃ��B
        {
            TimerManager_.add(&timer, VECTOR2(640, 350));
            TimerManager_.add(&timer, VECTOR2(640, 350));
            TimerManager_.add(&timer, VECTOR2(600, 350));
        }
        else
        {
            tutorial.init();
            FukidasiManager_.init();
        }

        CombManager_.init();
        CombManager_.add(&comb, VECTOR2(890, 350), 0);
        if (twoPlayMode)
        {
            CombManager_.add(&comb, VECTOR2(1060, 350), 1);
        }

        RandoManager_.init();
        if (!tutorialMode)//�`���[�g���A���ɓ����ĂȂ��Ƃ��B
        {
            RandoManager_.add(&randomMark, VECTOR2(390, 105));
            RandoManager_.add(&randomMark, VECTOR2(653, 105));
            RandoManager_.add(&randomMark, VECTOR2(916, 105));
        }

        ItemManager_.init();

        PlayerUIManager_.init();
        PlayerUIManager_.add(&playerUI, VECTOR2(0, 0), 0);
        if (twoPlayMode) { PlayerUIManager_.add(&playerUI, VECTOR2(0, 0), 1); }
        
        shutter.init();

        game_state++;
        break;

    case 1:

        if (shutter.scrollUp()) { game_state++; }
        break;

    case 2:
        //////// �ʏ펞 ////////

        if (!pauseFlg)
        {
            pause_state = 0;//�|�[�Y�ł͂Ȃ��Ƃ���ɂO�ɂ��Ă���
            game_common();
        }

        if (pauseFlg)
        {
            game_pause();
        }
        if (timerNum < 0 && !tutorialMode)
        {
            //if (twoPlayMode) { game_state = 4; }
            //else { game_state++; }         
            game_state++;
        }
        //if (TRG(0) & PAD_L1)//�����L���O�ɔ�ԁB
        //{
        //    game_state++;
        //}

        //game_state++;
        break;

        //case 2://�����L���O�̏�����(�\�[�g�������ōs���Ă���)
        //
        //    RankingNumManager_.init();
        //    ranking.init();
        //    game_state++;
        //    break;
        //
        //case 3://�����L���O�̃A�b�v�f�[�g
        //
        //    ranking.update();
        //    RankingNumManager_.update();        
        //    break;

    case 3://�������ƃV�[���ڍs
        if (shutter.scrollDown()) { nextScene = SCENE_OVER; }

        //combNum[0] = 0;
        //combNum[1] = 0;
        //combKeta[0] = 0;
        //combKeta[1] = 0;
        //timerNum = 10800;
        //timerKeta = 0;
                
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

    PlateManager_.draw();

    if (!tutorialMode)
    {
        TimerManager_.draw();

        if (timerNum > 0 && game_state == 2) //�^�C�}�[�̃R���}
        {
            texture::begin(TEXNO::NUMBER);
            texture::draw(TEXNO::NUMBER,
                550, 350, 1.0f, 1.0f,
                64 * 12, 0, 64, 64,
                32, 32, 0,
                1.0f, 1.0f, 1.0f, 1.0f);
            texture::end(TEXNO::NUMBER);
        }
    }

    CombManager_.draw();
    if (twoPlayMode)//2�l�v���C
    {

        if (!player[0].moveUpFlg)
        {
            player[0].draw();
            player[1].draw();
            GarbageManager_.draw();
        }
        else
        {

            GarbageManager_.draw();
            player[0].draw();
            player[1].draw();
        }
    }
    else//�P�l�v���C
    {
        if (!player[0].moveUpFlg)
        {
            player[0].draw();
            GarbageManager_.draw();
        }
        else
        {
            GarbageManager_.draw();
            player[0].draw();
        }
    }
    EffectManager_.draw();

    DustBoxManager_.draw();

    if (!tutorialMode) { RandoManager_.draw(); }

    press_machine.draw();

    if (!tutorialMode)
    {
        ItemManager_.draw();
    }

    PlayerUIManager_.draw();

    if (tutorialMode)
    {
        tutorial.draw();
        FukidasiManager_.draw();
    }    

    if (pauseFlg)
    {
        pause[5].draw();//���̔w�i
        pause[0].draw();//pause
        pause[1].draw();//continue
        pause[2].draw();//item
        pause[3].draw();//title

        if (pause_ItiranFlg)
        {
            pause[4].draw();
        }
    }

    shutter.draw();

    //primitive::circle(press_machine.position.x + press_machine.size.x, press_machine.atariSize, 20, 1.0f, 0, 0, 1.0f);
}


//--------------------------------
// �I������
//--------------------------------
void game_end()
{
    for (int i = 0; i < 2; i++)
    {
        player[i].mvAlg = nullptr;
    }

    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
    {
        music::stop(i);
    }

    // �X�v���C�g�̔j�� 
    //SAFE_DELETE(sprPlayer); // �v���C���[�X�v���C�g�̔j��
}
