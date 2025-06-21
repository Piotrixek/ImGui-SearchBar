#define NOMINMAX
#include <Windows.h> 
#include <tchar.h>   

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include "dx_setup.h"       
#include "ui_style.h"       
#include "command_menu.h"   
#include "window_setup.h"   

int main(int, char**)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    const TCHAR* className = _T("ImGuiCommandMenuClass"); 
    HWND hwnd = SetupWindow(hInstance, className); 
    if (!hwnd) {
        return 1; 
    }

    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D(); 
        ::DestroyWindow(hwnd); 
        CleanupWindow(hInstance, className); 
        return 1; 
    }

    IMGUI_CHECKVERSION(); 
    ImGui::CreateContext(); 
    ImGuiIO& io = ImGui::GetIO(); (void)io; 
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; 
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   

    ApplyCommandMenuStyle();
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = style.WindowRounding; 
        style.Colors[ImGuiCol_WindowBg].w = 1.0f; 
    }

    ImGui_ImplWin32_Init(hwnd); 
    ImGui_ImplDX11_Init(GetDevice(), GetImmediateContext()); 


    bool done = false;
    bool show_command_menu = true; 
    while (!done)
    {
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg); 
            ::DispatchMessage(&msg); 
            if (msg.message == WM_QUIT) 
                done = true;
        }
        if (done) 
            break;

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ShowCommandMenuWindow(&show_command_menu);

        ImGui::Render(); 

        const float clear_color_with_alpha[4] = { 0.2f, 0.22f, 0.23f, 1.00f }; 
        ID3D11RenderTargetView* mainRenderTargetView = GetMainRenderTargetView(); 
        ID3D11DeviceContext* context = GetImmediateContext(); 

        if (mainRenderTargetView && context) {
            context->OMSetRenderTargets(1, &mainRenderTargetView, NULL); 
            context->ClearRenderTargetView(mainRenderTargetView, clear_color_with_alpha); 
        }

        if (ImGui::GetDrawData()) { 
            ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        }

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        IDXGISwapChain* swapChain = GetSwapChain(); 
        if (swapChain) {
            swapChain->Present(1, 0); 
        }
    } 

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    CleanupWindow(hInstance, className);

    return 0; 
}

