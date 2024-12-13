#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            throw std::overflow_error("Stack overflow!");
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            throw std::underflow_error("Stack underflow!");
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            throw std::underflow_error("Stack is empty!");
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Top element: " << stack.peek() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Top element: " << stack.peek() << std::endl;
    return 0;
}
