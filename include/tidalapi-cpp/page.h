#pragma once

#include "session.h"

namespace tidalapi {
    class Page {
    public:
        ~Page();

        void get_title();
        void get_categories();

        void next();
        void get();

        const void* handle;
    };

    class PageCategory : public Page {
    public:
        ~PageCategory();

        void get_type();
        void get_title();
        void get_description();

        void show_more();

        const void* handle;
    };

    class FeaturedItems : public PageCategory {
    public:
        ~FeaturedItems();

        void get_items();

        const void* handle;
    };

    class PageLinks : public PageCategory {
    public:
        ~PageLinks();

        void get_items();

        const void* handle;
    };

    class ItemList : public PageCategory {
    public:
        ~ItemList();

        void get_items();

        const void* handle;
    };

    class LinkList : public PageCategory {
    public:
        ~LinkList();

        void get_items();
        void get_title();
        void get_description();

        const void* handle;
    };

    class PageLink {
    public:
        ~PageLink();

        void get_header();
        void get_short_header();
        void get_short_sub_header();
        void get_image_id();
        void get_text();
        void get_featured();

        void get();

        const void* handle;
    };

    class TextBlock {
    public:
        ~TextBlock();

        void get_text();
        void get_icon();
        void get_items();

        const void* handle;
    };
}