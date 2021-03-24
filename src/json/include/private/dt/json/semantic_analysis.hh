#pragma once

#include <dt/json/lexical_analysis/token.hh>
#include <dt/json/semantic_analysis/container_imp.hh>

#include <string>

namespace dt {

json_container_imp parse_stream(std::string const& id, token::stream_type const& stream);

}
