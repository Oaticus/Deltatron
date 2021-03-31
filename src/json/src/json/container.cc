#include <dt/json/container.hh>
#include <dt/json/semantic_analysis/container_imp.hh>

#include <optional>
#include <string>

dt::json_container::~json_container() noexcept {}

dt::json_container::json_container(json_container_imp const& container) noexcept
: _container(container) {}

bool dt::json_container::is_object() const noexcept { return _container.is_object(); }

bool dt::json_container::is_array() const noexcept { return _container.is_array(); }

bool dt::json_container::is_string() const noexcept { return _container.is_string_value(); }

bool dt::json_container::is_integer() const noexcept { return _container.is_integer_value(); }

bool dt::json_container::is_float() const noexcept { return _container.is_float_value(); }

bool dt::json_container::is_bool() const noexcept { return _container.is_bool_value(); }

bool dt::json_container::is_null() const noexcept { return _container.is_null_value(); }

std::size_t dt::json_container::size() const noexcept {
	if (_container.is_object())
		return std::get<array_type>(_container.value()).size();

	if (_container.is_array())
		return std::get<object_type>(_container.value()).size();

	return 0;
}

std::optional<std::string_view> dt::json_container::string_view_at(std::string const& key) const noexcept
{ return _container.object_value_at<std::string_view>(key); }

std::optional<std::string_view> dt::json_container::string_view_at(std::size_t const& idx) const noexcept
{ return _container.array_value_at<std::string_view>(idx); }

std::optional<std::string> dt::json_container::string_at(std::string const& key) const noexcept {
	if (auto const opt_strv = string_view_at(key); opt_strv)
		return std::string(opt_strv->data(), opt_strv->size());

	return std::nullopt;
}
std::optional<std::string> dt::json_container::string_at(std::size_t const& idx) const noexcept {
	if (auto const opt_strv = string_view_at(idx); opt_strv)
		return std::string(opt_strv->data(), opt_strv->size());

	return std::nullopt;
}

std::optional<bool> dt::json_container::bool_at(std::string const& key) const noexcept
{ return _container.object_value_at<bool>(key); }

std::optional<bool> dt::json_container::bool_at(std::size_t const& idx) const noexcept
{ return _container.array_value_at<bool>(idx); }

std::optional<int> dt::json_container::integer_at(std::string const& key) const noexcept
{ return _container.object_value_at<int>(key); }

std::optional<int> dt::json_container::integer_at(std::size_t const& idx) const noexcept
{ return _container.array_value_at<int>(idx); }

std::optional<float> dt::json_container::float_at(std::string const& key) const noexcept
{ return _container.object_value_at<float>(key); }

std::optional<float> dt::json_container::float_at(std::size_t const& idx) const noexcept
{ return _container.array_value_at<float>(idx); }

std::optional<dt::json_container> dt::json_container::object_at(std::string const& key) const noexcept {
	if (auto const container_ptr = _container.object_at(key); container_ptr)
		return json_container(*container_ptr);

	return std::nullopt;
}

std::optional<dt::json_container> dt::json_container::object_at(std::size_t const& idx) const noexcept{
	if (auto const container_ptr = _container.object_at(idx); container_ptr)
		return json_container(*container_ptr);

	return std::nullopt;
}

std::optional<dt::json_container> dt::json_container::array_at(std::string const& key) const noexcept {
	if (auto const container_ptr = _container.array_at(key); container_ptr)
		return json_container(*container_ptr);

	return std::nullopt;
}

std::optional<dt::json_container> dt::json_container::array_at(std::size_t const& idx) const noexcept {
	if (auto const container_ptr = _container.array_at(idx); container_ptr)
		return json_container(*container_ptr);

	return std::nullopt;
}
