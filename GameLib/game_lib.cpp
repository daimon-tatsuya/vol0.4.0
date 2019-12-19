//******************************************************************************
//
//      GameLib
//
//      ECC College of Computer & Multimedia
//
//******************************************************************************

//------< ���C�u���� >-----------------------------------------------------------
#pragma comment( lib, "d3d11.lib" )
#pragma comment( lib, "dxgi.lib" )
#pragma comment( lib, "winmm.lib" )

#ifdef _DEBUG
#pragma comment( lib, "./GameLib/Lib/Debug/DirectXTK.lib" )
#pragma comment( lib, "./GameLib/Lib/Debug/DirectXTKAudioWin8.lib" )
#else
#pragma comment( lib, "./GameLib/Lib/Release/DirectXTK.lib" )
#pragma comment( lib, "./GameLib/Lib/Release/DirectXTKAudioWin8.lib" )
#endif

//------< �C���N���[�h >---------------------------------------------------------
#include "game_lib.h"
#include <ctime>
#include <crtdbg.h>

#include "blender.h"
#include "misc.h"
#include "util.h"

#include "high_resolution_timer.h"
#include "frame_rate.h"

#include "debug.h"
#include "primitive.h"
#include "input_manager.h"

namespace GameLib
{

    // �����ϐ��p�\���́����̐錾
    struct Members
    {
        // �E�C���h�E�֘A
        HWND hwnd;  // �E�C���h�E�n���h��

        // DirectX11�֘A
        ID3D11Device*           device;
        ID3D11DeviceContext*    context;
        IDXGISwapChain*         swapChain;
        ID3D11RenderTargetView* renderTargetView;
        ID3D11DepthStencilView* depthStencilView;
        ID3D11BlendState*       blendState;

        // ���̑�
        Blender*                blender;
        Debug*                  debug;
        Primitive*              primitive;
        PrimitiveBatch*         primitiveBatch;
        HighResolutionTimer     hrTimer;
    };

    static Members m;

    //--------------------------------------------------------------------------

    //**************************************************************************
    //
    //
    //      GameLib�C���^�[�t�F�C�X
    //
    //
    //**************************************************************************

    //==========================================================================
    //
    //      ���C�u���������ݒ聕�I�������AWindows API�Ȃ�
    //
    //==========================================================================

    //--------------------------------
    //  ���C�u���������ݒ�
    //--------------------------------
    void init(LPCTSTR caption, int width, int height, bool isFullscreen, double frameRate)
    {
        // �����n��̐ݒ�
        srand((unsigned int)time(NULL));

#ifdef _DEBUG
        // �t���X�N���[���̐ݒ�i�O�̂��߃f�o�b�O���[�h�ł͕s�j
        isFullscreen = false;
#endif

        // �E�C���h�E�̏����ݒ�
        m.hwnd = window::init(caption, width, height);

        // DirectX11�̏�����
        DirectX11::init(m.hwnd, width, height, isFullscreen);

        // �t���[�����[�g�̐ݒ�
        m.hrTimer.setFrameRate(frameRate);
    }

    //--------------------------------
    //  ���C�u�����I������
    //--------------------------------
    void uninit()
    {
        // DirectX11�̏I������
        DirectX11::uninit();

        // �E�C���h�E�̏I������
        window::uninit();
    }

    //--------------------------------
    //  �Q�[�����[�v�i���Ԃ̓��b�Z�[�W���[�v�j
    //--------------------------------
    bool gameLoop(bool isShowFrameRate)
    {
        MSG msg;
        while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) return false;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        //�t���[�����[�g�p
        while (!m.hrTimer.tick());
        if (isShowFrameRate)
        {
            calculateFrameStats(m.hwnd, &m.hrTimer);//�t���[�����[�g�v�Z�E�^�C�g���o�[�ɕ\��
        }

        return true;
    }

    //--------------------------------
    //  ��ʃN���A
    //--------------------------------
    void clear(const VECTOR4& color)
    {
        m.context->ClearRenderTargetView(m.renderTargetView, (const float *)&color);
        m.context->ClearDepthStencilView(m.depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1, 0);
    }

    //--------------------------------
    //  ��ʃN���A
    //--------------------------------
    void clear(float r, float g, float b)
    {
        clear(VECTOR4(r, g, b, 1.0f));
    }

    //--------------------------------
    //  ���̃o�b�N�o�b�t�@�̓��e��\��
    //--------------------------------
    HRESULT present(UINT SyncInterval, UINT Flags)
    {
        return m.swapChain->Present(SyncInterval, Flags);
    }

    //--------------------------------
    //  �u�����h���[�h�ݒ�
    //--------------------------------
    void setBlendMode(Blender::BLEND_STATE blend)
    {
        m.context->OMSetBlendState(m.blender->states[blend], nullptr, 0xFFFFFFFF);
    }

    //--------------------------------
    //  �X�v���C�g�ǂݍ���
    //--------------------------------
    void sprite_load(Sprite** ppSpr, const wchar_t* fileName)
    {
        *ppSpr = new Sprite(m.device, fileName);
    }

    //--------------------------------
    //  �X�v���C�g�`��
    //--------------------------------
    void sprite_render(Sprite* pSpr,
        float x, float y, float sx, float sy,
        float tx, float ty, float tw, float th,
        float cx, float cy, float angle,
        float r, float g, float b, float a)
    {
        if (pSpr)
        {
            pSpr->render(m.context, x, y, sx, sy, tx, ty, tw, th, cx, cy, angle, r, g, b, a);
        }
    }

    //==========================================================================
    //
    //      DirectX11
    //
    //==========================================================================

    //--------------------------------
    //  DirectX11�̏�����
    //--------------------------------
    HRESULT DirectX11::init(HWND hwnd, int width, int height, bool isFullscreen)
    {
        HRESULT hr = S_OK;

        UINT createDeviceFlags = 0;

#ifdef _DEBUG
//      createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif//_DEBUG

        D3D_DRIVER_TYPE driverTypes[] = {
            D3D_DRIVER_TYPE_UNKNOWN,
            D3D_DRIVER_TYPE_HARDWARE,
            D3D_DRIVER_TYPE_WARP,
            D3D_DRIVER_TYPE_REFERENCE,
        };
        UINT numDriverTypes = ARRAYSIZE(driverTypes);

        D3D_FEATURE_LEVEL featureLevels[] = {
            D3D_FEATURE_LEVEL_11_0,
            D3D_FEATURE_LEVEL_10_1,
            D3D_FEATURE_LEVEL_10_0,
            D3D_FEATURE_LEVEL_9_3,
            D3D_FEATURE_LEVEL_9_2,
            D3D_FEATURE_LEVEL_9_1,
        };
        UINT numFeatureLevels = ARRAYSIZE(featureLevels);

        //bool enable_4x_msaa = false;  // ���g�p

        for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
        {
            D3D_DRIVER_TYPE driverType = driverTypes[driverTypeIndex];
            D3D_FEATURE_LEVEL featureLevel;
            hr = D3D11CreateDevice(nullptr, driverType, nullptr, createDeviceFlags, featureLevels,
                numFeatureLevels, D3D11_SDK_VERSION, &m.device, &featureLevel, &m.context);
            if (SUCCEEDED(hr)) break;
        }
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr)) return false;

        DXGI_SWAP_CHAIN_DESC sd = { 0 };
        sd.BufferCount = 1;
        sd.BufferDesc.Width = width;
        sd.BufferDesc.Height = height;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 0;
        sd.BufferDesc.RefreshRate.Denominator = 0;
        sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.Windowed = !isFullscreen;
        sd.OutputWindow = hwnd;

#ifdef	MSAA
        UINT msaa_quality_level;
        device->CheckMultisampleQualityLevels(sd.BufferDesc.Format, 16, &msaa_quality_level);
        enable_4x_msaa = msaa_quality_level > 0 ? true : false;
        sd.SampleDesc.Count = enable_4x_msaa ? 4 : 1;
        sd.SampleDesc.Quality = enable_4x_msaa ? msaa_quality_level - 1 : 0;
#else //MSAA
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
#endif//MSAA
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
        sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

#if 1
        IDXGIDevice *dxgi;
        hr = m.device->QueryInterface(__uuidof(IDXGIDevice), (void **)&dxgi);
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr))	return false;

        IDXGIAdapter1 *adapter;
        hr = dxgi->GetAdapter((IDXGIAdapter **)&adapter);
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr))	return false;

        IDXGIFactory1 *factory;
        hr = adapter->GetParent(__uuidof(IDXGIFactory1), (void **)&factory);
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr))	return false;

        hr = factory->CreateSwapChain(m.device, &sd, &m.swapChain);

        // �t���X�N���[������
        m.swapChain->SetFullscreenState(isFullscreen, nullptr);
        if (!isFullscreen)
        {
            //������Ԃ��t���X�N���[���łȂ���΁A���[�h�ؑւ��֎~����
            factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_WINDOW_CHANGES | DXGI_MWA_NO_ALT_ENTER);
        }

        factory->Release();
        adapter->Release();
        dxgi->Release();
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr))	return false;
#else
        IDXGIFactory1 *factory;
        CreateDXGIFactory(__uuidof(IDXGIFactory), (void **)&factory);
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr))	return false;
        hr = factory->CreateSwapChain(Device, &sd, &SwapChain);
        factory->Release();
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr))	return false;
#endif

        //Create a render target view
        D3D11_TEXTURE2D_DESC back_buffer_desc;
        ID3D11Texture2D *pBackBuffer = nullptr;
        hr = m.swapChain->GetBuffer(
            0,
            __uuidof(ID3D11Texture2D),
            (LPVOID *)&pBackBuffer
            );
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr)) return false;
        hr = m.device->CreateRenderTargetView(
            pBackBuffer,
            nullptr,
            &m.renderTargetView
            );
        pBackBuffer->GetDesc(&back_buffer_desc);
        pBackBuffer->Release();
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr)) return false;

        //Create depth stencil texture
        D3D11_TEXTURE2D_DESC descDepth = back_buffer_desc;
        ID3D11Texture2D *DepthStencil;
        descDepth.MipLevels = 1;
        descDepth.ArraySize = 1;
        descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        descDepth.Usage = D3D11_USAGE_DEFAULT;
        descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
        descDepth.CPUAccessFlags = 0;
        descDepth.MiscFlags = 0;
        hr = m.device->CreateTexture2D(&descDepth, nullptr, &DepthStencil);
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));

        //Create the depth stencil view
        D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
        SecureZeroMemory(&descDSV, sizeof(descDSV));
        descDSV.Format = descDepth.Format;
#ifdef MSAA
        descDSV.ViewDimension = enable_4x_msaa ? D3D11_DSV_DIMENSION_TEXTURE2DMS : D3D11_DSV_DIMENSION_TEXTURE2D;
#else//MSAA
        descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
#endif//MSAA
        descDSV.Flags = 0;
        descDSV.Texture2D.MipSlice = 0;
        hr = m.device->CreateDepthStencilView(DepthStencil, &descDSV, &m.depthStencilView);
        DepthStencil->Release();
        _ASSERT_EXPR_A(SUCCEEDED(hr), hr_trace(hr));
        if (FAILED(hr)) return false;

        //Setup the viewport
        D3D11_VIEWPORT vp;
        vp.Width = (FLOAT)width;//��
        vp.Height = (FLOAT)height;//����
        vp.MinDepth = 0.0f;
        vp.MaxDepth = 1.0f;
        vp.TopLeftX = 0;
        vp.TopLeftY = 0;
        m.context->RSSetViewports(1, &vp);
        m.context->OMSetRenderTargets(1, &m.renderTargetView, m.depthStencilView);

        m.blender = new Blender(m.device);
        m.debug = new Debug(m.device, L"./Data/fonts/font4.png", system::DEBUG_INSTANCE_NUM, height);
        m.primitive = new Primitive(m.device);
        m.primitiveBatch = new PrimitiveBatch(m.device, system::PRIMITIVE_BATCH_INSTANCE_NUM);

        // �ő喇��256�Ńe�N�X�`��������
        TextureManager::getInstance()->init(system::TEXTURE_NUM);

        // InputManager�̏�����
        InputManager::getInstance()->init();

        // FontManager�̏�����
        FontManager::getInstance()->init(m.device);

        // DXTKAudio
        audio::DXTKAudio::getInstance();   // �C���X�^���X�𐶐����Ă���

        return hr;
    }

    //--------------------------------
    //  DirectX11�̏I������
    //--------------------------------
    void DirectX11::uninit()
    {
        m.swapChain->SetFullscreenState(false, nullptr);

        safe_delete(m.primitiveBatch);
        safe_delete(m.primitive);
        safe_delete(m.debug);
        safe_delete(m.blender);

        safe_release(m.depthStencilView);
        safe_release(m.renderTargetView);
        safe_release(m.swapChain);
        safe_release(m.context);
        safe_release(m.device);
    }

    //==========================================================================
    //
    //      window
    //
    //==========================================================================

    //--------------------------------------------------------------------------
    static const LPCWSTR CLASS_NAME = L"2dgp";

    //------< �v���g�^�C�v�錾 >-------------------------------------------------
    LRESULT CALLBACK fnWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    //--------------------------------
    //  �E�C���h�E�̏���������
    //--------------------------------
    HWND window::init(LPCTSTR caption, int width, int height)
    {
#if defined(DEBUG) | defined(_DEBUG)
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

        WNDCLASSEX wcex;
        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = fnWndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = GetModuleHandle(NULL);
        wcex.hIcon = NULL;
        wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = NULL;
        wcex.lpszClassName = CLASS_NAME;
        wcex.hIconSm = 0;
        RegisterClassEx(&wcex);

        RECT rc = { 0, 0, width, height };
        AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
        HWND hwnd = CreateWindow(CLASS_NAME, caption, WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, GetModuleHandle(NULL), NULL);
        ShowWindow(hwnd, SW_SHOWDEFAULT);

        return hwnd;
    }

    //--------------------------------
    //  �E�C���h�E�̏I������
    //--------------------------------
    void window::uninit()
    {
        // �I������
        UnregisterClass(CLASS_NAME, GetModuleHandle(NULL));
    }

    //--------------------------------
    //  �E�C���h�E�v���V�[�W��
    //--------------------------------
    LRESULT CALLBACK fnWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        using DirectX::Keyboard;

        switch (msg)
        {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc;
            hdc = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_ACTIVATEAPP:
            Keyboard::ProcessMessage(msg, wParam, lParam);
            break;
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE)
            {
                PostMessage(hwnd, WM_CLOSE, 0, 0);
                break;
            }
        case WM_SYSKEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYUP:
            Keyboard::ProcessMessage(msg, wParam, lParam);
            break;
        case WM_ENTERSIZEMOVE:
            // WM_EXITSIZEMOVE is sent when the user grabs the resize bars.
            m.hrTimer.stop();
            break;
        case WM_EXITSIZEMOVE:
            // WM_EXITSIZEMOVE is sent when the user releases the resize bars.
            // Here we reset everything based on the new window dimensions.
            m.hrTimer.start();
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }
        return 0;
    }

    //==========================================================================
    //
    //      texture_manager
    //
    //==========================================================================

    namespace texture
    {

        //--------------------------------
        //  �e�N�X�`���}�l�[�W��������
        //--------------------------------
        void init(size_t max)
        {
            TextureManager::getInstance()->init(max);
        }

        //--------------------------------
        //  �e�N�X�`���}�l�[�W���I������
        //--------------------------------
        void uninit()
        {
            TextureManager::getInstance()->uninit();
        }

        //--------------------------------
        //  �e�N�X�`���̃��[�h�i�ԍ����w�肵�ă��[�h�j
        //--------------------------------
        void load(int texNo, const wchar_t* fileName, size_t maxInstance)
        {
            TextureManager::getInstance()->load(m.device, texNo, fileName, maxInstance);
        }

        //--------------------------------
        //  �e�N�X�`���̃��[�h�i�󂫔ԍ���T���ă��[�h�j
        //--------------------------------
        int load(const wchar_t* fileName, size_t maxInstance)
        {
            return TextureManager::getInstance()->load(m.device, fileName, maxInstance);
        }

        //--------------------------------
        //  �e�N�X�`���̃��[�h�i���[�h�e�N�X�`���̃f�[�^���g���ă��[�h�j
        //--------------------------------
        void load(const LoadTexture* data)
        {
            TextureManager::getInstance()->load(m.device, data);
        }

        //--------------------------------
        //  �e�N�X�`���̉���i�ԍ����w�肵�ĉ���j
        //--------------------------------
        void release(int texNo)
        {
            TextureManager::getInstance()->release(texNo);
        }

        //--------------------------------
        //  �e�N�X�`���̉���i���[�h�e�N�X�`���̃f�[�^���g���ĉ���j
        //--------------------------------
        void release(const LoadTexture* data)
        {
            TextureManager::getInstance()->release(data);
        }

        //--------------------------------
        //  �e�N�X�`���̉���i�S�āj
        //--------------------------------
        void releaseAll()
        {
            TextureManager::getInstance()->releaseAll();
        }

        //--------------------------------
        //  �`��̑O����
        //--------------------------------
        void begin(int texNo)
        {
            TextureManager::getInstance()->begin(m.context, texNo);
        }

        //--------------------------------
        //  �`��̌㏈��
        //--------------------------------
        void end(int texNo)
        {
            TextureManager::getInstance()->end(m.context, texNo);
        }

        //--------------------------------
        //  �e�N�X�`���̕`��
        //--------------------------------
        void draw(int texNo, 
            float x, float y, float scaleX, float scaleY,
            float left, float top, float width, float height,
            float centerX, float centerY, float angle,
            float r, float g, float b, float a)
        {
            TextureManager::getInstance()->draw(texNo,
                x, y, scaleX, scaleY,
                left, top, width, height,
                centerX, centerY, angle,
                r, g, b, a);
        }

        //--------------------------------
        //  �e�N�X�`���̕`��
        //--------------------------------
        void draw(int texNo,
            const VECTOR2& position, const VECTOR2& scale,
            const VECTOR2& texPos, const VECTOR2& texSize,
            const VECTOR2& center, float angle,
            const VECTOR4& color)
        {
            TextureManager::getInstance()->draw(texNo,
                position, scale,
                texPos, texSize, 
                center, angle,
                color);
        }

    }

    //==========================================================================
    //
    //      primitive
    //
    //==========================================================================

    namespace primitive
    {

        //--------------------------------
        //  ��`�`��
        //--------------------------------
        void rect(
            float x, float y, float w, float h,
            float cx, float cy, float angle,
            float r, float g, float b, float a)
        {
            m.primitive->rect(m.context, x, y, w, h, cx, cy, angle, r, g, b, a);
        }

        //--------------------------------
        //  ��`�`��
        //--------------------------------
        void rect(
            const VECTOR2& position, const VECTOR2& size,
            const VECTOR2& center, float angle, 
            const VECTOR4& color)
        {
            m.primitive->rect(m.context, position, size, center, angle, color);
        }

        //------------------------------------------------------
        //  ���`��
        //------------------------------------------------------
        void line(
            float x1, float y1, float x2, float y2,
            float r, float g, float b, float a,
            float width)
        {
            m.primitive->line(m.context, x1, y1, x2, y2, r, g, b, a, width);
        }

        //--------------------------------
        //  ���`��
        //--------------------------------
        void line(
            const VECTOR2& from, const VECTOR2& to,
            const VECTOR4& color,
            float width)
        {
            m.primitive->line(m.context, from, to, color, width);
        }

        //------------------------------------------------------
        //  �~�`��
        //------------------------------------------------------
        void circle(
            float x, float y, float radius,
            float r, float g, float b, float a,
            int n)
        {
            m.primitive->circle(m.context, x, y, radius, r, g, b, a, n);
        }

        //------------------------------------------------------
        //  �~�`��
        //------------------------------------------------------
        void circle(
            const VECTOR2& pos, float radius,
            const VECTOR4& color, 
            int n)
        {
            m.primitive->circle(m.context, pos, radius, color, n);
        }

        //------------------------------------------------------
        //  �l�p�|���S���`��i���_�w��j
        //------------------------------------------------------
        void quad(const VECTOR2(&v)[4], float r, float g, float b, float a)
        {
            m.primitive->quad(m.context, v, r, g, b, a);
        }

        //------------------------------------------------------
        //  �l�p�|���S���`��i���_�w��j
        //------------------------------------------------------
        void quad(const VECTOR2 (&v)[4], const VECTOR4& color)
        {
            m.primitive->quad(m.context, v, color);
        }

    }

    //==========================================================================
    //
    //      primitive_batch
    //
    //==========================================================================

    namespace primitive_batch
    {

        //------------------------------------------------------
        //	�O����
        //------------------------------------------------------
        void begin()
        {
            m.primitiveBatch->begin(m.context);
        }

        //------------------------------------------------------
        //  �㏈��
        //------------------------------------------------------
        void end()
        {
            m.primitiveBatch->end(m.context);
        }

        //------------------------------------------------------
        //  ��`�`��
        //------------------------------------------------------
        void rect(
            float x, float y, float w, float h,
            float cx, float cy, float angle,
            float r, float g, float b, float a)
        {
            m.primitiveBatch->rect(x, y, w, h, cx, cy, angle, r, g, b, a);
        }

        //------------------------------------------------------
        //  ��`�`��
        //------------------------------------------------------
        void rect(
            const VECTOR2& pos, const VECTOR2& size,
            const VECTOR2& center, float angle,
            const VECTOR4& color)
        {
            m.primitiveBatch->rect(pos, size, center, angle, color);
        }

        //------------------------------------------------------
        //  ���`��
        //------------------------------------------------------
        void line(
            float x1, float y1, float x2, float y2,
            float r, float g, float b, float a,
            float width)
        {
            m.primitiveBatch->line(x1, y1, x2, y2, r, g, b, a, width);
        }

        //------------------------------------------------------
        //  ���`��
        //------------------------------------------------------
        void line(
            const VECTOR2& from, const VECTOR2& to,
            const VECTOR4& color, 
            float width)
        {
            m.primitiveBatch->line(from, to, color, width);
        }

    }

    //==========================================================================
    //
    //      music
    //
    //==========================================================================

    namespace music
    {

        //--------------------------------
        //  ���y�̃��[�h
        //--------------------------------
        void load(int trackNo, const wchar_t* waveFileName, float volume)
        {
            audio::DXTKAudio::getInstance()->musicLoad(trackNo, waveFileName, volume);
        }

        //--------------------------------
        //  ���y�̉��
        //--------------------------------
        void unload(int trackNo)
        {
            audio::DXTKAudio::getInstance()->musicUnload(trackNo);
        }

        //--------------------------------
        //  ���y�̍Đ�
        //--------------------------------
        void play(int trackNo, bool isLoop)
        {
            audio::DXTKAudio::getInstance()->musicPlay(trackNo, isLoop);
        }

        //--------------------------------
        //  ���y�̒�~
        //--------------------------------
        void stop(int trackNo)
        {
            audio::DXTKAudio::getInstance()->musicStop(trackNo);
        }

        //--------------------------------
        //  ���y�̈ꎞ��~
        //--------------------------------
        void pause(int trackNo)
        {
            audio::DXTKAudio::getInstance()->musicPause(trackNo);
        }

        //--------------------------------
        //  ���y�̍ĊJ(pause����̍ĊJ)
        //--------------------------------
        void resume(int trackNo)
        {
            audio::DXTKAudio::getInstance()->musicResume(trackNo);
        }

        //--------------------------------
        //  ���y�̃{�����[���ݒ�
        //--------------------------------
        void setVolume(int trackNo, float volume)
        {
            audio::DXTKAudio::getInstance()->musicSetVolume(trackNo, volume);
        }

        //--------------------------------
        //  ���y�̃N���A
        //--------------------------------
        void clear()
        {
            for (int i = 0; i < MUSIC_FILE_MAX; i++)
            {
                stop(i);     // ���y���~�߂�
                unload(i);   // ���y���������
            }
        }

        //--------------------------------
        //  SoundState�̎擾
        //--------------------------------
        DirectX::SoundState getState(int trackNo)
        {
            return audio::DXTKAudio::getInstance()->musicGetState(trackNo);
        }

        //--------------------------------
        //  ���[�v�̗L���̎擾
        //--------------------------------
        bool isLooped(int trackNo)
        {
            return audio::DXTKAudio::getInstance()->musicIsLooped(trackNo);
        }

        //--------------------------------
        //  pan�̐ݒ�
        //--------------------------------
        void setPan(int trackNo, float pan)
        {
            audio::DXTKAudio::getInstance()->musicSetPan(trackNo, pan);
        }

        //--------------------------------
        //  pitch�̐ݒ�
        //--------------------------------
        void setPitch(int trackNo, float pitch)
        {
            audio::DXTKAudio::getInstance()->musicSetPitch(trackNo, pitch);
        }

        //--------------------------------
        //  �t�H�[�}�b�g�̎擾
        //--------------------------------
        const WAVEFORMATEX* getFormat(int trackNo)
        {
            return audio::DXTKAudio::getInstance()->musicGetFormat(trackNo);
        }

        //--------------------------------
        //  ���y���g�p�����ǂ���
        //--------------------------------
        bool isInUse(int trackNo)
        {
            return audio::DXTKAudio::getInstance()->musicIsInUse(trackNo);
        }
    }

    //==========================================================================
    //
    //      sound
    //
    //==========================================================================

    namespace sound
    {

        //--------------------------------
        //  ���ʉ��t�@�C���̃��[�h
        //--------------------------------
        void load(const wchar_t* xwbFileName, float volume)
        {
            audio::DXTKAudio::getInstance()->soundLoad(xwbFileName, volume);
        }

        //--------------------------------
        //  ���ʉ��̍Đ�
        //--------------------------------
        void play(int trackNo)
        {
            audio::DXTKAudio::getInstance()->soundPlay(trackNo);
        }

        //--------------------------------
        //  ���ʉ��̃{�����[���ݒ�
        //--------------------------------
        void setVolume(int trackNo, float volume)
        {
            audio::DXTKAudio::getInstance()->soundSetVolume(trackNo, volume);
        }
    }

    //==========================================================================
    //
    //      debug
    //
    //==========================================================================

    namespace debug
    {
        //--------------------------------
        //  �f�o�b�O��������Z�b�g����i�L���[�Ɋi�[����j
        //--------------------------------
        void setString(const char *format, ...)
        {
            char str[256];
            vsprintf_s(str, format, (char *)(&format + 1));
            m.debug->setString(str);
        }

        //--------------------------------
        //  �f�o�b�O�������\��������
        //--------------------------------
        void display(float r, float g, float b, float sx, float sy)
        {
            m.debug->display(m.context, r, g, b, sx, sy);
        }

    }

    //==========================================================================
    //
    //      font
    //
    //==========================================================================

    namespace font
    {

        //--------------------------------
        //  �����̕`��
        //--------------------------------
        float textOut(
            int fontNo, std::string str,
            float x, float y, float scaleX, float scaleY,
            float r, float g, float b, float a)
        {
            return FontManager::getInstance()->textOut(m.context,
                fontNo, str,
                x, y, scaleX, scaleY,
                r, g, b, a);
        }

        //--------------------------------
        //  �����̕`��
        //--------------------------------
        float textOut(
            int fontNo, std::string str,
            const VECTOR2& position, const VECTOR2& scale,
            const VECTOR4& color)
        {
            return FontManager::getInstance()->textOut(m.context,
                fontNo, str,
                position, scale, color);
        }

        //--------------------------------
        //  ������̃t�H�[�}�b�g
        //--------------------------------
        LPCSTR FormatString(LPCSTR format, ...)
        {
            static CHAR buf[1024];
            va_list args;
            va_start(args, format);
            vsnprintf_s(buf, sizeof(buf), 1024, format, args);
            va_end(args);
            return buf;
        }

    }

    //==========================================================================
    //
    //      input
    //
    //==========================================================================

    namespace input
    {

        //--------------------------------
        //  ���̓}�l�[�W���̏�����
        //--------------------------------
        void init()
        {
            InputManager::getInstance()->init();
        }

        //--------------------------------
        //  ���̓}�l�[�W���̍X�V
        //--------------------------------
        void update()
        {
            InputManager::getInstance()->update(m.hwnd);
        }

        //--------------------------------
        //  �g���K�[�i�������u�ԁj���̎擾
        //--------------------------------
        int TRG(int player)
        {
            return InputManager::getInstance()->getPadAddress()[player].trigger;
        }

        //--------------------------------
        //  �g���K�[�i�������u�ԁj���̎擾
        //--------------------------------
        int TRG_UP(int player)
        {
            return InputManager::getInstance()->getPadAddress()[player].triggerUp;
        }

        //--------------------------------
        //  �X�e�[�g�i��ԁj���̎擾
        //--------------------------------
        int STATE(int player)
        {
            return InputManager::getInstance()->getPadAddress()[player].state;
        }

        //--------------------------------
        //  ���s�[�g�i�J�Ԃ��j���̎擾
        //--------------------------------
        int REPEAT(int player)
        {
            return InputManager::getInstance()->getPadAddress()[player].repeat;
        }

        //--------------------------------
        //  �}�E�X�J�[�\����x���W���擾
        //--------------------------------
        int getCursorPosX()
        {
            return InputManager::getInstance()->getCursorPosX();
        }

        //--------------------------------
        //  �}�E�X�J�[�\����y���W���擾
        //--------------------------------
        int getCursorPosY()
        {
            return InputManager::getInstance()->getCursorPosY();
        }

        //--------------------------------
        //  �R���g���[���̏�Ԃ��擾
        //--------------------------------
        //PadState*
        // ::PadState* getPadState(int player)
        PadState* getPadState(int player)
        {
            return &InputManager::getInstance()->getPadAddress()[player];
        }

    }
}

//******************************************************************************
