#include <tidalapi-cpp.h>
#include <pybind11/embed.h>
#include <iostream>
#include <stdlib.h>
#include "session.h"

namespace py = pybind11;

static py::scoped_interpreter guard{};
static py::module_ tidal;
static py::object session;

std::tuple<int, char*> error;

int tidalapi::init() {
    tidal = py::module_::import("tidalapi");
    session = tidal.attr("Session")();
    return 0;
}

int tidalapi::web_login() {
    py::tuple status = session.attr("login_oauth")();
    std::string url = status[0].attr("verification_uri_complete").cast<std::string>();
    system(("xdg-open https://" + url).c_str());
    status[1].attr("result")();
    return 0;
}

int tidalapi::token_login(Session token) {
    auto expiry_time = py::module_::import("datetime").attr("datetime").attr("fromisoformat")(token.expiry_time.c_str());
    py::print(expiry_time);
    // expiry_time = datetime.fromisoformat('2020-01-08T15:29:52.040435')
    // auto expiry_time = bytes(std_string).arg("");
    session.attr("load_oauth_session")(token.token_type, token.access_token, token.refresh_token, token.expiry_time);
    return 0;
}

int tidalapi::get_token(Session* token) {
    token->token_type = session.attr("token_type").cast<std::string>();
    token->access_token = session.attr("access_token").cast<std::string>();
    token->refresh_token = session.attr("refresh_token").cast<std::string>();
    token->expiry_time = session.attr("expiry_time").attr("isoformat")().cast<std::string>();
    return 0;
}

int tidalapi::set_quality(QUALITY quality) {
    switch (quality){
        case QUALITY::LOW:
            session.attr("audio_quality") = "LOW";
    }
    return 0;
}

// std::tuple get_error() {
//     return error;
// }

// import tidalapi

// session = tidalapi.Session()
// # Will run until you visit the printed url and link your account
// session.login_oauth_simple()
// # Override the required playback quality, if necessary
// # Note: Set the quality according to your subscription.
// # Normal: Quality.low_320k
// # HiFi: Quality.high_lossless
// # HiFi+ Quality.hi_res_lossless
// session.audio_quality = Quality.low_320k

// album = session.album(66236918)
// tracks = album.tracks()
// for track in tracks:
//     print(track.name)
//     for artist in track.artists:
//         print(' by: ', artist.name)