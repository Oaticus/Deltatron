#include <dt/json/comment.hh>

dt::comment::comment(std::size_t const& index, std::string const& comm) noexcept
: _index(index),
  _comment(comm) {}

dt::comment::~comment() noexcept {}
