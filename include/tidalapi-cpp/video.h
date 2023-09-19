#pragma once

namespace tidalapi {
    class Video {
    public:
        ~Video();

        void get_release_date();
        void get_video_quality();

        void get_url();
        void image();

        const void* handle;
    };
}