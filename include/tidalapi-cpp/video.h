#pragma once

namespace tidalapi {
    class Video {
    public:
        void get_release_date();
        void get_video_quality();

        void get_url();
        void image();

    private:
        void* video;
    };
}