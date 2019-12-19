#ifndef INCLUDED_INPUT_MANAGER
#define	INCLUDED_INPUT_MANAGER

//******************************************************************************
//
//
//      ���̓}�l�[�W��
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
//#define NOMINMAX	// �w�K�p�ɃR�����g�A�E�g
#include <Windows.h>
#include "template.h"
#include "./DirectXTK-master/Inc/Keyboard.h"
#include "./DirectXTK-master/Inc/GamePad.h"

namespace GameLib
{

    namespace input
    {

        // �L�[���x��
        const int PAD_UP = (1 << 0);
        const int PAD_DOWN = (1 << 1);
        const int PAD_LEFT = (1 << 2);
        const int PAD_RIGHT = (1 << 3);
        const int PAD_START = (1 << 4);
        const int PAD_TRG1 = (1 << 5);
        const int PAD_TRG2 = (1 << 6);
        const int PAD_TRG3 = (1 << 7);
        const int PAD_SELECT = (1 << 8);
        const int PAD_TRG4 = (1 << 9);
        const int PAD_L1 = (1 << 10);
        const int PAD_R1 = (1 << 11);
        const int PAD_L2 = (1 << 12);
        const int PAD_R2 = (1 << 13);
        const int PAD_L3 = (1 << 14);
        const int PAD_R3 = (1 << 15);

        // �p�b�h�̍ő吔
        const int	GAMEPAD_NUM = 4;

        // �Q�[���p�b�h
        enum GamePad
        {
            UP = 0,// dpad
            DOWN,
            RIGHT,
            LEFT,
            A = 4, // buttons
            B,
            X,
            Y,
            LSTICK,
            RSTICK,
            LSHOULDER,
            RSHOULDER,
            BACK,
            START,
        };
    }

    // �L�[���蓖�ăf�[�^�p�\����
    struct PadAssign
    {
        int         bit;				// PAD_STATE�p�r�b�g�f�[�^
        int         code;				// �Ή�����L�[�i�{�^���j�R�[�h
    };

    //==============================================================================
    //
    //      ���͏��N���X
    //
    //==============================================================================
    class PadState
    {
    public:

        int         state;              // �L�[���͏��
        int         trigger;            // �g���K�[����
        int         triggerUp;          // �������u��
        int         repeat;             // ���s�[�g����
        int         old[8];
        float       leftX, leftY;       // ���X�e�B�b�N
        float       rightX, rightY;     // �E�X�e�B�b�N
        float       left, right;        // ���E�g���K�[
        PadAssign*  keyAssign;          // �L�[�{�[�h���蓖�ăf�[�^
        PadAssign*  joyAssign;          // �W���C�X�e�B�b�N���蓖�ăf�[�^
    };

    //==============================================================================
    //
    //      InputManager�N���X
    //
    //==============================================================================
    class InputManager : public Singleton<InputManager>
    {
    private:
        DirectX::Keyboard*  keyboard;   // https://github.com/Microsoft/DirectXTK/wiki/Keyboard
        DirectX::GamePad*   gamePad;    // https://github.com/Microsoft/DirectXTK/wiki/GamePad

        PadState     pad[input::GAMEPAD_NUM];	    // �Q�[���p�b�h
        POINT        mousePos;			            // �}�E�X���W

        // �L�[�E�{�^�����蓖��
        void setKeyAssign(int no, PadAssign* data); // �L�[���蓖�Ă̐ݒ�
        void setJoyAssign(int no, PadAssign* data); // �W���C�X�e�B�b�N���蓖�Ă̐ݒ�

    public:

        ~InputManager();

        // ������
        void init();                                // ������

        // �X�V
        void update(HWND);                          // ���͏��̍X�V

        // �p�b�h
        PadState* getPadAddress() { return pad; }	// �Q�[���p�b�h�̎擾

        // �}�E�X�֘A
        int getCursorPosX();                        // x���W�擾
        int getCursorPosY();                        // y���W�擾
    };

}


//******************************************************************************

#endif // !INCLUDED_INPUT_MANAGER
