#ifndef INCLUDED_OBJ2D
#define INCLUDED_OBJ2D

#include <list>

//******************************************************************************
//
//
//      obj2d.h
//
//
//******************************************************************************

//------< �萔 >----------------------------------------------------------------

//------< �\���� >---------------------------------------------------------------

//==============================================================================
//
//      OBJ2D
//
//==============================================================================
//class OBJ2D
//{
//public:
//
//    // �X�v���C�g�֘A
//    Sprite* data;           // �X�v���C�g�|�C���^
//    VECTOR2 texPos;         // �摜�ʒu
//    VECTOR2 texSize;        // �摜�T�C�Y
//    VECTOR2 texPivot;       // �摜�̊�_
//    int     anime;          // �A�j���[�V�����p�i���j
//
//    // OBJ2D�̃^�C�v�E���݃t���O
//    int     type;           // �^�C�v
//    BOOL    exist;          // ���݃t���O
//
//    // �ėp�I�Ȃ���
//    VECTOR2 pos;            // �ʒu
//    VECTOR2 scale;          // �X�P�[��
//    float   angle;          // �p�x
//    VECTOR4 color;          // �F�ixyzw���ꂼ��rgba�j
//    float   radius;         // ���a
//    int     state;          // ��ԑJ�ڗp
//    int     timer;          // �^�C�}�[
//    VECTOR2 speed;          // ���x
//    int     cnt;            // �ėp�J�E���^�i�g�����͎��R�j
//    BOOL    hostilityFg;    // �G�t���O�i���񂩂�ǉ��j
//
//    // ����Ȃ���
//    BOOL    grndFg;         // �n��t���O�i�n��̂��̂�TRUE�j
//    float   rotate;         // ���񂷂�p�x
//    OBJ2D*  parent;         // �e�I�u�W�F�N�g���w���|�C���^
//    VECTOR2 rpos;           // ���ΓI�Ȉʒu�irelative position)
//    int     hp;             // �q�b�g�|�C���g
//    int     atk;            // �U����
//    int     damageTimer;    // �_���[�W�^�C�}�[
//    int     score;          // ���̓G��|�����牽�_���邩
//};

// �O���錾
class OBJ2D;

//------< �v���g�^�C�v�錾 >-----------------------------------------------------
//
// �ړ��A���S���Y���N���X�i���ۃN���X�j
class MoveAlg
{
public:
    virtual void move(OBJ2D* obj) = 0;  // �������z�֐������̂ŁAMoveAlg�^�̃I�u�W�F�N�g�͐錾�ł��Ȃ��i�h�������Ďg���j
};

// �����A���S���Y���N���X�i���ۃN���X�j
class EraseAlg
{
public:
    virtual void erase(OBJ2D* obj) = 0; // ��Ɠ��l
};

class OBJ2D
{
public:
    //��ÓI�����o�ϐ��̏������iC++11�j
    MoveAlg*                mvAlg = nullptr;      // �ړ��A���S���Y��
    EraseAlg*               eraseAlg = nullptr;   // �����A���S���Y��

    GameLib::SpriteData*    data = nullptr;         // �X�v���C�g�f�[�^
    GameLib::Anime          anime ;                 // �A�j���[�V�����N���X

    VECTOR2                 position  ;             // �ʒu
    VECTOR2                 scale = {1, 1};         // �X�P�[��
    float                   angle = 0;              // �p�x
    VECTOR4                 color ;                 // �`��F
    VECTOR2                 size = {1, 1};          // ������p�T�C�Y�i�c���j
    
    float                   velocity = 0;           // ���x
    VECTOR2                 speed ;                 // �u�Ԃ̈ړ��ʃx�N�g��
    int                     state = 0;              // �X�e�[�g
    int                     timer = 0;              // �^�C�}�[
    int                     param = 0;              //�ėp�p�����[�^
    int                     type = 0;               // �^�C�v
    int                     inversion;              //���]
//<<<<<<< HEAD
    float                   GROUND_POS_Y;           //�n��(init�Ō��߂�)
//=======
   
//<<<<<<< HEAD
//<<<<<<< HEAD
     int                    no;                     //�ėp
//>>>>>>> 0ecd60dfe11cdb69557f833ea8a896513ec56bde
//=======
   //int              no;                     //�ԍ��U�蕪��
//>>>>>>> 0109f21d0b202314af7c1d09622182140ff74ef5
//=======
  //  int                     no;                     //�ԍ��U�蕪��
//>>>>>>> a24f0345bfffecba1977123f24777fafc7059949

    int                     iWork[16] ;             // �ėp�i�g�����͎��R�j
    float                   fWork[16] ;             // �ėp�i�g�����͎��R�j
    bool                    bWork[16] ;             // �ėp�i�g�����͎��R�j    
                      
    int                     jumpTimer = 0;          // �������W�����v�^�C�}�[
    int                     mutekiTimer = 0;        // ���G�^�C�}�[
    int                     damageTimer = 0;        // �_���[�W�^�C�}�[

    GameLib::fRECT          hitRect = {};           // �����蔻��RECT

    bool                    judgeFlag = false;      // �����蔻��̗L���itrue:�L�� / false:�����j
    bool                    isDrawHitRect = false;  // �����蔻��`��t���O
    bool                    hashigoFlag = false;    // �͂����t���O
    bool                    hasSword = false;       // ���������Ă��邩�itrue:���� / false:�����j

    int                     command = 0;            // ���̃I�u�W�F�N�g����̃R�}���h
    VECTOR2                 delta ;                 // �ړ��ʂ̍���

    GameLib::AnimeData*     animeData = nullptr;    // �A�j���[�V�����f�[�^
    bool                    onGround = false;       // �n�ʃt���O�i�n��ɂ���j
    float                     xFlip;                  // x���̔��]
    //bool                    kabeFlag = false;     // �ǃt���O�i����悪�ǁj
    //bool                    gakeFlag = false;     // �R�t���O�i����悪�R�j
 
    BOOL    exist;                                  // ���݃t���O

    bool caughtFlg = false;    //true�̎������グ���Ă�

    bool throwFlg = false;

    int                     count = 0;

    VECTOR2 initVelocity = VECTOR2(0 ,0);//�����x
public:
    // �����o�֐�
   // OBJ2DC();        // �R���X�g���N�^

    //void clear();   // �����o�ϐ��̃N���A
    void move();    // �ړ�
    void draw();    // �`��
    //bool animeUpdate();                         // �A�j���[�V�����̃A�b�v�f�[�g
    bool animeUpdate(AnimeData* animeData);                         // �A�j���[�V�����̃A�b�v�f�[�g

    void drawHitRect(const VECTOR4&);           // �����蔻��`��
};
OBJ2D* searchSet(OBJ2D[], int, int, VECTOR2);
BOOL areaCheck(OBJ2D*, float);

// OBJ2DManager�N���X
class OBJ2DManager
{
protected:
    std::list<OBJ2D>  objList; // ���X�g�iOBJ2D�̔z��̂悤�Ȃ��́j
public:
    // �f�X�g���N�^
    ~OBJ2DManager();

    void init();    // ������
    void update();  // �X�V
    void draw();    // �`��

    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos = VECTOR2(0, 0)); // objList�ɐV����OBJ2D��ǉ�����
    std::list<OBJ2D>* getList() { return &objList; }                // objList���擾����
};

//template<class getData>
void readData(std::string fileName, float& data);

#endif // !INCLUDED_OBJ2D
