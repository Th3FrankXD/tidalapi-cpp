#include "error.h"

static std::tuple<int, char*> error;

std::tuple<int, char*> get_error() {
    return(error);
}

void set_error(int error_code, char* message) {
    error = std::tuple(error_code, message);
}