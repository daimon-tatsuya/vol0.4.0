//******************************************************************************
//
//
//      Sprite描画用
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "sprite.h"
#include "util.h"
#include "misc.h"
#include "game_lib.h"

namespace GameLib
{

    //==========================================================================
    //
    //      Spriteクラス
    //
    //==========================================================================

    //--------------------------------
    //  コンストラクタ
    //--------------------------------
    Sprite::Sprite(ID3D11Device* device, const wchar_t* fileName) :
        vertexShader(nullptr), pixelShader(nullptr), inputLayout(nullptr), buffer(nullptr),
        rasterizerState(nullptr), shaderResourceView(nullptr), samplerState(nullptr)
    {
        //VertexBufferの作成
        vertex vertices[4] = {};
        D3D11_BUFFER_DESC bd = {};
        bd.Usage = D3D11_USAGE_DYNAMIC;
        bd.ByteWidth = sizeof(vertices);            // 頂点バッファのサイズ
        bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;    // 頂点バッファ
        bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE; // GPU→読み取りのみ　CPU→書き込みのみ
        bd.MiscFlags = 0;
        bd.StructureByteStride = 0;
        D3D11_SUBRESOURCE_DATA initData = {};
        initData.pSysMem = vertices;                // 頂点のアドレス
        initData.SysMemPitch = 0;
        initData.SysMemSlicePitch = 0;
        if (FAILED(device->CreateBuffer(&bd, &initData, &buffer)))
        {
            assert(!"頂点バッファの作成に失敗(Sprite)");
            return;
        }

        // 頂点宣言
        // 入力レイアウトの定義
        D3D11_INPUT_ELEMENT_DESC layout[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,     D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR",	  0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,       0, 4 * 7, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };
        UINT numElements = ARRAYSIZE(layout);

        //	頂点シェーダーの読み込み
        if (!ResourceManager::loadVertexShader(device, "./Data/Shaders/sprite_vs.cso", layout, numElements, &vertexShader, &inputLayout))
        {
            assert(!"頂点シェーダーの読み込みに失敗(Sprite)");
            return;
        }
        //	ピクセルシェーダーの作成
        if (!ResourceManager::loadPixelShader(device, "./Data/Shaders/sprite_ps.cso", &pixelShader))
        {
            assert(!"ピクセルシェーダーの作成に失敗(Sprite)");
            return;
        }

        //	ラスタライザステートの設定
        D3D11_RASTERIZER_DESC rsDesc = {};
        rsDesc.FillMode = D3D11_FILL_SOLID;//
        rsDesc.CullMode = D3D11_CULL_NONE;//	カリング
        rsDesc.FrontCounterClockwise = false;
        rsDesc.DepthBias = 0;
        rsDesc.DepthBiasClamp = 0;
        rsDesc.SlopeScaledDepthBias = 0;
        rsDesc.DepthClipEnable = false;
        rsDesc.ScissorEnable = false;
        rsDesc.MultisampleEnable = false;
        rsDesc.AntialiasedLineEnable = false;
        if (FAILED(device->CreateRasterizerState(&rsDesc, &rasterizerState)))
        {
            assert(!"ラスタライザステートの作成に失敗(Sprite)");
            return;
        }

        //	テクスチャ画像読み込み
        if (!ResourceManager::loadShaderResourceView(device, fileName, &shaderResourceView, &tex2dDesc))
        {
            assert(!"テクスチャ画像読み込み失敗(Sprite)");
            return;
        }

        //	サンプラーステート設定
        D3D11_SAMPLER_DESC	samplerDesc;
        SecureZeroMemory(&samplerDesc, sizeof(D3D11_SAMPLER_DESC));
        samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
        samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
        samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
        samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
        samplerDesc.MipLODBias = 0;
        samplerDesc.MaxAnisotropy = 16;
        samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
        samplerDesc.MinLOD = 0;
        samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
        if (FAILED(device->CreateSamplerState(&samplerDesc, &samplerState)))
        {
            assert(!"サンプラーステートの生成に失敗(Sprite)");
            return;
        }

        D3D11_DEPTH_STENCIL_DESC dsDesc;
        dsDesc.DepthEnable = false;
        dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
        dsDesc.DepthFunc = D3D11_COMPARISON_ALWAYS;
        dsDesc.StencilEnable = FALSE;
        dsDesc.StencilReadMask = 0xFF;
        dsDesc.StencilWriteMask = 0xFF;
        dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
        dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
        dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
        dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
        dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
        dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
        dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
        dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
        if (FAILED(device->CreateDepthStencilState(&dsDesc, &depthStencilState)))
        {
            assert(!"デプスステンシルステートの作成に失敗(Sprite)");
            return;
        }
    }

    //--------------------------------
    //	デストラクタ
    //--------------------------------
    Sprite::~Sprite()
    {
        safe_release(depthStencilState);
        safe_release(samplerState);
        ResourceManager::releaseShaderResourceView(shaderResourceView);
        safe_release(rasterizerState);
        safe_release(buffer);
        ResourceManager::releasePixelShader(pixelShader);
        ResourceManager::releaseVertexShader(vertexShader, inputLayout);
    }

    //--------------------------------
    //  スプライト描画
    //--------------------------------
    void Sprite::render(ID3D11DeviceContext* context, 
        const VECTOR2& position, const VECTOR2& scale,
        const VECTOR2& texPos, const VECTOR2& texSize, 
        const VECTOR2& center, float angle, 
        const VECTOR4& color) const
    {
        if (scale.x * scale.y == 0.0f) return;

        D3D11_VIEWPORT viewport;
        UINT numViewports = 1;
        context->RSGetViewports(&numViewports, &viewport);

        float tw = texSize.x;
        float th = texSize.y;
        if (tw <= 0.0f || th <= 0.0f)
        {
            tw = (float)tex2dDesc.Width;
            th = (float)tex2dDesc.Height;
        }

        vertex vertices[] = {
            { VECTOR3(-0.0f, +1.0f, 0), color, VECTOR2(0, 1) },
            { VECTOR3(+1.0f, +1.0f, 0), color, VECTOR2(1, 1) },
            { VECTOR3(-0.0f, -0.0f, 0), color, VECTOR2(0, 0) },
            { VECTOR3(+1.0f, -0.0f, 0), color, VECTOR2(1, 0) },
        };

        float sinValue = sinf(angle);
        float cosValue = cosf(angle);
        float mx = (tw * scale.x) / tw * center.x;
        float my = (th * scale.y) / th * center.y;
        for (int i = 0; i < 4; i++)
        {
            vertices[i].position.x *= (tw * scale.x);
            vertices[i].position.y *= (th * scale.y);

            vertices[i].position.x -= mx;
            vertices[i].position.y -= my;

            float rx = vertices[i].position.x;
            float ry = vertices[i].position.y;
            vertices[i].position.x = rx * cosValue - ry * sinValue;
            vertices[i].position.y = rx * sinValue + ry * cosValue;

            vertices[i].position.x += mx;
            vertices[i].position.y += my;

            vertices[i].position.x += (position.x - scale.x * center.x);
            vertices[i].position.y += (position.y - scale.y * center.y);

            vertices[i].position.x = vertices[i].position.x * 2 / viewport.Width - 1.0f;
            vertices[i].position.y = 1.0f - vertices[i].position.y * 2 / viewport.Height;

            vertices[i].texcoord.x = (texPos.x + vertices[i].texcoord.x * tw) / tex2dDesc.Width;
            vertices[i].texcoord.y = (texPos.y + vertices[i].texcoord.y * th) / tex2dDesc.Height;
        }

        D3D11_MAPPED_SUBRESOURCE msr;
        context->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
        memcpy(msr.pData, vertices, sizeof(vertices));
        context->Unmap(buffer, 0);

        UINT stride = sizeof(vertex);
        UINT offset = 0;
        context->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
        context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
        context->IASetInputLayout(inputLayout);
        context->RSSetState(rasterizerState);
        context->VSSetShader(vertexShader, nullptr, 0);
        context->PSSetShader(pixelShader, nullptr, 0);

        context->PSSetShaderResources(0, 1, &shaderResourceView);
        context->PSSetSamplers(0, 1, &samplerState);

        context->OMSetDepthStencilState(depthStencilState, 1);

        context->Draw(4, 0);
    }

    //--------------------------------
    //  スプライト描画
    //--------------------------------
    void Sprite::render(ID3D11DeviceContext* context, 
        float x, float y, float sx, float sy, 
        float tx, float ty, float tw, float th,
        float cx, float cy, float angle, 
        float r, float g, float b, float a) const
    {
        return render(context, VECTOR2(x, y), VECTOR2(sx, sy), VECTOR2(tx, ty), VECTOR2(tw, th), VECTOR2(cx, cy), angle, VECTOR4(r, g, b, a));
    }

    //--------------------------------
    //  テキスト描画
    //--------------------------------
    float Sprite::textout(ID3D11DeviceContext* context, 
        std::string s, 
        const VECTOR2& position, const VECTOR2& scale, 
        const VECTOR4& color) const
    {
        float tw = static_cast<float>(tex2dDesc.Width / 16.0);
        float th = static_cast<float>(tex2dDesc.Height / 16.0);
        float cursor = 0.0f;
        for (const auto& c : s)
        {
            render(context, VECTOR2(position.x + cursor, position.y), scale, VECTOR2(tw*(c & 0x0F), th*(c >> 4)),
                VECTOR2(tw, th), VECTOR2(0, 0), 0, color);
            cursor += tw * scale.x;
        }
        return th * scale.y;
    }

    //--------------------------------
    //  テキスト描画
    //--------------------------------
    float Sprite::textout(ID3D11DeviceContext* context, 
        std::string s, 
        float x, float y, float sx, float sy, 
        float r, float g, float b, float a) const
    {
        return textout(context, s, VECTOR2(x, y), VECTOR2(sx, sy), VECTOR4(r, g, b, a));
    }

    //--------------------------------
    //  四角ポリゴン描画
    //--------------------------------
    void Sprite::quad(ID3D11DeviceContext* context, 
        const VECTOR2(&v)[4], 
        const VECTOR2& texPos, const VECTOR2& texSize, 
        const VECTOR4 &color) const
    {
        float tw = texSize.x;
        float th = texSize.y;
        if (tw <= 0.0f || th <= 0.0f)
        {
            tw = (float)tex2dDesc.Width;
            th = (float)tex2dDesc.Height;
        }

        D3D11_VIEWPORT viewport;
        UINT numViewports = 1;
        context->RSGetViewports(&numViewports, &viewport);

        vertex vertices[] = {
            { VECTOR3(v[3].x, v[3].y, 0), color, VECTOR2(0, 1) },
            { VECTOR3(v[2].x, v[2].y, 0), color, VECTOR2(1, 1) },
            { VECTOR3(v[0].x, v[0].y, 0), color, VECTOR2(0, 0) },
            { VECTOR3(v[1].x, v[1].y, 0), color, VECTOR2(1, 0) },
        };

        for (int i = 0; i < 4; i++)
        {
            vertices[i].position.x = vertices[i].position.x * 2 / viewport.Width - 1.0f;
            vertices[i].position.y = 1.0f - vertices[i].position.y * 2 / viewport.Height;

            vertices[i].texcoord.x = (texPos.x + vertices[i].texcoord.x * tw) / tex2dDesc.Width;
            vertices[i].texcoord.y = (texPos.y + vertices[i].texcoord.y * th) / tex2dDesc.Height;
        }

        D3D11_MAPPED_SUBRESOURCE msr;
        context->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
        memcpy(msr.pData, vertices, sizeof(vertices));
        context->Unmap(buffer, 0);

        UINT stride = sizeof(vertex);
        UINT offset = 0;
        context->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
        context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
        context->IASetInputLayout(inputLayout);
        context->RSSetState(rasterizerState);
        context->VSSetShader(vertexShader, NULL, 0);
        context->PSSetShader(pixelShader, NULL, 0);
        context->PSSetShaderResources(0, 1, &shaderResourceView);
        context->PSSetSamplers(0, 1, &samplerState);
        context->OMSetDepthStencilState(depthStencilState, 1);

        context->Draw(4, 0);
    }

    //--------------------------------
    //  四角ポリゴン描画
    //--------------------------------
    void Sprite::quad(ID3D11DeviceContext* context, 
        const VECTOR2(&v)[4], 
        float tx, float ty, float tw, float th, 
        float r, float g, float b, float a) const
    {
        quad(context, v, VECTOR2(tx, ty), VECTOR2(tw, th), VECTOR4(r, g, b, a));
    }


    //==========================================================================
    //
    //      SpriteBatchクラス
    //
    //==========================================================================

    //--------------------------------
    //  コンストラクタ
    //--------------------------------
    SpriteBatch::SpriteBatch(ID3D11Device* device, const wchar_t* fileName, size_t maxInstance)
    {
        MAX_INSTANCES = maxInstance;

        //VertexBufferの作成
        vertex vertices[] = {
            { VECTOR3(0, 0, 0), VECTOR2(0, 0) },
            { VECTOR3(1, 0, 0), VECTOR2(1, 0) },
            { VECTOR3(0, 1, 0), VECTOR2(0, 1) },
            { VECTOR3(1, 1, 0), VECTOR2(1, 1) },
        };
        D3D11_BUFFER_DESC bufferDesc = {};
        bufferDesc.ByteWidth = sizeof(vertices);
        bufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
        bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        bufferDesc.CPUAccessFlags = 0;
        bufferDesc.MiscFlags = 0;
        bufferDesc.StructureByteStride = 0;
        D3D11_SUBRESOURCE_DATA subresourceData = {};
        subresourceData.pSysMem = vertices;
        subresourceData.SysMemPitch = 0; //Not use for vertex buffers.
        subresourceData.SysMemSlicePitch = 0; //Not use for vertex buffers.
        if (FAILED(device->CreateBuffer(&bufferDesc, &subresourceData, &buffer)))
        {
            assert(!"頂点バッファの作成に失敗(SpriteBatch)");
            return;
        }

        D3D11_INPUT_ELEMENT_DESC layout[] = {
            { "POSITION",           0, DXGI_FORMAT_R32G32B32_FLOAT,    0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA,   0 },
            { "TEXCOORD",           0, DXGI_FORMAT_R32G32_FLOAT,       0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA,   0 },
            { "NDC_TRANSFORM",      0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "NDC_TRANSFORM",      1, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "NDC_TRANSFORM",      2, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "NDC_TRANSFORM",      3, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "TEXCOORD_TRANSFORM", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "COLOR",              0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
        };
        UINT numElements = ARRAYSIZE(layout);
        if (!ResourceManager::loadVertexShader(device, "./Data/Shaders/sprite_batch_vs.cso", layout, numElements, &vertexShader, &inputLayout))
        {
            assert(!"頂点シェーダーの読み込みに失敗(SpriteBatch)");
            return;
        }
        if (!ResourceManager::loadPixelShader(device, "./Data/Shaders/sprite_batch_ps.cso", &pixelShader))
        {
            assert(!"ピクセルシェーダーの作成に失敗(SpriteBatch)");
            return;
        }

        instance* inst = new instance[MAX_INSTANCES];
        {
            D3D11_BUFFER_DESC bd = {};
            D3D11_SUBRESOURCE_DATA sd = {};

            bd.ByteWidth = sizeof(instance) * MAX_INSTANCES;
            bd.Usage = D3D11_USAGE_DYNAMIC;
            bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
            bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
            bd.MiscFlags = 0;
            bd.StructureByteStride = 0;
            sd.pSysMem = inst;
            sd.SysMemPitch = 0; //Not use for vertex buffers.mm 
            sd.SysMemSlicePitch = 0; //Not use for vertex buffers.
            if (FAILED(device->CreateBuffer(&bd, &sd, &instanceBuffer)))
            {
                assert(!"バッファの生成に失敗(SpriteBatch)");
                return;
            }
        }
        delete[] inst;

        D3D11_RASTERIZER_DESC rasterizerDesc = {};
        rasterizerDesc.FillMode = D3D11_FILL_SOLID; //D3D11_FILL_WIREFRAME, D3D11_FILL_SOLID
        rasterizerDesc.CullMode = D3D11_CULL_NONE; //D3D11_CULL_NONE, D3D11_CULL_FRONT, D3D11_CULL_BACK   
        rasterizerDesc.FrontCounterClockwise = FALSE;
        rasterizerDesc.DepthBias = 0;
        rasterizerDesc.DepthBiasClamp = 0;
        rasterizerDesc.SlopeScaledDepthBias = 0;
        rasterizerDesc.DepthClipEnable = FALSE;
        rasterizerDesc.ScissorEnable = FALSE;
        rasterizerDesc.MultisampleEnable = FALSE;
        rasterizerDesc.AntialiasedLineEnable = FALSE;
        if (FAILED(device->CreateRasterizerState(&rasterizerDesc, &rasterizerState)))
        {
            assert(!"ラスタライザステートの作成に失敗(SpriteBatch)");
            return;
        }

        if (!ResourceManager::loadShaderResourceView(device, fileName, &shaderResourceView, &tex2dDesc))
        {
            assert(!"テクスチャ画像読み込み失敗(SpriteBatch)");
            return;
        }

        D3D11_SAMPLER_DESC samplerDesc;
        samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
        samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
        samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
        samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
        samplerDesc.MipLODBias = 0;
        samplerDesc.MaxAnisotropy = 16;
        samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
        for (int i = 0; i < 4; i++) samplerDesc.BorderColor[i] = 0;
        samplerDesc.MinLOD = 0;
        samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
        if (FAILED(device->CreateSamplerState(&samplerDesc, &samplerState)))
        {
            assert(!"サンプラーステートの生成に失敗(SpriteBatch)");
            return;
        }

        D3D11_DEPTH_STENCIL_DESC dsDesc;
        dsDesc.DepthEnable = false;
        dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
        dsDesc.DepthFunc = D3D11_COMPARISON_ALWAYS;
        dsDesc.StencilEnable = false;
        dsDesc.StencilReadMask = 0xFF;
        dsDesc.StencilWriteMask = 0xFF;
        dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
        dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
        dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
        dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
        dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
        dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
        dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
        dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
        if (FAILED(device->CreateDepthStencilState(&dsDesc, &depthStencilState)))
        {
            assert(!"デプスステンシルステートの作成に失敗(SpriteBatch)");
            return;
        }
    }

    //--------------------------------
    //  デストラクタ
    //--------------------------------
    SpriteBatch::~SpriteBatch()
    {
        safe_release(instanceBuffer);
        safe_release(depthStencilState);
        safe_release(samplerState);
        ResourceManager::releaseShaderResourceView(shaderResourceView);
        safe_release(rasterizerState);
        safe_release(buffer);
        ResourceManager::releasePixelShader(pixelShader);
        ResourceManager::releaseVertexShader(vertexShader, inputLayout);
    }

    //--------------------------------
    //  前処理（描画前に1度呼ぶ）
    //--------------------------------
    void SpriteBatch::begin(ID3D11DeviceContext* context)
    {
        HRESULT hr = S_OK;

        UINT strides[2] = { sizeof(vertex), sizeof(instance) };
        UINT offsets[2] = { 0, 0 };
        ID3D11Buffer *vbs[2] = { buffer, instanceBuffer };
        context->IASetVertexBuffers(0, 2, vbs, strides, offsets);
        context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
        context->IASetInputLayout(inputLayout);
        context->OMSetDepthStencilState(depthStencilState, 1);
        context->RSSetState(rasterizerState);
        context->VSSetShader(vertexShader, nullptr, 0);
        context->PSSetShader(pixelShader, nullptr, 0);
        context->PSSetShaderResources(0, 1, &shaderResourceView);
        context->PSSetSamplers(0, 1, &samplerState);

        UINT numViewports = 1;
        context->RSGetViewports(&numViewports, &viewport);

        D3D11_MAP map = D3D11_MAP_WRITE_DISCARD;
        D3D11_MAPPED_SUBRESOURCE mappedBuffer;
        hr = context->Map(instanceBuffer, 0, map, 0, &mappedBuffer);
        _ASSERT_EXPR(SUCCEEDED(hr), hr_trace(hr));
        instances = static_cast<instance *>(mappedBuffer.pData);

        instanceCount = 0;
    }

    //--------------------------------
    //  描画準備
    //--------------------------------
    void SpriteBatch::render(
        const VECTOR2& position, const VECTOR2& scale, 
        const VECTOR2& texPos, const VECTOR2& texSize,
        const VECTOR2& center, float angle/*radian*/, 
        const VECTOR4& color)
    {
        if (instanceCount >= MAX_INSTANCES)
        {
            assert(!"Number of instances must be less than MAX_INSTANCES.(SpriteBatch)");
            return;
        }

        if (scale.x * scale.y == 0.0f) return;
        float tw = texSize.x;
        float th = texSize.y;
        if (texSize.x <= 0.0f || texSize.y <= 0.0f)
        {
            tw = (float)tex2dDesc.Width;
            th = (float)tex2dDesc.Height;
        }

        //	float cx = dw*0.5f, cy = dh*0.5f; /*Center of Rotation*/
        float cx = center.x;
        float cy = center.y;
        cx *= scale.x;
        cy *= scale.y;

#if 0
        DirectX::XMVECTOR scaling = DirectX::XMVectorSet(dw, dh, 1.0f, 0.0f);
        DirectX::XMVECTOR origin = DirectX::XMVectorSet(cx, cy, 0.0f, 0.0f);
        DirectX::XMVECTOR translation = DirectX::XMVectorSet(dx, dy, 0.0f, 0.0f);
        DirectX::XMMATRIX M = DirectX::XMMatrixAffineTransformation2D(scaling, origin, angle*0.01745f, translation);
        DirectX::XMMATRIX N(
            2.0f / viewport.Width, 0.0f, 0.0f, 0.0f,
            0.0f, -2.0f / viewport.Height, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            -1.0f, 1.0f, 0.0f, 1.0f);
        XMStoreFloat4x4(&instances[count_instance].ndc_transform, DirectX::XMMatrixTranspose(M*N)); //column_major
#else
        FLOAT c = cosf(angle);
        FLOAT s = sinf(angle);
        FLOAT w = 2.0f / viewport.Width;
        FLOAT h = -2.0f / viewport.Height;

        instances[instanceCount].ndcTransform._11 = w * scale.x * tw * c;
        instances[instanceCount].ndcTransform._21 = h * scale.x * tw * s;
        instances[instanceCount].ndcTransform._31 = 0.0f;
        instances[instanceCount].ndcTransform._41 = 0.0f;
        instances[instanceCount].ndcTransform._12 = w * scale.y * th * -s;
        instances[instanceCount].ndcTransform._22 = h * scale.y * th * c;
        instances[instanceCount].ndcTransform._32 = 0.0f;
        instances[instanceCount].ndcTransform._42 = 0.0f;
        instances[instanceCount].ndcTransform._13 = 0.0f;
        instances[instanceCount].ndcTransform._23 = 0.0f;
        instances[instanceCount].ndcTransform._33 = 1.0f;
        instances[instanceCount].ndcTransform._43 = 0.0f;
        instances[instanceCount].ndcTransform._14 = w * (-cx * c + -cy * -s + cx * 0 + position.x) - 1.0f;
        instances[instanceCount].ndcTransform._24 = h * (-cx * s + -cy * c + cy * 0 + position.y) + 1.0f;
        instances[instanceCount].ndcTransform._34 = 0.0f;
        instances[instanceCount].ndcTransform._44 = 1.0f;
#endif
        float tex_width = static_cast<float>(tex2dDesc.Width);
        float tex_height = static_cast<float>(tex2dDesc.Height);
        instances[instanceCount].texcoordTransform = VECTOR4(texPos.x / tex_width, texPos.y / tex_height, tw / tex_width, th / tex_height);
        instances[instanceCount].color = color;

        instanceCount++;
    }

    //--------------------------------
    //  描画準備
    //--------------------------------
    void SpriteBatch::render(
        float x, float y, float sx, float sy,
        float tx, float ty, float tw, float th,
        float cx, float cy, float angle/*radian*/,
        float r, float g, float b, float a)
    {
        render(VECTOR2(x, y), VECTOR2(sx, sy), 
            VECTOR2(tx, ty), VECTOR2(tw, th),
            VECTOR2(cx, cy), angle, 
            VECTOR4(r, g, b, a));
    }

    //--------------------------------
    //  テキスト描画準備
    //--------------------------------
    float SpriteBatch::textout(std::string s, 
        const VECTOR2& pos, const VECTOR2& scale, 
        const VECTOR4& color)
    {
        float tw = static_cast<float>(tex2dDesc.Width / 16.0);
        float th = static_cast<float>(tex2dDesc.Height / 16.0);
        float cursor = 0.0f;
        for (const auto& c : s)
        {
            render(VECTOR2(pos.x + cursor, pos.y), scale, VECTOR2(tw*(c & 0x0F), th*(c >> 4)),
                VECTOR2(tw, th), VECTOR2(0, 0), 0, color);
            cursor += tw * scale.x;
        }
        return th * scale.y;
    }

    //--------------------------------
    //  テキスト描画準備
    //--------------------------------
    float SpriteBatch::textout(std::string s,
        float x, float y, float sx, float sy, 
        float r, float g, float b, float a)
    {
        return textout(s, VECTOR2(x, y), VECTOR2(sx, sy), VECTOR4(r, g, b, a));
    }

    //--------------------------------
    //  後処理（描画準備後に1度呼ぶ）
    //--------------------------------
    void SpriteBatch::end(ID3D11DeviceContext* context)
    {
        context->Unmap(instanceBuffer, 0);
        context->DrawInstanced(4, instanceCount, 0, 0);
    }

}

//******************************************************************************
