//Assumption :  Linked list is made of integers
//Algorithm  :  deleteNode : Assigns node to next node and deletes memory of
//              original node. Tail can anyway not be deleted. Check if input
//              node == head to avoid deletion of head
//              Time Complexity : O(1) ; Space Complexity : O(1)

#include <iostream> 
#include "LinkedList.h"

template <typename T>
class myClass : public LinkedList<T> {
    public : 
        void deleteNode(Node<T>* node);  //Overriding the base class function
};

template <typename T>
void myClass<T> :: deleteNode(Node<T>* node) {
    Node<T>* ptr;
    if (this->head == NULL || node == NULL)
        return;
    
    ptr = node->next;
    //Process head
    if (this->head == node) {
        cout << "The element at node " << node << " will be deleted " << node->data << endl;
        node->data = ptr->data;
        node->next = ptr->next;
        this->head = node;
        delete ptr;
        return;
    }
    if (node->next != NULL) {
        cout << "The element at node " << node << " will be deleted " << node->data << endl;
        node->data = ptr->data;
        node->next = ptr->next;
        node = ptr;
        delete ptr;
        return;
    } 
    cout << "ERROR cannot delete tail node " << node->data << endl;
}

int main() {
    myClass<int> lis;
    Node<int>* input;
    lis.insertNode(10);
    lis.insertNode(20);
    lis.insertNode(100);
    lis.insertNode(23);
    lis.insertNode(60);
    lis.insertNode(90); 
    lis.insertNode(70);
    cout << "Original: " << endl;
    lis.printLinkedList();

    input = lis.head->next; //Try with head, tail, outside and mid
    if (input == lis.head) 
        cout << "ERROR cannot delete head node " << lis.head->data << endl;
    else 
    	lis.deleteNode(input);
    cout << "Final: " << endl;
    lis.printLinkedList();
}
