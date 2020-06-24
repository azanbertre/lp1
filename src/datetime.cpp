#include <string>
#include <ctime>
#include "datetime.h"

datetime::datetime(
    const unsigned year,
    const unsigned month,
    const unsigned day,
    const unsigned hour,
    const unsigned minute,
    const unsigned second
) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

datetime datetime::now() {
    std::time_t now = std::time(nullptr);
    tm *ltm = std::localtime(&now);

    datetime dt = datetime(
        (unsigned) 1900 + ltm->tm_year,
        (unsigned) 1 + ltm->tm_mon,
        (unsigned) ltm->tm_mday,
        (unsigned) ltm->tm_hour,
        (unsigned) ltm->tm_min,
        (unsigned) ltm->tm_sec
    );

    return dt;
}

std::string datetime::get_current_date() {
    std::string date = format_int(this->day);
    date.append("/");
    date.append(format_int(this->month));
    date.append("/");
    date.append(format_int(this->year));

    return date;
}

std::string datetime::get_current_time() {
    std::string time = format_int(this->hour);
    time.append(":");
    time.append(format_int(this->minute));
    time.append(":");
    time.append(format_int(this->second));

    return time;
}

std::string format_int(int value) {
    if (value < 10) {
        std::string zero = "0";
        zero.append(std::to_string(value));
        return zero;
    }
    return std::to_string(value);
}