class Lyrics {
public:
    void get_track_id();
    void get_provider();
    void get_provider_track_id();
    void get_provider_lyrics_id();
    void get_text();
    void get_subtitles();
    void get_right_to_left();

private:
    void* lyrics;
};