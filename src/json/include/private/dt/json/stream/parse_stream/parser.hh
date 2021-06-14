#pragma once

#include <dt/json/stream/parse_stream/parser/state.hh>

namespace dt {

json_object parse_object(parser_state& state);

json_array parse_array(parser_state& state);

}
