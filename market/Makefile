GCC = g++
GCC_FLAGS = -I include -std=c++11
NAME = main

$(NAME): src/main.cpp src/app.cpp src/establishment.cpp src/product.cpp src/client.cpp src/provider.cpp include/app.h include/establishment.h include/product.h include/client.h include/provider.h include/vector_market.h
	$(GCC) $(GCC_FLAGS) src/main.cpp src/app.cpp src/establishment.cpp src/product.cpp src/client.cpp src/provider.cpp -o $(NAME)

clean:
	rm $(NAME)