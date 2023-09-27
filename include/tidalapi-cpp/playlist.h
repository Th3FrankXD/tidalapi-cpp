#pragma once

#include <string>
#include <memory>

namespace tidalapi {
    class Playlist {
    public:
        // Playlist
        void get_id();
        const std::string get_name();
        void get_num_tracks();
        void get_num_videos();
        void get_creator();
        void get_description();
        void get_duration();
        void get_last_updated();
        void get_created();
        void get_type();
        void get_public();
        void get_popularity();
        void get_promoted_artists();
        void get_last_item_added_at();
        void get_user_date_added();
        void tracks();
        void items();
        void image();
        void wide_image();

        // UserPlaylist
        void edit();
        void destroy();
        void add();
        void remove_by_index();
        void remove_by_indeces();
        void remove_by_id();

        const void* handle;
    };

    // class UserPlaylist : public Playlist {
    // public:
    //     ~UserPlaylist();

    //     void edit();
    //     void destroy();
    //     void add();
    //     void remove_by_index();
    //     void remove_by_indeces();
    //     void remove_by_id();

    //     const void* handle;
    // };
}