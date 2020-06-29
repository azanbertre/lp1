GCC = g++
GCC_FLAGS = -I include -std=c++11
NAME = main

$(NAME): src/main.cpp src/app.cpp src/datetime.cpp src/message.cpp src/diary.cpp include/app.h include/datetime.h include/message.h include/diary.h
	$(GCC) $(GCC_FLAGS) src/main.cpp src/app.cpp src/datetime.cpp src/message.cpp src/diary.cpp -o $(NAME)