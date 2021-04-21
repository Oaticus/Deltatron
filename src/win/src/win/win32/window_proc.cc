#include <dt/win/win32/window_proc.hh>

#include <Windows.h>

static void _dt_win32_do_paint(HWND const& window_handle) noexcept {
  auto paint_data    = PAINTSTRUCT{};
  auto device_handle = BeginPaint(window_handle, &paint_data);

  FillRect(device_handle, &paint_data.rcPaint, CreateSolidBrush(RGB(50, 0, 100)));
  EndPaint(window_handle, &paint_data);
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
