#pragma once

#include "session.h"

namespace tidalapi {
    class Media {
    public:
        ~Media();

        void get_id();
        void get_name();
        void get_duration();
        void get_available();
        void get_tidal_release_date();
        void get_user_date_added();
        void get_track_num();
        void get_volume_num();
        void get_explicit();
        void get_popularity();
        void get_artist();
        void get_artist_roles();
        void get_artists();
        void get_album();
        void get_type();

        const void* handle;
    };
}