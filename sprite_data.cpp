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
//������
SpriteData sprPlayer_Down0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 1, 96, 128);
SpriteData sprPlayer_Down1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 1, 96, 128);
SpriteData sprPlayer_Down2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 1, 96, 128);

//�����
SpriteData sprPlayer_Up0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 2, 96, 128);
SpriteData sprPlayer_Up1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 2, 96, 128);
SpriteData sprPlayer_Up2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 2, 96, 128);

//������
SpriteData sprPlayer_Left0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 3, 96, 128);
SpriteData sprPlayer_Left1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 3, 96, 128);
SpriteData sprPlayer_Left2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 3, 96, 128);

//�E����
SpriteData sprPlayer_Right0 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 0, 128 * 4, 96, 128);
SpriteData sprPlayer_Right1 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 1, 128 * 4, 96, 128);
SpriteData sprPlayer_Right2 = SPRITE_BOTTOM(TEXNO::PLAYER, 96 * 2, 128 * 4, 96, 128);

////��^
//SpriteData sprGarbage_Large0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 192 * 0, 0, 192, 192);
//SpriteData sprGarbage_Large1  = SPRITE_BOTTOM(TEXNO::GARBAGE, 192 * 1, 0, 192, 192);
//SpriteData sprGarbage_Large2  = SPRITE_BOTTOM(TEXNO::GARBAGE, 192 * 2, 0, 192, 192);
////���^
//SpriteData sprGarbage_Medium0 = SPRITE_BOTTOM(TEXNO::GARBAGE, 128 * 0, 192 , 128, 128);
//SpriteData sprGarbage_Medium1 = SPRITE_BOTTOM(TEXNO::GARBAGE, 128 * 1, 192 , 128, 128);
//SpriteData sprGarbage_Medium2 = SPRITE_BOTTOM(TEXNO::GARBAGE, 128 * 2, 192 , 128, 128);
////���^
//SpriteData sprGarbage_Small0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 320 * 0, 320 , 64, 64);
//SpriteData sprGarbage_Small1  = SPRITE_BOTTOM(TEXNO::GARBAGE, 320 * 1, 320 , 64, 64);
//SpriteData sprGarbage_Small2  = SPRITE_BOTTOM(TEXNO::GARBAGE, 320 * 2, 320 , 64, 64);
//��^
SpriteData sprGarbage_Large0  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 0, 64, 64);
//SpriteData sprGarbage_Large1  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 0, 64, 64);
//SpriteData sprGarbage_Large2  = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 0, 64, 64);
//���^
SpriteData sprGarbage_Medium0 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 0, 64, 64);
//SpriteData sprGarbage_Medium1 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 1, 192, 64, 64);
//SpriteData sprGarbage_Medium2 = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 2, 192 ,64, 64);
//���^
SpriteData sprGarbage_Small0  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 0, 0, 64, 64);
//SpriteData sprGarbage_Small1  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 1, 128, 64, 64);
//SpriteData sprGarbage_Small2  = SPRITE_BOTTOM(TEXNO::GARBAGE,  64 * 2 ,128, 64, 64);

SpriteData sprGarbage_Gold = SPRITE_BOTTOM(TEXNO::GOLD, 64 * 0, 0, 64, 64);

//�v���X�@
SpriteData sprPressMachine = SPRITE_BOTTOM(TEXNO::PRESS, 0, 0, 275, 610);

//�w�i
SpriteData sprBG = SPRITE_LEFT(TEXNO::BG, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//�R���x�A�[
SpriteData sprConveyor0 = SPRITE_LEFT(TEXNO::CONVEYOR, system::SCREEN_WIDTH * 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor1 = SPRITE_LEFT(TEXNO::CONVEYOR, system::SCREEN_WIDTH * 1, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);
SpriteData sprConveyor2 = SPRITE_LEFT(TEXNO::CONVEYOR, system::SCREEN_WIDTH * 2, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);


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

//�A�C�e��
SpriteData sprItem0 = SPRITE_BOTTOM(TEXNO::ITEM, 64 * 0, 128, 64, 64);
SpriteData sprItem1 = SPRITE_BOTTOM(TEXNO::ITEM, 64 * 0, 192, 64, 64);
SpriteData sprItem2 = SPRITE_BOTTOM(TEXNO::ITEM, 64 * 0, 64, 64, 64);
SpriteData sprItem3 = SPRITE_BOTTOM(TEXNO::ITEM2, 64 * 0,  0, 64, 64);

//�͂Ăȃ}�[�N
SpriteData sprHatena = SPRITE_BOTTOM(TEXNO::GARBAGE, 64 * 3, 0, 64, 64);

//�G�t�F�N�g
SpriteData sprEffect1_1 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 0, 0, 96, 128);
SpriteData sprEffect1_2 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 1, 0, 96, 128);
SpriteData sprEffect2_1 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 0, 128, 96, 128);
SpriteData sprEffect2_2 = SPRITE_BOTTOM(TEXNO::EFFECT, 96 * 1, 128, 96, 128);

//�v���[�g
SpriteData sprPlate1 = SPRITE_LEFT(TEXNO::PLATE1, 0, 0, system::SCREEN_WIDTH, system::SCREEN_HEIGHT);

//******************************************************************************
// 2D�摜���[�h�f�[�^
LoadTexture loadTexture[] = {
    { TEXNO::PLAYER,        L"./Data/Images/player.png",          1U },// �v���C���[
    { TEXNO::GARBAGE,       L"./Data/Images/item.png",          256U },//�S�~
    { TEXNO::GOLD,          L"./Data/Images/golden wheel.png",    1U },//�S�~
    { TEXNO::PRESS,         L"./Data/Images/obj_puresu.png",      1U },//�v���X�@
    { TEXNO::BG,            L"./Data/Images/wall.png",            1U },//�w�i
    { TEXNO::CONVEYOR,      L"./Data/Images/berutokonbea.png",    1U },//�R���x�A�[
    { TEXNO::BER,           L"./Data/Images/obj_saku.png",        1U },//��
    { TEXNO::DUSTBOX,       L"./Data/Images/obj_dakuto.png",      1U },//�_�X�g�{�b�N�X
    { TEXNO::NUMBER,        L"./Data/Images/font.png",            1U },//����
    { TEXNO::ITEM,          L"./Data/Images/item.png",            1U },//�A�C�e��
    { TEXNO::ITEM2,         L"./Data/Images/treasure box.png",    1U },
    { TEXNO::PLATE1,        L"./Data/Images/plate.png",           1U },
    { TEXNO::EFFECT,        L"./Data/Images/buff_ef.png",         1U },
    
    //�A�C�e��
    //{ TEXNO::OBJ,           L"./Data/Images/garbage.png", },
    //{ TEXNO::MAP_BACK,      L"./Data/Maps/back_chip.png",       336U }, // �}�b�v�w�i
    //{ TEXNO::MAP_TERRAIN,   L"./Data/Maps/terrain_chip.png",    336U }, // �}�b�v�n�`
    //{ TEXNO::MAP_ITEM,      L"./Data/Maps/item_chip.png",       1U },   // �A�C�e���`��
    //                                                                    //TODO_12
    //{ TEXNO::ENEMY0, L"./Data/Images/enemy00.png", 1U },
    //{ TEXNO::ENEMY1, L"./Data/Images/enemy01.png", 1U },
    //{ TEXNO::ENEMY2, L"./Data/Images/enemy02.png", 1U },
    //{ TEXNO::ENEMY3, L"./Data/Images/enemy03.png", 1U },
    //{ TEXNO::ENEMY4, L"./Data/Images/enemy04.png", 1U },
    //{ TEXNO::ENEMY5, L"./Data/Images/enemy05.png", 1U },
    { -1, nullptr }	// �I���t���O
};



//------< �v���C���[ >----------------------------------------------------------
//�����
AnimeData animePlayer_Up[] = {
    { &sprPlayer_Up0, 10 },
    { &sprPlayer_Up1, 10 },
    { &sprPlayer_Up2, 10 },
    { &sprPlayer_Up1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�E����
AnimeData animePlayer_Right[] = {
    { &sprPlayer_Right0, 10 },
    { &sprPlayer_Right1, 10 },
    { &sprPlayer_Right2, 10 },
    { &sprPlayer_Right1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer_Down[] = {
    { &sprPlayer_Down0, 10 },
    { &sprPlayer_Down1, 10 },
    { &sprPlayer_Down2, 10 },
    { &sprPlayer_Down1, 10 },
    { nullptr, -1 },// �I���t���O
};
//������
AnimeData animePlayer_Left[] = {
    { &sprPlayer_Left0, 10 },
    { &sprPlayer_Left1, 10 },
    { &sprPlayer_Left2, 10 },
    { &sprPlayer_Left1, 10 },
    { nullptr, -1 },// �I���t���O
};
//�S�~\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//��^
//AnimeData animeGarbage_Large[] =
//{
//    {&sprGarbage_Large0,10},
//    {&sprGarbage_Large1,10},
//    {&sprGarbage_Large2,10},
//    { nullptr, -1 },// �I���t���O
//};
//
////���^
//AnimeData animeGarbage_Medium[] =
//{
//    { &sprGarbage_Medium0,10 },
//    { &sprGarbage_Medium1,10 },
//    { &sprGarbage_Medium2,10 },
//    { nullptr, -1 },// �I���t���O
//};
//
////���^
//
//AnimeData animeGarbage_Small[] =
//{
//    { &sprGarbage_Small0,10 },
//    { &sprGarbage_Small1,10 },
//    { &sprGarbage_Small2,10 },
//    { nullptr, -1 },// �I���t���O
//};


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
    { &sprNumber3,60 }, //�ŏ�����1�b��
    { &sprNumber2,3600 },
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
AnimeData animeConveyor[] = {
    { &sprConveyor0, 10},
    { &sprConveyor1, 10 },
    { &sprConveyor2, 10 },
    { nullptr, -1 },// �I���t���O
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
