#pragma once

#include <tuple>
#include <string>
#include "session.h"

namespace tidalapi {
    void init();
    void close();
    std::tuple<int, std::string> error_status();
}