#include <dt/window/win32/proc.hh>

#include <dt/window/win32/sys.hh> // _w32byte

#include <Windows.h>

extern "C" inline void _dt_win32_paint(HWND const& window_handle) noexcept {
  using namespace dt::win32literals;

  auto paint_data    = PAINTSTRUCT{};
  auto device_handle = BeginPaint(window_handle, &paint_data);

  auto const purple = COLORREF(50_win32byte | 0_win32byte << 8_win32byte | 100_win32byte << 16_win32byte);

  FillRect(device_handle, &paint_data.rcPaint, CreateSolidBrush(purple));
  EndPaint(window_handle, &paint_data);
}

extern "C" LRESULT CALLBACK _dt_win32_window_proc(HWND window_handle, UINT message, WPARAM w_param, LPARAM l_param) noexcept {
  switch (message) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;

    case WM_PAINT:
      _dt_win32_paint(window_handle);
      return 0;

    default:
      return DefWindowProc(window_handle, message, w_param, l_param);
  }
}
