#include <iostream>
using namespace std;

template<class anydata>
class Node
{
public:
    anydata data;
    Node* next;
    Node(anydata data = NULL)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <class any>
class LinkedQueue
{
    Node<any>* front; // Pointer to the front of the queue
    Node<any>* rear; // Pointer to the rear of the queue
    int count; // Number of elements in the queue

public:
    /**
     * Constructor for the LinkedQueue class.
     * Initializes the front and rear pointers to nullptr and count to 0.
     */
    LinkedQueue()
    {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    /**
     * Adds an element to the rear of the queue.
     * @param data The data to be added to the queue.
     */
    void enqueue(any data)
    {
        Node<any>* new_node = new Node<any>(data);
        if (is_empty())
        {
            front = rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
        count++;
    }

    /**
     * Removes the element from the front of the queue.
     */
    void dequeue()
    {
        if (!is_empty())
        {
            Node<any>* temp = front;
            front = front->next;
            delete temp;
            count--;
        }
    }

    /**
     * Removes the element from the front of the queue and returns it.
     * @param element Pointer to store the removed element.
     */
    void dequeue(any* element)
    {
        if (!is_empty())
        {
            Node<any>* temp = front;
            *element = temp->data;
            front = front->next;
            delete temp;
            count--;
        }
    }

    /**
     * Returns the element at the front of the queue without removing it.
     * @return The element at the front of the queue.
     */
    any get_front()
    {
        if (!is_empty())
        {
            return front->data;
        }
    }

    /**
     * Returns the element at the rear of the queue without removing it.
     * @return The element at the rear of the queue.
     */
    any get_rear()
    {
        if (!is_empty())
        {
            return rear->data;
        }
    }

    /**
     * Returns the number of elements in the queue.
     * @return The number of elements in the queue.
     */
    int length()
    {
        return count;
    }

    /**
     * Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    bool is_empty()
    {
        return front == nullptr;
    }

    /**
     * Displays the elements of the queue.
     */
    void display()
    {
        if (!is_empty())
        {
            Node<any>* n = front;
            while (n != nullptr)
            {
                cout << n->data << " ";
                n = n->next;
            }
            cout<<endl;
        }
    }

    /**
     * Destructor for the LinkedQueue class.
     * Deletes all the nodes in the queue.
     */
    ~LinkedQueue()
    {
        while(front != nullptr){
            Node<any>* temp = front;
            front = front->next;
            delete temp;            
        }
    }
};
