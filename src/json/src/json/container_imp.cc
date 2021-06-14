#include <dt/json/container_imp.hh>

#include <optional>
#include <string>

dt::json_container_imp* dt::json_container_imp::object_at(std::string const& key) noexcept {
  if (is_object())
    if (auto& root_obj = std::get<json_object>(_value); root_obj.find(key) != root_obj.end())
      if (auto& target_obj = root_obj.find(key)->second; target_obj.is_object())
        return &target_obj;

  return nullptr;
}

dt::json_container_imp* dt::json_container_imp::array_at(std::string const& key) noexcept {
  if (is_object())
    if (auto& root_obj = std::get<json_object>(_value); root_obj.find(key) != root_obj.end())
      if (auto& target_arr = root_obj.find(key)->second; target_arr.is_array())
        return &target_arr;

  return nullptr;
}

dt::json_container_imp* dt::json_container_imp::object_at(std::size_t const& idx) noexcept {
  if (is_object())
    if (auto& root_obj = std::get<json_array>(_value); idx < root_obj.size())
      if (auto& target_obj = root_obj.at(idx); target_obj.is_object())
        return &target_obj;

  return nullptr;
}

dt::json_container_imp* dt::json_container_imp::array_at(std::size_t const& idx) noexcept {
  if (is_array())
    if (auto& root_arr = std::get<json_array>(_value); idx < root_arr.size())
      if (auto& target_arr = root_arr.at(idx); target_arr.is_array())
        return &target_arr;

  return nullptr;
}
