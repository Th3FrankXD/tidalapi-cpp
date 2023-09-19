#include "user.h"
#include "utils.h"

tidalapi::User::~User() {
    delete get_pyobject(handle);
}

const int tidalapi::User::get_id() const {
    return get_pyobject(handle)->attr("id").cast<int>(); 
}