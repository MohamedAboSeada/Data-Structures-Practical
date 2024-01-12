#include <iostream>
#include "stack.hpp"
using namespace std;

int main() {
    // Create a stack of size 5
    FixedStack<int> stack(5);

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

    // Test is_full() and is_empty()
    bool full = stack.is_full();
    bool empty = stack.is_empty();
    cout << "Is stack full? " << (full ? "Yes" : "No") << endl;    // Expected output: No
    cout << "Is stack empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: No

    // Test pop(element)
    int element;
    stack.pop(&element);
    cout << "Popped element: " << element << endl;  // Expected output: 20

    // Test Length()
    int length = stack.Length();
    std::cout << "Stack length: " << length << std::endl;  // Expected output: 5

    return 0;
}