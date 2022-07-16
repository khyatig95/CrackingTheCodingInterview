//Assumption :  Linked list is made of integers
//Algorithm  :  isDup : Iterates through the list for each element to check for duplicate
//              Time Complexity : O(N^2) ; Space Complexity : O(1)
//              isDupHash : Stores element from list to hash one at a time. If element
//              already exists, delete that element from list
//              Time Complexity : O(N)  ; Space Complexity : O(N)

#include <iostream> 
#include <unordered_set>
#include "LinkedList.h"

using namespace std; 

template <typename T> 
class myClass : public LinkedList<T> {
    public :
        bool isDup();
        bool isDupHash();
    private : 
        bool has_duplicate;
};

template <typename T> 
bool myClass<T> :: isDup() {
    Node<T>* itr1 = this->head;
    Node<T>* itr2;
    Node<T>* ptr;
    has_duplicate = false;
    bool skip = false;
    if (this->head == NULL) {
        cout << "Empty Linked List" << endl;
        return has_duplicate;
    }
    //itr1 iterates through head to tail-1
    //itr2 iterates through itr1+1 to tail
    //We delete itr1 if found. Since it doesn't go to tail,
    //We can use deleteNode from 2_3 as it is O(1) only.
    while (itr1 != NULL) {
        itr2 = itr1->next;
        while(itr2 != NULL) {
            cout << "Comparing " << itr1->data << " at " << itr1 << " with " << itr2->data << " at " << itr2 << endl;
            if (itr1->data == itr2->data) { //Duplicates
                has_duplicate = true;
                cout << "Found duplicate and deleting node " << itr1 << endl;
                ptr = itr1;
                itr1 = itr1->next;
                this->deleteNode(ptr);
                skip = true; //By deleting the node at itr1, we are already at itr1->next
                break;
            } else
                skip = false;
            itr2 = itr2->next;
        }
        if (skip == false)
            itr1 = itr1->next;
    }
    return has_duplicate;
}

template <typename T> 
bool myClass<T> :: isDupHash() {
    Node<T>* n = this->head;
    Node<T>* temp;
    unordered_set<int> uset;
    has_duplicate = false;
    if (this->head == NULL) {
        cout << "Empty Linked List" << endl;
        return has_duplicate;
    }
    cout << "Added " << this->head->data << " to the uset" << endl;
    uset.insert(this->head->data); //The first element will be the first one
    while(n->next != NULL) {
        cout << "Process data " << n->next->data << " at node " << n->next << endl;
        if (uset.find(n->next->data) != uset.end()) { //Duplicate
            has_duplicate = true;
            temp = n->next;
            n->next = n->next->next;
            cout << "Delete Node " << temp << " with val " << temp->data << endl;
            this->deleteNode(temp);
        } else {
            uset.insert(n->next->data);
            cout << "Added " << n->next->data << " to the uset" << endl;
            n = n->next;
        }
    }
    return has_duplicate;
}


int main() {
    myClass<int> lis;
    lis.insertNode(70);
    lis.insertNode(60);
    lis.insertNode(100);
    lis.insertNode(23);
    lis.insertNode(60);
    lis.insertNode(70); 
    lis.insertNode(70);
    lis.printLinkedList();
    if (lis.isDupHash()) 
        cout << "Linked List has duplicates" << endl;
    else 
        cout << "Linked List has NO duplicates" << endl;
    lis.printLinkedList();
    return 0;
}
