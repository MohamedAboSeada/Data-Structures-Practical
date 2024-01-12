#include <iostream>
#include "Lstack.hpp"
using namespace std;

void test_stack() {
    // Create an instance of LinkedStack
    LinkedStack stack;

    // Test is_empty() on an empty stack
    bool empty = stack.is_empty();
    cout << "Is stack empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: Yes

    // Test push() and display()
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();  // Expected output: 30 20 10

    // Test pop() and display()
    stack.pop();
    stack.display();  // Expected output: 20 10

    // Test get_top()
    int top = stack.get_top();
    cout << "Top element: " << top << endl;  // Expected output: 20

    // Test is_empty() on a non-empty stack
    empty = stack.is_empty();
    cout << "Is stack empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: No

    // Test pop(element)
    int element;
    stack.pop(&element);
    cout << "Popped element: " << element << endl;  // Expected output: 20

    // Test display() on an empty stack
    stack.display();  // Expected output: (nothing)

    // Test pop() on an empty stack
    stack.pop();  // No output expected

    // Test get_top() on an empty stack
    top = stack.get_top();  // No output expected

    // Test is_empty() on an empty stack
    empty = stack.is_empty();
    cout << "Is stack empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: Yes
}

int main() {
    // test_stack();
    LinkedStack stack;
    for(int i = 0;i<20;i++){
        stack.push(i+1);
    }
    stack.pop();//20

    int element = 0;
    stack.pop(&element);
    cout<<element<<endl; // 19

    stack.display(); // 18
    return 0;
}