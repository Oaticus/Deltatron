#include <dt/json/to_string.hh>

#include <sstream>
#include <string>

namespace dt {

constexpr void add_basic_value(std::stringstream& stream, token::value_type const& value) noexcept {
  if (has_value<std::string>(value))
    stream << std::get<std::string>(*value);

  else if (has_value<int>(value))
    stream << std::get<int>(*value);

  else if (has_value<float>(value))
    stream << std::get<float>(*value);

  else if (has_value<bool>(value))
    stream << std::get<bool>(*value);

  else
    stream << "null";
}


void add_array(std::stringstream&, json_container_imp const&) noexcept;

void add_object(std::stringstream& stream, json_container_imp const& con) noexcept {
  auto const& obj = std::get<json_object>(con.cvalue());

  if (obj.empty()) {
    stream << "{}";
    return;
  }

  stream << '{';

  for (auto idx = obj.begin(); idx != obj.end(); ++idx) {
    auto const& [key, value] = *idx;

    stream << '"' << key << "\":";

    if (value.is_object())
      add_object(stream, value);

    else if (value.is_array())
      add_array(stream, value);

    else
      add_basic_value(stream, std::get<token::value_type>(value.cvalue()));

    if (idx != obj.end())
      stream << ',';
  }

  stream << '}';
}

void add_array(std::stringstream& stream, json_container_imp const& con) noexcept {
  auto const& arr    = std::get<json_array>(con.cvalue());

  if (arr.empty()) {
    stream << "[]";
    return;
  }

  stream << '[';

  for (auto idx = arr.begin(); idx != arr.end(); ++idx) {
    auto const& value = *idx;

    if (value.is_object())
      add_object(stream, value);

    else if (value.is_array())
      add_array(stream, value);

    else
      add_basic_value(stream, std::get<token::value_type>(value.cvalue()));

    if (idx != arr.end())
      stream << ',';
  }

  stream << ']';
}

}

std::string dt::fast_to_string(json_container_imp const& con) noexcept {
  std::stringstream stream;

  if (con.is_object())
    add_object(stream, con);

  else if (con.is_array())
    add_array(stream, con);

  else
    add_basic_value(stream, std::get<token::value_type>(con.cvalue()));

  return stream.str();
}
