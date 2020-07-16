GCC = g++
GCC_FLAGS = -I include -std=c++11
NAME = main

$(NAME): src/main.cpp src/account.cpp src/agency.cpp src/client.cpp src/clientpj.cpp include/account.h include/agency.h include/client.h include/clientpj.h
	$(GCC) $(GCC_FLAGS) src/main.cpp src/account.cpp src/agency.cpp src/client.cpp src/clientpj.cpp -o $(NAME)

clean:
	rm $(NAME)