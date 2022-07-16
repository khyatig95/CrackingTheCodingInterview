#include <iostream> 
using namespace std; 

template <typename T>
class Node {
    public :
        Node<T>* next;
        Node<T>* prev;
        T data;
        Node() {
            next = NULL;
            prev = NULL;
        }
};

template <typename T>
class DoublyLinkedList {
    public :
        void insertNodeHead(T val); //Add to the head. Create Memory
        void insertNodeTail(T val); //Add to the tail. Create Memory
        void deleteNodewithVal(T val);   //Delete assigned Memory
        void deleteNode(Node<T>* node); //Delete assigned Memory
        void printLinkedList();
        DoublyLinkedList() {
            head = NULL; 
            tail = NULL;
        }
        Node<T>* head;
        Node<T>* tail;
};

template <typename T>
void DoublyLinkedList<T> :: insertNodeHead(T val) {
    Node<T>* n = new Node<T>(); //Assign Memory
    n->data = val;
    n->prev = NULL;
    n->next = head;
    if (head == NULL)
        tail = n;
    else 
        head->prev = n; //Update the prev of  previous head
    head = n; //Update the head
    cout << "Insert data at head "<< head->data << endl;

}

template <typename T>
void DoublyLinkedList<T> :: insertNodeTail(T val) {
    Node<T>* n = new Node<T>(); //Assign Memory
    n->data = val;
    n->next = NULL;
    n->prev = tail;
    if (tail == NULL)
        head = n;
    else 
        tail->next = n; //Update next of the previous tail
    tail = n; //Update the tail
    cout << "Insert data at tail "<< tail->data << endl;
}

template <typename T>
void DoublyLinkedList<T> :: deleteNodewithVal(T val) {
    Node<T>* n = head;
    Node<T>* ptr;
    if (head == NULL)
        return;

    while(n->next->next != NULL) { //Starting from head->next to tail->prev
        cout << "Processing data " << n->next->data << endl;
        if (n->next->data == val) {
            cout << "Delete data " << n->next->data << endl;
            ptr = n->next;
            n->next = n->next->next;
            n->next->prev = n;
            delete ptr;
            continue;
        }
        n = n->next;
    }
    
            //Process head
    if (head->data == val) {
        ptr = head;
        cout << "The element at head will be deleted " << head->data << endl;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            head = NULL;
            tail = NULL;
        }
        delete ptr;
    }
    //Process tail
    if (tail->data == val) {
        ptr = tail;
        cout << "The element at tail will be deleted " << tail->data << endl;
        if (tail->prev != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            head = NULL;
            tail = NULL;
        }
        delete ptr;
    }
}

template <typename T>
void DoublyLinkedList<T> :: deleteNode(Node<T>* node) {
    Node<T>* n = head;
    Node<T>* ptr;
    if (node == NULL || head == NULL || tail == NULL) 
        return;
        
    //Process head
    if (node == head) {
        cout << "Delete head with data " << head->data << endl;
        ptr = head;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            head = NULL;
            tail = NULL;
        }
        delete ptr;
        return;
    }
    //Process tail
    if (node == tail) {
        cout << "Delete tail with data " << tail->data << endl;
        ptr = tail;
        if (tail->prev != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            tail = NULL;
            head = NULL;
         }
        delete ptr;
        return;
    }
    
    while(n->next->next != NULL) {
        if (n->next == node) {
            cout << "Delete node with data " << n->next->data << endl;
            ptr = n->next;
            n->next = n->next->next;
            n->next->prev = n;
            delete ptr;
            return;
        }
        n = n->next;
    }


}

template <typename T>
void DoublyLinkedList<T> :: printLinkedList() {
    Node<T>* n;
    cout << "Linked list is" << endl;
    n = head;
    while (n != tail) {
        cout << n->data << "->";
        n = n->next;
    }
    cout << n->data << endl; //tail
    cout << "Reverse Linked list is " << endl;
    n = tail;
    while (n != head) {
        cout << n->data << "<-";
        n = n->prev;
    }
    cout << n->data << endl; //head
  
}
