#pragma once

#include <dt/json/token.hh>
#include <dt/json/container_imp.hh>

#include <string>

namespace dt {

token::stream_type create_stream(std::string const& id, std::string const& text_data);

json_container_imp parse_stream(std::string const& id, token::stream_type stream);

}
