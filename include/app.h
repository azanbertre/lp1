#ifndef app_h
#define app_h

#include <string>
#include "diary.h"

struct app {
    Diary diary;

    app(const std::string& filename);

    int run(int argc, char* argv[]);
    int show_usage(const std::string &prog_name);
    void add();
    void add(const std::string message);
    void list_messages();
};

#endif