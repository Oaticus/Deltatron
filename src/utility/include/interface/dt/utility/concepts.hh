#pragma once

#include <type_traits>

namespace dt {

template <typename T>
concept CharType =
  std::is_same_v<T, char   > || std::is_same_v<T, wchar_t > ||
  std::is_same_v<T, char8_t> || std::is_same_v<T, char16_t> || std::is_same_v<T, char32_t>;

}
