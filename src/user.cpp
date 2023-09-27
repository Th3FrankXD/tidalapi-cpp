#include "user.h"
#include "utils.h"
#include <iostream>

tidalapi::User::~User() {
    delete get_pyobject(handle);
}

const int tidalapi::User::get_id() const {
    return get_pyobject(handle)->attr("id").cast<int>(); 
}

const std::string tidalapi::User::get_name() {
    std::string user_type = get_class_name(handle);
    if (user_type == "PlaylistCreator") {
        return get_pyobject(handle)->attr("name").cast<std::string>();
    }
    return "";
}

const std::string tidalapi::User::get_first_name() {
    std::string user_type = get_class_name(handle);
    if (user_type == "FetchedUser" || user_type == "LoggedInUser") {
        return get_pyobject(handle)->attr("first_name").cast<std::string>();
    }
    return "";
}

const std::string tidalapi::User::get_last_name() {
    std::string user_type = get_class_name(handle);
    if (user_type == "FetchedUser" || user_type == "LoggedInUser") {
        return get_pyobject(handle)->attr("last_name").cast<std::string>();
    }
    return "";
}

const std::string tidalapi::User::image(int dimensions) {
    std::string user_type = get_class_name(handle);
    if (user_type == "FetchedUser" || user_type == "LoggedInUser") {
        if (get_pyobject(handle)->attr("picture_id").attr("__class__").attr("__name__").cast<std::string>() != "NoneType") {
            if (dimensions == 100 || dimensions == 210 || dimensions == 600) {
                return get_pyobject(handle)->attr("image")(dimensions).cast<std::string>();
            }
        }
    }
    return "";
}

const std::string tidalapi::User::get_username() {
    std::string user_type = get_class_name(handle);
    const py::object* test = get_pyobject(handle);
    if (user_type == "LoggedInUser") {
        return get_pyobject(handle)->attr("username").cast<std::string>();
    }
    return "";
}

const std::string tidalapi::User::get_email() {
    std::string user_type = get_class_name(handle);
    if (user_type == "LoggedInUser") {
        return get_pyobject(handle)->attr("email").cast<std::string>();
    }
    return "";
}

std::vector<tidalapi::Playlist> tidalapi::User::playlists() {
    std::vector<tidalapi::Playlist> playlists;
    std::string user_type = get_class_name(handle);
    if (user_type == "LoggedInUser") {
        py::list py_playlists = get_pyobject(handle)->attr("playlists")();
        for (py::handle py_playlist : py_playlists) {
            playlists.push_back(tidalapi::Playlist());
            playlists.back().handle = pyhandle_to_heap(py_playlist);
            std::cout << get_pyobject(playlists.back().handle)->attr("name").cast<std::string>() << std::endl;
        }
        std::cout << get_pyobject(playlists.back().handle)->attr("name").cast<std::string>() << std::endl;
    }
    std::cout << get_pyobject(playlists.back().handle)->attr("name").cast<std::string>() << std::endl;
    std::cout << "end of playlists" << std::endl;
    return playlists;
}