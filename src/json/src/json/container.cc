#include <dt/json/container.hh>
#include <dt/json/container_imp.hh>

#include <optional>
#include <string>

#include <cstdint> // std::size_t

dt::json_container::json_container(json_container_imp& container) noexcept
: _container(container) {}

bool dt::json_container::is_object() const noexcept
{ return _container.is_object(); }

bool dt::json_container::is_array() const noexcept
{ return _container.is_array(); }

////////////
// Object //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::optional<dt::json_container> dt::json_container::object_at(std::string const& key) const noexcept {
  if (auto obj_ptr = _container.object_at(key); obj_ptr != nullptr) return json_container(*obj_ptr);
  return std::nullopt;
}

std::optional<dt::json_container> dt::json_container::array_at(std::string const& key) const noexcept {
  if (auto arr_ptr = _container.array_at(key); arr_ptr != nullptr) return json_container(*arr_ptr);
  return std::nullopt;
}

std::optional<std::string> dt::json_container::string_at(std::string const& key) const noexcept
{ return _container.value_at<std::string>(key); }

std::optional<int> dt::json_container::integer_at(std::string const& key) const noexcept
{ return _container.value_at<int>(key); }

std::optional<float> dt::json_container::float_at(std::string const& key) const noexcept
{ return _container.value_at<float>(key); }

std::optional<bool> dt::json_container::bool_at(std::string const& key) const noexcept
{ return _container.value_at<bool>(key); }

// Setters

dt::json_container& dt::json_container::set_string_at(std::string const& key, std::string const& new_value) noexcept
{ _container.set_value_at(key, new_value); return *this; }

dt::json_container& dt::json_container::set_integer_at(std::string const& key, int const& new_value) noexcept
{ _container.set_value_at(key, new_value); return *this; }

dt::json_container& dt::json_container::set_float_at(std::string const& key, float const& new_value) noexcept
{ _container.set_value_at(key, new_value); return *this; }

dt::json_container& dt::json_container::set_bool_at(std::string const& key, bool const& new_value) noexcept
{ _container.set_value_at(key, new_value); return *this; }

///////////
// Array //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::optional<dt::json_container> dt::json_container::object_at(std::size_t const& idx) const noexcept {
  if (auto obj_ptr = _container.object_at(idx); obj_ptr != nullptr) return json_container(*obj_ptr);
  return std::nullopt;
}

std::optional<dt::json_container> dt::json_container::array_at(std::size_t const& idx) const noexcept {
  if (auto arr_ptr = _container.array_at(idx); arr_ptr != nullptr) return json_container(*arr_ptr);
  return std::nullopt;
}

std::optional<std::string> dt::json_container::string_at(std::size_t const& idx) const noexcept
{ return _container.value_at<std::string>(idx); }

std::optional<int> dt::json_container::integer_at(std::size_t const& idx) const noexcept
{ return _container.value_at<int>(idx); }

std::optional<float> dt::json_container::float_at(std::size_t const& idx) const noexcept
{ return _container.value_at<float>(idx); }

std::optional<bool> dt::json_container::bool_at(std::size_t const& idx) const noexcept
{ return _container.value_at<bool>(idx); }

// Setters

dt::json_container& dt::json_container::set_string_at(std::size_t const& idx, std::string const& new_value) noexcept
{ _container.set_value_at(idx, new_value); return *this; }

dt::json_container& dt::json_container::set_integer_at(std::size_t const& idx, int const& new_value) noexcept
{ _container.set_value_at(idx, new_value); return *this; }

dt::json_container& dt::json_container::set_float_at(std::size_t const& idx, float const& new_value) noexcept
{ _container.set_value_at(idx, new_value); return *this; }

dt::json_container& dt::json_container::set_bool_at(std::size_t const& idx, bool const& new_value) noexcept
{ _container.set_value_at(idx, new_value); return *this; }
