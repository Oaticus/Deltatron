#pragma once

#include <dt/json/token.hh>
#include <dt/json/container_imp.hh>

#include <sstream>

namespace dt {

void write_fmt_value(std::stringstream&, json_container_imp const&, int) noexcept;
void write_fmt_array(std::stringstream&, json_container_imp const&, int) noexcept;
void write_fmt_object(std::stringstream&, json_container_imp const&, int) noexcept;

void write_fmt_indentation(std::stringstream& stream, int indentation) noexcept {
  while (indentation --> 0)
    stream << ' ';
}

void write_fmt_object(std::stringstream& stream, json_container_imp const& container, int indentation) noexcept {
  auto const& object = std::get<json_object>(container.cvalue());

  write_fmt_indentation(stream, indentation);
  stream << '{' << std::endl;

  for (auto read_head = object.begin(); read_head != object.end(); ++read_head) {
    auto const& key = read_head->first;
    auto const& con = read_head->second;

    write_fmt_indentation(stream, indentation);
    stream << key << " : ";
    write_fmt_value(stream, con, indentation);

    if (read_head != object.end()) {
      stream << "," << std::endl;

    } else {
      stream << std::endl;
      write_fmt_indentation(stream, indentation);
      stream << '}' << std::endl;

    }

  }
}

void write_fmt_array(std::stringstream& stream, json_container_imp const& container, int indentation) noexcept {
  auto const& array = std::get<json_array>(container.cvalue());

  write_fmt_indentation(stream, indentation);
  stream << '[' << std::endl;

  for (auto read_head = array.begin(); read_head != array.end(); ++read_head) {
    auto const& con = *read_head;

    write_fmt_indentation(stream, indentation);
    write_fmt_value(stream, con, indentation);

  }
}

void write_fmt_value(std::stringstream& stream, json_container_imp const& con, int indentation) noexcept {
  if (con.is_object()) {
      write_fmt_object(stream, con, indentation + 2);

  } else if (con.is_array()) {
      write_fmt_array(stream, con, indentation + 2);

  } else {
    auto const& basic_value = std::get<token::value_type>(con.cvalue());

    if (!basic_value)
      stream << "null";

    else if (std::holds_alternative<int>(*basic_value))
    stream << std::get<int>(*basic_value);

    else if (std::holds_alternative<float>(*basic_value))
      stream << std::get<float>(*basic_value);

    else if (std::holds_alternative<bool>(*basic_value))
      stream << std::get<bool>(*basic_value);

    else
      stream << std::get<std::string>(*basic_value);
  }
}

}
