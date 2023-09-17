#pragma once

#include "tidalapi-cpp.h"
#include "quality.h"

class Config {
public:
    Config(int quality, int video_quality, int item_limit, bool alac);

    void get_quality();
    void get_video_quality();
    void get_item_limit();
    void get_alac();

private:
    void* config;
};