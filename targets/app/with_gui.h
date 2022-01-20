
#pragma once
#include <cstdint>

template<typename TWithGui>
concept with_gui = requires(TWithGui a)
    {
        { a.draw_gui() } -> void;
    };

template<typename TWndProcListener>
concept wndproc_listener = requires(TWndProcListener a)
    {
        {
            a.wndproc(
                std::optional<int64_t>(), // previous result
                nullptr, // HWND
                uint32_t() // message
                uint64_t(), uint64_t() // wParam, lParam
            )
        } -> std::optional<LRESULT>;
    };