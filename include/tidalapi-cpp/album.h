#pragma once

#include "session.h"
namespace tidalapi {
    class Album {
    public:
        Album(Session session, char* album_id);
        ~Album();

        void get_id();
        void get_video_cover();
        void get_duration();
        void get_available();
        void get_num_tracks();
        void get_num_videos();
        void get_num_volumes();
        void get_copyright();
        void get_version();
        void get_explicit();
        void get_universal_product_number();
        void get_popularity();
        void get_type();
        void get_artist();
        void get_artists();
        void get_user_date_added();
        void get_name();
        void get_type();

        void year();
        void available_release_date();
        void tracks();
        void items();
        void image();
        void video_image();
        void page();
        void similar();
        void review();

        const void* handle;
    };
}