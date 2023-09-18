#pragma once

#include "quality.h"

namespace tidalapi {
    class Config {
    public:
        Config(QUALITY quality, VIDEO_QUALITY video_quality, int item_limit, bool alac);

        void get_quality();
        void get_video_quality();
        void get_item_limit();
        void get_alac();
        
        const void* handle;
    };
}