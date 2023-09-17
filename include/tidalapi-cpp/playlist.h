#include "session.h"

class Playlist {
public:
    Playlist(Session session, char* playlist_id);

    void get_id();
    void get_name();
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
};

class UserPlaylist : public Playlist {
public:
    void edit();
    void destroy();
    void add();
    void remove_by_index();
    void remove_by_indeces();
    void remove_by_id();
};