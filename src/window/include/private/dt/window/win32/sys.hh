#pragma once

// General-purpose functions for Win32-related assistance

#include <Windows.h>

namespace dt {

char const* win32_last_err_id() noexcept;

namespace win32literals {

constexpr BYTE operator""_win32byte(unsigned long long ull) noexcept { return ull; }

};

}
