#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedStack{
    Node* top;
public:
    /**
     * @brief Constructor for LinkedStack class.
     */
    LinkedStack(){
        top = nullptr;
    }

    /**
     * @brief Checks if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     * @complexity O(1)
     */
    bool is_empty(){
        return this->top == nullptr;
    }

    /**
     * @brief Pushes an item onto the top of the stack.
     * @param item The item to be pushed onto the stack.
     * @complexity O(1)
     */
    void push(int item){
        Node* new_node = new Node();
        new_node->data = item;
        new_node->next = top;
        top = new_node;
    }

    /**
     * @brief Pops the top item from the stack.
     * @complexity O(1)
     */
    void pop(){
        if(!is_empty()){
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    /**
     * @brief Pops the top item from the stack and returns its value.
     * @param element Pointer to store the popped item's value.
     * @complexity O(1)
     */
    void pop(int* element){
        int value = -1;
        if(!is_empty()){
            Node* temp = top;
            value = top->data;
            top = top->next;
            delete temp;
        }
        *element = value;
    }

    /**
     * @brief Returns the value of the top item in the stack.
     * @return The value of the top item, or -1 if the stack is empty.
     * @complexity O(1)
     */
    int get_top(){
        int value = -1; 
        if(!is_empty())
            value = top->data;
        return value;
    }

    /**
     * @brief Displays the elements in the stack.
     * @complexity O(n), where n is the number of elements in the stack.
     */
    void display(){
        if(!is_empty()){
            Node* n = this->top;
            while(n != nullptr){
                cout<<n->data<<" ";
                n = n->next;
            }
            cout<<endl;
        }
    }

    /**
     * @brief Destructor for LinkedStack class.
     *        Frees all the elements in the stack.
     * @complexity O(n), where n is the number of elements in the stack.
     */
    ~LinkedStack(){
        while (top != nullptr){
            Node* temp = top;
            top = top->next;
            delete temp;
        } 
        cout<<"All Freed"<<endl;  
    }
};