#ifndef datetime_h
#define datetime_h

#include <string>

struct datetime {
    unsigned year;
    unsigned month;
    unsigned day;
    unsigned hour;
    unsigned minute;
    unsigned second;

    static datetime now();
    std::string get_current_date();
    std::string get_current_time();
};

std::string format_int(int value);

#endif