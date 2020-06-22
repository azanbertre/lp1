#ifndef datetime_h
#define datetime_h

struct datetime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    static datetime now();
    std::string get_current_date();
    std::string get_current_time();
};

std::string format_int(int value);

#endif