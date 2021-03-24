#pragma once

#include <dt/json/type.hh>

#include <optional>
#include <string>
#include <string_view>

#include <cstdint>

namespace dt {

class json;
class json_container_imp;

class json_container final {
	friend class json;

	json_container_imp const& _container;

public:
	~json_container() noexcept;

	json_type type() const noexcept;

	std::size_t size() const noexcept;

	bool is_object() const noexcept;
	bool is_array() const noexcept;
	bool is_string() const noexcept;
	bool is_integer() const noexcept;
	bool is_float() const noexcept;
	bool is_bool() const noexcept;
	bool is_null() const noexcept;

	std::optional<std::string_view> string_view_at(std::string const& key) const noexcept;
	std::optional<std::string_view> string_view_at(std::size_t const& idx) const noexcept;

	std::optional<std::string> string_at(std::string const& key) const noexcept;
	std::optional<std::string> string_at(std::size_t const& idx) const noexcept;

	std::optional<bool> bool_at(std::string const& key) const noexcept;
	std::optional<bool> bool_at(std::size_t const& idx) const noexcept;

	std::optional<int> integer_at(std::string const& key) const noexcept;
	std::optional<int> integer_at(std::size_t const& idx) const noexcept;

	std::optional<float> float_at(std::string const& key) const noexcept;
	std::optional<float> float_at(std::size_t const& idx) const noexcept;

	std::optional<json_container> object_at(std::string const& key) const noexcept;
	std::optional<json_container> object_at(std::size_t const& idx) const noexcept;

	std::optional<json_container> array_at(std::string const& key) const noexcept;
	std::optional<json_container> array_at(std::size_t const& idx) const noexcept;

private:
	json_container(json_container_imp const&) noexcept;
};

}
