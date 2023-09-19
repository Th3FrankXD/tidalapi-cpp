#include "session.h"
#include <pybind11/embed.h>
#include "utils.h"

#include <iostream>
#include <format>

namespace py = pybind11;


tidalapi::Session::Session(Config config) {
    py::module_ tidal = get_tidal();
    handle = pyobject_to_heap(tidal.attr("Session")(*get_pyobject(config.handle)));
}

tidalapi::Session::~Session() {
    delete get_pyobject(handle);
}

const tidalapi::QUALITY tidalapi::Session::get_quality() {
    py::object session = *get_pyobject(handle);
    return string_to_quality(session.attr("audio_quality").cast<std::string>());
}

const tidalapi::Login tidalapi::Session::login_oauth() {
    py::tuple status = get_pyobject(handle)->attr("login_oauth")();
    tidalapi::Login login;
    login.handle = pyobject_to_heap(status[0]);
    login.result_handle = pyobject_to_heap(status[1]);
    return login;
}

const bool tidalapi::Session::check_login() {
    return get_pyobject(handle)->attr("check_login")().cast<bool>();
}

const std::string tidalapi::Session::get_access_token() {
    return get_pyobject(handle)->attr("access_token").cast<std::string>();
}

const std::string tidalapi::Session::get_expiry_time() {
    return get_pyobject(handle)->attr("expiry_time").attr("isoformat")().cast<std::string>();
}

const std::string tidalapi::Session::get_refresh_token() {
    return get_pyobject(handle)->attr("refresh_token").cast<std::string>();
}

const std::string tidalapi::Session::get_token_type() {
    return get_pyobject(handle)->attr("token_type").cast<std::string>();
}


// int tidalapi::get_token(Session* token) {
//     token->token_type = session.attr("token_type").cast<std::string>();
//     token->access_token = session.attr("access_token").cast<std::string>();
//     token->refresh_token = session.attr("refresh_token").cast<std::string>();
//     token->expiry_time = session.attr("expiry_time").attr("isoformat")().cast<std::string>();
//     return 0;
// }