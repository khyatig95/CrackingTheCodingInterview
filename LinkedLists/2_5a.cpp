//Algorithm  :  doSum : Add elements with corresponding positions in both
//              lists and keep inserting at tail for result list 
//              Head has 1's place, head->next has 10's place ...
//              Time Complexity : O(N) where N is the longer list length; Space Complexity : O(1)
using namespace std;
#include <iostream>
#include "LinkedList.h"

class myClass {
    public :
            void doSum(Node<int>* n1, Node<int>* n2, int carry);
            LinkedList<int> Res;
            Node<int>* lastNode = NULL;
};

void myClass :: doSum(Node<int>* n1, Node<int>* n2, int carry) {
    Node<int>* n  = new Node<int>();  //We cant use insert function as that adds to head.
    Node<int>* ptr1;
    Node<int>* ptr2;
    int currVal = 0;
    int carryNext;
  
    if (n1 == NULL && n2 == NULL) {
	cout << "ERROR : Both input sum lists are empty!!" << endl;
	return;
    }
    cout << "Adding ";
    if (n1 != NULL) {
        cout << n1->data << " to ";
        currVal += n1->data;
    }
    if (n2 != NULL) {
        cout << n2->data << " and ";
        currVal += n2->data;
    }
    cout << carry << endl;
    currVal += carry;
    
    n->data = currVal%10;
    n->next = NULL;
    carryNext = (currVal >= 10) ? 1 : 0;

    //Insert at tail
    if (lastNode == NULL) { //first element
        lastNode = n;
        Res.head = n;
    } else {
        lastNode->next = n;
        lastNode = n;
    }
    cout << "lastNode data is " << lastNode->data << endl;
    
    if (n1 == NULL) 
        ptr1 = NULL;
    else
        ptr1 = n1->next;
        
    if (n2 == NULL)
        ptr2 = NULL;
    else
        ptr2 = n2->next;
        
    if ((ptr1 != NULL) && (ptr2 != NULL)) {
        cout << "CASE1" << endl; 
        doSum(n1->next, n2->next, carryNext);
    } else if (ptr1 != NULL) {
        cout << "CASE2" << endl; 
        doSum(n1->next, NULL, carryNext);
    } else if (ptr2 != NULL) {
        cout << "CASE3" << endl; 
        doSum(NULL, n2->next, carryNext);
    } else {
        cout << "CASE4" << endl; 
        if (carryNext == 1) {
            cout << "Inserting carry as the last element" << endl;
            Node<int>* n_new = new Node<int>();
            n_new->data = carryNext;
            n_new->next = NULL;
            lastNode->next = n_new;
            lastNode = n_new;
        }
        return;
    }
}

int main() {
    LinkedList<int> lis1;
    LinkedList<int> lis2;
    myClass obj;
    lis1.insertNode(6);
    lis1.insertNode(1);
    lis1.insertNode(7);
    lis2.insertNode(9); 
    lis2.insertNode(9);  
    lis2.insertNode(5);
    lis2.insertNode(3); 
    cout << "Original List1:" << endl;
    lis1.printLinkedList();
    cout << "Original List2:" << endl;
    lis2.printLinkedList();
    obj.doSum(lis1.head, lis2.head, 0);
    cout << "Sum List:" << endl;
    obj.Res.printLinkedList();
    return 0;
}
