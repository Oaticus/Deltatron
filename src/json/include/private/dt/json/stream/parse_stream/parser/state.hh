#pragma once

#include <dt/json/error.hh>
#include <dt/json/token.hh>
#include <dt/json/container_imp.hh>

#include <string>

namespace dt {

class parser_state final {
public:
  using size_type = token::size_type;
  using pointer   = token::stream_type::pointer;

private:
  std::string const& _id;
  pointer            _current_token;
  pointer     const  _end;

public:
  parser_state(std::string const& id, token::stream_type& stream) noexcept;

  constexpr auto eof() const noexcept -> bool { return _current_token >= _end; }

  constexpr auto current_token() noexcept -> token& { return *_current_token; }

  constexpr auto current_token_line() const noexcept -> size_type
  { return eof() ? _current_token->line() : (_end - 1)->line(); }

  auto try_increment() -> void;

  [[noreturn]] auto throw_error(char const* message) const -> void;
};

}
