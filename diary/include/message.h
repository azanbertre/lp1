#ifndef message_h
#define message_h

#include <string>
#include "datetime.h"

struct Message {
    Message();
    Message(const std::string& content);
    Message(const std::string& content, const datetime& dt);

    datetime dt;
    std::string content;

    std::string format_message(const std::string format);
};

#endif