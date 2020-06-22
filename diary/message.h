#ifndef message_h
#define message_h

#include <string>
#include "datetime.h"

struct Message {
    datetime dt;
    std::string content;

    bool compare_dates(const Message &other_message);
};

#endif