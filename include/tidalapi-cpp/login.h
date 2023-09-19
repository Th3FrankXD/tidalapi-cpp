#pragma once
#include <string>

namespace tidalapi {
    class Login {
    public:
        ~Login();

        const int expires_in();
        const std::string get_user_code();
        const std::string get_verification_uri();
        const std::string get_verification_uri_complete();

        const bool done();

        const void* handle;
        const void* result_handle;
    };
} 