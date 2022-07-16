//Algorithm  :  haveLoop : If fast intersects slow where fast is 2x faster than slow
//              findLoop : The place where slow==fast, move one pointer at head and
//              then move both till they intersect again. That is the loop. 
//              (The place where they intersect is "K" nodes away from the starting of the loop
//              where K is the no. of nodes before the loop)
//              Time Complexity : O(N) where N is length of longer list; 
//              Space Complexity : O(1)

using namespace std;
#include <iostream>
#include "LinkedList.h"

template <typename T>
class myClass {
    public :
            bool hasLoop(LinkedList<T> lis);
            Node<T>* loop = NULL;
};

template <typename T>
bool myClass<T> :: hasLoop(LinkedList<T> lis) {
    Node<T>* fast = lis.head;
    Node<T>* slow = lis.head;
    bool skip = true;

    while (fast->next != NULL) { //Compare nodes, not data!!!
        cout << "Fast is " << fast->data << " and slow is " << slow->data << endl;
        if (!skip)
            slow = slow->next;
        skip = !skip;
        fast = fast->next;
        if (fast == slow) 
            break;
    }
    if (fast->next == NULL) {
        cout << "List has an end" << endl;
        return false;
    } 
    fast = lis.head;
    slow = slow->next;
    while (fast != slow) {
        cout << "Fast is " << fast->data << " and slow is " << slow->data << endl;
        fast = fast->next;
        slow = slow->next;
    }
    loop = fast;
    return true;
}

int main() {
    
    LinkedList<int> lis1; 
    myClass<int> obj;
    lis1.insertNode(1);
    lis1.insertNode(2);
    lis1.insertNode(7);
    lis1.insertNode(9);  
    lis1.insertNode(5);  
    lis1.insertNode(34);
    lis1.insertNode(3); 
    if (lis1.head->next->next->next->next->next->next->next == NULL) 
        lis1.head->next->next->next->next->next->next->next = lis1.head->next->next;
    
    //cout << "List1:" << endl;
    //lis1.printLinkedList();
    
    if (obj.hasLoop(lis1)) {
        cout << "List has Loop" << endl;
        cout << "Intersection at " << obj.loop->data << endl;
    } else 
        cout << "List does NOT have Loop" << endl;
    return 0;
}
