#include <dt/log.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

// #include <chrono>
#include <fstream>
#include <string>

// #include <ctime>

dt::log::log(directory const& log_dir, std::string const& file_name)
: _directory(log_dir),
  _file_name(file_name) { }

dt::log::~log() noexcept {}

void dt::log::write(log_level const level, std::string const& user_message) const noexcept {
  static char const* const _dt_log_info_str = "(INFO) ";
  static char const* const _dt_log_warn_str = "(WARN) ";
  static char const* const _dt_log_err_str  = "(ERR) ";

  std::string const message = [&] {
    switch (level) {
      case dt::log_level::Information: return _dt_log_info_str;
      case dt::log_level::Warning:     return _dt_log_warn_str;
      case dt::log_level::Error:       return _dt_log_err_str;
    }
  }() + user_message;

  _directory.append_file(message);

  // std::string const time_str = [] {
  //   auto const now = std::time_t(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
  //   auto const tm  = std::tm(*std::localtime(&now));
  //   auto       str = std::string(16,'\0');
  //   std::strftime(str.data(), str.size(), "[%H:%M:%s] ", &tm);
  //   return str;
  // }();
}
