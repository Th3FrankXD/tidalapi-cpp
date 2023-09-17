#pragma once

#include <tuple>
#include "session.h"

namespace tidalapi {
    int init();
    std::tuple<int, char*> get_error();
}