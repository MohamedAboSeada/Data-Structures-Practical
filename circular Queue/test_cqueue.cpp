#include <iostream>
#include "cqueue.hpp"

using namespace std;

void test_circular_queue() {
    // Create an instance of CircularQueue
    CircularQueue<int> queue(5);

    // Test is_empty() on an empty queue
    bool empty = queue.is_empty();
    cout << "Is queue empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: Yes

    // Test enqueue() and display()
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();  // Expected output: 10 20 30

    // Test dequeue() and display()
    queue.dequeue();
    queue.display();  // Expected output: 20 30

    // Test get_front()
    int front = queue.get_front();
    cout << "Front element: " << front << endl;  // Expected output: 20

    // Test is_empty() on a non-empty queue
    empty = queue.is_empty();
    cout << "Is queue empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: No

    // Test dequeue(element)
    int element;
    queue.dequeue(&element);
    cout << "Dequeued element: " << element << endl;  // Expected output: 20

    // Test display() on an empty queue
    queue.display();  // Expected output: 30

    // Test dequeue() on an empty queue
    queue.dequeue();  // No output expected

    // Test get_front() on an empty queue
    front = queue.get_front();  // No output expected

    // Test is_empty() on an empty queue
    empty = queue.is_empty();
    cout << "Is queue empty? " << (empty ? "Yes" : "No") << endl;  // Expected output: Yes
}

int main() {
    test_circular_queue();
    return 0;
}