#pragma once

namespace tidalapi {
    class Stream {
    public:
        void get_track_id();
        void get_audio_mode();
        void get_audio_quality();
        void get_manifest_mime_type();
        void get_manifest_hash();
        void get_manifest();

    private:
        void* stream;
    };
}