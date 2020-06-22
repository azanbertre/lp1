#ifndef diary_h
#define diary_h

#include "message.h"

struct Diary {
    Message* messages;
    
    void add_message();
    void list_messages();
    void dump_messages();
};

#endif