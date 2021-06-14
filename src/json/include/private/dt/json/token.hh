#pragma once

#include <iosfwd>      // std::ostream
#include <optional>
#include <string>
#include <type_traits> // std::is_same_v
#include <variant>
#include <vector>

namespace dt {

enum class token_type : char {
    String  = 1,
    Integer = 2,
    Float   = 4,
    Bool    = 8,
    Null    = 16,

    LBrace  = '{',
    RBrace  = '}',
    LBrack  = '[',
    RBrack  = ']',
    Comma   = ',',
    Colon   = ':'
};

class token final {
public:
  using value_type  = std::optional<std::variant<bool, int, float, std::string>>;
  using stream_type = std::vector<token>;
  using size_type   = std::size_t;

private:
  token_type       _type;
  size_type  const _line;
  value_type       _value;

public:
  token(std::string string_value, size_type line) noexcept;

  constexpr token(int int_value, size_type line) noexcept
  : _type(token_type::Integer),
    _line(line),
    _value(int_value) {}

  constexpr token(float float_value, size_type line) noexcept
  : _type(token_type::Float),
    _line(line),
    _value(float_value) {}

  constexpr token(bool bool_value, size_type line) noexcept
  : _type(token_type::Bool),
    _line(line),
    _value(bool_value) {}

  constexpr token(token_type type, size_type line) noexcept
  : _type(type),
    _line(line),
    _value(std::nullopt) {}

  constexpr auto has_type(token_type const type) const noexcept -> bool { return _type == type;      }
  constexpr auto has_value()                     const noexcept -> bool { return _value.has_value(); }

  constexpr auto type()  const noexcept -> token_type        { return _type;  }
  constexpr auto line()  const noexcept -> size_type         { return _line;  }
  constexpr auto value() const noexcept -> value_type const& { return _value; }

  template <typename T>
  constexpr auto value_as() const noexcept -> std::optional<T> {
    if (has_value() && std::holds_alternative<T>(*_value))
      return std::get<T>(*_value);

    return std::nullopt;
  }

  template <typename T>
  inline auto operator=(T const& new_value) noexcept -> token& {
    static_assert(!std::is_same_v<T, double>, "Attempting to assign double to token value (use float)");

    _type  = _type_to_token<T>();
    _value = new_value;

    return *this;
  }

private:
  template <typename T>
  constexpr auto _type_to_token() const noexcept -> token_type {
    if constexpr (std::is_same_v<T, std::string>)
      return token_type::String;

    else if constexpr (std::is_same_v<T, int>)
      return token_type::Integer;

    else if constexpr (std::is_same_v<T, float>)
      return token_type::Float;

    else if constexpr (std::is_same_v<T, bool>)
      return token_type::Bool;

    return token_type::Null;
  }

};

template <typename T>
constexpr auto has_value(token::value_type const& value) noexcept -> bool
{ return value.has_value() && std::holds_alternative<T>(*value); }

constexpr auto to_char(token_type const t) noexcept -> char
{ return static_cast<char>(t); }

constexpr auto to_token_type(char const c) noexcept -> token_type
{ return static_cast<token_type>(c); }

auto operator<<(std::ostream& os, token const&) noexcept -> std::ostream&;
}
