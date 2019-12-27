//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <stdio.h>

#include "all.h"

#include "main.h"

//------< �ϐ� >----------------------------------------------------------------
// �V�[���؂�ւ��p�ϐ��̐錾
int curScene;
int nextScene;

template<class SavaData>
void writeData(std::string fileName, SavaData data) //�f�[�^��������
{
    std::ofstream ofs(fileName);

    assert(ofs);

    ofs << data;
}



bool MyImGui::CreateDevice(HWND hWindow)
{
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWindow;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(
        NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        createDeviceFlags,
        featureLevelArray,
        2,
        D3D11_SDK_VERSION,
        &sd,
        &pSwapChain,
        &pDevice,
        &featureLevel,
        &pDeviceContext
    ) != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void MyImGui::CleanupDevice()
{
    CleanupRenderTarget();
    if (pSwapChain) { pSwapChain->Release(); pSwapChain = NULL; }
    if (pDeviceContext) { pDeviceContext->Release(); pDeviceContext = NULL; }
    if (pDevice) { pDevice->Release(); pDevice = NULL; }
}

void MyImGui::CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRenderTargetView);
    pBackBuffer->Release();
}

void MyImGui::CleanupRenderTarget()
{
    if (pRenderTargetView)
    {
        pRenderTargetView->Release();
        pRenderTargetView = NULL;
    }
}


//IMGUI_API LRESULT   ImGui_ImplDX11_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI MyImGui::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (pDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            CleanupRenderTarget();
            pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

//--------------------------------
//  WinMain�i�G���g���|�C���g�j
//--------------------------------
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    // �Q�[�����C�u�����̏����ݒ�
    GameLib::init(L"�Q�[���v���O���~���O�T�@����p�ЂȌ^", 
        (int)system::SCREEN_WIDTH, (int)system::SCREEN_HEIGHT, FALSE);

    // �u�����h���[�h�̐ݒ�
    GameLib::setBlendMode(Blender::BS_ALPHA);

    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = MyImGui::WndProc;
    wc.hInstance = GetModuleHandle(0);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"MyImGui";
    RegisterClassEx(&wc);

    MyImGui::hWindow = CreateWindow(wc.lpszClassName, L"MyImGui", WS_OVERLAPPEDWINDOW, 100, 100, 800, 800, NULL, NULL, wc.hInstance, NULL);

    if (MyImGui::hWindow == NULL)
    {
        std::cout << "�E�B���h�E�̍쐬�Ɏ��s\n";
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        std::exit(1);
    }

    if (!MyImGui::CreateDevice(MyImGui::hWindow))
    {
        std::cout << "�f�o�C�X�̍쐬�Ɏ��s\n";
        MyImGui::CleanupDevice();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        std::exit(1);
    }

    ShowWindow(MyImGui::hWindow, SW_SHOW);
    UpdateWindow(MyImGui::hWindow);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsLight();

    if (!ImGui_ImplWin32_Init(MyImGui::hWindow))
    {
        std::cout << "ImGui_ImplWin32_Init failed\n";
        ImGui::DestroyContext();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        std::exit(1);
    }

    // Setup Dear ImGui context
    //IMGUI_CHECKVERSION();
    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    //
    //// Setup Platform/Renderer bindings
    //ImGui_ImplDX11_Init(MyImGui::pDevice, MyImGui::pDeviceContext);
    ////ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
    //
    //// Setup Style
    //ImGui::StyleColorsDark();

    if (!ImGui_ImplDX11_Init(MyImGui::pDevice, MyImGui::pDeviceContext))
    {
        std::cout << "ImGui_ImplDX11_Init failed\n";
        ImGui::DestroyContext();
        //UnregisterClass(wc.lpszClassName, wc.hInstance);
        std::exit(1);
    }

    //ini�𐶐����Ȃ��悤��
    io.IniFilename = NULL;
    //���{��t�H���g�ɑΉ�
    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\meiryo.ttc", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());


    float clear_color[4] = { 0.45f, 0.55f, 0.60f, 1.00f };
    float color_picker[4] = { 0.0f, 0.0f, 0.0f, 0.0f };


    // �Q�[���V�[���̐ݒ�
    curScene  = SCENE_TITLE;
    nextScene = SCENE_TITLE;

    // ���y�E���ʉ��̏����ݒ���s���֐����Ă�
    audio_init();

    // �^�C�g���̏����ݒ���s��
    title_init();

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;

    // �Q�[�����[�v
    while (GameLib::gameLoop())
    {

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        /*
        �E�B���h�E�T�C�Y��ݒ肵�܂��B
        ImGuiCond_Once �ɂ��A����̂ݐݒ肳��܂��B
        ImGuiCond_Always �ŁA��ɐݒ肷�邱�Ƃ��ł��܂��B
        */
        ImGui::SetNextWindowSize(ImVec2(500, 600), ImGuiCond_Once);

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            ImGui::SliderFloat("player.x", &player.position.x, 0.0f, system::SCREEN_WIDTH); //�v���C���[��x���̃p�����[�^�[
            
            if (ImGui::Button("Save"))
            {
                //std::ofstream ofs("player.pos.txt");
                //
                //if (!ofs)
                //{
                //    std::cout << "�t�@�C�����J���܂���ł����B" << std::endl;
                //    return 0;
                //}
                //
                //ofs << player.position.x;

                writeData("player.pos.txt", player.position.x);
            }

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        //if (ImGui::Begin("MyImGui TitleBar Text", &MyImGui::show_gui))
        //{
        //    ImGui::Text(u8"�����͓V�C���ǂ��ł�");
        //
        //    //��؂��
        //    ImGui::Separator();
        //
        //    ImGui::Text(u8"���̂悤��");
        //    ImGui::SameLine();
        //    ImGui::Text(u8"�����s�ɃR���e���c��ǉ����邱�Ƃ��ł��܂�");
        //
        //    ImGui::Separator();
        //
        //    ImGui::Checkbox(u8"�`�F�b�N�{�b�N�X", &MyImGui::checkbox);
        //
        //    ImGui::Separator();
        //
        //    ImGui::ColorPicker4(u8"�J���[�s�b�J�[", color_picker);
        //
        //    //�t���[�����[�g��\��
        //    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        //
        //    ImGui::End();
        //}

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        // ���͏���
        input::update();

        // �Q�[���V�[���؂�ւ�
        if (nextScene != curScene)  // ���t���[���ŃV�[���ύX�������
        {
            switch (curScene)       // ���V�[���̏I���������s��
            {
            case SCENE_TITLE:
                title_end();
                break;
            case SCENE_GAME:
                game_end();
                break;
            }
            switch (nextScene)      // ���V�[���̏����ݒ���s��
            {
            case SCENE_TITLE:
                title_init();
                break;
            case SCENE_GAME:
                game_init();
                break;
            }
            curScene = nextScene;   // ���V�[���Ɏ��V�[����������
        }

        // ���݂̃V�[���ɉ������X�V����
        switch (curScene)
        {
        case SCENE_TITLE:
            title_update();
            break;
        case SCENE_GAME:
            game_update();
            break;
        }

        // ���݂̃V�[���ɉ������`�揈��
        switch (curScene)
        {
        case SCENE_TITLE:
            title_draw();
            break;
        case SCENE_GAME:
            game_draw();
            break;
        }

        // �f�o�b�O������̕`��
        debug::display(1, 0, 0, 1, 1);
        debug::setString("GP1_PROTO_TYPE");

        // �o�b�N�o�b�t�@�̓��e��\��
        GameLib::present(1, 0);

        //Rendering
        ImGui::Render();
        MyImGui::pDeviceContext->ClearRenderTargetView(MyImGui::pRenderTargetView, (float*)&clear_color);
        MyImGui::pDeviceContext->OMSetRenderTargets(1, &MyImGui::pRenderTargetView, NULL);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        MyImGui::pSwapChain->Present(1, 0); // Present with vsync
    }

    // ���݂̃V�[���ɉ������I������
    switch (curScene)
    {
    case SCENE_TITLE:
        title_end();
        break;
    case SCENE_GAME:
        game_end();
        break;
    }

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    MyImGui::CleanupDevice();
    DestroyWindow(MyImGui::hWindow);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    // ���y�E���ʉ��̏I���������Ă�ł���
    audio_uninit();

    // �I������
    GameLib::uninit();

    return 0;
}

//******************************************************************************
