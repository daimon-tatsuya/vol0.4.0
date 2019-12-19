#ifndef INCLUDED_TEXTURE
#define INCLUDED_TEXTURE
//******************************************************************************
//
//
//      �e�N�X�`���Ǘ��N���X�A�e�N�X�`���N���X
//
//
//******************************************************************************

#include "sprite.h"
#include "template.h"

namespace GameLib
{

    // �e�N�X�`�����[�h�f�[�^
    struct LoadTexture
    {
        int             texNum;         // �e�N�X�`���ԍ�
        const wchar_t*  fileName;       // �t�@�C����
        UINT            maxInstance;    // �ő吔�iSpriteBatch�g�p���j
    };

    //==========================================================================
    //
    //      �e�N�X�`���N���X
    //
    //==========================================================================
    class Texture
    {
    private:
        SpriteBatch*    sprBat;    // �X�v���C�g�o�b�`

    public:
        Texture();
        ~Texture();

        bool load(ID3D11Device*, const wchar_t*, size_t);
        void release();

        void begin(ID3D11DeviceContext*);
        void end(ID3D11DeviceContext*);

        void draw(
            float, float, float, float, 
            float, float, float, float,
            float, float, float, 
            float, float, float, float);

        void draw(
            const VECTOR2&, const VECTOR2&,
            const VECTOR2&, const VECTOR2&,
            const VECTOR2&, float,
            const VECTOR4&);

        bool isEmpty();	// �e�N�X�`���f�[�^�̗L���itrue : ��, false : �L�j
    };

    //==========================================================================
    //
    //		�e�N�X�`���}�l�[�W��
    //
    //==========================================================================
    class TextureManager : public Singleton<TextureManager>
    {
    private:
        size_t      maxNum;
        Texture*    texture;
        UINT        current;

    public:
        TextureManager();
        ~TextureManager();

    public:
        void init(size_t max);
        void uninit();

        void load(ID3D11Device*, int, const wchar_t*, size_t);  // �ԍ����w�肵�ă��[�h
        int load(ID3D11Device*, const wchar_t*, size_t);        // �󂫔ԍ���T���ă��[�h�i�߂�l�F�e�N�X�`���ԍ��A-1�F���[�h�G���[�j
        void load(ID3D11Device*, const LoadTexture*);           // ���[�h�f�[�^�ɂ�郍�[�h

        void release(int);
        void release(const LoadTexture*);
        void releaseAll();

        void begin(ID3D11DeviceContext*, int);
        void end(ID3D11DeviceContext*, int);

        void draw(int, 
            float, float, float, float, 
            float, float, float, float,
            float, float, float, 
            float, float, float, float);
        void draw(int, 
            const VECTOR2&, const VECTOR2&, 
            const VECTOR2&, const VECTOR2&,
            const VECTOR2&, float angle, 
            const VECTOR4&);
    };

}

#endif// ! INCLUDED_TEXTURE