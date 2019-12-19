//******************************************************************************
//
//
//      ���̓}�l�[�W��
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------

#include "input_manager.h"
#include "./DirectXTK-master/Inc/Keyboard.h"
#include "./DirectXTK-master/Inc/GamePad.h"
#include "game_lib.h"

namespace GameLib
{
    using namespace input;
    using DirectX::Keyboard;

    //------< �f�[�^ >-----------------------------------------------------------

    // �L�[���蓖�ăf�[�^
    PadAssign keyAssign00[] = {
        { PAD_UP       , Keyboard::Up },            // VK_UP
        { PAD_DOWN     , Keyboard::Down },          // VK_DOWN
        { PAD_LEFT     , Keyboard::Left },          // VK_LEFT
        { PAD_RIGHT    , Keyboard::Right },         // VK_RIGHT

        //{ PAD_UP       , Keyboard::W },           // 'W'
        //{ PAD_DOWN     , Keyboard::S },           // 'S'
        //{ PAD_LEFT     , Keyboard::A },           // 'A'
        //{ PAD_RIGHT    , Keyboard::D },           // 'D'

        { PAD_TRG3     , Keyboard::Space },       // VK_SPACE

        { PAD_START    , Keyboard::Enter },         // VK_RETURN
        { PAD_TRG1     , Keyboard::Z },             // 'Z'
        { PAD_TRG2     , Keyboard::X },             // 'X'
        //{ PAD_TRG3     , Keyboard::C },             // 'C'

        { PAD_L1       , Keyboard::A },             // VK_LCONTROL
        { PAD_R1       , Keyboard::S },             // VK_RCONTROL
        { PAD_TRG4     , Keyboard::D },             // 'D'

        { PAD_SELECT   , Keyboard::Back },          // VK_BACK

//      { PAD_START  , VK_LBUTTON },                // �}�E�X���{�^��
//      { PAD_SELECT , VK_RBUTTON },                // �}�E�X�E�{�^��
//      { PAD_TRG1   , VK_MBUTTON },                // �}�E�X���{�^��

        { 0x00, 0x00 }                              // �I���R�[�h
    };

    // �W���C�X�e�B�b�N���蓖�ăf�[�^
    PadAssign joyAssign00[] = {
        { PAD_UP        , GamePad::UP },            // ��L�[
        { PAD_DOWN      , GamePad::DOWN },          // ���L�[
        { PAD_LEFT    	, GamePad::LEFT },          // ���L�[
        { PAD_RIGHT     , GamePad::RIGHT },         // �E�L�[

        { PAD_START     , GamePad::START },         // �X�^�[�g�{�^��
        { PAD_TRG1      , GamePad::A },             // A�{�^��
        { PAD_TRG2      , GamePad::B },             // B�{�^��
        { PAD_TRG3      , GamePad::X },             // X�{�^��
        { PAD_TRG4      , GamePad::Y },             // Y�{�^��
        { PAD_L1        , GamePad::LSHOULDER },     // L�{�^��
        { PAD_R1        , GamePad::RSHOULDER },     // R�{�^��

        { PAD_SELECT    , GamePad::BACK },          // �o�b�N�i�Z���N�g�j�{�^��

        { 0x00, 0x00 }                              // �I���R�[�h
    };

    // �L�[���蓖�ăf�[�^
    PadAssign keyAssign01[] = {
        { PAD_UP        , Keyboard::W },            // VK_W
        { PAD_DOWN      , Keyboard::S },            // VK_S
        { PAD_LEFT      , Keyboard::A },            // VK_A
        { PAD_RIGHT     , Keyboard::D },            // VK_D

        { PAD_TRG1      , Keyboard::J },            // 'J'
        { PAD_TRG2      , Keyboard::K },            // 'K'
        { PAD_TRG3      , Keyboard::L },            // 'L'

        { PAD_SELECT    , Keyboard::F1 },           // VK_F1

//      { PAD_START     , VK_LBUTTON },             // �}�E�X���{�^��
//      { PAD_SELECT    , VK_RBUTTON },             // �}�E�X�E�{�^��
//      { PAD_TRG1      , VK_MBUTTON },             // �}�E�X���{�^��

        { 0x00, 0x00 }                              // �I���R�[�h
    };

    //--------------------------------
    //  �L�[���蓖�Ă̐ݒ�
    //--------------------------------
    void InputManager::setKeyAssign(int no, PadAssign *data)
    {
        pad[no].keyAssign = data;
    }

    //--------------------------------
    //  �W���C�X�e�B�b�N���蓖�Ă̐ݒ�
    //--------------------------------
    void InputManager::setJoyAssign(int no, PadAssign *data)
    {
        pad[no].joyAssign = data;
    }

    //--------------------------------
    //  �f�X�g���N�^
    //--------------------------------
    InputManager::~InputManager()
    {
        safe_delete(keyboard);
        safe_delete(gamePad);
    }

    //--------------------------------
    //  ������
    //--------------------------------
    void InputManager::init()
    {
        keyboard = new DirectX::Keyboard;
        gamePad = new DirectX::GamePad;

        // �R���g���[��0�̐ݒ�
        setKeyAssign(0, keyAssign00);
        setJoyAssign(0, joyAssign00);

        // �R���g���[��1�̐ݒ�
        setKeyAssign(1, keyAssign01);
        setJoyAssign(1, joyAssign00);

        // �R���g���[��2�̐ݒ�
        setJoyAssign(2, joyAssign00);

        // �R���g���[��3�̐ݒ�
        setJoyAssign(3, joyAssign00);
    }

    //--------------------------------
    //  ���͏��̍X�V
    //--------------------------------
    void InputManager::update(HWND hwnd)
    {
        // �L�[�{�[�h�̏�Ԏ擾
        DirectX::Keyboard::State kb = keyboard->GetState();
        DirectX::GamePad::State gpad[GAMEPAD_NUM] = {};

        // �Q�[���p�b�h�̏�Ԏ擾
        for (int i = 0; i < GAMEPAD_NUM; i++)
            gpad[i] = gamePad->GetState(i);

        // 
        for (int i = 0; i < GAMEPAD_NUM; i++)
        {
            PadState* p = &pad[i];

            int old_state = p->state;

            // pad_state�̍X�V
            p->state = 0;

            // �L�[�{�[�h�E�}�E�X
            PadAssign *assign = p->keyAssign;
            if (assign)
            {
                while (assign->bit)
                {
                    if ((assign->code == VK_LBUTTON) ||
                        (assign->code == VK_RBUTTON) ||
                        (assign->code == VK_MBUTTON))
                    {	// Mouse
                        if (GetAsyncKeyState(assign->code) < 0) p->state |= assign->bit;
                    }
                    else
                    {	// Keyboard
                        if (kb.IsKeyDown((Keyboard::Keys)assign->code)) p->state |= assign->bit;
                    }

                    assign++;
                }
            }

            // �W���C�X�e�B�b�N
            assign = p->joyAssign;
            if (assign && gpad[i].IsConnected())
            {
                while (assign->bit)
                {
                    struct hoge_t { bool b[10]; } hoge;
                    if (assign->code >= GamePad::A)
                    {	// buttons
                        hoge = *(hoge_t*)&gpad[i].buttons;
                        if (hoge.b[assign->code - GamePad::A]) p->state |= assign->bit;
                    }
                    else
                    {	// dpad
                        hoge = *(hoge_t*)&gpad[i].dpad;
                        if (hoge.b[assign->code]) p->state |= assign->bit;
                    }

                    assign++;
                }

                // ���X�e�B�b�N
                p->leftX = gpad[i].thumbSticks.leftX;
                p->leftY = gpad[i].thumbSticks.leftY;

                // �E�X�e�B�b�N
                p->rightX = gpad[i].thumbSticks.rightX;
                p->rightY = gpad[i].thumbSticks.rightY;

                // ���E�g���K�[
                p->left = gpad[i].triggers.left;
                p->right = gpad[i].triggers.right;

                // �V�т̐ݒ�
                // ���K�v������ΐݒ肷��
            }

            // p->trigger�̍X�V
            p->trigger = (~old_state) & p->state;

            // p->triggerUp�̍X�V
            p->triggerUp = old_state & (~p->state);

            // p->repeat�̌v�Z
            p->repeat = p->state;
            for (int j = 8 - 1; j > 0; --j) {
                p->old[j] = p->old[j - 1];				// �f�[�^���ЂƂ��炷
                p->repeat &= p->old[j];					// repeat���v�Z����
            }
            p->old[0] = p->state & (~p->repeat);		// �ŐV�̃f�[�^��ۑ�
            p->repeat |= p->trigger;					// �{���̃g���K�[���͂��ݒ肷��
        }

        // �}�E�X���W�̎擾
        GetCursorPos(&mousePos);
        ScreenToClient(hwnd, &mousePos);
    }

    //--------------------------------
    //  �}�E�X�J�[�\����x���W���擾
    //--------------------------------
    int InputManager::getCursorPosX()
    {
        return mousePos.x;
    }

    //--------------------------------
    //  �}�E�X�J�[�\����y���W���擾
    //--------------------------------
    int InputManager::getCursorPosY()
    {
        return mousePos.y;
    }

}

//******************************************************************************
