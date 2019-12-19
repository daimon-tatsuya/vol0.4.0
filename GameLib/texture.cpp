//******************************************************************************
//
//
//      �e�N�X�`���Ǘ��N���X�A�e�N�X�`���N���X
//
//
//******************************************************************************

//------< �C���N���[�h >--------------------------------------------------------
#include "texture.h"
#include "game_lib.h"

namespace GameLib
{

    //==========================================================================
    //
    //      �e�N�X�`���Ǘ��N���X
    //
    //==========================================================================

    //--------------------------------
    //  �R���X�g���N�^
    //--------------------------------
    TextureManager::TextureManager() : maxNum( 0 ), texture( nullptr )
    {
    }

    //--------------------------------
    //  �f�X�g���N�^
    //--------------------------------
    TextureManager::~TextureManager()
    {
        uninit();	// �O�̂���
    }

    //--------------------------------
    //  ������
    //--------------------------------
    void TextureManager::init(size_t max)
    {
        uninit();	// �O�̂���

        texture = new Texture[max];
        maxNum = max;
    }

    //--------------------------------
    //  �I������
    //--------------------------------
    void TextureManager::uninit()
    {
        if (texture)
        {
            releaseAll();
            delete[] texture;
            texture = nullptr;
            maxNum = 0;
        }
    }

    //--------------------------------
    //  �e�N�X�`�����[�h�i�ԍ��w��j
    //--------------------------------
    void TextureManager::load(ID3D11Device *device, int i, const wchar_t* fileName, size_t maxInstance)
    {
        if ((size_t)i < maxNum) texture[i].load(device, fileName, maxInstance);
    }

    //--------------------------------
    //  �e�N�X�`���̃��[�h�i�󂫔ԍ������j
    //--------------------------------
    int TextureManager::load(ID3D11Device *device, const wchar_t* fileName, size_t maxInstance)
    {
        for (size_t i = 0; i < maxNum; i++)
        {
            if (texture[i].isEmpty())
            {
                load(device, i, fileName, maxInstance);
                return i;
            }
        }
        return -1;
    }

    //--------------------------------
    //  �e�N�X�`���̈ꊇ���[�h
    //--------------------------------
    void TextureManager::load(ID3D11Device* device, const LoadTexture* data)
    {
        while ((size_t)data->texNum < maxNum)
        {
            release(data->texNum);
            load(device, data->texNum, data->fileName, data->maxInstance);
            data++;
        }
    }

    //--------------------------------
    //  �e�N�X�`������i�P�j
    //--------------------------------
    void TextureManager::release(int i)
    {
        if ((size_t)i < maxNum)
        {
            texture[i].release();
        }
    }

    //--------------------------------
    //  �e�N�X�`���̈ꊇ���
    //--------------------------------
    void TextureManager::release(const LoadTexture* data)
    {
        while ((size_t)data->texNum < maxNum)
        {
            release(data->texNum);
            data++;
        }
    }

    //--------------------------------
    //  �e�N�X�`������i���ׂāj
    //--------------------------------
    void TextureManager::releaseAll()
    {
        for (size_t i = 0; i < maxNum; i++) release(i);
    }

    //--------------------------------
    //  �`��̑O����
    //--------------------------------
    void TextureManager::begin(ID3D11DeviceContext* context, int texNo)
    {
        texture[texNo].begin(context);
    }

    //--------------------------------
    //  �`��̌㏈��
    //--------------------------------
    void TextureManager::end(ID3D11DeviceContext* context, int texNo)
    {
        texture[texNo].end(context);
    }

    //--------------------------------
    //  �e�N�X�`���`��
    //--------------------------------
    void TextureManager::draw(int i,
        float x, float y, 
        float scaleX, float scaleY, 
        float left, float top, 
        float width, float height, 
        float centerX, float centerY, float angle, 
        float r, float g, float b, float a)
    {
        if ((size_t)i < maxNum)
        {
            texture[i].draw(
                x, y, scaleX, scaleY,
                left, top, width, height,
                centerX, centerY, angle,
                r, g, b, a);
        }
    }

    //--------------------------------
    //  �e�N�X�`���`��
    //--------------------------------
    void TextureManager::draw(int i,
        const VECTOR2& position, const VECTOR2& scale,
        const VECTOR2& texPos, const VECTOR2& texSize,
        const VECTOR2& center, float angle, const VECTOR4& color)
    {
        if ((size_t)i < maxNum)
        {
            texture[i].draw(
                position, scale,
                texPos, texSize,
                center, angle,
                color);
        }
    }

    //==========================================================================
    //
    //      �e�N�X�`���N���X
    //
    //==========================================================================

    //--------------------------------
    //  �R���X�g���N�^
    //--------------------------------
    Texture::Texture() : sprBat( nullptr )
    {
    }

    //--------------------------------
    //  �f�X�g���N�^
    //--------------------------------
    Texture::~Texture()
    {
        release();
    }

    //--------------------------------
    //  �e�N�X�`���̃��[�h
    //--------------------------------
    bool Texture::load(ID3D11Device *device, const wchar_t* fileName, size_t maxInstance)
    {
        sprBat = new SpriteBatch(device, fileName, maxInstance);
        return (sprBat != nullptr);
    }

    //--------------------------------
    //  �`��̑O����
    //--------------------------------
    void Texture::begin(ID3D11DeviceContext* context)
    {
        sprBat->begin(context);
    }

    //--------------------------------
    //  �`��̌㏈��
    //--------------------------------
    void Texture::end(ID3D11DeviceContext* context)
    {
        sprBat->end(context);
    }

    //--------------------------------
    //  �e�N�X�`���̕`��
    //--------------------------------
    void Texture::draw(
        float x, float y, float scaleX, float scaleY,
        float left, float top, float width, float height,
        float centerX, float centerY, float angle,
        float r, float g, float b, float a)
    {
        if (sprBat)
        {
            sprBat->render(
                x, y, scaleX, scaleY,
                left, top, width, height,
                centerX, centerY, angle,
                r, g, b, a);
        }
    }

    //--------------------------------
    //  �e�N�X�`���̕`��
    //--------------------------------
    void Texture::draw(
        const VECTOR2& pos, const VECTOR2& scale,
        const VECTOR2& texPos, const VECTOR2& texSize,
        const VECTOR2& center, float angle,
        const VECTOR4& color)
    {
        if (sprBat)
        {
            sprBat->render(
                pos, scale, texPos, texSize,
                center, angle, color);
        }
    }

    //--------------------------------
    //  �e�N�X�`���̉��
    //--------------------------------
    void Texture::release()
    {
        safe_delete(sprBat);
    }

    //--------------------------------
    //  �e�N�X�`���̗L��
    //--------------------------------
    bool Texture::isEmpty()
    {
        return (sprBat == nullptr);
    }
}
