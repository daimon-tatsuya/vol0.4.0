#pragma once
#include <string>
#include <iostream>


//#include "all.h"

#include "imGui/imgui.h"
#include "imGui/imgui_impl_win32.h"
#include "imGui/imgui_impl_dx11.h"

#include "D3D11.h"
#include "GameLib\game_lib.h"
//#include "D3DX11.h"

namespace MyImGui {
    static ID3D11Device*            pDevice = NULL;
    static ID3D11DeviceContext*     pDeviceContext = NULL;
    static IDXGISwapChain*          pSwapChain = NULL;
    static ID3D11RenderTargetView*  pRenderTargetView = NULL;

    HWND hWindow;

    bool show_gui = true;
    bool checkbox;

    static bool CreateDevice(HWND hWindow);
    static void CleanupDevice();
    static void CreateRenderTarget();
    static void CleanupRenderTarget();

    static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
}




