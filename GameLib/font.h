#ifndef INCLUDED_FONT
#define INCLUDED_FONT

//******************************************************************************
//
//
//      �t�H���g�\���p
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include <Windows.h>
#include "template.h"
#include "sprite.h"

namespace GameLib
{
    const UINT FONT_NUM = 7;
    const UINT FONT_MAX_INSTANCE = 256;

    // �t�H���g���[�h�f�[�^
    struct LoadFont
    {
        int             fontNo;     // �e�N�X�`���ԍ�
        const wchar_t*  fileName;   // �t�@�C����
    };

    // ���x����`
    enum FONTNO
    {
        // �^�C�g��
        FONT0 = 0,
        FONT1,
        FONT2,
        FONT3,
        FONT4,
        FONT5,
        FONT6,
    };

    //==========================================================================
    //
    //      �t�H���g�}�l�[�W��
    //
    //==========================================================================
    class FontManager : public Singleton<FontManager>
    {
    private:
        SpriteBatch** font;

    public:
        FontManager();
        ~FontManager();

        void init(ID3D11Device*);
        void uninit();
        void release(int);
        void releaseAll();

        float textOut(ID3D11DeviceContext*, int, 
            std::string, 
            float, float, float, float,
            float, float, float, float);
        float textOut(ID3D11DeviceContext*, int,
            std::string, 
            const VECTOR2&, const VECTOR2&,
            const VECTOR4&);
    };
}

#endif // !INCLUDED_FONT