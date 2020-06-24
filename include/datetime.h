#ifndef datetime_h
#define datetime_h

#include <string>

struct datetime {
    datetime(
        const unsigned year=0U,
        const unsigned month=0U,
        const unsigned day=0U,
        const unsigned hour=0U,
        const unsigned minute=0U,
        const unsigned second=0U
    );

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