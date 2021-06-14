#include <dt/window/win32/sys.hh>

#include <Windows.h>

#include <algorithm>
#include <charconv>
#include <string>

namespace dt {

void win32_err_id_to_str(std::string& str) noexcept {
  str.erase();

  auto first = str.data();
  auto last  = first + str.size() - 1;

  std::to_chars(first, last, GetLastError());
}

}

char const* dt::win32_last_err_id() noexcept {
  static auto err_id_str = std::string(16, '\0');

  win32_err_id_to_str(err_id_str);

  return err_id_str.c_str();
}
