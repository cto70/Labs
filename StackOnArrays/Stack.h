#pragma once

template<typename T>
class Stack {
private:
    const int resize_coefficient = 2;
    const int default_size = 100;
    int top_;
    int size;
    T *stack;

    void resize() {
        size *= resize_coefficient;
        T *new_stack = new T[size];
        for (int i = 0; i < top_; i++) {
            new_stack[i] = stack[i];
        }
        delete[] stack;
        stack = new_stack;
    }

public:
    Stack() {
        size = default_size;
        top_ = 0;
        stack = new T[size];
    }

    Stack(int size_) {
        size = size_;
        top_ = 0;
        stack = new T[size];
    }

    ~Stack() {
        delete[] stack;
    }

    void push(T value) {
        if (top_ == size) {
            resize();
        }
        stack[top_] = value;
        top_++;
    }

    T pop() {
        if (!IsEmpty()) {
            top_--;
            return stack[top_];
        }
        throw std::out_of_range("Can't delete element in empty stack");
    }

    T top() {
        if (!IsEmpty()) {
            return stack[top_ - 1];
        }
        throw std::out_of_range("Stack is empty");
    }

    bool IsEmpty() {
        return (top_ == 0);
    }

    void print() {
        for (int i = 0; i < top_; i++) {
            std::cout << stack[i] << " ";
        }
    }
};
