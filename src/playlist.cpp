#include "playlist.h"
#include "utils.h"

const std::string tidalapi::Playlist::get_name() {
    const py::object* test = get_pyobject(handle);
    return get_pyobject(handle)->attr("name").cast<std::string>();
}