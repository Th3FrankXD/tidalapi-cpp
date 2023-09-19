#pragma once

#include "config.h"
#include "quality.h"
#include "login.h"
#include "user.h"

namespace tidalapi {
    class Session {
    public:
        Session(Config config);
        ~Session();

        const std::string get_session_id();

        const std::string get_access_token();
        const std::string get_expiry_time();
        const std::string get_refresh_token();
        const std::string get_token_type();

        const bool token_refresh(std::string refresh_token);

        const bool load_session(std::string session_id, std::string country_code="", int user_id=-1);
        void load_oauth_session();
        void login();
        const tidalapi::Login login_oauth();
        const bool check_login();

        const tidalapi::User get_current_user();

        const tidalapi::User get_user(int user_id);

        void playlist();
        void track();
        void video();
        void artist();
        void album();
        void mix();
        
        void home();
        void explore();
        void for_you();
        void videos();
        void genres();
        void local_genres();
        void mood();
        void mixes();

        void search();

        const tidalapi::QUALITY get_quality();
        void get_video_quality();
        void set_quality();
        void set_video_quality();

        const std::string get_country_code();

        const void* handle;
    };
}