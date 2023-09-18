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

tidalapi::QUALITY tidalapi::Session::get_quality() {
    py::object session = *get_pyobject(handle);
    return string_to_quality(session.attr("audio_quality").cast<std::string>());
}

tidalapi::Login tidalapi::Session::login_oauth() {
    py::tuple status = get_pyobject(handle)->attr("login_oauth")();
    tidalapi::Login login;
    login.handle = pyobject_to_heap(status[0]);
    login.result_handle = pyobject_to_heap(status[1]);
    return login;
}