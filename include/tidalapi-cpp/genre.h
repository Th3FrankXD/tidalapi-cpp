#pragma once

#include "session.h"

class Genre {
public:
    Genre(Session session);

    void get_name();
    void get_path();
    void get_has_playlists();
    void get_has_artists();
    void get_has_albums();
    void get_has_tracks();
    void get_has_videos();

    void get_genres();
    void items();
    void image();
};