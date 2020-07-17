#ifndef vector_market_h
#define vector_market_h

#include <iostream>

template <class T>
class vector_market {
    private:
        int count;
        int top;
        T *elements;

    public:
        vector_market() {
            this->count = 10;
            this->top = -1;
            this->elements = new T[count];
        }
        ~vector_market() {
            for(size_t i = 0; i < this->top + 1; i++) {
                delete this->elements[i];
            }

            delete this->elements;
        }
        void push(T element) {
            if (this->top == (this->count - 1)) {

                this->count = this->top + this->count;

                // add more space
                T *temp = new T[this->count];

                for (size_t i = 0; i < count; i++) {
                    temp[i] = this->elements[i];
                }

                delete this->elements;

                this->elements = temp;
            }

            this->elements[++this->top] = element;
        }
        void pop() {
            if (this->top == -1) {
                std::cout << "Empty" << std::endl;
            }
            else {
                this->elements[this->top--];
            }
        }
        bool isEmpty() {
            if (this->top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
        T back() {
            return this->elements[this->top];
        }
        T get(size_t index) {
            if (index > this->top) {
                return nullptr;
            }
            return this->elements[index];
        }
        size_t size() {
            return this->top + 1;
        }
};

#endif
