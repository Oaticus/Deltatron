#include <dt/win/win32/callback.hh>

extern "C" void _dt_win32_callback_paint(HWND const& handle) noexcept {
  auto paint_struct          = PAINTSTRUCT{};
  auto device_context_handle = BeginPaint(handle, &paint_struct);

  FillRect(device_context_handle, &paint_struct.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
  EndPaint(handle, &paint_struct);
}

extern "C" LRESULT CALLBACK _dt_win32_callback(HWND handle, UINT message, WPARAM _wp, LPARAM _lp) noexcept {
  switch (message) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;

    case WM_PAINT:
      _dt_win32_callback_paint(handle);
      return 0;

    default:
      return DefWindowProc(handle, message, _wp, _lp);
  }
}
