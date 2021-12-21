//
// Created by yarov on 21.12.2021.
//

#ifndef GOOGLE_TESTS_STACK_H
#define GOOGLE_TESTS_STACK_H

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cmath>

template<typename T>
class Stack {
private:
    const static int resize_coefficient = 2;
    const static int default_size = 100;
    int top_;
    int stack_size_;
    T *stack;

    void resize() {
        stack_size_ *= resize_coefficient;
        T *new_stack = new T[stack_size_];
        for (int i = 0; i < top_; i++) {
            new_stack[i] = stack[i];
        }
        delete[] stack;
        stack = new_stack;
    }

public:
    Stack() {
        stack_size_ = default_size;
        top_ = 0;
        stack = new T[stack_size_];
    }

    Stack(int size_) {
        size_ = size_;
        top_ = 0;
        stack = new T[size_];
    }

    Stack(const Stack<T> &st_) {
        delete[] stack;
        stack = new T[st_.stack_size_];
        for (int i = 0; i < st_.number_of_elements(); i++) {
            push(st_.stack[i]);
        }
        stack_size_ = st_.stack_size_;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(T value) {
        if (top_ == stack_size_) {
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

    T top_element() const {
        if (!IsEmpty()) {
            return stack[top_ - 1];
        }
        throw std::out_of_range("Stack is empty");
    }

    bool IsEmpty() const {
        return (number_of_elements() == 0);
    }

    void print() const {
        for (int i = 0; i < number_of_elements(); i++) {
            std::cout << stack[i] << " ";
        }
    }

    int number_of_elements() const {
        return top_;
    }

    void operator<<(const T &value_) {
        push(value_);
    }

    void operator>>(T &value_) {
        value_ = pop();
    }

    /*
    T &operator[](const int& index_) {
        return stack[index_];
    }
    */
    const T &operator[](const int &index_) const {
        return stack[index_];
    }

    void operator=(const Stack<T> &st_) {
        delete[] stack;
        stack = new T[st_.number_of_elements()];
        for (int i = 0; i < st_.number_of_elements(); i++) {
            push(st_.stack[i]);
        }
        top_ = st_.top_;
        stack_size_ = st_.stack_size_;
    }

    bool operator<(const Stack<T> &st_) {
        return (number_of_elements() < st_.number_of_elements());
    }

    bool operator==(const Stack<T> &st_) {
        return (number_of_elements() == st_.number_of_elements());
    }
};

#endif //GOOGLE_TESTS_STACK_H
