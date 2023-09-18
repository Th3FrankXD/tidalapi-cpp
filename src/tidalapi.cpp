#include <tidalapi.h>
#include <pybind11/embed.h>
#include "error.h"
#include <iostream>
#include <tuple>
#include <format>

namespace py = pybind11;

static py::scoped_interpreter guard{};

void crash() {
    std::cout << "fatal error!\nPress enter to close program";
    std::cin.ignore();
    exit(0);
}

std::tuple<int, int, int> check_python_version() {
    py::module_ sys = py::module_::import("sys");
    int major = sys.attr("version_info").attr("major").cast<int>();
    int minor = sys.attr("version_info").attr("minor").cast<int>();
    int micro = sys.attr("version_info").attr("micro").cast<int>();
    if (major < 3) {
        set_error(-1, std::format("Python version {}.{}.{} is too old\n", major, minor, micro));
    } else {
        set_error(0, "");
    }
    return std::tuple(major, minor, micro);
}

std::string check_tidalapi_version() {
    std::string version = "";
    try {
        py::module_ tidal = py::module_::import("tidalapi");
        version = tidal.attr("__version__").cast<std::string>();
        set_error(0, "");
    } catch(...) {
        set_error(-1, "tidalapi module not found");
    }
    return version;
}

int tidalapi::init() {
    std::tuple<int, int, int> version = check_python_version();
    std::tuple<int, std::string> error = get_error();
    if (std::get<0>(error) != 0) {
        std::cout << std::get<1>(error) << std::endl;
        crash();
    } else {
        std::cout << std::format("Using Python version: {}.{}.{}\n", std::get<0>(version), std::get<1>(version), std::get<2>(version));
    }
    if (std::get<0>(error) != 0) {
        std::cout << std::get<1>(error) << std::endl;
        crash();
    } else {
        std::cout << std::format("Using tidalapi version: {}\n", check_tidalapi_version());
    }
    return 0;
}

std::tuple<int, std::string> tidalapi::error_status() {
    return(get_error());
}

// int tidalapi::token_login(Session token) {
//     auto expiry_time = py::module_::import("datetime").attr("datetime").attr("fromisoformat")(token.expiry_time.c_str());
//     py::print(expiry_time);
//     // expiry_time = datetime.fromisoformat('2020-01-08T15:29:52.040435')
//     // auto expiry_time = bytes(std_string).arg("");
//     session.attr("load_oauth_session")(token.token_type, token.access_token, token.refresh_token, token.expiry_time);
//     return 0;
// }

// int tidalapi::get_token(Session* token) {
//     token->token_type = session.attr("token_type").cast<std::string>();
//     token->access_token = session.attr("access_token").cast<std::string>();
//     token->refresh_token = session.attr("refresh_token").cast<std::string>();
//     token->expiry_time = session.attr("expiry_time").attr("isoformat")().cast<std::string>();
//     return 0;
// }