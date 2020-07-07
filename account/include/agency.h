#ifndef agency_h
#define agency_h

#include <string>

class Agency {
    public:
        std::string name;
        std::string number;

        Agency(std::string _name, std::string _number);
};

#endif