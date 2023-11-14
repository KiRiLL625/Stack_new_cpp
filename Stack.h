//
// Created by Admin on 15.11.2023.
//

#ifndef STACK_NEW_STACK_H
#define STACK_NEW_STACK_H

#include <vector>
#include <ostream>

class Stack {
private:
    std::vector<int> stack; //хранит элементы стека
    unsigned int size;
    unsigned int max_size;
public:
    Stack(); //конструктор по умолчанию
    explicit Stack(unsigned int max_size); //конструктор с параметром
    Stack(const Stack& other); //конструктор копирования
    Stack& operator=(const Stack& other); //оператор копирующего присваивания
    Stack& operator=(Stack&& other) noexcept; //оператор перемещающего присваивания
    void push(int value); //добавление элемента в стек
    void pop(); //удаление элемента из стека
    int top(); //возвращает верхний элемент стека
    Stack& operator+(const Stack& other); //оператор сложения двух стеков
    friend std::ostream& operator<<(std::ostream& out, const Stack& stack); //оператор вывода
    friend std::istream& operator>>(std::istream& in, Stack& stack); //оператор ввода
};


#endif //STACK_NEW_STACK_H
