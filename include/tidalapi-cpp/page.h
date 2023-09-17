#include "session.h"

class Page {
public:
    void get_title();
    void get_categories();

    void next();
    void get();
};

class PageCategory : public Page {
public:
    void get_type();
    void get_title();
    void get_description();

    void show_more();
};

class FeaturedItems : public PageCategory {
public:
    void get_items();
};

class PageLinks : public PageCategory {
public:
    void get_items();
};

class ItemList : public PageCategory {
public:
    void get_items();
};

class LinkList : public PageCategory {
public:
    void get_items();
    void get_title();
    void get_description();
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
};

class TektBlock {
public:
    void get_text();
    void get_icon();
    void get_items();
};