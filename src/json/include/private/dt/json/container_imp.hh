#pragma once

#include <dt/json/token.hh>

#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace dt {

class json_container_imp;

using object_type = std::map<std::string_view, json_container_imp>;
using array_type  = std::vector<json_container_imp>;

enum class container_type : unsigned char {
	Object, Array,
	String, Integer, Float, Bool, Null
};

class json_container_imp final {
public:
	using value_type = std::variant<token::value_type, object_type, array_type>;

private:
	value_type _value;

public:
	json_container_imp(value_type const value = token::value_type(std::nullopt)) noexcept;

	~json_container_imp() noexcept;

	json_container_imp operator=(json_container_imp const&) noexcept;

	constexpr bool is_object() const noexcept { return std::holds_alternative<object_type>(_value); }
	constexpr bool is_array()  const noexcept { return std::holds_alternative<array_type >(_value); }

  constexpr bool is_string_value() const noexcept
	{ return _is_value() ? std::holds_alternative<std::string_view>(*std::get<token::value_type>(_value)) : false; }

  constexpr bool is_integer_value() const noexcept
	{ return _is_value() ? std::holds_alternative<int>(*std::get<token::value_type>(_value)) : false; }

  constexpr bool is_float_value() const noexcept
	{ return _is_value() ? std::holds_alternative<float>(*std::get<token::value_type>(_value)) : false; }

  constexpr bool is_bool_value() const noexcept
	{ return _is_value() ? std::holds_alternative<bool>(*std::get<token::value_type>(_value)) : false; }

	constexpr bool is_null_value() const noexcept
	{ return std::holds_alternative<token::value_type>(_value) && !std::get<token::value_type>(_value).has_value(); }

	constexpr value_type const& value() const noexcept { return _value; }

	constexpr std::size_t array_size() const noexcept
	{ return is_array() ? std::get<array_type>(_value).size() : 0; }

	template <typename T>
	std::optional<T> object_value_at(std::string const& key) const noexcept {
		if (auto const& opt_obj_iter = _find_obj_key(key); opt_obj_iter)
			if (auto const value = opt_obj_iter.value()->second._extract_basic_value<T>(); value)
				return value.value();

		return std::nullopt;
	}

	template <typename T>
	std::optional<T> array_value_at(std::size_t const idx) const noexcept {
		if (auto const opt_arr_iter = _find_arr_idx(idx); opt_arr_iter)
			if (auto const value = opt_arr_iter.value()->_extract_basic_value<T>(); value)
				return *value;

		return std::nullopt;
	}

	json_container_imp const* object_at(std::string const& key) const noexcept;
	json_container_imp const* object_at(std::size_t const  idx) const noexcept;

	json_container_imp const* array_at(std::string const& key) const noexcept;
	json_container_imp const* array_at(std::size_t const  idx) const noexcept;

private:
	template <typename T>
	std::optional<T> _extract_basic_value() const noexcept {
		if (auto const tval = std::get_if<token::value_type>(&_value); tval && *tval)
			if (T const* v = std::get_if<T>(&**tval); v)
				return *v;

		return std::nullopt;
	}

	std::optional<object_type::const_iterator> _find_obj_key(std::string const& key) const noexcept;
	std::optional<array_type::const_iterator > _find_arr_idx(std::size_t const  idx) const noexcept;

  constexpr bool _is_value() const noexcept
	{ return std::holds_alternative<token::value_type>(_value) ? std::get<token::value_type>(_value).has_value() : false; }
};

}
