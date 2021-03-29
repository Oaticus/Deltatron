#include <dt/win/win32/proc.hh>

#include <Windows.h>

void _dt_win32_do_paint(HWND const& window_handle) noexcept {
  auto paint_struct = PAINTSTRUCT{};
  HDC device_handle = BeginPaint(window_handle, &paint_struct);
  FillRect(device_handle, &paint_struct.rcPaint, (HBRUSH)(COLOR_WINDOW+1));
  EndPaint(window_handle, &paint_struct);
}

extern "C" LRESULT CALLBACK _dt_win32_window_proc(HWND window_handle, UINT message, WPARAM w_param, LPARAM l_param) noexcept {
  switch (message) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;

    case WM_PAINT:
      _dt_win32_do_paint(window_handle);
      return 0;

    default:
      return DefWindowProc(window_handle, message, w_param, l_param);
  }
}
