
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
        { a.wndproc(nullptr, uint32_t(), uint64_t(), uint64_t()) } -> int64_t;
    };