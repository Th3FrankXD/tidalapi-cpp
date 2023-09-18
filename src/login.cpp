#include "login.h"
#include "utils.h"
#include <string>

namespace tidalapi {
    int tidalapi::Login::expires_in() {
        return get_pyobject(handle)->attr("expires_in").cast<int>();
    }
    
    std::string tidalapi::Login::get_user_code() {
        return get_pyobject(handle)->attr("user_code").cast<std::string>();
    }

    std::string tidalapi::Login::get_verification_uri() {
        return get_pyobject(handle)->attr("verification_uri").cast<std::string>();
    }

    std::string tidalapi::Login::get_verification_uri_complete() {
        return get_pyobject(handle)->attr("verification_uri_complete").cast<std::string>();
    }

    bool tidalapi::Login::done() {
        return get_pyobject(result_handle)->attr("done")().cast<bool>();
    }
}