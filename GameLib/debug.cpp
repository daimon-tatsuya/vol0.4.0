//******************************************************************************
//
//
//      �f�o�b�O������\���p
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "debug.h"
#include "game_lib.h"

namespace GameLib
{
    //--------------------------------
    //	�R���X�g���N�^
    //--------------------------------
    Debug::Debug(ID3D11Device *device, 
        const wchar_t *fileName, size_t maxInstance, int scr_h)
        : SpriteBatch(device, fileName, maxInstance), yPos(0), screenHeight(scr_h)
    {
    }

    //--------------------------------
    //	�f�X�g���N�^
    //--------------------------------
    Debug::~Debug()
    {
    }

    //--------------------------------
    //	�f�o�b�O������̐ݒ�
    //--------------------------------
    void Debug::setString(const char *str)
    {
        std::string s(str);
        debugQueue.push(s);
    }

    //--------------------------------
    //	�f�o�b�O������̕\��
    //--------------------------------
    void Debug::display(ID3D11DeviceContext* context, 
        float r, float g, float b, float sx, float sy)
    {
        yPos = 0;
        begin(context);
        while (!debugQueue.empty())
        {
            std::string t = debugQueue.front();
            yPos += textout(t, 0, yPos, sx, sy, r, g, b, 1);
            debugQueue.pop();

            if (yPos > screenHeight)
            {
                while (!debugQueue.empty())	debugQueue.pop();
                break;
            }
        }
        end(context);
    }

}

//******************************************************************************