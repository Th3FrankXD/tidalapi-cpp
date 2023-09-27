#pragma once

#include <pybind11/embed.h>
#include "quality.h"

namespace py = pybind11;

const py::module_ get_tidal();

const void* pyhandle_to_heap(py::handle handle);
const void* pyobject_to_heap(py::object object);
const py::object* get_pyobject(const void* handle);
const std::string get_class_name(const void* handle);

const tidalapi::QUALITY string_to_quality(std::string quality);
const tidalapi::VIDEO_QUALITY string_to_video_quality(std::string quality);

const py::object quality_to_pyobject(tidalapi::QUALITY quality);
const py::object quality_to_pyobject(tidalapi::VIDEO_QUALITY quality);