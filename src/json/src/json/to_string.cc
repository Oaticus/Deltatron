#include <dt/json/to_string.hh>

#include <dt/json/container_imp.hh>
#include <dt/json/token.hh>

#include <sstream>

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


void add_array(std::stringstream&, json_container_imp const&, int) noexcept;

void add_object(std::stringstream& stream, json_container_imp const& con, int indent) noexcept {
  auto        add_ws = [&stream, indent] () mutable { while (indent --> 0) stream << ' '; };
  auto const& obj    = std::get<json_object>(con.cvalue());

  if (obj.empty()) {
    stream << "{ }";
    return;
  }

  stream << '{' << std::endl;

  for (auto idx = obj.begin(); idx != obj.end(); ++idx) {
    auto const& [key, value] = *idx;

    add_ws();
    stream << '"' << key << "\" : ";

    if (value.is_object())
      add_object(stream, value, indent + 2);

    else if (value.is_array())
      add_array(stream, value, indent + 2);

    else
      add_basic_value(stream, std::get<token::value_type>(value.cvalue()));

    if (idx != obj.end())
      stream << ',' << std::endl;
  }

  add_ws();
  stream << '}';
}

void add_array(std::stringstream& stream, json_container_imp const& con, int indent) noexcept {
  auto        add_ws = [&stream, indent] () mutable { while (indent --> 0) stream << ' '; };
  auto const& arr    = std::get<json_array>(con.cvalue());

  if (arr.empty()) {
    stream << "[ ]";
    return;
  }

  add_ws();
  stream << '[' << std::endl;

  for (auto idx = arr.begin(); idx != arr.end(); ++idx) {
    auto const& value = *idx;

    add_ws();

    if (value.is_object())
      add_object(stream, value, indent + 2);

    else if (value.is_array())
      add_array(stream, value, indent + 2);

    else
      add_basic_value(stream, std::get<token::value_type>(value.cvalue()));

    if (idx != arr.end())
      stream << ',' << std::endl;
  }

  add_ws();
  stream << ']';
}

}

std::string dt::to_string(json_container_imp const& con) noexcept {
  auto stream = std::stringstream{};

  if (con.is_object())
    add_object(stream, con, 0);

  else if (con.is_array())
    add_array(stream, con, 0);

  else
    add_basic_value(stream, std::get<token::value_type>(con.cvalue()));

  return stream.str();
}
