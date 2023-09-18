#pragma once

#include <tuple>
#include <string>
#include "session.h"

namespace tidalapi {
    int init();
    std::tuple<int, std::string> error_status();
}