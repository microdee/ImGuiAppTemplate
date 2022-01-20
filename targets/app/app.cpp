#include "app.h"

#include "imgui.h"

using namespace ImGui;

void app::draw_gui()
{
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking
        | ImGuiWindowFlags_NoTitleBar
        | ImGuiWindowFlags_NoCollapse
        | ImGuiWindowFlags_NoResize
        | ImGuiWindowFlags_NoMove
        | ImGuiWindowFlags_NoBringToFrontOnFocus
        | ImGuiWindowFlags_NoNavFocus;

    ImGuiViewport* viewport = GetMainViewport();
    SetNextWindowPos(viewport->WorkPos);
    SetNextWindowSize(viewport->WorkSize);
    SetNextWindowViewport(viewport->ID);
    PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    bool open = true;
    Begin("Main", &open, window_flags);

    PopStyleVar(3);
    
    if (show_imgui_metrics) { ShowMetricsWindow(&show_imgui_metrics); }
    if (show_imgui_about) { ShowAboutWindow(&show_imgui_about); }
    if (show_style_editor)
    {
        Begin("Dear ImGui Style Editor", &show_style_editor);
        ShowStyleEditor();
        End();
    }
    
    ImGuiID dockspace_id = GetID("MainDockSpace");
    DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);
    SetNextWindowDockID(dockspace_id, ImGuiCond_Once);

    // your window here instead of the Demo
    ShowDemoWindow(&open);

    if (BeginMainMenuBar())
    {
        if (BeginMenu("File"))
        {
            if (MenuItem("Exit"))
            {
                ::PostQuitMessage(0);
            }
            ImGui::EndMenu();
        }
        if (BeginMenu("Tools"))
        {
            if (BeginMenu("ImGui"))
            {
                MenuItem("Metrics/Debugger", NULL, &show_imgui_metrics);
                MenuItem("Style Editor", NULL, &show_style_editor);
                MenuItem("About Dear ImGui", NULL, &show_imgui_about);
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        EndMainMenuBar();
    }
    End();
}

LRESULT app::wndproc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
