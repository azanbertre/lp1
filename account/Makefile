GCC = g++
GCC_FLAGS = -I include -std=c++11
NAME = main

$(NAME): src/main.cpp src/account.cpp include/account.h
	$(GCC) $(GCC_FLAGS) src/main.cpp src/account.cpp -o $(NAME)

clean:
	rm $(NAME)