#include <iostream>
#include "employee.h"
#include "company.h"

#include <vector>

int main(int argc, char const *argv[]) {

    Company c("Name1", "12312321");

    std::string _n;
    std::cout << "Number of employees: " << std::ends;
    std::getline(std::cin, _n);

    size_t employee_number = std::stoi(_n);

    std::vector<Employee*> employees;
    for (size_t i = 0; i < employee_number; i++) {
        std::string _name = "employee-";
        _name.append(std::to_string(i));
        employees.push_back(new Employee(_name, 500 * (i + 1), c));
    }

    for (size_t i = 0; i < employee_number; i++) {
        std::cout << "Salary " << employees[i]->get_name() << " - " << employees[i]->get_salary() << std::endl;
    }

    std::cout << "\nUpdating salaries\n" << std::endl;
    for (size_t i = 0; i < employee_number; i++) {
        employees[i]->set_salary(employees[i]->get_salary() * 1.1);
    }

    for (size_t i = 0; i < employee_number; i++) {
        std::cout << "Salary " << employees[i]->get_name() << " - " << employees[i]->get_salary() << std::endl;
    }

    for (size_t i = 0; i < employee_number; i++) {
        delete employees[i];
    }

    employees.clear();

    return 0;
}