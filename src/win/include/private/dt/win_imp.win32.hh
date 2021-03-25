#pragma once

#include <dt/win/win32/window_class.hh>
#include <dt/win/win32/window_handle.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <string>

#include <Windows.h>

namespace dt {

class win_imp final {
  HINSTANCE           const _instance;
  win32_window_class  const _window_class;
  win32_window_handle const _window_handle;

public:
  win_imp(cmd const&, fs const&);

  ~win_imp() noexcept;

  void show() const noexcept;

  void hide() const noexcept;

  void loop() const noexcept;

private:
  HINSTANCE _get_instance_handle() const;
};

}
