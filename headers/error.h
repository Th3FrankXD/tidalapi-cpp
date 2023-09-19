#pragma once

#include <tuple>
#include <string>

const std::tuple<int, std::string> get_error();
void set_error(int error_code, std::string message);