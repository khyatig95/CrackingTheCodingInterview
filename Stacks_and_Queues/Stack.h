using namespace std;
#include <iostream>
#include "DoublyLinkedList.h"

//LIFO - Insert and Delete at Tail
template <typename T>
class Stack : protected DoublyLinkedList<T> {
    public :
        void pop();
        void push(T val);
        Node<T>* peek();
        bool isEmpty();
        void printStack();
};

template <typename T>
void Stack<T> :: pop() {
    if (this->tail == NULL) {
	cout << "ERROR : Cannot pop from empty stack!" << endl;
        return;
    }
    //cout << "Delete node " << this->tail->data << endl;
    this->deleteNode(this->tail);
}

template <typename T>
void Stack<T> :: push(T val) {
    //cout << "Insert node " << val << " at tail " << endl;
    this->insertNodeTail(val);
}

template <typename T>
Node<T>* Stack<T> :: peek() {
    //cout << "Top of the stack is " << this->tail->data << endl;
    return(this->tail);
}

template <typename T>
bool Stack<T> :: isEmpty() {
    if (this->head != NULL && this->tail != NULL)
        return false;
    return true;
}

template <typename T>
void Stack<T> :: printStack() {
    Node<T>* n = this->tail;
    if (this->tail == NULL)
        return;
    while (n != this->head) {
        cout << n->data << endl << "^" << endl << "|" << endl;
        n = n->prev;
    }
    cout << n->data << endl; //head
    cout << endl;
}