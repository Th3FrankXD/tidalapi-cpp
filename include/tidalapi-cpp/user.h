#pragma once

#include <string>
#include <vector>
#include "playlist.h"

namespace tidalapi {
    class User {
    public:
        ~User();
        // User
        const int get_id() const;

        // FetchedUser : User
        const std::string get_first_name();
        const std::string get_last_name();
        const std::string image(int dimensions);

        // playlistCreator : User
        const std::string get_name();

        // LoggedInUser : FetchedUser
        const std::string get_username();
        const std::string get_email();
        const std::string get_profile_metadata();
        std::vector<tidalapi::Playlist> playlists();
        void playlist_and_favorite_playlists();
        void create_playlist();

        const void* handle;
    };

    class Favorites {
    public:
        ~Favorites();

        void add_album();
        void add_artist();
        void add_playlist();
        void add_track();
        void add_video();
        void remove_artist();
        void remove_album();
        void remove_playlist();
        void remove_track();
        void remove_video();
        void artists();
        void albums();
        void playlists();
        void tracks();
        void videos();

        const void* handle;
    };
}