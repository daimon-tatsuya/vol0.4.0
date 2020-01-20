#ifndef INCLUDED_SPRITE_DATA
#define	INCLUDED_SPRITE_DATA
//******************************************************************************
//
//
//		SPRITE_DATA
//
//
//******************************************************************************

#include "GameLib\texture.h"



#if 11
//******************************************************************************
// TODO:11 �G�e�N�X�`���p���x���̒�`
//------------------------------------------------------------------------------
/*
�ۑ�j
�G�p�̃e�N�X�`�������ʂ��郉�x�����`����B

���L��TEXNO���ɁAENEMY0����ENEMY5�܂Œǉ�����B
*/
//******************************************************************************
#endif
// ���x����`
enum TEXNO
{
    // �Q�[��
    PLAYER,
    GARBAGE,
    GOLD,
    ITEM2,
    PRESS,
    BG,
    CONVEYOR,
    BER,
    DUSTBOX,
    NUMBER,
    PLATE1,
    EFFECT,
    ITEM,
    TITLE,
    SINGLE,
    DOUDLE,
    OBJ,

    /*MAP_BACK,
    MAP_TERRAIN,
    MAP_ITEM,
    //TODO_11
    ENEMY0,
    ENEMY1,
    ENEMY2,
    ENEMY3,
    ENEMY4,
    ENEMY5,*/
};

extern GameLib::LoadTexture loadTexture[];

// ------< �v���C���[ >----------------------------------------------------------

//�A�j���[�V����
extern GameLib::AnimeData animePlayer_Up[];
extern GameLib::AnimeData animePlayer_Right[];
extern GameLib::AnimeData animePlayer_Down[];
extern GameLib::AnimeData animePlayer_Left[];
extern GameLib::AnimeData animeTimer1[];
extern GameLib::AnimeData animeTimer10[];
extern GameLib::AnimeData animeTimer100[];
extern GameLib::AnimeData animeRandoMark[];
extern GameLib::AnimeData animeConveyor[];
extern GameLib::AnimeData* animeTimer[];
extern GameLib::AnimeData animeEffect1[];
extern GameLib::AnimeData animeEffect2[];

//�����
extern GameLib::SpriteData sprPlayer_Up0;
extern GameLib::SpriteData sprPlayer_Up1;
extern GameLib::SpriteData sprPlayer_Up2;

//�E����
extern GameLib::SpriteData sprPlayer_Right0;
extern GameLib::SpriteData sprPlayer_Right1;
extern GameLib::SpriteData sprPlayer_Right2;

//������
extern GameLib::SpriteData sprPlayer_Down0;
extern GameLib::SpriteData sprPlayer_Down1;
extern GameLib::SpriteData sprPlayer_Down2;

//������
extern GameLib::SpriteData sprPlayer_Left0;
extern GameLib::SpriteData sprPlayer_Left1;
extern GameLib::SpriteData sprPlayer_Left2;

//�S�~\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//�A�j���[�V����\\AnimeData animeGarbage_Large[]

extern GameLib::AnimeData animeGarbage_Large[];
extern GameLib::AnimeData animeGarbage_Medium[];
extern GameLib::AnimeData animeGarbage_Small[];


//��^
extern GameLib::SpriteData sprGarbage_Large0;
extern GameLib::SpriteData sprGarbage_Large1;
extern GameLib::SpriteData sprGarbage_Large2;

//���^                     
extern GameLib::SpriteData sprGarbage_Medium0;
extern GameLib::SpriteData sprGarbage_Medium1;
extern GameLib::SpriteData sprGarbage_Medium2;

//���^                      
extern GameLib::SpriteData sprGarbage_Small0;
extern GameLib::SpriteData sprGarbage_Small1;
extern GameLib::SpriteData sprGarbage_Small2;

//�S�[���h�S�~
extern GameLib::SpriteData sprGarbage_Gold;

//�͂Ăȃ}�[�N
extern GameLib::SpriteData sprHatena;

//�v���X�@
extern GameLib::SpriteData sprPressMachine;

//�w�i
extern GameLib::SpriteData sprBG;

//�R���x�A�[
extern GameLib::SpriteData sprConveyor0;
extern GameLib::SpriteData sprConveyor1;
extern GameLib::SpriteData sprConveyor2;

//��
extern GameLib::SpriteData sprBer;

//�_�X�g�{�b�N�X
extern SpriteData sprDustBox;

//����
extern GameLib::SpriteData sprNumber0;
extern GameLib::SpriteData sprNumber1;
extern GameLib::SpriteData sprNumber2;
extern GameLib::SpriteData sprNumber3;
extern GameLib::SpriteData sprNumber4;
extern GameLib::SpriteData sprNumber5;
extern GameLib::SpriteData sprNumber6;
extern GameLib::SpriteData sprNumber7;
extern GameLib::SpriteData sprNumber8;
extern GameLib::SpriteData sprNumber9;

//�R���{
extern GameLib::SpriteData sprComb[];

//�����_���}�[�N
extern GameLib::SpriteData sprRandoMark[];

//�A�C�e��
extern GameLib::SpriteData sprItem0;
extern GameLib::SpriteData sprItem1;
extern GameLib::SpriteData sprItem2;
extern GameLib::SpriteData sprItem3;

//�G�t�F�N�g
extern GameLib::SpriteData sprEffect1_1;
extern GameLib::SpriteData sprEffect1_2;
extern GameLib::SpriteData sprEffect2_1;
extern GameLib::SpriteData sprEffect2_2;
//�v���[�g       
extern GameLib::SpriteData sprPlate1;
//�Q�[�����[�h
extern GameLib::SpriteData sprTitle_single;
extern GameLib::SpriteData sprTitle_doubles;
//�^�C�g��
//extern GameLib::SpriteData SpriteData sprTitle;


//extern GameLib::SpriteData  SpriteData sprTitle[];

#endif // !INCLUDED_SPRITE_DATA
