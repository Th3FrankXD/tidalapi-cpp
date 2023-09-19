#include <tidalapi.h>
#include <pybind11/embed.h>
#include "error.h"
#include <iostream>
#include <tuple>
#include <format>

namespace py = pybind11;

// static py::scoped_interpreter guard{};

void crash() {
    std::tuple<int, std::string> error = get_error();
    std::cout << std::format("Error code: {}, {}", std::get<0>(error), std::get<1>(error)) << std::endl;;
    std::cout << std::format("fatal error!\nPress enter to close program") << std::endl;;
    std::cin.ignore();
    exit(0);
}

const std::tuple<int, int, int> check_python_version() {
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

const std::string check_tidalapi_version() {
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

void tidalapi::init() {
    py::initialize_interpreter();

    check_python_version();
    std::tuple<int, std::string> error = get_error();
    if (std::get<0>(error) != 0) {
        std::cout << std::get<1>(error) << std::endl;
        crash();
    }

    check_tidalapi_version();
    error = get_error();
    if (std::get<0>(error) != 0) {
        std::cout << std::get<1>(error) << std::endl;
        crash();
    }
}

void tidalapi::close() {
    py::finalize_interpreter();
}

std::tuple<int, std::string> tidalapi::error_status() {
    return(get_error());
}

// int tidalapi::token_login(Session token) {
//     auto expiry_time = py::module_::import("datetime").attr("datetime").attr("fromisoformat")(token.expiry_time.c_str());
//     py::print(expiry_time);
//     // expiry_time = datetime.fromisoformat('2020-01-08T15:29:52.040435')
//     // auto expiry_time = bytes(std_string).arg("");
//     session.attr("load_oauth_session")(token.token_type, token.access_token, token.refresh_token, expiry_time);
//     return 0;
// }