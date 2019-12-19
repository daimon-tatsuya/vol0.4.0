//******************************************************************************
//
//
//      �t�H���g�\���p
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "font.h"
#include "util.h"

namespace GameLib
{

    //------< �f�[�^ >-----------------------------------------------------------
    LoadFont fontTexture[] = {
        { FONTNO::FONT0, L"./Data/Fonts/font0.png" }, // �t�H���g
        { FONTNO::FONT1, L"./Data/Fonts/font1.png" }, // �t�H���g
        { FONTNO::FONT2, L"./Data/Fonts/font2.png" }, // �t�H���g
        { FONTNO::FONT3, L"./Data/Fonts/font3.png" }, // �t�H���g
        { FONTNO::FONT4, L"./Data/Fonts/font4.png" }, // �t�H���g
        { FONTNO::FONT5, L"./Data/Fonts/font5.png" }, // �t�H���g
        { FONTNO::FONT6, L"./Data/Fonts/font6.png" }, // �t�H���g
        { -1, nullptr }	// �I���t���O
    };

    //--------------------------------
    //  �R���X�g���N�^
    //--------------------------------
    FontManager::FontManager() : font(nullptr)
    {
    }

    //--------------------------------
    //  �f�X�g���N�^
    //--------------------------------
    FontManager::~FontManager()
    {
        uninit();
    }

    //--------------------------------
    //  ������
    //--------------------------------
    void FontManager::init(ID3D11Device* device)
    {
        font = new SpriteBatch*[FONT_NUM];

        LoadFont *data = fontTexture;
        while ((size_t)data->fontNo < FONT_NUM)
        {
            font[data->fontNo] = new SpriteBatch(
                device, data->fileName, FONT_MAX_INSTANCE);
            data++;
        }
    }

    //--------------------------------
    //  �I������
    //--------------------------------
    void FontManager::uninit()
    {
        releaseAll();
        safe_delete_array(font);
    }

    //--------------------------------
    //  �ԍ����w�肵�ĉ��
    //--------------------------------
    void FontManager::release(int i)
    {
        if ((size_t)i < FONT_NUM)
        {
            safe_delete(font[i]);
        }
    }

    //--------------------------------
    //  �S�ĉ��
    //--------------------------------
    void FontManager::releaseAll()
    {
        for (size_t i = 0; i < FONT_NUM; i++) release(i);
    }

    //--------------------------------
    //  �e�L�X�g�\��
    //--------------------------------
    float FontManager::textOut(ID3D11DeviceContext* context, 
        int fontNo, std::string str,
        float x, float y, float scaleX, float scaleY,
        float r, float g, float b, float a)
    {
        if (fontNo >= FONT_NUM) return -1;
        font[fontNo]->begin(context);
        float h = font[fontNo]->textout(str, x, y, scaleX, scaleY, r, g, b, a);
        font[fontNo]->end(context);
        return h;
    }

    //--------------------------------
    //  �e�L�X�g�\��
    //--------------------------------
    float FontManager::textOut(ID3D11DeviceContext* context, 
        int fontNo, std::string str, 
        const VECTOR2& position, const VECTOR2& scale,
        const VECTOR4& color)
    {
        if (fontNo >= FONT_NUM) return -1;
        font[fontNo]->begin(context);
        float h = font[fontNo]->textout(str, position, scale, color);
        font[fontNo]->end(context);
        return h;
    }

}