#pragma once

#include <dt/json/token.hh>

#include <map>
#include <optional>
#include <vector>

#include <cstdint> // std::size_t

namespace dt {

class json_container_imp;

using json_object = std::map<std::string, json_container_imp>;
using json_array  = std::vector<json_container_imp>;

class json_container_imp final {
public:
  using value_type = std::variant<token::value_type, json_object, json_array>;

private:
  value_type _value;

public:
  constexpr json_container_imp()                  noexcept : _value(std::nullopt) {}
  constexpr json_container_imp(token& tok)        noexcept : _value(tok.value()) {}
  constexpr json_container_imp(json_object&& obj) noexcept : _value(obj) {}
  constexpr json_container_imp(json_array&& arr)  noexcept : _value(arr) {}

  constexpr auto is_basic_value() const noexcept -> bool { return std::holds_alternative<token::value_type>(_value); }
  constexpr auto is_object()      const noexcept -> bool { return std::holds_alternative<json_object      >(_value); }
  constexpr auto is_array()       const noexcept -> bool { return std::holds_alternative<json_array       >(_value); }

  auto object_at(std::string const& key) noexcept -> json_container_imp*;
  auto array_at(std::string const& key)  noexcept -> json_container_imp*;

  auto object_at(std::size_t const& idx) noexcept -> json_container_imp*;
  auto array_at(std::size_t const& idx)  noexcept -> json_container_imp*;

  constexpr auto value()        noexcept -> value_type      & { return _value; }
  constexpr auto cvalue() const noexcept -> value_type const& { return _value; }

  template <typename T>
  constexpr auto basic_value_as() const noexcept -> std::optional<T> {
    if (is_basic_value())
      if (auto const val = std::get<token::value_type>(_value); val.has_value() && std::holds_alternative<T>(*val))
        return std::get<T>(*val);

    return std::nullopt;
  }

  template <typename T>
  constexpr auto value_at(std::string const& key) const noexcept -> std::optional<T> {
    if (is_object())
      if (auto const& root_obj = std::get<json_object>(_value); root_obj.find(key) != root_obj.end())
        if (auto const& target_val = root_obj.find(key)->second; target_val.is_basic_value())
          return target_val.basic_value_as<T>();

    return std::nullopt;
  }

  template <typename T>
  constexpr auto value_at(std::size_t const& idx) const noexcept -> std::optional<T> {
    if (is_array())
      if (auto const& root_arr = std::get<json_array>(_value); idx < root_arr.size())
        if (auto const& target_val = root_arr.at(idx); target_val.is_basic_value())
          return target_val.basic_value_as<T>();

    return std::nullopt;
  }

  template <typename T>
  constexpr void set_value_at(std::string const& key, T const& new_value) noexcept {
    if (is_object())
      if (auto& root_obj = std::get<json_object>(_value); root_obj.find(key) != root_obj.end())
        if (auto& target_val = root_obj.find(key)->second; target_val.is_basic_value())
          std::get<token::value_type>(target_val.value()) = new_value;
  }

  template <typename T>
  constexpr void set_value_at(std::size_t const& idx, T const& new_value) noexcept {
    if (is_array())
      if (auto& root_arr = std::get<json_array>(_value); idx < root_arr.size())
        if (auto& target_val = root_arr.at(idx); target_val.is_basic_value())
          std::get<token::value_type>(target_val.value()) = new_value;
  }
};

}
