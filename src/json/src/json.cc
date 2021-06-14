#include <dt/json.hh>
#include <dt/json_imp.hh>

#include <string>

dt::json::json(std::string const& id, std::string const& text_data)
: _json(std::make_unique<json_imp>(id, text_data)) {}

dt::json::~json() noexcept {}

dt::json_container dt::json::root() const noexcept
{ return json_container(_json->root()); }

std::string dt::json::str() const noexcept
{ return _json->str(); }

std::string dt::json::fast_str() const noexcept
{ return _json->fast_str(); }
