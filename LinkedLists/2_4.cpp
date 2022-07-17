//Assumption :  Linked list is made of integers
//Algorithm  :  doPartition : Assigns node less than a partition value
//              on the left and the others on the right. 
//              Time Complexity : O(N) ; Space Complexity : O(1)
using namespace std;
#include <iostream>
#include "LinkedList.h"

template <typename T>
class myClass : public LinkedList<T> {
    public :
            void doPartition(T partition);
};

template <typename T>
void myClass<T> :: doPartition(T partition) {
    Node<T>* n = this->head;
    Node<T>* temp;
    bool skip = false;
    int tempdata;
    while(n->next != NULL) {
        if (n->next->data < partition) {
            temp = n->next;
            tempdata = temp->data;
            n->next = n->next->next;
            skip = true;
            delete temp;  //Delete the node
            this->insertNode(tempdata); //Insert at head (leftmost)
        } else
            skip = false;
        if (skip == false)
            n = n->next;
    }
}

int main() {
    myClass<int> lis;
    lis.insertNode(1);
    lis.insertNode(2);
    lis.insertNode(10);
    lis.insertNode(5);
    lis.insertNode(8);  
    lis.insertNode(5);
    lis.insertNode(3); //This will be new head
    cout << "Original List:" << endl;
    lis.printLinkedList();
    lis.doPartition(5);
    cout << "Partitioned List:" << endl;
    lis.printLinkedList();
    return 0;
}
