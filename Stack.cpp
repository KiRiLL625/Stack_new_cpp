//
// Created by Admin on 15.11.2023.
//

#include "Stack.h"

Stack::Stack() {
    this->size = 0;
    this->max_size = 0;
}

Stack::Stack(unsigned int max_size) {
    this->stack = std::vector<int>(); //выделяем память под вектор
    this->size = 0;
    this->max_size = max_size;
}

Stack::Stack(const Stack& other) {
    this->stack = other.stack; //копируем вектор
    this->size = other.size;
    this->max_size = other.max_size;
}

Stack& Stack::operator=(const Stack& other) {
    this->stack = other.stack; //копируем вектор
    this->size = other.size;
    this->max_size = other.max_size;
    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept {
    this->stack = std::move(other.stack); //перемещаем вектор
    this->size = other.size;
    this->max_size = other.max_size;
    return *this;
}

void Stack::push(int value) {
    //проверяем, не переполнен ли стек
    if (this->size == this->max_size) {
        throw std::out_of_range("Stack is full");
    }
    this->stack.push_back(value);
    this->size++;
}

void Stack::pop() {
    //проверяем, не пуст ли стек
    if (this->size == 0) {
        throw std::out_of_range("Stack is empty");
    }
    this->stack.pop_back();
    this->size--;
}

int Stack::top() {
    //проверяем, не пуст ли стек
    if (this->size == 0) {
        throw std::out_of_range("Stack is empty");
    }
    return this->stack.back();
}

Stack& Stack::operator+(const Stack& other) {
    //проверяем, не переполнен ли стек
    if (this->size + other.size > this->max_size) {
        throw std::out_of_range("Stack is full");
    }
    Stack* new_stack = new Stack(this->max_size);
    //копируем элементы из стеков в новый стек
    for (int i = 0; i < this->size; i++) {
        new_stack->push(this->stack[i]);
    }
    for (int i = 0; i < other.size; i++) {
        new_stack->push(other.stack[i]);
    }
    return *new_stack;
}

//перегружаем оператор вывода
std::ostream& operator<<(std::ostream& out, const Stack& stack) {
    for (int i = 0; i < stack.size; i++) {
        out << stack.stack[i] << " ";
    }
    return out;
}

//перегружаем оператор ввода
std::istream& operator>>(std::istream& in, Stack& stack) {
    std::string value;
    in >> value;
    //закидываемв стек введенное значение
    stack.push(std::stoi(value));
    return in;
}