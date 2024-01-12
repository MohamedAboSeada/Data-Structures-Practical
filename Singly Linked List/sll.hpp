#include <iostream>
using namespace std;

/**
 * @brief the element of the list that has 2 attributes item the actual node value
 * next pointer used to link nodes together each node points to it's next node
*/
template <class Any>
class Node{
public:
    Any item;
    Node<Any>* next;
    Node(Any item){
        this->item = item;
        next = nullptr;
    }
};

/**
 * @brief Data structure that uses nodes to add elements to it dinamiclly
 * without fixed size
*/
template <class Any>
class SinglyLinkedList{
    
    Node<Any>* head;
    int count;

public:
    SinglyLinkedList(){
        head = nullptr;
        count = 0;
    }

    /**
     * @brief add item to the end of the list
     * @param item the item to add
    */
    void append(Any item){
        Node<Any>* new_node = new Node<Any>(item);
        if(is_empty()){
            head = new_node;
        }else{
            Node<Any>* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new_node;
        }
        count++;
    }

    /**
     * @brief add item to the start of the list
     * @param item the item to add 
    */
    void prepend(Any item){
        Node<Any>* new_node = new Node<Any>(item);
        if(is_empty()){
            head = new_node;
        }else{
            new_node->next = head;
            head = new_node;
        }
        count++;
    }

    /**
     * @brief insert item at a given index 
     * @param item to add the list
     * @param pos index to insert at
     */ 
    void insert(Any item,int pos){
        if(pos <= 0){
            prepend(item);
        }else if(pos > 0 && pos < this->count){
            int count = 0;
            Node<Any>* new_node = new Node(item);
            Node<Any>* temp = head;
            while(count < pos-1){
                temp = temp->next;
                count++;
            }
            new_node->next = temp->next;
            temp->next = new_node;

        }else{
            cout<<"IndexError : Index out of range\n";
        }
    }

    /**
     * @brief remove element from the end
    */
    void pop(){
        if(!is_empty()){
            Node<Any>* temp = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            delete(temp->next);
            temp->next = nullptr;
            count--;
        }
    }

    /**
     * @brief remove element from the start
    */
    void remove_start(){
        if(!is_empty()){
            Node<Any>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * @brief remove item form the list at a given position
     * @param pos the position to remove the element in pos = index
    */
    void remove(int pos){
        if(!is_empty()){
            if(pos == 0){
                remove_start();
            }else{
                int count = 0;
                Node<Any>* temp = head;
                while(count < pos-1){
                    temp = temp->next;
                    count++;
                }
                Node<Any>* remove_elmenet = temp->next;
                temp->next = remove_elmenet->next;
                delete remove_elmenet;
                this->count--;
            }
        }
    }

    /**
     * @brief clear all list items
    */
    void clear(){
        if(!is_empty()){
            while(head != nullptr){
                Node<Any>* temp = head;
                head = head->next;
                delete temp;
                count = 0;
            }
        }
    }

    /**
     * @brief Seach for an item in the list 
     * @param item the item to search for in the list
     * @return True if the element founded False otherwise
     * @details 
     * we used in search normal while loop to traverse all items
     * and if it found the given item break the loop and return True
     * if not found the item continue the loop and return False
    */
    bool search(Any item){
        if(!is_empty()){
            Node<Any>* temp = head;
            while(temp != nullptr){
                if(item == temp->item){
                    return true; 
                    break;
                }
                temp = temp->next;
            }
        }
        return false;
    }

    /**
     * @brief used to sord list items in desending order
     * @details the funcion uses two pointers one to point
     * head and the other to point the next of head and then
     * make a condition if temp2->item < temp->item if true
     * swap the temp2->item with temp->item
    */
    void sort(){
        if(!is_empty()){
            Node<Any>* temp = head;
            while(temp != nullptr){
                Node<Any>* temp2 = temp->next;
                while(temp2 != nullptr){
                    if(temp2->item < temp->item){
                        Any temp_item = temp->item;
                        temp->item = temp2->item;
                        temp2->item = temp_item;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }
    }

    /**
     * @brief Reverses the elements in the singly linked list.
     * 
     * @details This function reverses the order of the elements in the singly linked list.
     * It iterates through the list and changes the next pointers of each node to reverse the order.
     * The head pointer is updated to point to the new first node after the reversal.
     */
    void reverse(){
        if(!is_empty()){
            Node<Any>* temp = head;
            Node<Any>* next = nullptr;
            Node<Any>* prev = nullptr;
            while(temp != nullptr){
                next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }
            head = prev;
        }
    }

    /**
     * @brief get number of list items
     * @return number of items in the list
    */
    int length(){
        return count;
    }
    
    /**
     * @return true if list is empty otherwise false
    */
    bool is_empty(){
        return this->head == nullptr;
    }
    
    /**
     * @brief display items of the list
    */
    void display(){
        if(!is_empty()){
            Node<Any>* temp = head;
            cout<<"[";
            while(temp->next != nullptr){
                cout<<temp->item<<", ";
                temp = temp->next;
            }
            cout<<temp->item<<"]"<<endl;
        }else{
            cout<<"[]\n";
        }
    }

    // desturctor to free the nodes when program terminate
    ~SinglyLinkedList(){
        clear();   
    }
};