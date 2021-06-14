#pragma once

#include <dt/json/container_imp.hh>

#include <string>

namespace dt {

std::string to_string(json_container_imp const& con) noexcept;

std::string fast_to_string(json_container_imp const& con) noexcept;

}
