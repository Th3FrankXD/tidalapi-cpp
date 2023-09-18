#include "config.h"
#include <pybind11/embed.h>
#include <iostream>
#include "utils.h"

namespace py = pybind11;

tidalapi::Config::Config(QUALITY quality=QUALITY::HIGH, VIDEO_QUALITY video_quality=VIDEO_QUALITY::HIGH, int item_limit=1000, bool alac=true) {
    py::module_ tidal = get_tidal();
    handle = pyobject_to_heap(tidal.attr("Config")(quality_to_pyobject(quality), quality_to_pyobject(video_quality), item_limit, alac));
}