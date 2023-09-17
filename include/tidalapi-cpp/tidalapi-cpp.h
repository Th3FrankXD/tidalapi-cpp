#pragma once

#include <string>
#include <tuple>
#include "session.h"

namespace tidalapi {
    struct Token {
        std::string token_type;
        std::string access_token;
        std::string refresh_token;
        std::string expiry_time;
    };

    int init();
    int web_login();
    int token_login(Session token);
    int get_token(Session* token);
    int set_quality(QUALITY quality);
    Session get_session();
    // std::tuple get_error();
}