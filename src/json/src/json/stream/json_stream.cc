#include <dt/json/stream.hh>

#include <algorithm>

dt::json_stream::json_stream(token::stream_type const& t, comment::stream_type const& c) noexcept
: tokens(t),
  comments(c) {}

std::size_t dt::json_stream::size() const noexcept
{ return std::max(tokens.back().index(), comments.back().index()); }
