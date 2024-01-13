/**
 * @details We use doubly linked list as it has some advantages over singly linked list : 
 * Advantages : 
 * 1 . we can add in 4 places (Start,after and before any node,end)
 * so it make the insertion and deletion more effecient
 * 2 . we can traverse the list from 2 direction from start and end
 * so this make it easier to reverse the list
 * 
 * disadvantages : 
 * 1. it need more space for the additional pointer that points to prevoius node
 * 
 * Which to choose use this condition: 
 * if(the porblem depend on inserstion and deletion)
 *     if(has no memory limition)
 *        use doubly linked list
 *     else:
 *        use singly linked list
 * 
 * @attention doubly linked list take one more attribute called previous
 * that points to the previous node
 * 
 * if list not empty the next always points to null and the prev of head points to null
 * NULL-[prev,value,next]-[prev,value,next]-[prev,value,next]-NULL
*/

#include <iostream>
#define ll long long 
using namespace std;
template <class Any>
class Node{
public:
    Node<Any>* Prev;
    Node<Any>* Next;
    Any Data;
    Node(Any Data){
        this->Data = Data;
        Prev = nullptr;
        Next = nullptr;
    }

    void set_next(Node<Any>* next){
        Next = next;
    }

    void set_prev(Node<Any>* prev){
        Prev = prev;
    }

    Node<Any>* get_prev(){
        return Prev;
    }

    Node<Any>* get_next(){
        return Next;
    }
};

template <class Any>
class doubly_linked_list{
    Node<Any>* head;
    Node<Any>* tail;
    ll length;
public:
    doubly_linked_list(){
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    // insert element to the start of the list
    void insert_start(Any item){
        Node<Any>* new_node = new Node<Any>(item);
        if(!is_empty()){
            new_node->set_next(head);
            head->set_prev(new_node);
            head = new_node;
        }else{
            head = tail = new_node;
        }
        length++;
    }
    // insert element to the end of the list
    void insert_end(Any item){
        Node<Any>* new_node = new Node<Any>(item);
        if(!is_empty()){
            new_node->set_prev(tail);
            tail->set_next(new_node);
            tail = new_node;
        }else{
            head = tail = new_node;
        }
        length++;
    }

    /**
     * @brief insert element after element in the list
     * @param before_node_value the value to insert item after it
     * @param item the item to insert
    */
    void insert_after(Any before_node_data,Any item){
        if(!is_empty()){
            if(search(before_node_data)){
                if(before_node_data == tail->Data){
                    insert_end(item);
                }else{
                    Node<Any>* new_node = new Node(item);
                    Node<Any>* temp = head;
                    while(temp->Data != before_node_data){
                        temp = temp->get_next();
                    }
                    new_node->set_prev(temp);
                    new_node->set_next(temp->Next);
                    temp->get_next()->set_prev(new_node);
                    temp->set_next(new_node);
                    length++;
                }
            }else{
                cout<<"element "<<before_node_data<<" not found\n";
            }
        }else{
            cout<<"List is empty\n";
        }
    }

    /**
     * @brief insert element before element in the list
     * @param after_node_value the value to insert item after it
     * @param item the item to insert
    */
    void insert_before(Any After_Node_data,Any item){
        if(!is_empty()){
            if(search(After_Node_data)){
                if(After_Node_data == head->Data){
                    insert_start(After_Node_data);
                }else{
                    Node<Any>* new_node = new Node(item);
                    Node<Any>* temp = head;
                    while(temp->Data != After_Node_data){
                        temp = temp->get_next();
                    }
                    new_node->set_next(temp);
                    new_node->set_prev(temp->get_prev());
                    temp->get_prev()->set_next(new_node);
                    temp->set_prev(new_node);
                    length++;
                }
            }else{
                cout<<"element "<<After_Node_data<<" not found !\n";
            }
        }else{
            cout<<"List is empty !\n";
        }
    }

    // delete element from the start of the list
    void delete_start(){
        if(!is_empty()){
            Node<Any>* temp = head;
            if(head->get_next() == nullptr){
                head = head->get_next();
                delete temp;
            }else{
                head = head->get_next();
                head->set_prev(nullptr);
                delete temp;
            }
            length--;
        }
    }
    // delete element from the end of the list
    void delete_end(){
        if(!is_empty()){
            if(head->get_next() == nullptr){
                delete_start();
            }else{
                Node<Any>* temp = tail;
                tail = tail->get_prev();
                tail->set_next(nullptr);
                delete temp;
                length--;
            }
        }
    }
    /**
     * @brief delete element after element in the list
     * @param before_node_data value of the node to delete the node after it 
    */
    void delete_after(Any before_node_data){
        if(!(is_empty())){
            if(search(before_node_data)){
                Node<Any>* crr = head;
                while(crr->Data != before_node_data){
                    crr = crr->get_next();
                }
                if(crr->Next != nullptr){
                    if(crr->get_next()->get_next() != nullptr){
                        Node<Any>* temp = crr->get_next();
                        crr->set_next(temp->get_next());
                        temp->get_next()->set_prev(crr);
                        delete temp;
                        length--;
                    }else{
                        delete_end();
                    }
                }else{
                    cout<<"There aren't nodes after this node !\n";
                }
            }else{
                cout<<"element "<<before_node_data<<" not found !\n";
            }
        }else{
            cout<<"list is empty!\n";
        }
    }
    // TODO : delete element before element in the list
    void delete_before();

    // sort the list
    void sort() {
        if (!is_empty()) {
            Node<Any>* current = head;
            while (current != nullptr) {
                Node<Any>* minNode = current;
                Node<Any>* temp = current->get_next();
                while (temp != nullptr) {
                    if (temp->Data < minNode->Data) {
                        minNode = temp;
                    }
                    temp = temp->get_next();
                }
                if (minNode != current) {
                    // Swap the data of current and minNode
                    Any tempData = current->Data;
                    current->Data = minNode->Data;
                    minNode->Data = tempData;
                }
                current = current->get_next();
            }
        }
    }

    // TODO : reverse the list 
    void reverse();

    // Search in the list
    bool search(Any item){
        if(!is_empty()){
            Node<Any>* temp = head;
            while(temp != nullptr){
                if(item == temp->Data){
                    return true;
                    break;
                }
                temp = temp->get_next();
            }
        }
        return false;
    }

    // Display items
    void display(bool reverse = false){
        if(!is_empty()){
            if(!reverse){
                Node<Any>* temp = head;
                while(temp != nullptr){
                    cout<<temp->Data<<" ";
                    temp = temp->get_next();
                }
                cout<<endl;
            }else{
                Node<Any>* temp = tail;
                while(temp != nullptr){
                    cout<<temp->Data<<" ";
                    temp = temp->get_prev();
                }
                cout<<endl;
            }
        }
    }

    // clear all list items
    void clear(){
        while(head != nullptr){
            Node<Any>* temp = head;
            head = head->get_next();
            delete temp;
        }
        length = 0;
    }
    ll Length(){
        return this->length;
    }
    // checks if list is empty
    bool is_empty(){
        return head == nullptr;
    }
    ~doubly_linked_list(){ 
        clear();       
    }
};
int main(){
    // TODO : Main funcion
    doubly_linked_list<int> dll;
    dll.insert_end(1);
    dll.insert_end(2);
    dll.insert_end(3);
    dll.insert_end(4);
    dll.insert_end(5);
    dll.display();
    return 0;
}