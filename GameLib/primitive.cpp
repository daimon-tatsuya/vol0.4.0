//******************************************************************************
//
//
//      �v���~�e�B�u�`��p
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "primitive.h"
#include "resource_manager.h"
#include "misc.h"
#include "util.h"
#include "game_lib.h"

namespace GameLib
{

    //**************************************************************************
    //
    //      Primitive�N���X
    //
    //**************************************************************************

    //--------------------------------
    //  �R���X�g���N�^
    //--------------------------------
    Primitive::Primitive(ID3D11Device* device) :
        vertexShader(nullptr), pixelShader(nullptr), inputLayout(nullptr), buffer(nullptr), rasterizerState(nullptr)
    {
        //VertexBuffer�̍쐬
        vertex vertices[130] = { VECTOR3(0, 0, 0), VECTOR4(0, 0, 0, 0) };
        D3D11_BUFFER_DESC bd = {};
        bd.Usage = D3D11_USAGE_DYNAMIC;
        bd.ByteWidth = sizeof(vertices);			// ���_�o�b�t�@�̃T�C�Y
        bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// ���_�o�b�t�@
        bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;	// GPU���ǂݎ��̂݁@CPU���������݂̂�
        bd.MiscFlags = 0;
        bd.StructureByteStride = 0;
        D3D11_SUBRESOURCE_DATA initData = {};
        initData.pSysMem = vertices;	// ���_�̃A�h���X
        initData.SysMemPitch = 0;
        initData.SysMemSlicePitch = 0;
        if (FAILED(device->CreateBuffer(&bd, &initData, &buffer)))
        {
            assert(!"���_�o�b�t�@�̍쐬�Ɏ��s(Primitive)");
            return;
        }

        // ���_�錾
        // ���̓��C�A�E�g�̒�`
        D3D11_INPUT_ELEMENT_DESC layout[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,     D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };
        UINT numElements = ARRAYSIZE(layout);

        //	���_�V�F�[�_�[�̓ǂݍ���
        if (!ResourceManager::loadVertexShader(device, "./Data/Shaders/primitive_vs.cso", layout, numElements, &vertexShader, &inputLayout))
        {
            assert(!"���_�V�F�[�_�[�̓ǂݍ��݂Ɏ��s(Primitive)");
            return;
        }
        //	�s�N�Z���V�F�[�_�[�̍쐬
        if (!ResourceManager::loadPixelShader(device, "./Data/Shaders/primitive_ps.cso", &pixelShader))
        {
            assert(!"�s�N�Z���V�F�[�_�[�̍쐬�Ɏ��s(Primitive)");
            return;
        }

        //	���X�^���C�U�X�e�[�g�̐ݒ�
        D3D11_RASTERIZER_DESC rsDesc = {};
        rsDesc.FillMode = D3D11_FILL_SOLID;//
        rsDesc.CullMode = D3D11_CULL_NONE;//	�J�����O
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
            assert(!"���X�^���C�U�X�e�[�g�̍쐬�Ɏ��s(Primitive)");
            return;
        }

        D3D11_DEPTH_STENCIL_DESC dsDesc;
        dsDesc.DepthEnable = FALSE;
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
            assert(!"�f�v�X�X�e���V���X�e�[�g�̍쐬�Ɏ��s(Primitive)");
            return;
        }
    }

    //--------------------------------
    //  �f�X�g���N�^
    //--------------------------------
    Primitive::~Primitive()
    {
        safe_release(depthStencilState);
        safe_release(rasterizerState);
        safe_release(buffer);
        ResourceManager::releasePixelShader(pixelShader);
        ResourceManager::releaseVertexShader(vertexShader, inputLayout);
    }

    //--------------------------------
    //  �l�p�`�̕`��
    //--------------------------------
    void Primitive::rect(ID3D11DeviceContext* context, 
        const VECTOR2& pos, const VECTOR2& size,
        const VECTOR2& center, float angle, 
        const VECTOR4& color) const
    {
        if (size.x * size.y == 0.0f) return;

        D3D11_VIEWPORT viewport;
        UINT numViewports = 1;
        context->RSGetViewports(&numViewports, &viewport);

        vertex vertices[] = {
            { VECTOR3(-0.0f, +1.0f, 0), color },
            { VECTOR3(+1.0f, +1.0f, 0), color },
            { VECTOR3(-0.0f, -0.0f, 0), color },
            { VECTOR3(+1.0f, -0.0f, 0), color },
        };

        float sinValue = sinf(angle);
        float cosValue = cosf(angle);
        for (int i = 0; i < 4; i++) {
            vertices[i].position.x *= size.x;
            vertices[i].position.y *= size.y;
            vertices[i].position.x -= center.x;
            vertices[i].position.y -= center.y;

            float rx = vertices[i].position.x;
            float ry = vertices[i].position.y;
            vertices[i].position.x = rx * cosValue - ry * sinValue;
            vertices[i].position.y = rx * sinValue + ry * cosValue;
            vertices[i].position.x += pos.x;
            vertices[i].position.y += pos.y;

            vertices[i].position.x = vertices[i].position.x * 2 / viewport.Width - 1.0f;
            vertices[i].position.y = 1.0f - vertices[i].position.y * 2 / viewport.Height;
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
        context->OMSetDepthStencilState(depthStencilState, 1);

        context->Draw(4, 0);
    }

    //--------------------------------
    //  �l�p�`�̕`��
    //--------------------------------
    void Primitive::rect(ID3D11DeviceContext* context, 
        float x, float y, float w, float h,
        float cx, float cy, float angle, 
        float r, float g, float b, float a) const
    {
        rect(context, VECTOR2(x, y), VECTOR2(w, h), VECTOR2(cx, cy), angle, VECTOR4(r, g, b, a));
    }

    //--------------------------------
    //  ���̕`��
    //--------------------------------
    void Primitive::line(ID3D11DeviceContext* context,
        const VECTOR2& from, const VECTOR2& to,
        const VECTOR4& color, float width) const
    {
        if (width <= 0.0f) return;

        VECTOR2 v1(from.x, from.y);
        VECTOR2 v2(to.x, to.y);
        float w = vec2Length(v2 - v1);
        float h = width;
        float cx = w * 0.5f;
        float cy = h * 0.5f;
        float x = (from.x + to.x) * 0.5f;
        float y = (from.y + to.y) * 0.5f;
        float angle = atan2(to.y - from.y, to.x - from.x);

        rect(context, VECTOR2(x, y), VECTOR2(w, h), VECTOR2(cx, cy), angle, color);
    }

    //--------------------------------
    //  ���̕`��
    //--------------------------------
    void Primitive::line(ID3D11DeviceContext* context, 
        float x1, float y1, float x2, float y2,
        float r, float g, float b, float a, 
        float width) const
    {
        line(context, VECTOR2(x1, y1), VECTOR2(x2, y2), VECTOR4(r, g, b, a), width);
    }

    //--------------------------------
    //  �~�̕`��
    //--------------------------------
    void Primitive::circle(ID3D11DeviceContext* context,
        const VECTOR2& center, float radius,
        const VECTOR4& color, int n) const
    {
        if (n < 3 || radius <= 0.0f) return;
        if (n > 64) n = 64;//�ő�64�p�`

        D3D11_VIEWPORT viewport;
        UINT numViewports = 1;
        context->RSGetViewports(&numViewports, &viewport);

        vertex vertices[130] = { VECTOR3(0,0,0) };
        float arc = DirectX::XM_PI * 2 / n;
        vertex *p = &vertices[0];
        for (int i = 0; i <= n; i++)
        {
            p->position.x = center.x + cosf(-DirectX::XM_PI*0.5f + arc * i) * radius;
            p->position.y = center.y + sinf(-DirectX::XM_PI*0.5f + arc * i) * radius;
            p->position.x = p->position.x * 2 / viewport.Width - 1.0f;
            p->position.y = 1.0f - p->position.y * 2 / viewport.Height;
            p->color = color;
            p++;

            p->position.x = center.x; p->position.y = center.y;
            p->position.x = p->position.x * 2 / viewport.Width - 1.0f;
            p->position.y = 1.0f - p->position.y * 2 / viewport.Height;
            p->color = color;
            p++;
        }

        D3D11_MAPPED_SUBRESOURCE msr;
        context->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
        memcpy(msr.pData, vertices, sizeof(vertex) * (n + 1) * 2);
        context->Unmap(buffer, 0);

        UINT stride = sizeof(vertex);
        UINT offset = 0;
        context->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
        context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
        context->IASetInputLayout(inputLayout);
        context->RSSetState(rasterizerState);
        context->VSSetShader(vertexShader, NULL, 0);
        context->PSSetShader(pixelShader, NULL, 0);
        context->OMSetDepthStencilState(depthStencilState, 1);

        context->Draw((n + 1) * 2 - 1, 0);
    }

    //--------------------------------
    //  �~�̕`��
    //--------------------------------
    void Primitive::circle(ID3D11DeviceContext* context,
        float x, float y, float radius,
        float r, float g, float b, float a, int n) const
    {
        circle(context, VECTOR2(x, y), radius, VECTOR4(r, g, b, a), n);
    }

    //--------------------------------
    //  �l�p�|���S���̕`��
    //--------------------------------
    void Primitive::quad(ID3D11DeviceContext* context,
        const VECTOR2(&v)[4], const VECTOR4& color) const
    {
        D3D11_VIEWPORT viewport;
        UINT numViewports = 1;
        context->RSGetViewports(&numViewports, &viewport);

        vertex vertices[] = {
            { VECTOR3(v[3].x, v[3].y, 0), color },
            { VECTOR3(v[2].x, v[2].y, 0), color },
            { VECTOR3(v[0].x, v[0].y, 0), color },
            { VECTOR3(v[1].x, v[1].y, 0), color },
        };

        for (int i = 0; i < 4; i++)
        {
            vertices[i].position.x = vertices[i].position.x * 2 / viewport.Width - 1.0f;
            vertices[i].position.y = 1.0f - vertices[i].position.y * 2 / viewport.Height;
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
        context->OMSetDepthStencilState(depthStencilState, 1);

        context->Draw(4, 0);
    }

    //--------------------------------
    //  �l�p�|���S���̕`��
    //--------------------------------
    void Primitive::quad(ID3D11DeviceContext* context, 
        const VECTOR2(&v)[4],
        float r, float g, float b, float a) const
    {
        quad(context, v, VECTOR4(r, g, b, a));
    }

    //******************************************************************************
    //
    //      PrimitiveBatch�N���X
    //
    //******************************************************************************

    //--------------------------------
    //  �R���X�g���N�^
    //--------------------------------
    PrimitiveBatch::PrimitiveBatch(ID3D11Device* device, size_t maxInstance)
    {
        MAX_INSTANCES = maxInstance;

        //VertexBuffer�̍쐬
        vertex vertices[] = { VECTOR3(0, 0, 0), VECTOR3(1, 0, 0), VECTOR3(0, 1, 0), VECTOR3(1, 1, 0), };
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
            assert(!"���_�o�b�t�@�̍쐬�Ɏ��s(PrimitiveBatch)");
            return;
        }

        D3D11_INPUT_ELEMENT_DESC layout[] = {
            { "POSITION",	   0, DXGI_FORMAT_R32G32B32_FLOAT,	  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA,	  0 },
            { "NDC_TRANSFORM", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "NDC_TRANSFORM", 1, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "NDC_TRANSFORM", 2, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "NDC_TRANSFORM", 3, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
            { "COLOR",		   0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
        };
        UINT numElements = ARRAYSIZE(layout);
        if (!ResourceManager::loadVertexShader(device, "./Data/Shaders/primitive_batch_vs.cso", layout, numElements, &vertexShader, &inputLayout))
        {
            assert(!"���_�V�F�[�_�[�̓ǂݍ��݂Ɏ��s(PrimitiveBatch)");
            return;
        }
        if (!ResourceManager::loadPixelShader(device, "./Data/Shaders/primitive_batch_ps.cso", &pixelShader))
        {
            assert(!"�s�N�Z���V�F�[�_�[�̍쐬�Ɏ��s(PrimitiveBatch)");
            return;
        }

        instance *inst = new instance[MAX_INSTANCES];
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
                assert(!"�o�b�t�@�̍쐬�Ɏ��s(PrimitiveBatch)");
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
            assert(!"���X�^���C�U�X�e�[�g�̍쐬�Ɏ��s(PrimitiveBatch)");
            return;
        }

        D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
        depthStencilDesc.DepthEnable = FALSE;
        depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
        depthStencilDesc.DepthFunc = D3D11_COMPARISON_ALWAYS;
        depthStencilDesc.StencilEnable = FALSE;
        depthStencilDesc.StencilReadMask = 0xFF;
        depthStencilDesc.StencilWriteMask = 0xFF;
        depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
        depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
        depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
        depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
        depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
        depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
        depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
        depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
        if (FAILED(device->CreateDepthStencilState(&depthStencilDesc, &depthStencilState)))
        {
            assert(!"�f�v�X�X�e���V���X�e�[�g�̍쐬�Ɏ��s(PrimitiveBatch)");
            return;
        }
    }

    //--------------------------------
    //  �f�X�g���N�^
    //--------------------------------
    PrimitiveBatch::~PrimitiveBatch()
    {
        safe_release(instanceBuffer);
        safe_release(depthStencilState);
        safe_release(rasterizerState);
        safe_release(buffer);
        ResourceManager::releasePixelShader(pixelShader);
        ResourceManager::releaseVertexShader(vertexShader, inputLayout);
    }

    //--------------------------------
    //  �O�����i�`��O��1�x�Ăԁj
    //--------------------------------
    void PrimitiveBatch::begin(ID3D11DeviceContext* context)
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
    //	�l�p�`�̕`��
    //--------------------------------
    void PrimitiveBatch::rect(const VECTOR2& pos, const VECTOR2& size, const VECTOR2& center, float angle, const VECTOR4& color)
    {
        _ASSERT_EXPR(instanceCount < MAX_INSTANCES, L"Number of instances must be less than MAX_INSTANCES.");
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

        instances[instanceCount].ndcTransform._11 = w * size.x * c;
        instances[instanceCount].ndcTransform._21 = h * size.x * s;
        instances[instanceCount].ndcTransform._31 = 0.0f;
        instances[instanceCount].ndcTransform._41 = 0.0f;
        instances[instanceCount].ndcTransform._12 = w * size.y * -s;
        instances[instanceCount].ndcTransform._22 = h * size.y * c;
        instances[instanceCount].ndcTransform._32 = 0.0f;
        instances[instanceCount].ndcTransform._42 = 0.0f;
        instances[instanceCount].ndcTransform._13 = 0.0f;
        instances[instanceCount].ndcTransform._23 = 0.0f;
        instances[instanceCount].ndcTransform._33 = 1.0f;
        instances[instanceCount].ndcTransform._43 = 0.0f;
        instances[instanceCount].ndcTransform._14 = w * (-center.x * c + -center.y * -s + pos.x) - 1.0f;
        instances[instanceCount].ndcTransform._24 = h * (-center.x * s + -center.y *  c + pos.y) + 1.0f;
        instances[instanceCount].ndcTransform._34 = 0.0f;
        instances[instanceCount].ndcTransform._44 = 1.0f;
#endif
        instances[instanceCount].color = color;

        instanceCount++;
    }

    //--------------------------------
    //  �l�p�`�̕`��
    //--------------------------------
    void PrimitiveBatch::rect(float x, float y, float w, float h,
        float cx, float cy, float angle, float r, float g, float b, float a)
    {
        rect(VECTOR2(x, y), VECTOR2(w, h), VECTOR2(cx, cy), angle, VECTOR4(r, g, b, a));
    }

    //--------------------------------
    //  ���̕`��
    //--------------------------------
    void PrimitiveBatch::line(const VECTOR2& from, const VECTOR2& to, const VECTOR4& color, float width)
    {
        if (width <= 0.0f) return;
        VECTOR2 v1(from.x, from.y);
        VECTOR2 v2(to.x, to.y);
        float w = vec2Length(v2 - v1);
        float h = width;
        float cx = w * 0.5f;
        float cy = h * 0.5f;
        float x = (from.x + to.x) * 0.5f;
        float y = (from.y + to.y) * 0.5f;
        float angle = atan2(to.y - from.y, to.x - from.x);

        rect(VECTOR2(x, y), VECTOR2(w, h), VECTOR2(cx, cy), angle, color);
    }

    //--------------------------------
    //  ���̕`��
    //--------------------------------
    void PrimitiveBatch::line(float x1, float y1, float x2, float y2, float r, float g, float b, float a, float width)
    {
        line(VECTOR2(x1, y1), VECTOR2(x2, y2), VECTOR4(r, g, b, a), width);
    }

    //--------------------------------
    //  �㏈���i�`����1�x�Ăԁj
    //--------------------------------
    void PrimitiveBatch::end(ID3D11DeviceContext* context)
    {
        context->Unmap(instanceBuffer, 0);
        context->DrawInstanced(4, instanceCount, 0, 0);
    }

}

//******************************************************************************
