#pragma once

#include <dt/json/token.hh>
#include <dt/json/comment.hh>
#include <dt/json/container_imp.hh>

#include <string>

namespace dt {

struct json_stream final {
  token::stream_type   tokens;
  comment::stream_type comments;

  json_stream(token::stream_type const&, comment::stream_type const&) noexcept;

  std::size_t size() const noexcept;
};

json_stream create_stream(std::string const& id, std::string const& text_data);

json_container_imp parse_stream(std::string const& id, token::stream_type const& tokens);

std::string to_string(json_stream const& stream) noexcept;

}
