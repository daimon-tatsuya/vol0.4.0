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
// ���x����`
enum TEXNO
{
    // �Q�[��
    PLAYER1,
    PLAYER2,
    GARBAGE,
    GOLD,
    ITEM2,
    PRESS,
    BG,
    CONVEYOR1,
    CONVEYOR2,
    BER,
    DUSTBOX,
    NUMBER,
    PLATE1,
    EFFECT,
    KEMURI,
    ITEM,
    TITLE,
    SINGLE,
    DOUDLE,
    FUKIDASI,
    ITIRAN,
    PAUSE,
    CONTINUE,
    GO_TITLE,
    GO_ITIRAN,
    TUTORIAL,
    WIN,
    LOSE,
    PAUSE_BG,

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
extern GameLib::AnimeData animePlayer1_Up[];
extern GameLib::AnimeData animePlayer1_Right[];
extern GameLib::AnimeData animePlayer1_Down[];
extern GameLib::AnimeData animePlayer1_Left[];
extern GameLib::AnimeData animePlayer2_Up[];
extern GameLib::AnimeData animePlayer2_Right[];
extern GameLib::AnimeData animePlayer2_Down[];
extern GameLib::AnimeData animePlayer2_Left[];
extern GameLib::AnimeData animeTimer1[];
extern GameLib::AnimeData animeTimer10[];
extern GameLib::AnimeData animeTimer100[];
extern GameLib::AnimeData animeRandoMark[];
extern GameLib::AnimeData animeConveyor1[];
extern GameLib::AnimeData animeConveyor2[];
extern GameLib::AnimeData* animeConveyor[];
extern GameLib::AnimeData* animeTimer[];
extern GameLib::AnimeData animeEffect1[];
extern GameLib::AnimeData animeEffect2[];
extern GameLib::AnimeData animeKemuri[];
extern GameLib::AnimeData* animeEffect[];

//player(kuma)
//�����
extern GameLib::SpriteData sprPlayer1_Up0;
extern GameLib::SpriteData sprPlayer1_Up1;
extern GameLib::SpriteData sprPlayer1_Up2;

//�E����
extern GameLib::SpriteData sprPlayer1_Right0;
extern GameLib::SpriteData sprPlayer1_Right1;
extern GameLib::SpriteData sprPlayer1_Right2;

//������
extern GameLib::SpriteData sprPlayer1_Down0;
extern GameLib::SpriteData sprPlayer1_Down1;
extern GameLib::SpriteData sprPlayer1_Down2;

//������
extern GameLib::SpriteData sprPlayer1_Left0;
extern GameLib::SpriteData sprPlayer1_Left1;
extern GameLib::SpriteData sprPlayer1_Left2;
//player(buriki)
//�����
extern GameLib::SpriteData sprPlayer2_Up0;
extern GameLib::SpriteData sprPlayer2_Up1;
extern GameLib::SpriteData sprPlayer2_Up2;

//�E����
extern GameLib::SpriteData sprPlayer2_Right0;
extern GameLib::SpriteData sprPlayer2_Right1;
extern GameLib::SpriteData sprPlayer2_Right2;

//������
extern GameLib::SpriteData sprPlayer2_Down0;
extern GameLib::SpriteData sprPlayer2_Down1;
extern GameLib::SpriteData sprPlayer2_Down2;

//������
extern GameLib::SpriteData sprPlayer2_Left0;
extern GameLib::SpriteData sprPlayer2_Left1;
extern GameLib::SpriteData sprPlayer2_Left2;

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
extern GameLib::SpriteData sprConveyor1_0;
extern GameLib::SpriteData sprConveyor1_1;
extern GameLib::SpriteData sprConveyor1_2;

extern GameLib::SpriteData sprConveyor2_0;
extern GameLib::SpriteData sprConveyor2_1;
extern GameLib::SpriteData sprConveyor2_2;

//��
extern GameLib::SpriteData sprBer;

//�_�X�g�{�b�N�X
extern GameLib::SpriteData sprDustBox;

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
extern GameLib::SpriteData sprTitle_tutorial;
//�^�C�g��
//extern GameLib::SpriteData SpriteData sprTitle;
//�|�[�Y��
extern GameLib::SpriteData sprPause;
extern GameLib::SpriteData sprPause_continue;
extern GameLib::SpriteData sprPause_goTitle ;
extern GameLib::SpriteData sprPause_goItiran;
extern GameLib::SpriteData sprPause_bg;
//�Q�[��GameLib::�I�[�o�[
extern GameLib::SpriteData sprwin;
extern GameLib::SpriteData sprlose;
//�����o��
extern GameLib::SpriteData sprFukidasi1;
extern GameLib::SpriteData sprFukidasi2;
extern GameLib::SpriteData sprFukidasi3;

extern GameLib::SpriteData sprFukidasi[];

//�A�C�e���ꗗ

extern GameLib::SpriteData sprItiran;
extern GameLib::SpriteData sprpause_itiran;
//extern GameLib::SpriteData  SpriteData sprTitle[];

//�v���C���[
extern  GameLib::AnimeData*animePlayer[2][4];

//���G�t�F�N�g
extern GameLib::SpriteData sprKemuri1;
extern GameLib::SpriteData sprKemuri2;
extern GameLib::SpriteData sprKemuri3;

#endif // !INCLUDED_SPRITE_DATA
