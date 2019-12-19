#ifndef INCLUDED_PRIMITIVE
#define INCLUDED_PRIMITIVE
//******************************************************************************
//
//
//      ÉvÉäÉ~ÉeÉBÉuï`âÊóp
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
    //      PrimitiveÉNÉâÉX
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
        //  ãÈå`ï`âÊ
        //------------------------------------------------------
        void rect(ID3D11DeviceContext*, const VECTOR2&, const VECTOR2&,
            const VECTOR2&, float, const VECTOR4&) const;

        //------------------------------------------------------
        //  ãÈå`ï`âÊ
        //------------------------------------------------------
        void rect(ID3D11DeviceContext*, float, float, float, float,
            float, float, float,
            float, float, float, float) const;

        //------------------------------------------------------
        //  ê¸ï`âÊ
        //------------------------------------------------------
        void line(ID3D11DeviceContext*, const VECTOR2&, const VECTOR2&,
            const VECTOR4&, float) const;

        //------------------------------------------------------
        //  ê¸ï`âÊ
        //------------------------------------------------------
        void line(ID3D11DeviceContext*, float, float, float, float,
            float, float, float, float,
            float) const;

        //------------------------------------------------------
        //  â~ï`âÊ
        //------------------------------------------------------
        void circle(ID3D11DeviceContext*, const VECTOR2&, float,
            const VECTOR4&, int) const;

        //------------------------------------------------------
        //  â~ï`âÊ
        //------------------------------------------------------
        void circle(ID3D11DeviceContext*, float, float, float,
            float, float, float, float,
            int) const;

        //------------------------------------------------------
        //  éläpÉ|ÉäÉSÉìï`âÊÅií∏ì_éwíËÅj
        //------------------------------------------------------
        void quad(ID3D11DeviceContext*, const VECTOR2(&)[4],
            const VECTOR4&) const;

        //------------------------------------------------------
        //  éläpÉ|ÉäÉSÉìï`âÊÅií∏ì_éwíËÅj
        //------------------------------------------------------
        void quad(ID3D11DeviceContext*, const VECTOR2(&)[4],
            float, float, float, float) const;

        //------------------------------------------------------
        //  ç\ë¢ëÃíËã`
        //------------------------------------------------------
        struct vertex { VECTOR3 position; VECTOR4 color; };

    };

    //==========================================================================
    //
    //      PrimitiveBatchÉNÉâÉX
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
        //  ëOèàóù
        //------------------------------------------------------
        void begin(ID3D11DeviceContext*);

        //------------------------------------------------------
        //  ãÈå`ï`âÊ
        //------------------------------------------------------
        void rect(const VECTOR2&, const VECTOR2&,
            const VECTOR2&, float,
            const VECTOR4&);

        //------------------------------------------------------
        //  ãÈå`ï`âÊ
        //------------------------------------------------------
        void rect(float, float, float, float,
            float, float, float,
            float, float, float, float);

        //------------------------------------------------------
        //  ê¸ï`âÊ
        //------------------------------------------------------
        void line(const VECTOR2&, const VECTOR2&,
            const VECTOR4&, float width);

        //------------------------------------------------------
        //  ê¸ï`âÊ
        //------------------------------------------------------
        void line(float, float, float, float,
            float, float, float, float,
            float);

        //------------------------------------------------------
        //  å„èàóù
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
