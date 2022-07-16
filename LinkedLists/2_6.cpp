//Algorithm  :  isPalindrome : Reverse the list and compare with original (only upto half)
//              Time Complexity : O(N); Space Complexity : O(N)
//              isPalindromeIter : Fast Runner moves 2x as fast as slow runner. When fast
//              runner reaches tail => slow runner is at mid. Push from mid to tail at stack.
//              Time Complexity : O(N); Space Complexity : O(N)
//              isPalindromeRecur : Length of linkedlist is known.
//              Recursive approach to return mid node and push to stack.
//              Time Complexity : O(N); Space Complexity : O(N)

using namespace std;
#include <iostream>
#include <stack>
#include "LinkedList.h"

class myClass {
    public :
            bool isPalindrome(LinkedList<char> lis);
            bool isPalindromeIter(LinkedList<char> lis);
            bool isPalindromeRecur(LinkedList<char> lis, int length);
            Node<char>* findMidNode(LinkedList<char> lis, int length);
            int findLength(LinkedList<char> lis);
};

int myClass :: findLength(LinkedList<char> lis) {
    Node<char>* n = lis.head;
    int length = 0;
    while (n->next != NULL) {
        length++;
        n = n->next;
    }
    length++; //For head
    return(length);
}

bool myClass :: isPalindrome(LinkedList<char> lis) {
    LinkedList<char> RevLis;
    Node<char>* n = lis.head;
    Node<char>* nLast;
    Node<char>* nRev;

    if (lis.head == NULL) {
        cout << "ERROR: Empty list" << endl;
        return false;
    }
    
    //Process Head
    RevLis.insertNode(lis.head->data); //Head==Tail for first element
    nLast = RevLis.head;

    //Inserting at Head for RevLis so that last element is at head
    while (n->next != NULL) {
        RevLis.insertNode(n->next->data);
        n = n->next;
    }
    RevLis.printLinkedList();
    
    n = lis.head;
    nRev = RevLis.head;
    //Compare lis with RevLis
    if (n->data != nRev->data) {
        cout << "Head = " << n->data << " does not match tail " << nRev->data << endl;
        return false;
    }

    while (n->next != NULL) { //Both lists are same length
        if (n->next->data != nRev->next->data) {
            cout << "Head = " << n->next->data << " does not match tail " << nRev->next->data << endl;
            return false;
        }
        n = n->next;
        nRev = nRev->next;
    }
    return true;
}

bool myClass :: isPalindromeIter(LinkedList<char> lis) {
    Node<char>* fast = lis.head;
    Node<char>* slow = lis.head;
    bool skip = true;
    stack<char> stk;
    
    if (lis.head == NULL) {
        cout << "ERROR: Empty list" << endl;
        return false;
    }  
    
    while (fast->next != NULL) {
        if (!skip)  
            slow = slow->next;
        skip = !skip;
        fast = fast->next;
    }
    cout << "Slow reached mid = " << slow->data << endl;
    
    //Push slow->next to tail in stack
    while (slow->next != NULL) {
        cout << "Pushing " << slow->next->data << " onto stack" << endl;
        stk.push(slow->next->data);
        slow = slow->next;
    }
    
    fast = lis.head;
    
    while (!stk.empty()) {
        char itr = stk.top();
        cout << "Popping " << itr << " from stack" << endl;
        if (fast->data != itr) {
            cout << "Head = " << fast->data << " does not match stack " << itr << endl;
            return false;
        }
        stk.pop();
        fast = fast->next;
    }
    return true;
}

bool myClass :: isPalindromeRecur(LinkedList<char> lis, int length) {
    LinkedList<char> temp = lis;
    stack<char> stk;
    if (lis.head == NULL) {
        cout << "ERROR: Empty list" << endl;
        return false;
    }
    
    Node<char>* mid = findMidNode(temp, length);
    while (mid->next != NULL) {
        cout << "Pushing " << mid->next->data << " onto stack" << endl;
        stk.push(mid->next->data);
        mid = mid->next;
    }
    
    Node<char>* n = lis.head;
    while (!stk.empty()) {
        char itr = stk.top();
        cout << "Popping " << itr << " from stack" << endl;
        if (n->data != itr) {
            cout << "Head = " << n->data << " does not match stack " << itr << endl;
            return false;
        }
        stk.pop();
        n = n->next;
    }
}

Node<char>* myClass :: findMidNode(LinkedList<char> lis, int length) {
    if ((length-2) == 0 || length == 1) {
        cout << "Found mid node : " << lis.head->data << endl;
        return lis.head;
    }

    lis.head = lis.head->next;
    Node<char>* n = findMidNode(lis, length-2);
    return n;
}

int main() {
    
    LinkedList<char> lis; //Odd length, even length
    myClass obj;
    lis.insertNode('a');
    lis.insertNode('b');
    lis.insertNode('c');
    lis.insertNode('f');  
    lis.insertNode('b');
    lis.insertNode('a'); 
    cout << "Original List" << endl;
    lis.printLinkedList();
    
    if (obj.isPalindromeRecur(lis, obj.findLength(lis))) 
        cout << "List is a Palindrome" << endl;
    else 
        cout << "List is NOT a Palindrome" << endl;
    return 0;
}
