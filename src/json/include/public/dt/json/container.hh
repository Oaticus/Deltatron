#pragma once

#include <optional>
#include <string>

#include <cstdint> // std::size_t

namespace dt {

class json;
class json_container_imp;

class json_container final {
  friend class json;

  json_container_imp& _container;

public:
  bool is_object() const noexcept;
  bool is_array()  const noexcept;

  auto object_at(std::string const& key)  const noexcept -> std::optional<json_container>;
  auto array_at(std::string const& key)   const noexcept -> std::optional<json_container>;
  auto string_at(std::string const& key)  const noexcept -> std::optional<std::string>;
  auto integer_at(std::string const& key) const noexcept -> std::optional<int>;
  auto float_at(std::string const& key)   const noexcept -> std::optional<float>;
  auto bool_at(std::string const& key)    const noexcept -> std::optional<bool>;

  auto object_at(std::size_t const& idx)  const noexcept -> std::optional<json_container>;
  auto array_at(std::size_t const& idx)   const noexcept -> std::optional<json_container>;
  auto string_at(std::size_t const& idx)  const noexcept -> std::optional<std::string>;
  auto integer_at(std::size_t const& idx) const noexcept -> std::optional<int>;
  auto float_at(std::size_t const& idx)   const noexcept -> std::optional<float>;
  auto bool_at(std::size_t const& idx)    const noexcept -> std::optional<bool>;

  auto set_string_at(std::string const& key, std::string const& new_value) noexcept -> json_container&;
  auto set_integer_at(std::string const& key, int const& new_value)        noexcept -> json_container&;
  auto set_float_at(std::string const& key, float const& new_value)        noexcept -> json_container&;
  auto set_bool_at(std::string const& key, bool const& new_value)          noexcept -> json_container&;

  auto set_string_at(std::size_t const& idx, std::string const& new_value) noexcept -> json_container&;
  auto set_integer_at(std::size_t const& idx, int const& new_value)        noexcept -> json_container&;
  auto set_float_at(std::size_t const& idx, float const& new_value)        noexcept -> json_container&;
  auto set_bool_at(std::size_t const& idx, bool const& new_value)          noexcept -> json_container&;

private:
  json_container(json_container_imp&) noexcept;

};

}
