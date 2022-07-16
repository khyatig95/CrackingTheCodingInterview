//Algorithm  :  doSumReverse : Pad zeroes if length not equal. Add partSum and recur return the carry.
//              Add elements at head for the result list
//              Tail has 1's place, tail->prev has 10's place ...
//              Time Complexity : O(N) where N is the longer list length; Space Complexity : O(1)
using namespace std;
#include <iostream>
#include "LinkedList.h"

class myClass {
    public :
            void padZeroes();
            int doSumReverse(Node<int>* n1, Node<int>* n2);
            LinkedList<int> lis1, lis2, Res;
};

void myClass :: padZeroes() {
    Node<int>* n1 = lis1.head;
    Node<int>* n2 = lis2.head;
    if (n1 == NULL && n2 == NULL) {
        cout << "ERROR : Both input sum lists are empty!!" << endl;
	    return;
    }
    while ((n1->next != NULL) || (n2->next != NULL)) {
        if (n1->next == NULL) { 
            lis1.insertNode(0); //We have to pad at head/MSB
            n2 = n2->next;
        } else if (n2->next == NULL) {
            lis2.insertNode(0); //We have to pad at head/MSB
            n1 = n1->next;
        } else {
            n1 = n1->next;
            n2 = n2->next;
        }
    }

}

int myClass :: doSumReverse(Node<int>* n1, Node<int>* n2) {
    int currVal = 0;
    int carry = 0;
    int carryNext = 0;
    int nodeVal = 0;
    Node<int>* ptr1;
    Node<int>* ptr2;

    if (n1==NULL && n2==NULL) { //It will either be both NULL or no null as we are padding zeroes
	    return 0;
    } 
    
    if (n1->next != NULL && n2->next != NULL) {
        carry = doSumReverse(n1->next, n2->next);
    } 
    cout << "Adding " << n1->data << " to " << n2->data << " and " << carry << endl;
    currVal += n1->data;
    currVal += n2->data;
    currVal += carry;
    nodeVal = currVal%10;
    carryNext = (currVal >= 10) ? 1 : 0;
    Res.insertNode(nodeVal); //Insert at head
    cout << "Node data is " << nodeVal << endl;

    return carryNext;
}

int main() {
    
    myClass obj; //Adding lists to class itself as we are gonna modify them with pad
    obj.lis2.insertNode(6);
    obj.lis2.insertNode(8);
    obj.lis2.insertNode(7);
    obj.lis1.insertNode(3); 
    obj.lis1.insertNode(9);  
    obj.lis1.insertNode(5);
    obj.lis1.insertNode(9); 
    cout << "Original List1:" << endl;
    obj.lis1.printLinkedList();
    cout << "Original List2:" << endl;
    obj.lis2.printLinkedList();
    
    obj.padZeroes();

    cout << "Padded List1:" << endl;
    obj.lis1.printLinkedList();
    cout << "Padded List2:" << endl;
    obj.lis2.printLinkedList();
    
    if (obj.doSumReverse(obj.lis1.head, obj.lis2.head) == 1) //If there is a carry from MSB, add an extra digit
        obj.Res.insertNode(1); 
    cout << "Sum List:" << endl;
    obj.Res.printLinkedList();
    return 0;
}
