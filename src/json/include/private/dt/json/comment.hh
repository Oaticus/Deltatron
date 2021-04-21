#pragma once

#include <string>
#include <vector>

namespace dt {

class comment final {
public:
  using stream_type = std::vector<comment>;

private:
  std::size_t const _index;
  std::string const _comment;

public:
  comment(std::size_t const& index, std::string const& comm) noexcept;

  ~comment() noexcept;

  constexpr auto const& string() const noexcept { return _comment; }
  constexpr auto const& index()  const noexcept { return _index;   }
};


}
