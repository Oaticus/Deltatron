#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace dt {

enum token_type : unsigned char {
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
  using value_type  = std::optional<std::variant<bool, int, float, std::string_view>>;
  using stream_type = std::vector<token>;

private:
  token_type  const _type;
  std::size_t const _line;
  value_type  const _value;

public:
  constexpr token(token_type const type, std::size_t const line, value_type const value = std::nullopt) noexcept
  : _type(type),
    _line(line),
    _value(value) {}

  constexpr bool has_value() const noexcept { return _value.has_value(); }

  constexpr bool has_type(token_type const type) const noexcept
  { return _type == type; }

  constexpr token_type type() const noexcept
  { return _type; }

  constexpr std::size_t line() const noexcept
  { return _line; }

  constexpr value_type const& value() const noexcept
  { return _value; }

  template <typename T>
  std::optional<T>
  value_as() const noexcept {
    if (_value && std::holds_alternative<T>(*_value))
      return std::get<T>(*_value);

    return std::nullopt;
  }

};

  constexpr char enum_to_char(token_type const t) noexcept
  { return static_cast<char>(t); }

  constexpr token_type char_to_enum(char const c) noexcept
  { return static_cast<token_type>(c); }


namespace dbg {

void raw_printout(token::stream_type const& stream) noexcept;

}

}
