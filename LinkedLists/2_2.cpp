//Assumption :  Linked list is made of integers. 0th from last = last, ..
//Algorithm  :  findFromLast : Calculates length and returns (Length-K) from the front
//              Time Complexity : O(N) ; Space Complexity : O(K) due to recursion
//              findFromLastIter : 2 pointers, K apart. When the farther pointer is at 
//              end, the other pointer is at Kth from last element
//              Time Complexity : O(N)  ; Space Complexity : O(1)
//              findFromLastRecur : Recursive function that returns index from last
//              Time Complexity : O(N) ; Space Complexity : O(N)

#include <iostream> 
#include <unordered_set>
#include "LinkedList.h"

using namespace std; 

template <typename T>
class myClass : public LinkedList<T> {
    public :
        T findFromLast(int k);
        T findFromLastIter(int k);
        T findFromLastRecur(int k);
        int returnIndex(Node<T>* n, int k);
        int findLength();
        Node<T>* KfromLast = NULL;
};

template <typename T>
int myClass<T> :: findLength() {
    Node<T>* n = this->head;
    int length = 0;
    while (n->next != NULL) {
        length++;
        n = n->next;
    }
    length++; //For head
    return(length);
}

template <typename T>
T myClass<T> :: findFromLast(int k) {
    Node<T>* n = this->head;
    int front_index, length;
    if (this->head == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }
    length = findLength();
    cout << "Length of linked list is " << length << endl;
    front_index = length - 1 - k;
    if (front_index < 0) {
        cout << "k = " << k << " is greater than length of linked list " << length << endl;
        return -1;
    } else if (front_index == 0) 
        return this->head->data;
    else {
        while(n->next != NULL) {
            front_index--; //Account for head
            cout << "Front index = " << front_index << " for data = " << n->next->data << endl;
            if (front_index == 0)
                break;
            n = n->next;
        }
    }
    return n->next->data;
}

template <typename T>
T myClass<T> :: findFromLastIter(int k) {
    Node<T>* slow = this->head; 
    Node<T>* fast = this->head; 
    int count = k;
    
    if (this->head == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }
    while(fast->next != NULL) {
        cout << "fast is at " << fast->data << " and slow is at " << slow->data << endl;
	   //We dont reset count as after the first separation, both pointer move together.
        if (count == 0)
            slow = slow->next;
        else 
            count --;
        fast = fast->next;
    }
    cout << "fast is at " << fast->data << " and slow is at " << slow->data << endl;

    cout << "slow is at " << slow->data << endl;
    if (count != 0) //Slow has not started moving, => k > length of linkedlist
        return -1;
    return(slow->data);
}

template <typename T>
T myClass<T> :: findFromLastRecur(int k) {
    if (this->head == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }
    
    int index = returnIndex(this->head, k);

    if (KfromLast != NULL)
        return KfromLast->data;
    else 
        return -1;
}

template <typename T>
int myClass<T> :: returnIndex(Node<T>* n, int k) {
    int index = 0;
    if (n->next == NULL) {//last element
        if (index == k) {
            KfromLast = n;
            cout << "Found element " << n->data << endl;
        }
        return index;
    }
      
    index = returnIndex(n->next, k) + 1;
    if (index == k) {
        KfromLast = n;
        cout << "Found element " << n->data << endl;
    }
    return index;
}

int main() {
    int Kth;
    Kth = 3; //some middle element
    //Kth = 6; //first element
    //Kth= 7; //error
    //Kth = 0; //last element
    myClass<int> lis;
    lis.insertNode(10);
    lis.insertNode(20);
    lis.insertNode(100);
    lis.insertNode(23);
    lis.insertNode(60);
    lis.insertNode(90); 
    lis.insertNode(70);
    lis.printLinkedList();
    int result = lis.findFromLast(Kth);

    if (result == -1) 
        cout << "Linked List has an error for k " <<  Kth << endl;
    else 
        cout << "Linked List has " << result << " at " << Kth << " from last" << endl;
    return 0;
}
