#pragma once

#include "tidalapi-cpp.h"

class Config {
public:
    Config(tidalapi::QUALITY quality=tidalapi::QUALITY::HI_RES, tidalapi::VIDEO_QUALITY video_quality=tidalapi::VIDEO_QUALITY::HIGH, int item_limit=1000, bool alac=true);

    void get_quality();
    void get_video_quality();
    void get_item_limit();
    void get_alac();
};