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

const std::string tidalapi::Session::get_session_id() {
    return get_pyobject(handle)->attr("session_id").cast<std::string>();
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

const bool tidalapi::Session::load_session(std::string session_id, std::string country_code, int user_id) {
    if (country_code == "" || user_id == -1){
        return get_pyobject(handle)->attr("load_session")(session_id).cast<bool>();
    }
    else {
        return get_pyobject(handle)->attr("load_session")(session_id, country_code, user_id).cast<bool>();
    }
}

const tidalapi::User tidalapi::Session::get_current_user() {
    py::object py_user;
    py_user = get_pyobject(handle)->attr("user");
    tidalapi::User user;
    user.handle = pyobject_to_heap(py_user);
    return user;
}

const tidalapi::User tidalapi::Session::get_user(int user_id) {
    py::object py_user;
    py_user = get_pyobject(handle)->attr("get_user")(user_id);
    tidalapi::User user;
    user.handle = pyobject_to_heap(py_user);
    return user;
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

const bool tidalapi::Session::token_refresh(std::string refresh_token) {
    return get_pyobject(handle)->attr("token_refresh")(refresh_token).cast<bool>();
}

const std::string tidalapi::Session::get_country_code() {
    return get_pyobject(handle)->attr("country_code").cast<std::string>();
}