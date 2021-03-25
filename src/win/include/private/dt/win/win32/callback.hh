#pragma once

#include <Windows.h>

extern "C" LRESULT CALLBACK _dt_win32_callback(HWND handle, UINT message, WPARAM _wp, LPARAM _lp) noexcept;
