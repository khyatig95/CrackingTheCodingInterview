//Algorithm  :  haveIntersection : If tail nodes (NOT DATA) are same => they intersect
//              findIntersection : If the two lists intersect, chop head of longer list 
//              till it matches length of shorter list and then find where nodes are same.
//              Time Complexity : O(N) where N is length of longer list; 
//              Space Complexity : O(1)

using namespace std;
#include <iostream>
#include "LinkedList.h"

template <typename T>
class myClass {
    public :
            bool haveIntersection(LinkedList<T> lis1, LinkedList<T> lis2);
            Node<T>* findIntersection(LinkedList<T> lis1, LinkedList<T> lis2);
            int findLength(LinkedList<T> lis);
};

template <typename T>
bool myClass<T> :: haveIntersection(LinkedList<T> lis1, LinkedList<T> lis2) {
    Node<T>* n1 = lis1.head;
    Node<T>* n2 = lis2.head;

    if (lis1.head == NULL || lis2.head == NULL) {
        cout << "ERROR: One or more input lists are empty" << endl;
        return false;
    }
    while ((n1->next != NULL) || (n2->next != NULL)) {
        if (n1->next != NULL)
            n1 = n1->next;
        if (n2->next != NULL)
            n2 = n2->next;
    }
    if (n1 == n2)
        return true;
    else 
        return false;
}

template <typename T>            
Node<T>* myClass<T> :: findIntersection(LinkedList<T> lis1, LinkedList<T> lis2) {
    int len1 = findLength(lis1);
    int len2 = findLength(lis2);
    
    while (len1 != len2) {
        if (len1 > len2) {
            lis1.deleteNode(lis1.head);
            len1--;
        } else {
            lis2.deleteNode(lis2.head);
            len2--;
        }
    }
    
    Node<T>* n1 = lis1.head;
    Node<T>* n2 = lis2.head;
    if (n1 == n2) {
        cout << "Found intersection at " << n1->data << endl;
        return n1;
    }
    while (n1->next != NULL) {
        if (n1->next == n2->next){ 
            cout << "Found intersection at " << n1->next->data << endl;
            return n1->next;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return NULL;
}

template <typename T>
int myClass<T> :: findLength(LinkedList<T> lis) {
    Node<T>* n = lis.head;
    int length = 0;
    while (n->next != NULL) {
        length++;
        n = n->next;
    }
    length++; //For head
    return(length);
}

int main() {
    
    LinkedList<int> lis1, lis2, lis3; 
    myClass<int> obj;
    lis3.insertNode(1);
    lis3.insertNode(2);
    lis3.insertNode(7);
    lis1 = lis3;
    lis2 = lis3;
    lis1.insertNode(9);  
    lis1.insertNode(5);  
    lis1.insertNode(1);
    lis1.insertNode(3); 
    lis2.insertNode(6);
    lis2.insertNode(4);
    cout << "List1:" << endl;
    lis1.printLinkedList();
    cout << "List2:" << endl;
    lis2.printLinkedList();    
    
    if (obj.haveIntersection(lis1, lis2)) {
        cout << "Both Lists have Intersection" << endl;
        cout << "Intersection at " << obj.findIntersection(lis1, lis2)->data << endl;
    } else 
        cout << "Both Lists do NOT have Intersection" << endl;
    return 0;
}
