#pragma once

#include "session.h"

namespace tidalapi {
    class Page {
    public:
        void get_title();
        void get_categories();

        void next();
        void get();

    private:
        void* page;
    };

    class PageCategory : public Page {
    public:
        void get_type();
        void get_title();
        void get_description();

        void show_more();

    private:
        void* page_category;
    };

    class FeaturedItems : public PageCategory {
    public:
        void get_items();

    private:
        void* featured_items;
    };

    class PageLinks : public PageCategory {
    public:
        void get_items();

    private:
        void* page_links;
    };

    class ItemList : public PageCategory {
    public:
        void get_items();

    private:
        void* item_list;
    };

    class LinkList : public PageCategory {
    public:
        void get_items();
        void get_title();
        void get_description();

    private:
        void* link_list;
    };

    class PageLink {
    public:
        void get_header();
        void get_short_header();
        void get_short_sub_header();
        void get_image_id();
        void get_text();
        void get_featured();

        void get();

    private:
        void* page_link;
    };

    class TextBlock {
    public:
        void get_text();
        void get_icon();
        void get_items();

    private:
        void* text_block;
    };
}