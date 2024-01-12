#include <iostream>
#include "sll.hpp"

using namespace std;

void test_singly_linked_list() {
    // Create an instance of SinglyLinkedList
    SinglyLinkedList<string> list;

    // Test is_empty() on an empty list
    bool empty = list.is_empty();
    cout << "Is list empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: Yes

    // Test append() and display()
    list.append("Mohamed");
    list.append("Ahmed");
    list.append("Ali");
    list.display();  // Expected output: [10, 20, 30]

    // Test prepend() and display()
    list.prepend("Ali");
    list.display();  // Expected output: [5, 10, 20, 30]

    // Test insert() and display()
    list.insert("Khaled", 2);
    list.display();  // Expected output: [5, 10, 15, 20, 30]

    // Test pop() and display()
    list.pop();
    list.display();  // Expected output: [5, 10, 15, 20]

    // Test remove_start() and display()
    list.remove_start();
    list.display();  // Expected output: [10, 15, 20]

    // Test remove() and display()
    list.remove(1);
    list.display();  // Expected output: [10, 20]

    // Test search()
    bool found = list.search("Mohamed");
    cout << "Is 20 found in the list? " << (found ? "Yes" : "No") << endl;  // Expected output: Yes

    // Test sort() and display()
    list.sort();
    list.display();  // Expected output: [10, 20]

    // Test reverse() and display()
    list.reverse();
    list.display();  // Expected output: [20, 10]

    // Test length()
    int length = list.length();
    cout << "Length of the list: " << length << endl;  // Expected output: 2

    // Test is_empty() on a non-empty list
    empty = list.is_empty();
    cout << "Is list empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: No

    // Test clear() and display()
    list.clear();
    list.display();  // Expected output: []

    // Test is_empty() on an empty list
    empty = list.is_empty();
    cout << "Is list empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: Yes
}

int main() {
    test_singly_linked_list();
    return 0;
}