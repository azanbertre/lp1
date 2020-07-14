#ifndef employee_h
#define employee_h

#include <string>
#include <ctime>
#include "company.h"

class Employee {
    private:
        std::string name;
        Company company;
        std::string department;
        double salary;
        std::time_t time_start;

    public:
        Employee(std::string _name, double _salary, Company _company);
        void set_name(std::string _name);
        std::string get_name();
        void set_company(Company _company);
        Company get_company();
        void set_department(std::string _department);
        std::string get_department();
        void set_salary(double _salary);
        double get_salary();
};

#endif