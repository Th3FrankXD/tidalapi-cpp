#pragma once

#include "session.h"

class Artist {
public:
    Artist(Session session, char* artist_id);

    void get_id();
    void get_name();
    void get_roles();
    void get_role();
    void get_user_date_added();

    void get_albums();
    void get_albums_ep_singles();
    void get_albums_other();
    void get_top_tracks();
    void get_videos();
    void get_bio();
    void get_similar();
    void get_radio();
    void image();
    void page();

private:
    void* artist;
};