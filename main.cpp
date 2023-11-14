#include <iostream>
#include "Stack.h"

int main() {
    Stack stack1(5);
    Stack stack2(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    std::cout << stack1.top() << std::endl;
    stack1.pop();
    std::cout << stack1 << std::endl;
    stack2.push(4);
    stack2.push(5);
    std::cout << stack2.top() << std::endl;
    Stack stack3 = stack1 + stack2;
    std::cout << stack3 << std::endl;
    return 0;
}
