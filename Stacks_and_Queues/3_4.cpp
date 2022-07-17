//Algorithm :   Keep pushing values at tail. When there is pop,
//              reverse elements in another stack and then pop 
//              so the pops happen at head. 
//              To prevent reversal at every operation, store 
//              which stack has elements is there are a series
//              of push and pop.
//              Space Complexity : O(N)
//              Push/Pop Time Complexity : O(N)

using namespace std;
#include <iostream>
#include "Stack.h"

template <typename T> 
class myQueue {
    private :
        Stack<T> pushQ, popQ;
        bool isPushQ = true;
        void shiftQ();
    public :
        void push(T val);
        void pop();
        Node<T>* peek();  //Looks at oldest element
        bool isEmpty();
        void printQueue();
};

template <typename T> 
void myQueue<T> :: push(T val) {
    if (!isPushQ)
        shiftQ();
    pushQ.push(val);
}

template <typename T> 
void myQueue<T> :: pop() {
    if (isPushQ)
        shiftQ();
    popQ.pop();
}

template <typename T> 
Node<T>* myQueue<T> :: peek() {
    if (isPushQ)
        shiftQ();
    return(popQ.peek());
}

template <typename T> 
bool myQueue<T> :: isEmpty() {
    if (isPushQ)
        return(pushQ.isEmpty());
    else
        return(popQ.isEmpty());
}

template <typename T>
void myQueue<T> :: shiftQ() {
    if (isPushQ) {
        cout << "Current q = PushQ and shifting to PopQ" << endl;
        while (!pushQ.isEmpty()) {
            popQ.push(pushQ.peek()->data);
            pushQ.pop();
        }
    } else {
        cout << "Current q = PopQ and shifting to PushQ" << endl;
        while (!popQ.isEmpty()) {
            pushQ.push(popQ.peek()->data);
            popQ.pop();
        }
    }
    isPushQ = !isPushQ;
}

template <typename T>
void myQueue<T> :: printQueue() {
    cout << "PushQ is :" << endl;
    pushQ.printStack();
    cout << endl << "PopQ is :" << endl;
    popQ.printStack();
} 

int main() {
    myQueue<int> que;
    que.push(23);
    que.push(45);
    que.push(70);
    que.push(81);
    que.push(92);
    que.printQueue();
    que.pop();
    que.pop();
    que.printQueue();
    cout << "Top of the stack is " << que.peek()->data << endl;
    if (que.isEmpty())
        cout << "Queue is Empty" << endl;
    else 
        cout << "Queue is NOT Empty" << endl;
    que.pop();
    que.pop();
    que.pop();
    if (que.isEmpty())
        cout << "Queue is Empty" << endl;
    else 
        cout << "Queue is NOT Empty" << endl;
    que.pop(); //Pop on empty queue
    
    que.push(3);
    que.push(55);
    que.printQueue();
    que.pop();
    que.printQueue();
    
    return 0;

}

