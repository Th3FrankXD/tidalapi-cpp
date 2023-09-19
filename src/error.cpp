#include "error.h"

static std::tuple<int, std::string> error;

const std::tuple<int, std::string> get_error() {
    return(error);
}

void set_error(int error_code, std::string message) {
    error = std::tuple(error_code, message.c_str());
}