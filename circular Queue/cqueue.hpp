#include <iostream>
using namespace std;

template<class any>
/**
 * @brief Circular Queue implementation.
 */
class CircularQueue{
    int front;  // index of queue front
    int rear;   // index of queue end
    int count;  // number of queue elements
    any* items; // array to store items
    int size;   // max size for the queue
public:
    /**
     * @brief Constructor for CircularQueue class.
     * @param size The maximum size of the queue.
     */
    CircularQueue(int size){
        this->size = size;
        this->front = 0;
        this->rear = size - 1;
        this->items = new any[this->size];
        this->count = 0;
    }

    /**
     * @brief Adds an element to the rear of the queue.
     * @param data The element to be added.
     * @complexity O(1)
     */
    void enqueue(any data){
        if(!is_full()){
            this->rear = (this->rear + 1) % this->size;
            this->items[this->rear] = data;
            this->count += 1;
        }else{
            cout<<"Queue is full on enqueue!\n";
        }
    }

    /**
     * @brief Removes the element from the front of the queue.
     * @complexity O(1)
     */
    void dequeue(){
        if(!is_empty()){
            this->front = (this->front + 1) % this->size;
            count-=1;
        }else{
            cout<<"Queue is empty on dequeue!\n";
        }
    }

    /**
     * @brief Removes the element from the front of the queue and returns it.
     * @param element Pointer to store the dequeued element.
     * @complexity O(1)
     */
    void dequeue(any* element){
        if(!is_empty()){
            *element = this->items[this->front];
            this->front = (this->front + 1) % this->size;
            count-=1;
        }else{
            cout<<"Queue is empty on dequeue!\n";
        }
    }

    /**
     * @brief Displays the elements of the queue.
     * @complexity O(n)
     */
    void display(){
        if(!is_empty()){
            int n = this->front;
            while(n != this->rear){
                cout<<this->items[n]<<" ";
                n = (n+1) % this->size;
            }
            cout<<this->items[this->rear]<<endl;
        }
    }

    /**
     * @brief Returns the number of elements in the queue.
     * @return The number of elements in the queue.
     * @complexity O(1)
     */
    int get_size(){
        return this->count;
    }

    /**
     * @brief Returns the maximum size of the queue.
     * @return The maximum size of the queue.
     * @complexity O(1)
     */
    int length(){
        return this->size;
    }

    /**
     * @brief Returns the element at the front of the queue without removing it.
     * @return The element at the front of the queue.
     * @complexity O(1)
     */
    any get_front(){
        any value = (any)NULL;
        if(!is_empty()){
            value = this->items[this->front];
        }
        return value;
    }

    /**
     * @brief Returns the element at the rear of the queue without removing it.
     * @return The element at the rear of the queue.
     * @complexity O(1)
     */
    any get_rear(){
        any value = (any)NULL;
        if(!is_empty()){
            value = this->items[this->rear];
        }
        return value;
    }

    /**
     * @brief Checks if the queue is full.
     * @return True if the queue is full, False otherwise.
     * @complexity O(1)
     */
    bool is_full(){
        return count == this->size;
    }

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, False otherwise.
     * @complexity O(1)
     */
    bool is_empty(){
        return count == 0;
    }

    /**
     * @brief Destructor for CircularQueue class.
     */
    ~CircularQueue(){
        delete[] items;
    }
};