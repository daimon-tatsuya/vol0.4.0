#ifndef INCLUDED_PRIMITIVE
#define INCLUDED_PRIMITIVE
//******************************************************************************
//
//
//      �v���~�e�B�u�`��p
//
//
//******************************************************************************

//------< include >-------------------------------------------------------------
#include <d3d11.h>
#include <DirectXMath.h>
#include "vector.h"

namespace GameLib
{

    //==========================================================================
    //
    //      Primitive�N���X
    //
    //==========================================================================
    class Primitive
    {

        ID3D11VertexShader*         vertexShader;
        ID3D11PixelShader*          pixelShader;
        ID3D11InputLayout*          inputLayout;
        ID3D11Buffer*               buffer;
        ID3D11RasterizerState*      rasterizerState;
        ID3D11DepthStencilState*    depthStencilState;

        ID3D11Device*               device;
    public:
        Primitive(ID3D11Device*);
        ~Primitive();

        //------------------------------------------------------
        //  ��`�`��
        //------------------------------------------------------
        void rect(ID3D11DeviceContext*, const VECTOR2&, const VECTOR2&,
            const VECTOR2&, float, const VECTOR4&) const;

        //------------------------------------------------------
        //  ��`�`��
        //------------------------------------------------------
        void rect(ID3D11DeviceContext*, float, float, float, float,
            float, float, float,
            float, float, float, float) const;

        //------------------------------------------------------
        //  ���`��
        //------------------------------------------------------
        void line(ID3D11DeviceContext*, const VECTOR2&, const VECTOR2&,
            const VECTOR4&, float) const;

        //------------------------------------------------------
        //  ���`��
        //------------------------------------------------------
        void line(ID3D11DeviceContext*, float, float, float, float,
            float, float, float, float,
            float) const;

        //------------------------------------------------------
        //  �~�`��
        //------------------------------------------------------
        void circle(ID3D11DeviceContext*, const VECTOR2&, float,
            const VECTOR4&, int) const;

        //------------------------------------------------------
        //  �~�`��
        //------------------------------------------------------
        void circle(ID3D11DeviceContext*, float, float, float,
            float, float, float, float,
            int) const;

        //------------------------------------------------------
        //  �l�p�|���S���`��i���_�w��j
        //------------------------------------------------------
        void quad(ID3D11DeviceContext*, const VECTOR2(&)[4],
            const VECTOR4&) const;

        //------------------------------------------------------
        //  �l�p�|���S���`��i���_�w��j
        //------------------------------------------------------
        void quad(ID3D11DeviceContext*, const VECTOR2(&)[4],
            float, float, float, float) const;

        //------------------------------------------------------
        //  �\���̒�`
        //------------------------------------------------------
        struct vertex { VECTOR3 position; VECTOR4 color; };

    };

    //==========================================================================
    //
    //      PrimitiveBatch�N���X
    //
    //==========================================================================
    class PrimitiveBatch
    {
    private:

        ID3D11VertexShader*         vertexShader;
        ID3D11PixelShader*          pixelShader;
        ID3D11InputLayout*          inputLayout;
        ID3D11Buffer*               buffer;
        ID3D11RasterizerState*      rasterizerState;
        ID3D11DepthStencilState*    depthStencilState;

        size_t MAX_INSTANCES;
        struct instance
        {
            DirectX::XMFLOAT4X4 ndcTransform;
            VECTOR4 color;
        };
        ID3D11Buffer* instanceBuffer;

    public:

        struct vertex
        {
            VECTOR3 position;
        };

        PrimitiveBatch(ID3D11Device*, size_t maxInstance = (256));
        ~PrimitiveBatch();

        //------------------------------------------------------
        //  �O����
        //------------------------------------------------------
        void begin(ID3D11DeviceContext*);

        //------------------------------------------------------
        //  ��`�`��
        //------------------------------------------------------
        void rect(const VECTOR2&, const VECTOR2&,
            const VECTOR2&, float,
            const VECTOR4&);

        //------------------------------------------------------
        //  ��`�`��
        //------------------------------------------------------
        void rect(float, float, float, float,
            float, float, float,
            float, float, float, float);

        //------------------------------------------------------
        //  ���`��
        //------------------------------------------------------
        void line(const VECTOR2&, const VECTOR2&,
            const VECTOR4&, float width);

        //------------------------------------------------------
        //  ���`��
        //------------------------------------------------------
        void line(float, float, float, float,
            float, float, float, float,
            float);

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

#endif // !INCLUDED_PRIMITIVE
