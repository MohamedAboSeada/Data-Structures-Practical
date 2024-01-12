#include <iostream>
using namespace std;

/**
 * @brief A fixed-size stack implementation.
 * 
 * @tparam uese Generic template to store any type of data
 */
template<class any>
class FixedStack{
private:
    int top;        ///< Index of the top element in the stack.
    any* items;     ///< Array to store the elements of the stack.
    int size;       ///< Maximum size of the stack.

public:
    /**
     * @brief Constructs a new FixedStack object with the specified size.
     * 
     * @param size The maximum size of the stack.
     */
    FixedStack(int size){
        top = -1;
        this->size = size;
        items = new any[this->size];
    }

    /**
     * @brief Pushes an element onto the top of the stack.
     * 
     * @param data The element to be pushed onto the stack.
     */
    void push(any data){
        if(!is_full()){
            this->top++;
            this->items[this->top] = data;
        }
    }

    /**
     * @brief Removes the top element from the stack.
     */
    void pop(){
        if(!is_empty())
            this->top--;
    }

    /**
     * @brief Removes the top element from the stack and returns it.
     * 
     * @param element Pointer to store the popped element.
     */
    void pop(any *element){
        any value = NULL;
        if(!is_empty()){
            value = this->items[this->top];
            this->top--;
        }
        *element = value;
    }

    /**
     * @brief Returns the top element of the stack without removing it.
     * 
     * @return The top element of the stack.
     */
    any get_top(){
        any value = NULL;
        if(!is_empty())
            value = this->items[this->top];
        return value;
    }

    /**
     * @brief Checks if the stack is full.
     * 
     * @return True if the stack is full, false otherwise.
     */
    bool is_full(){
        return this->top >= this->size;
    }

    /**
     * @brief Checks if the stack is empty.
     * 
     * @return True if the stack is empty, false otherwise.
     */
    bool is_empty(){
        return this->top == -1;
    }

    /**
     * @brief Displays the elements of the stack.
     */
    void display(){
        if(!is_empty()){
            int n = this->top;
            while(n != -1){
                cout<<this->items[n]<<" ";
                n--;
            }
            cout<<endl;
        }
    }

    /**
     * @brief Returns the maximum size of the stack.
     * 
     * @return The maximum size of the stack.
     */
    int Length(){
        return this->size;
    }

    /**
     * @brief Destroys the FixedStack object and frees the memory.
     */
    ~FixedStack(){
        delete[] items;
    }
};
