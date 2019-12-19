//******************************************************************************
//
//
//      テクスチャ管理クラス、テクスチャクラス
//
//
//******************************************************************************

//------< インクルード >--------------------------------------------------------
#include "texture.h"
#include "game_lib.h"

namespace GameLib
{

    //==========================================================================
    //
    //      テクスチャ管理クラス
    //
    //==========================================================================

    //--------------------------------
    //  コンストラクタ
    //--------------------------------
    TextureManager::TextureManager() : maxNum( 0 ), texture( nullptr )
    {
    }

    //--------------------------------
    //  デストラクタ
    //--------------------------------
    TextureManager::~TextureManager()
    {
        uninit();	// 念のため
    }

    //--------------------------------
    //  初期化
    //--------------------------------
    void TextureManager::init(size_t max)
    {
        uninit();	// 念のため

        texture = new Texture[max];
        maxNum = max;
    }

    //--------------------------------
    //  終了処理
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
    //  テクスチャロード（番号指定）
    //--------------------------------
    void TextureManager::load(ID3D11Device *device, int i, const wchar_t* fileName, size_t maxInstance)
    {
        if ((size_t)i < maxNum) texture[i].load(device, fileName, maxInstance);
    }

    //--------------------------------
    //  テクスチャのロード（空き番号検索）
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
    //  テクスチャの一括ロード
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
    //  テクスチャ解放（１つ）
    //--------------------------------
    void TextureManager::release(int i)
    {
        if ((size_t)i < maxNum)
        {
            texture[i].release();
        }
    }

    //--------------------------------
    //  テクスチャの一括解放
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
    //  テクスチャ解放（すべて）
    //--------------------------------
    void TextureManager::releaseAll()
    {
        for (size_t i = 0; i < maxNum; i++) release(i);
    }

    //--------------------------------
    //  描画の前処理
    //--------------------------------
    void TextureManager::begin(ID3D11DeviceContext* context, int texNo)
    {
        texture[texNo].begin(context);
    }

    //--------------------------------
    //  描画の後処理
    //--------------------------------
    void TextureManager::end(ID3D11DeviceContext* context, int texNo)
    {
        texture[texNo].end(context);
    }

    //--------------------------------
    //  テクスチャ描画
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
    //  テクスチャ描画
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
    //      テクスチャクラス
    //
    //==========================================================================

    //--------------------------------
    //  コンストラクタ
    //--------------------------------
    Texture::Texture() : sprBat( nullptr )
    {
    }

    //--------------------------------
    //  デストラクタ
    //--------------------------------
    Texture::~Texture()
    {
        release();
    }

    //--------------------------------
    //  テクスチャのロード
    //--------------------------------
    bool Texture::load(ID3D11Device *device, const wchar_t* fileName, size_t maxInstance)
    {
        sprBat = new SpriteBatch(device, fileName, maxInstance);
        return (sprBat != nullptr);
    }

    //--------------------------------
    //  描画の前処理
    //--------------------------------
    void Texture::begin(ID3D11DeviceContext* context)
    {
        sprBat->begin(context);
    }

    //--------------------------------
    //  描画の後処理
    //--------------------------------
    void Texture::end(ID3D11DeviceContext* context)
    {
        sprBat->end(context);
    }

    //--------------------------------
    //  テクスチャの描画
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
    //  テクスチャの描画
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
    //  テクスチャの解放
    //--------------------------------
    void Texture::release()
    {
        safe_delete(sprBat);
    }

    //--------------------------------
    //  テクスチャの有無
    //--------------------------------
    bool Texture::isEmpty()
    {
        return (sprBat == nullptr);
    }
}
