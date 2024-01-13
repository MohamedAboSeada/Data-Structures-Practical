#include <iostream>
#include "dll.hpp"
using namespace std;

int main(){
    doubly_linked_list<int> dll;
    dll.insert_start(1);
    dll.insert_start(2);
    dll.insert_start(3);
    dll.insert_start(4);
    dll.insert_start(5);
    dll.display(); // 5 4 3 2 1
    
    dll.insert_end(1);
    dll.insert_end(2);
    dll.insert_end(3);
    dll.insert_end(4);
    dll.insert_end(5);
    dll.display(); // 5 4 3 2 1 1 2 3 4 5

    dll.insert_before(3,2);
    dll.display(); // 5 4 2 3 2 1 1 2 3 4 5

    dll.insert_after(3,6);
    dll.display(); // 5 4 2 3 6 2 1 1 2 3 4 5
  
    dll.display(true); // 5 4 3 2 1 1 2 6 3 2 4 5

    cout<<"List number of items is "<<dll.Length()<<endl; // 12
    dll.is_empty() ? cout<<"Empty : Yes\n" : cout<<"Empty : No\n"; // Yes

    dll.sort();
    dll.display();

    (dll.search(1)) ? cout<<"found\n" : cout<<"not found\n";
    (dll.search(10)) ? cout<<"found\n" : cout<<"not found\n";

    dll.delete_start();
    dll.delete_start(); // 2 2 2 3 3 4 4 5 5 6 
    dll.display();
    
    dll.delete_end();
    dll.delete_end(); // 2 2 2 3 3 4 4 5
    dll.display();

    dll.delete_after(4);
    dll.delete_after(3); // 2 2 2 3 4 5
    dll.display();

    dll.delete_before(2);
    dll.delete_before(1); // 2 3 4 5 5 6
    dll.display();
    // there aren't no nodes
    // number isn't found
    cout<<"Hello World\n";
    return 0;
}