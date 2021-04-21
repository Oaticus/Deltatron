#pragma once

#include <dt/json/stream.hh>
#include <dt/json/container.hh>

#include <string>

namespace dt {

class json_imp final {
  std::string    	   const  _id;
  std::string        const& _text_data;
  json_stream               _stream;
  json_container_imp        _root_container;

public:
  json_imp(std::string const& id, std::string const& text_data)
  : _id(id),
    _text_data(text_data),
    _stream(create_stream(_id, _text_data)),
    _root_container(parse_stream(_id, _stream.tokens)) {}

  constexpr json_container_imp const& root() const noexcept { return _root_container; }
};

}
