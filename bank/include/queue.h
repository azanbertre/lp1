#include <iostream>

template <class T>
class Queue {
    private:
        int size;
        int top;
        T *elements;

    public:
        Queue(int s) {
            this->size = s;
            this->top = -1;
            this->elements = new T[size];
        }

        void push(T element) {
            if (top == (size - 1)) {
                std::cout << "Full queue" << std::endl;
            }
            else {
                this->elements[++top] = element;
            }
        }
        void pop() {
            if (top == -1) {
                std::cout << "Empty queue" << std::endl;
            }
            else {
                this->elements[top--];
            }
        }
        bool isEmpty() {
            if (top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
        T back() {
            return this->elements[top];
        }
};