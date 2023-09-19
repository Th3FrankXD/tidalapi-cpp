#include "login.h"
#include "utils.h"
#include <string>

tidalapi::Login::~Login() {
    delete get_pyobject(handle);
}

const int tidalapi::Login::expires_in() {
    return get_pyobject(handle)->attr("expires_in").cast<int>();
}

const std::string tidalapi::Login::get_user_code() {
    return get_pyobject(handle)->attr("user_code").cast<std::string>();
}

const std::string tidalapi::Login::get_verification_uri() {
    return get_pyobject(handle)->attr("verification_uri").cast<std::string>();
}

const std::string tidalapi::Login::get_verification_uri_complete() {
    return get_pyobject(handle)->attr("verification_uri_complete").cast<std::string>();
}

const bool tidalapi::Login::done() {
    return get_pyobject(result_handle)->attr("done")().cast<bool>();
}