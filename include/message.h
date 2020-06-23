#ifndef message_h
#define message_h

#include <string>
#include "datetime.h"

struct Message {
    Message(const std::string& content);

    datetime dt;
    std::string content;

    std::string format_message();
    bool compare_dates(const Message &other_message);
};

#endif