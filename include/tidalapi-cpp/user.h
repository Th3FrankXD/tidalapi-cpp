#pragma once

namespace tidalapi {
    class User {
    public:
        ~User();

        const int get_id() const;

        const void* handle;
    };

    class FetchedUser : public User {
    public:
        ~FetchedUser();

        void get_first_name();
        void get_last_name();
        void get_picture_id();

        void image();

        const void* handle;
    };

    class PlaylistCreator : public User {
    public:
        ~PlaylistCreator();

        void get_name();

        const void* handle;
    };

    class LoggedInUser : public FetchedUser {
    public:
        ~LoggedInUser();

        void get_username();
        void get_email();
        void get_profile_metadata();

        void playlists();
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
        void almbums();
        void playlists();
        void tracks();
        void videos();

        const void* handle;
    };
}