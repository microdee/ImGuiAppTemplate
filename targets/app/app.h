
#pragma once

#include <Windows.h>
#include <optional>

class app
{
public:
    void draw_gui();
    std::optional<LRESULT> wndproc(std::optional<LRESULT> previous, HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    
private:
    bool show_imgui_metrics = false;
    bool show_style_editor = false;
    bool show_imgui_about = false;
};