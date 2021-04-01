#include <dt/json/container_imp.hh>

#include <map>
#include <optional>
#include <variant>
#include <vector>

dt::json_container_imp::json_container_imp(value_type const value) noexcept
: _value(value) {}

dt::json_container_imp::~json_container_imp() noexcept {}

dt::json_container_imp dt::json_container_imp::operator=(json_container_imp const& rhs) noexcept {
	if (this != &rhs)
		_value = rhs._value;

	return *this;
}

dt::json_container_imp const* dt::json_container_imp::object_at(std::string const& key) const noexcept {
	if (auto const opt_obj_iter = _find_obj_key(key); opt_obj_iter)
		if (auto const& container = opt_obj_iter.value()->second; container.is_object())
			return &container;

	return nullptr;
}

dt::json_container_imp const* dt::json_container_imp::object_at(std::size_t const idx) const noexcept {
	if (auto const opt_arr_iter = _find_arr_idx(idx); opt_arr_iter)
		if (auto const& container = *opt_arr_iter.value(); container.is_object())
			return &container;

	return nullptr;
}

dt::json_container_imp const* dt::json_container_imp::array_at(std::string const& key) const noexcept {
	if (auto const opt_obj_iter = _find_obj_key(key); opt_obj_iter)
		if (auto const& container = opt_obj_iter.value()->second; container.is_array())
			return &container;

	return nullptr;
}

dt::json_container_imp const* dt::json_container_imp::array_at(std::size_t const idx) const noexcept {
	if (auto const opt_arr_iter = _find_arr_idx(idx); opt_arr_iter)
		if (auto const& container = *opt_arr_iter.value(); container.is_array())
			return &container;

	return nullptr;
}

std::optional<dt::object_type::const_iterator> dt::json_container_imp::_find_obj_key(std::string const& key) const noexcept {
	if (is_object()) {
		auto const& obj = std::get<object_type>(_value);

		if (auto const obj_iter = obj.find(key); obj_iter != obj.end())
			return obj_iter;
	}

	return std::nullopt;
}

std::optional<dt::array_type::const_iterator> dt::json_container_imp::_find_arr_idx(std::size_t const idx) const noexcept {
	if (is_array()) {
		auto const& arr = std::get<array_type>(_value);

		if (idx < arr.size())
			return arr.begin() + idx;
	}

	return std::nullopt;
}
