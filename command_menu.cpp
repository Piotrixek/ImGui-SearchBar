#include "command_menu.h"
#include "imgui.h"
#include "imgui_internal.h" 
static void DrawCommandMenuItem(const char* title, const char* subtitle, bool selected = false) {
    ImGuiStyle& style = ImGui::GetStyle();
    float itemHeight = ImGui::GetTextLineHeight() * 2 + style.ItemInnerSpacing.y + style.FramePadding.y * 2;
    ImVec2 itemSize = ImVec2(ImGui::GetContentRegionAvail().x, itemHeight);
    ImGui::PushID(title);
    ImGui::PushID(subtitle);
    ImGui::PushStyleColor(ImGuiCol_Header, ImVec4(0,0,0,0)); 
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, style.Colors[ImGuiCol_HeaderHovered]); 
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, style.Colors[ImGuiCol_HeaderActive]); 
    ImGui::Selectable("##selectable", selected, ImGuiSelectableFlags_AllowItemOverlap, itemSize);
    ImGui::PopStyleColor(3);
    ImGui::PopID();
    ImGui::PopID();
    ImVec2 itemRectMin = ImGui::GetItemRectMin();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImVec2 textPos = ImVec2(itemRectMin.x + style.FramePadding.x, itemRectMin.y + style.FramePadding.y); 
    draw_list->AddText(textPos, ImGui::GetColorU32(ImGuiCol_Text), title);
    textPos.y += ImGui::GetTextLineHeight() + style.ItemInnerSpacing.y * 0.5f; 
    draw_list->AddText(textPos, ImGui::GetColorU32(ImGuiCol_TextDisabled), subtitle);
}
void ShowCommandMenuWindow(bool* p_open)
{
    ImGuiWindowFlags command_menu_flags =
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize
          | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse
          | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoDocking; 
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    if (viewport) {
        ImVec2 window_pos = ImVec2(viewport->WorkPos.x + viewport->WorkSize.x * 0.5f, viewport->WorkPos.y + viewport->WorkSize.y * 0.2f);
        ImVec2 window_pivot = ImVec2(0.5f, 0.0f); 
        ImGui::SetNextWindowPos(window_pos, ImGuiCond_Appearing, window_pivot);
        ImGui::SetNextWindowSize(ImVec2(450, 0), ImGuiCond_Appearing); 
    } else {
         ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Appearing);
         ImGui::SetNextWindowSize(ImVec2(450, 400), ImGuiCond_Appearing);
    }
    ImGui::SetNextWindowBgAlpha(0.98f); 
    ImGui::Begin("Command Menu", p_open, command_menu_flags);
    ImGuiStyle& style = ImGui::GetStyle(); 
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 6.0f); 
    static char search_buf[128] = "";
    ImGui::PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]);
    ImGui::TextUnformatted("Q"); 
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(-1.0f); 
    ImGui::InputTextWithHint("##SearchCmd", "Search", search_buf, IM_ARRAYSIZE(search_buf));
    ImGui::PopStyleVar(); 
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::TextDisabled("Client"); 
    ImGui::Indent();
    DrawCommandMenuItem("Breanna Butler", "@breanna"); 
    ImGui::Unindent();
    ImGui::Spacing(); ImGui::Spacing(); 
    ImGui::TextDisabled("Project"); 
    ImGui::Indent();
    DrawCommandMenuItem("Marketing website", "Mobile view design", true); 
    DrawCommandMenuItem("Marketing website", "Content marketing strategy");
    DrawCommandMenuItem("Marketing website", "Infographic creation");
    DrawCommandMenuItem("Marketing website", "SEO optimization plan");
    ImGui::Unindent();
    ImGui::End(); 
}