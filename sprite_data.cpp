//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

//------< �C���N���[�h >----------------------------------------------------------
#include "all.h"
//------< �}�N�� >--------------------------------------------------------------
#define SPRITE_LEFT(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),0,0 }      // �摜�̍��オ���S
#define SPRITE_CENTER(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)/2 }  // �摜�̐^�񒆂����S
#define SPRITE_BOTTOM(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)   }  // �摜�̑��������S
//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �f�[�^ >---------------------------------------------------------------
//player�F
//������
SpriteData sprPlayer1_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 1, 96, 128);
SpriteData sprPlayer1_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 1, 96, 128);
SpriteData sprPlayer1_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 1, 96, 128);

//�����
SpriteData sprPlayer1_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 2, 96, 128);
SpriteData sprPlayer1_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 2, 96, 128);
SpriteData sprPlayer1_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 2, 96, 128);

//������
SpriteData sprPlayer1_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 3, 96, 128);
SpriteData sprPlayer1_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 3, 96, 128);
SpriteData sprPlayer1_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 3, 96, 128);

//�E����
SpriteData sprPlayer1_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 4, 96, 128);
SpriteData sprPlayer1_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 4, 96, 128);
SpriteData sprPlayer1_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 4, 96, 128);
//�����グ�Ă���Ƃ�(�F)
//������
SpriteData sprPlayer1_Lift_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 5, 96, 128);
SpriteData sprPlayer1_Lift_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 5, 96, 128);
SpriteData sprPlayer1_Lift_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 5, 96, 128);
                     
//�����              
SpriteData sprPlayer1_Lift_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 6, 96, 128);
SpriteData sprPlayer1_Lift_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 6, 96, 128);
SpriteData sprPlayer1_Lift_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 6, 96, 128);
                     
//������              
SpriteData sprPlayer1_Lift_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 7, 96, 128);
SpriteData sprPlayer1_Lift_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 7, 96, 128);
SpriteData sprPlayer1_Lift_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 7, 96, 128);
                     
//�E����              
SpriteData sprPlayer1_Lift_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 8, 96, 128);
SpriteData sprPlayer1_Lift_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 1, 128 * 8, 96, 128);
SpriteData sprPlayer1_Lift_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 2, 128 * 8, 96, 128);

//����
SpriteData sprPlayer1_Damaged= SPRITE_BOTTOM(TEXNO::PLAYER1, 96 * 0, 128 * 10, 96, 128);

//player�l�`
//������
SpriteData sprPlayer2_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 1, 96, 128);
SpriteData sprPlayer2_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 1, 96, 128);
SpriteData sprPlayer2_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 1, 96, 128);
                   
//�����            
SpriteData sprPlayer2_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 2, 96, 128);
SpriteData sprPlayer2_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 2, 96, 128);
SpriteData sprPlayer2_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 2, 96, 128);
                  
//������           
SpriteData sprPlayer2_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 3, 96, 128);
SpriteData sprPlayer2_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 3, 96, 128);
SpriteData sprPlayer2_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 3, 96, 128);
                 
//�E����          
SpriteData sprPlayer2_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 4, 96, 128);
SpriteData sprPlayer2_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 4, 96, 128);
SpriteData sprPlayer2_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 4, 96, 128);
//�����グ�Ă���Ƃ�(�l�`)
//������
SpriteData sprPlayer2_Lift_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 5, 96, 128);
SpriteData sprPlayer2_Lift_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 5, 96, 128);
SpriteData sprPlayer2_Lift_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 5, 96, 128);
                    
//�����             
SpriteData sprPlayer2_Lift_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 6, 96, 128);
SpriteData sprPlayer2_Lift_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 6, 96, 128);
SpriteData sprPlayer2_Lift_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 6, 96, 128);
                    
//������             
SpriteData sprPlayer2_Lift_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 7, 96, 128);
SpriteData sprPlayer2_Lift_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 7, 96, 128);
SpriteData sprPlayer2_Lift_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 7, 96, 128);
                    
//�E����             
SpriteData sprPlayer2_Lift_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 8, 96, 128);
SpriteData sprPlayer2_Lift_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 1, 128 * 8, 96, 128);
SpriteData sprPlayer2_Lift_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 2, 128 * 8, 96, 128);

//����
SpriteData sprPlayer2_Damaged = SPRITE_BOTTOM(TEXNO::PLAYER2, 96 * 0, 128 * 9, 96, 128);

//�S�~
// ��^
SpriteData sprGarbage_Large0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 0, 64, 64);
// ���^
SpriteData sprGarbage_Medium0 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 0, 64, 64);
// ���^
SpriteData sprGarbage_Small0  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 0, 0, 64, 64);

SpriteData sprGarbage_Gold = SPRITE_BOTTOM(TEXNO::GOLD, 64 * 0, 0, 64, 64);

//�v���X�@
SpriteData sprPressMachine = SPRITE_BOTTOM(TEXNO::PRESS, 0, 0, 275, 610);

//�w�i
SpriteData sprBG = SPRITE_LEFT(TEXNO::BG, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//�R���x�A�[
SpriteData sprConveyor1_0 = SPRITE_LEFT(TEXNO::CONVEYOR1, system::SCREEN_WIDTH * 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor1_1 = SPRITE_LEFT(TEXNO::CONVEYOR1, system::SCREEN_WIDTH * 1, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor1_2 = SPRITE_LEFT(TEXNO::CONVEYOR1, system::SCREEN_WIDTH * 2, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

SpriteData sprConveyor2_0 = SPRITE_LEFT(TEXNO::CONVEYOR2, system::SCREEN_WIDTH * 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor2_1 = SPRITE_LEFT(TEXNO::CONVEYOR2, system::SCREEN_WIDTH * 1, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor2_2 = SPRITE_LEFT(TEXNO::CONVEYOR2, system::SCREEN_WIDTH * 2, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//��
SpriteData sprBer = SPRITE_LEFT(TEXNO::BER, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//�_�X�g�{�b�N�X
SpriteData sprDustBox = SPRITE_CENTER(TEXNO::DUSTBOX, 387, 0, 173, 171);

//����
SpriteData sprNumber0 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 0, 64, 64, 64);
SpriteData sprNumber1 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 1, 64, 64, 64);
SpriteData sprNumber2 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 2, 64, 64, 64);
SpriteData sprNumber3 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 3, 64, 64, 64);
SpriteData sprNumber4 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 4, 64, 64, 64);
SpriteData sprNumber5 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 5, 64, 64, 64);
SpriteData sprNumber6 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 6, 64, 64, 64);
SpriteData sprNumber7 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 7, 64, 64, 64);
SpriteData sprNumber8 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 8, 64, 64, 64);
SpriteData sprNumber9 = SPRITE_CENTER(TEXNO::NUMBER, 64 * 9, 64, 64, 64);

//�R���{
SpriteData sprComb[] = {
    sprNumber0,
    sprNumber1,
    sprNumber2,
    sprNumber3,
    sprNumber4,
    sprNumber5,
    sprNumber6,
    sprNumber7,
    sprNumber8,
    sprNumber9,
};

//�����_���}�[�N
SpriteData sprRandoMark[] = {
    sprGarbage_Large0,
    sprGarbage_Medium0,
    sprGarbage_Small0,
    sprGarbage_Gold,
    sprItem0,
    sprItem1,
    sprItem2,
    sprItem3,
    sprHatena,
};

//�S�~
SpriteData sprGarbage[] = {
    sprGarbage_Large0,
    sprGarbage_Medium0,
    sprGarbage_Small0,
};
//�Q�[�����[�h
SpriteData sprTitle_single   = SPRITE_CENTER(TEXNO::SINGLE,   0, 0, 1188, 648);
SpriteData sprTitle_doubles  = SPRITE_CENTER(TEXNO::DOUDLE,   0, 0, 1188, 648);
SpriteData sprTitle_tutorial = SPRITE_CENTER(TEXNO::TUTORIAL, 0, 0, 1188, 648);

//�|�[�Y��
SpriteData sprPause          = SPRITE_CENTER(TEXNO::PAUSE,     0, 0, 744,  212);
SpriteData sprPause_continue = SPRITE_CENTER(TEXNO::CONTINUE,  0, 0, 800,  144);
SpriteData sprPause_goTitle  = SPRITE_CENTER(TEXNO::GO_TITLE,  0, 0, 538,  117);
SpriteData sprPause_goItiran = SPRITE_CENTER(TEXNO::GO_ITIRAN, 0, 0, 393,  125);
SpriteData sprPause_bg       = SPRITE_CENTER(TEXNO::PAUSE_BG,  0, 0,1188,  648);
//�Q�[���I�[�o�[
SpriteData sprwin  = SPRITE_CENTER(TEXNO::WIN,  0, 0, 1188, 648);
SpriteData sprlose = SPRITE_CENTER(TEXNO::LOSE, 0, 0, 1188, 648);
//�^�C�g��
//SpriteData sprTitle=SPRITE_BOTTOM(TEXNO::TITLE,,,,);
//SpriteData sprTitle[] =
//{ };

//�A�C�e��
SpriteData sprItem0 = SPRITE_BOTTOM(TEXNO::ITEM,  64 * 0, 128, 64, 64);
SpriteData sprItem1 = SPRITE_BOTTOM(TEXNO::ITEM,  64 * 0, 192, 64, 64);
SpriteData sprItem2 = SPRITE_BOTTOM(TEXNO::ITEM,  64 * 0, 64, 64, 64);
SpriteData sprItem3 = SPRITE_BOTTOM(TEXNO::ITEM2, 64 * 0,  0, 64, 64);

//�͂Ăȃ}�[�N
SpriteData sprHatena = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 3, 0, 64, 64);

//�G�t�F�N�g
SpriteData sprEffect1_1 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 0, 0,   96, 128);
SpriteData sprEffect1_2 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 1, 0,   96, 128);
SpriteData sprEffect2_1 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 0, 128, 96, 128);
SpriteData sprEffect2_2 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 1, 128, 96, 128);

//�v���[�g
SpriteData sprPlate1 = SPRITE_LEFT(TEXNO::PLATE1, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//�����o��
SpriteData sprFukidasi1 = SPRITE_BOTTOM(TEXNO::FUKIDASI, 600 * 0, 0, 600, 277);
SpriteData sprFukidasi2 = SPRITE_BOTTOM(TEXNO::FUKIDASI, 600 * 1, 0, 600, 277);
SpriteData sprFukidasi3 = SPRITE_BOTTOM(TEXNO::FUKIDASI, 600 * 2, 0, 600, 277);

//�A�C�e���ꗗ
SpriteData sprItiran = SPRITE_LEFT(TEXNO::ITIRAN, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprpause_itiran = SPRITE_CENTER(TEXNO::ITIRAN, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//���G�t�F�N�g
SpriteData sprKemuri1 = SPRITE_BOTTOM(TEXNO::KEMURI, 64 * 0, 0, 64, 64);
SpriteData sprKemuri2 = SPRITE_BOTTOM(TEXNO::KEMURI, 64 * 1, 0, 64, 64);
SpriteData sprKemuri3 = SPRITE_BOTTOM(TEXNO::KEMURI, 64 * 2, 0, 64, 64);

SpriteData sprFukidasi[] = {
    sprFukidasi1,
    sprFukidasi2,
    sprFukidasi3,
};

//******************************************************************************
// 2D�摜���[�h�f�[�^
LoadTexture loadTexture[] = {
    { TEXNO::PLAYER1,       L"./Data/Images/player1.png",         1U },// �v���C���[
    { TEXNO::PLAYER2,       L"./Data/Images/player2.png",         1U },// �v���C���[
    { TEXNO::GARBAGE,       L"./Data/Images/item.png",            1U },//�S�~
    { TEXNO::GOLD,          L"./Data/Images/golden wheel.png",    1U },//�S�~
    { TEXNO::PRESS,         L"./Data/Images/obj_puresu.png",      1U },//�v���X�@
    { TEXNO::BG,            L"./Data/Images/wall.png",            1U },//�w�i
    { TEXNO::CONVEYOR1,     L"./Data/Images/berutokonbea.png",    1U },//�R���x�A�[
    { TEXNO::CONVEYOR2,     L"./Data/Images/berutokonbea2.png",   1U },//�R���x�A�[
    { TEXNO::BER,           L"./Data/Images/obj_saku.png",        1U },//��
    { TEXNO::DUSTBOX,       L"./Data/Images/obj_dakuto.png",      1U },//�_�X�g�{�b�N�X
    { TEXNO::NUMBER,        L"./Data/Images/font.png",            1U },//����
    { TEXNO::ITEM,          L"./Data/Images/item.png",            1U },//�A�C�e��
    { TEXNO::ITEM2,         L"./Data/Images/treasure box.png",    1U },//�A�C�e��
    { TEXNO::FUKIDASI,      L"./Data/Images/hukidasi.png",        1U },//�����o��
    { TEXNO::ITIRAN ,       L"./Data/Images/item_itiran.png",     1U },//�ꗗ
    //{ TEXNO::TITLE,         L"./Data/Images/title.png",           1U },//�^�C�g��
    { TEXNO::SINGLE ,       L"./Data/Images/single.png",          1U },//�P�l���[�h
    { TEXNO::DOUDLE,        L"./Data/Images/doubles.png",         1U },//2�l���[�h
    { TEXNO::ITEM2,         L"./Data/Images/treasure box.png",    1U },
    { TEXNO::PLATE1,        L"./Data/Images/plate.png",           1U },
    { TEXNO::EFFECT,        L"./Data/Images/buff_ef.png",         1U },
    { TEXNO::PAUSE,         L"./Data/Images/pause_pause.png",     1U },
    { TEXNO::GO_TITLE,      L"./Data/Images/pause_title.png",     1U },
    { TEXNO::CONTINUE,      L"./Data/Images/pause_continue.png",  1U },
    { TEXNO::TUTORIAL,      L"./Data/Images/tutorial.png",        1U },
    { TEXNO::GO_ITIRAN,     L"./Data/Images/pause_item.png",      1U },
    { TEXNO::WIN,           L"./Data/Images/win.png",             1U },
    { TEXNO::LOSE,          L"./Data/Images/lose.png",            1U },
    { TEXNO::KEMURI,        L"./Data/Images/efe_1.png",           1U },//���G�t�F�N�g    
    { TEXNO::PAUSE_BG,      L"./Data/Images/pause_bg.png",        1U },
    { -1, nullptr }	// �I���t���O
};



//------< �v���C���[ >----------------------------------------------------------
//�F�̃A�j��
//�����
AnimeData animePlayer1_Up[] = {
    { &sprPlayer1_Up0, 10 },
    { &sprPlayer1_Up1, 10 },
    { &sprPlayer1_Up2, 10 },
    { &sprPlayer1_Up1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�E����
AnimeData animePlayer1_Right[] = {
    { &sprPlayer1_Right0, 10 },
    { &sprPlayer1_Right1, 10 },
    { &sprPlayer1_Right2, 10 },
    { &sprPlayer1_Right1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer1_Down[] = {
    { &sprPlayer1_Down0, 10 },
    { &sprPlayer1_Down1, 10 },
    { &sprPlayer1_Down2, 10 },
    { &sprPlayer1_Down1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer1_Left[] = {
    { &sprPlayer1_Left0, 10 },
    { &sprPlayer1_Left1, 10 },
    { &sprPlayer1_Left2, 10 },
    { &sprPlayer1_Left1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�����グ�Ă���Ƃ�(�F)
//�����
AnimeData animePlayer1_Lift_Up[] = {
    { &sprPlayer1_Lift_Up0, 10 },
    { &sprPlayer1_Lift_Up1, 10 },
    { &sprPlayer1_Lift_Up2, 10 },
    { &sprPlayer1_Lift_Up1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�E����
AnimeData animePlayer1_Lift_Right[] = {
    { &sprPlayer1_Lift_Right0, 10 },
    { &sprPlayer1_Lift_Right1, 10 },
    { &sprPlayer1_Lift_Right2, 10 },
    { &sprPlayer1_Lift_Right1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer1_Lift_Down[] = {
    { &sprPlayer1_Lift_Down0, 10 },
    { &sprPlayer1_Lift_Down1, 10 },
    { &sprPlayer1_Lift_Down2, 10 },
    { &sprPlayer1_Lift_Down1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer1_Lift_Left[] = {
    { &sprPlayer1_Lift_Left0, 10 },
    { &sprPlayer1_Lift_Left1, 10 },
    { &sprPlayer1_Lift_Left2, 10 },
    { &sprPlayer1_Lift_Left1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�l�`�̃A�j��
//�����
AnimeData animePlayer2_Up[] = {
    { &sprPlayer2_Up0, 10 },
    { &sprPlayer2_Up1, 10 },
    { &sprPlayer2_Up2, 10 },
    { &sprPlayer2_Up1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�E����
AnimeData animePlayer2_Right[] = {
    { &sprPlayer2_Right0, 10 },
    { &sprPlayer2_Right1, 10 },
    { &sprPlayer2_Right2, 10 },
    { &sprPlayer2_Right1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer2_Down[] = {
    { &sprPlayer2_Down0, 10 },
    { &sprPlayer2_Down1, 10 },
    { &sprPlayer2_Down2, 10 },
    { &sprPlayer2_Down1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer2_Left[] = {
    { &sprPlayer2_Left0, 10 },
    { &sprPlayer2_Left1, 10 },
    { &sprPlayer2_Left2, 10 },
    { &sprPlayer2_Left1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�����グ�Ă���Ƃ�(�F)
//�����
AnimeData animePlayer2_Lift_Up[] = {
    { &sprPlayer2_Lift_Up0, 10 },
    { &sprPlayer2_Lift_Up1, 10 },
    { &sprPlayer2_Lift_Up2, 10 },
    { &sprPlayer2_Lift_Up1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�E����
AnimeData animePlayer2_Lift_Right[] = {
    { &sprPlayer2_Lift_Right0, 10 },
    { &sprPlayer2_Lift_Right1, 10 },
    { &sprPlayer2_Lift_Right2, 10 },
    { &sprPlayer2_Lift_Right1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer2_Lift_Down[] = {
    { &sprPlayer2_Lift_Down0, 10 },
    { &sprPlayer2_Lift_Down1, 10 },
    { &sprPlayer2_Lift_Down2, 10 },
    { &sprPlayer2_Lift_Down1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer2_Lift_Left[] = {
    { &sprPlayer2_Lift_Left0, 10 },
    { &sprPlayer2_Lift_Left1, 10 },
    { &sprPlayer2_Lift_Left2, 10 },
    { &sprPlayer2_Lift_Left1, 10 },
    { nullptr, -1 },// �I���t���O
};
//����
//���������Ԃŏ��Ԃɏo���ꍇ�b����0����\������B

AnimeData animeTimer1[] =
{
    { &sprNumber0,60 },
    { &sprNumber9,60 },
    { &sprNumber8,60 },
    { &sprNumber7,60 },
    { &sprNumber6,60 },
    { &sprNumber5,60 },
    { &sprNumber4,60 },
    { &sprNumber3,60 },
    { &sprNumber2,60 },
    { &sprNumber1,60 },
    { nullptr, -1 },// �I���t���O
};

AnimeData animeTimer10[] =
{
    { &sprNumber0,60 },
    { &sprNumber5,600 },
    { &sprNumber4,600 },
    { &sprNumber3,600 },
    { &sprNumber2,600 },
    { &sprNumber1,600 },
    { &sprNumber0,540 }, //�Ō�10�̒P�ʂ�0�ɂȂ�������1�b�������Z������B
    { nullptr, -1 },// �I���t���O
};

AnimeData animeTimer100[] =
{    
    { &sprNumber2,60 }, //�ŏ�����1�b��    
    { &sprNumber1,3600 },
    { &sprNumber0,3600 },
    { nullptr, -1 },// �I���t���O
};

AnimeData* animeTimer[] =
{
    animeTimer1,
    animeTimer10,
    animeTimer100,
};

//�����_���}�[�N
AnimeData animeRandoMark[] =
{
    { &sprGarbage_Large0, 20 },
    { &sprGarbage_Medium0, 20 },
    { &sprGarbage_Small0, 20 },
    { &sprGarbage_Gold, 20 },
    { &sprItem0, 20 },
    { &sprItem1, 20 },
    { &sprItem2, 20 },
    { &sprItem3, 20 },
    { &sprHatena, 20 },
    { nullptr, -1 },// �I���t���O
};

//�x���g�R���x�A
AnimeData animeConveyor1[] = {
    { &sprConveyor1_0, 10},
    { &sprConveyor1_1, 10 },
    { &sprConveyor1_2, 10 },
    { nullptr, -1 },// �I���t���O
};

AnimeData animeConveyor2[] = {
    { &sprConveyor2_0, 10 },
    { &sprConveyor2_1, 10 },
    { &sprConveyor2_2, 10 },
    { nullptr, -1 },// �I���t���O
};

AnimeData* animeConveyor[] = {
    animeConveyor1,
    animeConveyor2,
};

//�G�t�F�N�g
AnimeData animeEffect1[] = {
    { &sprEffect1_1, 10 },
    { &sprEffect1_2, 10 },    
    { nullptr, -1 },// �I���t���O
};

AnimeData animeEffect2[] = {
    { &sprEffect2_1, 10 },
    { &sprEffect2_2, 10 },
    { nullptr, -1 },// �I���t���O
};

AnimeData animeKemuri[] = {
    { &sprKemuri1, 10 },
    { &sprKemuri2, 10 },
    { &sprKemuri3, 10 },
    { nullptr, 10 },// �I���t���O
    { nullptr, -1 },// �I���t���O
};

AnimeData* animeEffect[] = {
    animeEffect1,
    animeEffect2,
    animeKemuri,
};
//
AnimeData*animePlayer[2][8]=
{     //�ʏ�     0             1               2                 3                  //�S�~��������      4               5                      6                7
    { animePlayer1_Down,animePlayer1_Up,animePlayer1_Left,animePlayer1_Right,       animePlayer1_Lift_Down,animePlayer1_Lift_Up,animePlayer1_Lift_Left,animePlayer1_Lift_Right},
    { animePlayer2_Down,animePlayer2_Up,animePlayer2_Left,animePlayer2_Right,       animePlayer2_Lift_Down,animePlayer2_Lift_Up,animePlayer2_Lift_Left,animePlayer2_Lift_Right},
};

