#pragma once
#include <string>

namespace tidalapi {
    class Login {
    public:
        int expires_in();
        std::string get_user_code();
        std::string get_verification_uri();
        std::string get_verification_uri_complete();

        bool done();

        const void* handle;
        const void* result_handle;
    };
} 