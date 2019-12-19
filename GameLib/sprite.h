#ifndef INCLUDED_SPRITE
#define INCLUDED_SPRITE
//******************************************************************************
//
//
//      �X�v���C�g�`��p�N���X
//
//
//******************************************************************************

//------< �C���N���[�h >--------------------------------------------------------
#include <string>

#include <d3d11.h>
#include <DirectXMath.h>

#include "vector.h"
#include "resource_manager.h"

namespace GameLib
{

    //==========================================================================
    //
    //      Sprite�N���X
    //
    //==========================================================================
    class Sprite
    {
        ID3D11VertexShader*         vertexShader;
        ID3D11PixelShader*          pixelShader;
        ID3D11InputLayout*          inputLayout;
        ID3D11Buffer*               buffer;
        ID3D11RasterizerState*      rasterizerState;

        ID3D11ShaderResourceView*   shaderResourceView;
        D3D11_TEXTURE2D_DESC        tex2dDesc;
        ID3D11SamplerState*         samplerState;
        ID3D11DepthStencilState*    depthStencilState;

    public:

        //------------------------------------------------------
        //  �R���X�g���N�^
        //------------------------------------------------------
        Sprite(ID3D11Device*, const wchar_t*);

        //------------------------------------------------------
        //  �f�X�g���N�^
        //------------------------------------------------------
        ~Sprite();

        //------------------------------------------------------
        //  �X�v���C�g�`��
        //------------------------------------------------------
        void render(ID3D11DeviceContext*, 
            const VECTOR2&, const VECTOR2&, 
            const VECTOR2&, const VECTOR2&,
            const VECTOR2&, float,
            const VECTOR4&) const;

        //------------------------------------------------------
        //  �X�v���C�g�`��
        //------------------------------------------------------
        void render(ID3D11DeviceContext*,
            float, float, float, float, 
            float, float, float, float,
            float, float, float,
            float, float, float, float) const;

        //------------------------------------------------------
        //  �e�L�X�g�`��
        //------------------------------------------------------
        float textout(ID3D11DeviceContext*, 
            std::string, const VECTOR2&,
            const VECTOR2&,
            const VECTOR4&) const;

        //------------------------------------------------------
        //  �e�L�X�g�`��
        //------------------------------------------------------
        float textout(ID3D11DeviceContext*, 
            std::string, float, float,
            float, float,
            float, float, float, float) const;

        //------------------------------------------------------
        //  �l�p�|���S���`��i���_�w��j
        //------------------------------------------------------
        void quad(ID3D11DeviceContext*, 
            const VECTOR2(&v)[4],
            const VECTOR2&, const VECTOR2&,
            const VECTOR4&) const;

        //------------------------------------------------------
        //  �l�p�|���S���`��i���_�w��j
        //------------------------------------------------------
        void quad(ID3D11DeviceContext*, 
            const VECTOR2(&v)[4],
            float, float, float, float,
            float, float, float, float) const;

        //--------------------------------
        //  �\���̒�`
        //--------------------------------
        struct vertex { VECTOR3 position; VECTOR4 color; VECTOR2 texcoord; };
    };

    //==========================================================================
    //
    //      SpriteBatch�N���X
    //
    //==========================================================================
    class SpriteBatch
    {
    private:
        ID3D11VertexShader*         vertexShader;
        ID3D11PixelShader*          pixelShader;
        ID3D11InputLayout*          inputLayout;
        ID3D11Buffer*               buffer;
        ID3D11RasterizerState*      rasterizerState;

        ID3D11ShaderResourceView*   shaderResourceView;
        D3D11_TEXTURE2D_DESC        tex2dDesc;
        ID3D11SamplerState*         samplerState;
        ID3D11DepthStencilState*    depthStencilState;

        size_t MAX_INSTANCES;

        //--------------------------------
        //  �\���̒�`
        //--------------------------------
        struct instance
        {
            DirectX::XMFLOAT4X4 ndcTransform;
            VECTOR4 texcoordTransform;
            VECTOR4 color;
        };
        ID3D11Buffer* instanceBuffer;

    public:

        //--------------------------------
        //  �\���̒�`
        //--------------------------------
        struct vertex
        {
            VECTOR3 position;
            VECTOR2 texcoord;
        };

        //------------------------------------------------------
        //  �R���X�g���N�^
        //------------------------------------------------------
        SpriteBatch(ID3D11Device*, const wchar_t*, size_t);

        //------------------------------------------------------
        //  �f�X�g���N�^
        //------------------------------------------------------
        ~SpriteBatch();

        //------------------------------------------------------
        //  �O����
        //------------------------------------------------------
        void begin(ID3D11DeviceContext*);

        //------------------------------------------------------
        //  �X�v���C�g�o�b�`�`��
        //------------------------------------------------------
        void render(
            const VECTOR2&, const VECTOR2&, 
            const VECTOR2&, const VECTOR2&,
            const VECTOR2&, float angle, 
            const VECTOR4&);

        //------------------------------------------------------
        //  �X�v���C�g�o�b�`�`��
        //------------------------------------------------------
        void render(
            float, float, float, float, 
            float, float, float, float,
            float, float, float,
            float, float, float, float);

        //------------------------------------------------------
        //  �e�L�X�g�`��
        //------------------------------------------------------
        float textout(
            std::string, const VECTOR2&,
            const VECTOR2&, const VECTOR4&);

        //------------------------------------------------------
        //  �e�L�X�g�`��
        //------------------------------------------------------
        float textout(
            std::string, float, float,
            float, float, float, float, float, float);

        //------------------------------------------------------
        //  �㏈��
        //------------------------------------------------------
        void end(ID3D11DeviceContext*);

    private:

        D3D11_VIEWPORT viewport;

        UINT instanceCount = 0;
        instance* instances = nullptr;
    };

}

//******************************************************************************

#endif // !INCLUDED_SPRITE
