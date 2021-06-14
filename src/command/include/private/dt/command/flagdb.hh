#pragma once

#include <dt/command/flag.hh>

#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include <sstream>

namespace dt {

struct flaginfo final {
  std::string const name;
  std::string const alias;
  std::string const def;

  flaginfo(std::string const& n, std::string const& a, std::string const& d) noexcept
  : name(n), alias(a), def(d) {}
};

class flagdb final {
  std::map<flag, flaginfo> const _flagdb;

public:
  flagdb() noexcept
  : _flagdb(_gen_db()) {}

  flaginfo const& flag_info(flag const f) const noexcept { return _flagdb.at(f); }

  std::string gen_helpmenu() const noexcept {
    auto const name_maxlen  = _name_maxlen();
    auto const alias_maxlen = _alias_maxlen();

    std::stringstream hms{};

    hms << std::left
      << std::setw(name_maxlen) << "Name"
      << std::setw(alias_maxlen) << "Alias"
      << "Description" << std::endl;

    for (auto const& p : _flagdb)
      hms << std::left
        << std::setw(name_maxlen) << p.second.name
        << std::setw(alias_maxlen) << p.second.alias
        << p.second.def << std::endl;

    return hms.str();
  }

private:
  std::map<flag, flaginfo> _gen_db() const noexcept {
    return std::map<flag, flaginfo>{
      std::pair<flag, flaginfo>(flag::help, flaginfo("--help", "-h", "Displays this help message")),
      std::pair<flag, flaginfo>(flag::version, flaginfo("--version", "-v", "Prints program version")),
      std::pair<flag, flaginfo>(flag::display_console, flaginfo("--console", "", "Displays console window during program runtime")),
      std::pair<flag, flaginfo>(flag::local_config, flaginfo("--local-config", "", "Writes config files to local executable directory"))
    };
  }

  std::streamsize _name_maxlen() const noexcept {
    auto const min_len = std::strlen("Name") + 2;

    auto const max_len = std::max_element(_flagdb.begin(), _flagdb.end(),
      [](auto const& b, auto const& n) {
        return b.second.name.size() < n.second.name.size();
      })->second.name.size() + 2;

    return static_cast<std::streamsize>(max_len < min_len ? min_len : max_len);
  }

  std::streamsize _alias_maxlen() const noexcept {
    auto const min_len = std::strlen("Alias") + 2;

    auto const max_len = std::max_element(_flagdb.begin(), _flagdb.end(),
      [](auto const& b, auto const& n) {
        return b.second.alias.size() < n.second.alias.size();
      })->second.alias.size() + 2;

    return static_cast<std::streamsize>(max_len < min_len ? min_len : max_len);
  }
};

}
