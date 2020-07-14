GCC = g++
GCC_FLAGS = -I include -std=c++11
NAME = main

$(NAME): src/main.cpp src/company.cpp src/employee.cpp include/company.h include/employee.h
	$(GCC) $(GCC_FLAGS) src/main.cpp src/company.cpp src/employee.cpp -o $(NAME)

clean:
	rm $(NAME)