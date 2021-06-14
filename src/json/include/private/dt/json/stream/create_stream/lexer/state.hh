#pragma once

#include <dt/json/error.hh>
#include <dt/json/token.hh>

#include <charconv>
#include <optional>
#include <string>

namespace dt {

class lexer_state final {
public:
  using const_pointer   = std::string::const_pointer;
  using difference_type = std::string::difference_type;
  using size_type       = std::string::size_type;

private:
  std::string   const& _id;
  std::string   const& _text_data;
  const_pointer const  _end;
  const_pointer        _current_char;
  size_type            _line;

public:
  lexer_state(std::string const& id, std::string const& text_data) noexcept;

  constexpr auto current_char() const noexcept -> const_pointer      { return _current_char; }
  constexpr auto end()          const noexcept -> const_pointer      { return _end;          }
  constexpr auto line()         const noexcept -> size_type          { return _line;         }
  constexpr auto id()           const noexcept -> std::string const& { return _id;           }

  constexpr auto eof() const noexcept -> bool { return _current_char >= _end; }

  constexpr auto increment_line(size_type const n = 1)   noexcept -> void { _line += n;         }
  constexpr auto decrement_line(size_type const n = 1)   noexcept -> void { _line -= n;         }
  constexpr auto set_current_char(const_pointer const p) noexcept -> void { _current_char = p;  }
  constexpr auto shift_current_char(difference_type n)   noexcept -> void { _current_char += n; }

  constexpr auto skip_whitespace() noexcept -> void {
    do {
      ++_current_char;

      if (*_current_char == '\n')
        ++_line;

    } while (!eof() && *_current_char <= ' ');
  }

  [[noreturn]] auto throw_error(char const* message) const -> void;
};

}
