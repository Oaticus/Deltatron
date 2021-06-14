#pragma once

#include <dt/json/stream.hh>
#include <dt/json/to_string.hh>

#include <string>

namespace dt {

class json_imp final {
  std::string    	   const  _id;
  std::string        const& _text_data;
  json_container_imp        _root_container;

public:
  json_imp(std::string const& id, std::string const& text_data)
  : _id(id),
    _text_data(text_data),
    _root_container(parse_stream(_id, create_stream(_id, _text_data))) {}

  constexpr json_container_imp& root() noexcept { return _root_container; }

  std::string str() const noexcept { return to_string(_root_container); }

  std::string fast_str() const noexcept { return fast_to_string(_root_container); }
};

}
