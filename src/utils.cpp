#include "utils.h"
#include <string>
#include <unordered_map>
#include "error.h"
#include <format>

static std::unordered_map<std::string, tidalapi::QUALITY> quality_map{
                {"LOW", tidalapi::QUALITY::LOW},
                {"HIGH", tidalapi::QUALITY::HIGH},
                {"LOSSLESS", tidalapi::QUALITY::LOSSLESS},
                {"HI_RES", tidalapi::QUALITY::HI_RES},
                {"HI_RES_LOSSLESS", tidalapi::QUALITY::HI_RES_LOSSLESS}};

static std::unordered_map<std::string, tidalapi::VIDEO_QUALITY> video_quality_map{
                {"LOW", tidalapi::VIDEO_QUALITY::LOW},
                {"MEDIUM", tidalapi::VIDEO_QUALITY::MEDIUM},
                {"HIGH", tidalapi::VIDEO_QUALITY::HIGH}};

py::module_ get_tidal() {
    return py::module_::import("tidalapi");
}

const void* pyobject_to_heap(py::object object) {
    py::object* temp = new py::object;
    *temp = object;
    return (const void*)temp;
}

py::object* get_pyobject(const void* handle) {
    return (py::object*)handle;
}

tidalapi::QUALITY string_to_quality(std::string quality) {
    if (auto search = quality_map.find(quality); search != quality_map.end()) {
        set_error(0, "");
        return quality_map.find(quality)->second;
    } else {
        set_error(-1, std::format("{} quality not found/n returning LOW instead", quality));
        return tidalapi::QUALITY::LOW;
    }
}

tidalapi::VIDEO_QUALITY string_to_video_quality(std::string quality) {
    if (auto search = video_quality_map.find(quality); search != video_quality_map.end()) {
        set_error(0, "");
        return video_quality_map.find(quality)->second;
    } else {
        set_error(-1, std::format("{} video_quality not found/n returning LOW instead", quality));
        return tidalapi::VIDEO_QUALITY::LOW;
    }
}

py::object quality_to_pyobject(tidalapi::QUALITY quality) {
    py::module_ tidal = get_tidal();
    switch (quality) {
        case tidalapi::QUALITY::LOW:
            return tidal.attr("Quality").attr("low_96k");
        case tidalapi::QUALITY::HIGH:
            return tidal.attr("Quality").attr("low_320k");
        case tidalapi::QUALITY::LOSSLESS:
            return tidal.attr("Quality").attr("high_lossless");
        case tidalapi::QUALITY::HI_RES:
            return tidal.attr("Quality").attr("hi_res");
        case tidalapi::QUALITY::HI_RES_LOSSLESS:
            return tidal.attr("Quality").attr("hi_res_lossless");
        default:
            return tidal.attr("Quality").attr("low_320k");
    };
}

py::object quality_to_pyobject(tidalapi::VIDEO_QUALITY quality) {
    py::module_ tidal = get_tidal();
    switch (quality) {
        case tidalapi::VIDEO_QUALITY::LOW:
            return tidal.attr("VideoQuality").attr("low");
        case tidalapi::VIDEO_QUALITY::MEDIUM:
            return tidal.attr("VideoQuality").attr("medium");
        case tidalapi::VIDEO_QUALITY::HIGH:
            return tidal.attr("VideoQuality").attr("high");
        default:
            return tidal.attr("VideoQuality").attr("high");
    };
}