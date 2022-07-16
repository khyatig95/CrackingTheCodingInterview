#include <iostream> 
using namespace std; 

template <typename T> 
class Node {
    public :
        Node* next;
        T data;
        Node() {  //You can even paramterize the constructor to pass the val here directly
            next = NULL;
        }
};

template <typename T> 
class LinkedList {
    public :
        void insertNode(T val); //Add to the head. Create Memory. O(1)
        void deleteNodewithVal(T val); //Delete all element with data==val. Delete assigned Memory. O(N)
        void deleteNode(Node<T>* node); //Delete the Node passed and its assigned memory. O(N). For O(1), refer to 2_3
        void printLinkedList();
        Node<T>* head;
        LinkedList() {
            head = NULL; 
        }
};

template <typename T> 
void LinkedList<T> :: insertNode(T val) {
    Node<T>* n = new Node<T>(); //Assign Memory
    n->data = val;
    n->next = head;  
    head = n;
    //cout << "Inserted val " << val << " at head " << head << endl;
}

template <typename T> 
void LinkedList<T> :: deleteNodewithVal(T val) {
    Node<T>* n = head;
    Node<T>* ptr;
    if (head == NULL)
        return;
    while(n->next != NULL) { //Process starting from head->next
        if (n->next->data == val) {
            cout << "Delete element " << n->next->data << " " ;
            ptr = n->next;
            n->next = n->next->next;
            cout << endl;
            delete ptr;
            continue;
        }
        n = n->next;
    }
    //Process head
    if (head->data == val) {
        ptr = head;
        cout << "The element at head will be deleted " << head->data << endl;
        head = head->next;
        delete ptr;
    }
}

template <typename T> 
void LinkedList<T> :: deleteNode(Node<T>* node) {
    Node<T>* n = head;
    Node<T>* ptr;
    cout << "Node " << node << " with val " << node->data << " will be deleted" << endl;
    if (head == NULL || node == NULL)
        return;
        
   //Process head
    if (head == node) {
        ptr = head;
        cout << "The element at head will be deleted " << head->data << endl;
        if (node->next != NULL) 
            node = node->next;
        else
            node = NULL;
        head = node;
        delete ptr;
    }
    while(n->next != NULL) { //Process starting from head->next
        if (n->next == node) {
            cout << "Delete element " << n->next->data << " " ;
            ptr = n->next;
            n->next = n->next->next;
            cout << endl;
            delete ptr;
            break;
        }
        n = n->next;
    }
}

template <typename T> 
void LinkedList<T> :: printLinkedList() {
    Node<T>* n = head;
    if (head == NULL)
        return;
    //Process head
    cout << n->data;
    while (n->next != NULL) { //Starting from head->next
        cout << "->" << n->next->data;
        n = n->next;
    }
    cout << endl;
}
