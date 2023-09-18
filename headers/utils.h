#pragma once

#include <pybind11/embed.h>
#include "quality.h"

namespace py = pybind11;

py::module_ get_tidal();

const void* pyobject_to_heap(py::object object); 
py::object* get_pyobject(const void* handle);

tidalapi::QUALITY string_to_quality(std::string quality);
tidalapi::VIDEO_QUALITY string_to_video_quality(std::string quality);

py::object quality_to_pyobject(tidalapi::QUALITY quality);
py::object quality_to_pyobject(tidalapi::VIDEO_QUALITY quality);