#include "ui_style.h"
#include "imgui.h" 

void ApplyCommandMenuStyle()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    ImVec4 text_color = ImVec4(0.15f, 0.15f, 0.15f, 1.00f); 
    ImVec4 text_disabled_color = ImVec4(0.55f, 0.55f, 0.55f, 1.00f); 
    ImVec4 bg_main = ImVec4(1.00f, 1.00f, 1.00f, 1.00f); 
    ImVec4 bg_secondary = ImVec4(0.96f, 0.96f, 0.97f, 1.00f); 
    ImVec4 border_color = ImVec4(0.88f, 0.88f, 0.88f, 1.00f); 
    ImVec4 hover_bg_color = ImVec4(0.92f, 0.92f, 0.93f, 1.00f); 
    ImVec4 active_bg_color = ImVec4(0.88f, 0.88f, 0.90f, 1.00f); 

    colors[ImGuiCol_Text] = text_color;
    colors[ImGuiCol_TextDisabled] = text_disabled_color;
    colors[ImGuiCol_WindowBg] = bg_main;
    colors[ImGuiCol_ChildBg] = bg_main; 
    colors[ImGuiCol_PopupBg] = bg_secondary;
    colors[ImGuiCol_Border] = border_color;
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f); 
    colors[ImGuiCol_FrameBg] = bg_secondary; 
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.88f, 0.88f, 0.88f, 1.00f);
    colors[ImGuiCol_TitleBg] = bg_main; 
    colors[ImGuiCol_TitleBgActive] = bg_main; 
    colors[ImGuiCol_TitleBgCollapsed] = bg_main; 
    colors[ImGuiCol_MenuBarBg] = bg_secondary;
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f); 
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
    colors[ImGuiCol_CheckMark] = text_color; 
    colors[ImGuiCol_SliderGrab] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
    colors[ImGuiCol_Button] = bg_secondary; 
    colors[ImGuiCol_ButtonHovered] = hover_bg_color;
    colors[ImGuiCol_ButtonActive] = active_bg_color;
    colors[ImGuiCol_Header] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f); 
    colors[ImGuiCol_HeaderHovered] = hover_bg_color; 
    colors[ImGuiCol_HeaderActive] = active_bg_color; 
    colors[ImGuiCol_Separator] = border_color;
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.70f, 0.70f, 0.70f, 1.00f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.8f, 0.8f, 0.8f, 0.20f); 
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.7f, 0.7f, 0.7f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.6f, 0.6f, 0.6f, 0.95f);
    colors[ImGuiCol_Tab] = bg_secondary;
    colors[ImGuiCol_TabHovered] = hover_bg_color;
    colors[ImGuiCol_TabActive] = bg_main; 
    colors[ImGuiCol_TabUnfocused] = bg_secondary;
    colors[ImGuiCol_TabUnfocusedActive] = bg_main;
    colors[ImGuiCol_DockingPreview] = ImVec4(0.75f, 0.75f, 0.75f, 0.7f); 
    colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f); 
    colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TableHeaderBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
    colors[ImGuiCol_TableBorderStrong] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
    colors[ImGuiCol_TableBorderLight] = ImVec4(0.88f, 0.88f, 0.90f, 1.00f);
    colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.00f, 0.00f, 0.00f, 0.04f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.75f, 0.75f, 0.75f, 0.45f); 
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered]; 
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.2f, 0.2f, 0.2f, 0.35f); 

    style.WindowRounding = 10.0f; 
    style.ChildRounding = 6.0f;
    style.FrameRounding = 8.0f;  
    style.PopupRounding = 6.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabRounding = 6.0f;
    style.TabRounding = 6.0f;

    style.WindowBorderSize = 1.0f; 
    style.FrameBorderSize = 0.0f; 
    style.PopupBorderSize = 1.0f; 
    style.ChildBorderSize = 0.0f; 
    style.TabBorderSize = 0.0f; 

    style.WindowPadding = ImVec2(14.0f, 14.0f); 
    style.FramePadding = ImVec2(10.0f, 7.0f); 
    style.ItemSpacing = ImVec2(8.0f, 6.0f);  
    style.ItemInnerSpacing = ImVec2(6.0f, 5.0f);  
    style.ScrollbarSize = 12.0f; 
    style.GrabMinSize = 12.0f;

    style.WindowTitleAlign = ImVec2(0.5f, 0.5f); 
    style.WindowMenuButtonPosition = ImGuiDir_None; 
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f); 
}
