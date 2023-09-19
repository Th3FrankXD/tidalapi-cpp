#pragma once

#include "session.h"

namespace tidalapi {
    class Mix {
    public:
        Mix(Session session, char* mix_id);
        ~Mix();

        void get_id();
        void get_title();
        void get_sub_title();
        void get_sharing_images();
        void get_mix_type();
        void get_content_behaviour();
        void get_short_subtitle();

        void get();
        void items();
        void image();

        const void* handle;
    };
}