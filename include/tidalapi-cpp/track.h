#pragma once

namespace tidalapi {
    class Track {
    public:
        ~Track();

        void get_replay_gain();
        void get_peak();
        void get_isrc();
        void get_audio_quality();
        void get_version();
        void get_full_name();
        void get_copyright();
        void get_media_metadata_tags();

        void get_url();
        void lyrics();
        void get_track_radio();
        void stream();

        const void* handle;
    };
}