#include <tuple>

std::tuple<int, char*> get_error();
void set_error(int error_code, char* message);