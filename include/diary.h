#ifndef diary_h
#define diary_h

#include "message.h"

struct Diary {
    Diary(const std::string& filename);

    std::string filename;
    Message* messages;
    unsigned messages_count;
    unsigned messages_capacity;

    void add_message(const Message& message);
    void dump_messages();
    void load_messages();
    void update_capacity();
};

#endif