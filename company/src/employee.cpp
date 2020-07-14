#include "../include/employee.h"

Employee::Employee(std::string _name, double _salary, Company _company) : name(_name), salary(_salary), company(_company) {
    this->time_start = std::time(nullptr);
}

double Employee::get_salary() {
    return this->salary;
}

void Employee::set_salary(double _salary) {
    this->salary = _salary;
}

std::string Employee::get_name() {
    return this->name;
}

void Employee::set_name(std::string _name) {
    this->name = _name;
}

Company Employee::get_company() {
    return this->company;
}

void Employee::set_company(Company _company) {
    this->company = _company;
}

std::string Employee::get_department() {
    return this->department;
}

void Employee::set_department(std::string _department) {
    this->department = _department;
}