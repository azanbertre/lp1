#ifndef app_h
#define app_h

#include <string>
#include "diary.h"

struct app {
    Diary diary;

    app();
    app(const std::string& filename);

    int run(int argc, char* argv[]);
    int show_usage(const std::string &prog_name);
    void add();
    void add(const std::string message);
    void list();
    void list(const std::string format);
    void search();
    void search(const std::string search);
    void load_config();
};

void open_menu(app* app);

#endif