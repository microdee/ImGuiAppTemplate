
#pragma once

#include <Windows.h>

class app
{
public:
    void draw_gui();
    LRESULT wndproc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
    bool show_imgui_metrics = false;
    bool show_style_editor = false;
    bool show_imgui_about = false;
};