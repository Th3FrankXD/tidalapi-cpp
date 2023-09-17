#include "session.h"

class User {
public:
    User(Session session, char* user_id);

    void get_id();
};

class FetchedUser : public User {
public:
    void get_first_name();
    void get_last_name();
    void get_picture_id();

    void image();
};

class PlaylistCreator : public User {
public:
    void get_name();
};

class LoggedInUser : public FetchedUser {
public:
    void get_username();
    void get_email();
    void get_profile_metadata();

    void playlists();
    void playlist_and_favorite_playlists();
    void create_playlist();
};

class Favorites {
public:
    Favorites(Session session, char* user_id);

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
};