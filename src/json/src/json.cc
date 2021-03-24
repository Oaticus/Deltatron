#include <dt/json.hh>
#include <dt/json_imp.hh>

dt::json::json(std::string const& id, std::string const& text_data)
: _json(std::make_unique<json_imp>(id, text_data)) {}

dt::json::~json() noexcept {}

dt::json_container dt::json::root() const noexcept { return json_container(_json->root()); }
