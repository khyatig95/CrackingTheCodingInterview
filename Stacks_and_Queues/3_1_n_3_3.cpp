//Algorithm :   Have each substack store capacity/size and return if their capacity
//              is exceeded

using namespace std;
#include <iostream>
#include "Stack.h"
#include <vector>

template <typename T> 
class subStack {
    private :
        int capacity, size;
        Stack<T> stk;
    public :
        subStack(int cap) {
            capacity = cap;
            size = 0;
        }
        int returnSize() {
            return size;
        }
        void push(T val);
        void pop();
        void print() {
            stk.printStack();
        }
        bool isEmpty() {
            return stk.isEmpty();
        }
        bool isFull() {
            return(size==capacity);
        }
        Node<T>* tail = stk.peek();
}; 

template <typename T> 
void subStack<T> :: push(T val) {
    if (size < capacity) {  //There is space for new element
        stk.push(val);
        size++;
        return;
    }
    cout << "No space in subStack. Push unsuccessful" << endl;
}

template <typename T> 
void subStack<T> :: pop() {
    stk.pop();
    if (size != 0) 
        size--;
}
//////////////////////////////////////////
/////////////////////////////////////////
template <typename T> 
class SetOfStacks {
    private : 
        int subCapacity;
        int currStackID;
        vector<subStack<T>*> vec;
    public : 
        void push(T val);
        void pop();
        void print();
        void popAtIndex(int stackID);
        SetOfStacks(int cap) {
            subCapacity = cap;
            currStackID = -1;
        }
};

template <typename T> 
void SetOfStacks<T> :: push(T val) {
    if (vec.empty()) {
        currStackID++; 
        subStack<T>* s = new subStack<T>(subCapacity);
        vec.push_back(s);
    } else if (vec[currStackID]->isFull()) { //Move to next sub-stack
        currStackID++; 
        subStack<T>* s = new subStack<T>(subCapacity);
        vec.push_back(s);
    }
    vec[currStackID]->push(val);

    cout << "Pushed value " << val << " into stack id " << currStackID << endl;
}

template <typename T> 
void SetOfStacks<T> :: pop() {
    if (vec.empty()) {
        cout << "ERROR: Can NOT pop. Set of Stacks is Empty!!" << endl;
        return;
    }
    vec[currStackID]->pop();
    if (vec[currStackID]->isEmpty()) {
        vec.erase(vec.end()-1); //Delete last subStack object
        currStackID--;
    }
    cout << "Pop done and current stack ID = " << currStackID << endl;
}

template <typename T> 
void SetOfStacks<T> :: print() {
    int count = 0;
    if (vec.empty()) {
        cout << "Set of Stacks is empty. Can NOT print" << endl;
        return;
    }
    while(count <= currStackID) { 
        cout << "Contents of sub stack " << count << " :" << endl;
        vec[count]->print();
        count++;
    }
}

template <typename T>
void SetOfStacks<T> :: popAtIndex(int stackID) {
    if (stackID > currStackID) {
        cout << "ERROR: Stack ID " << stackID << " does NOT exist" << endl;
        return;
    }
    cout << "Pop from stack ID " << stackID << endl;
    vec[stackID]->pop();
    if (vec[stackID]->isEmpty()) 
        vec.erase(vec.begin()+stackID);
}


int main() {
    SetOfStacks<int> ss(2);
    ss.push(12);
    ss.push(13);
    ss.push(55);
    ss.push(75);
    ss.push(33);
    ss.push(6);
    
    ss.print();
    
    ss.pop();
    ss.popAtIndex(0);
    
    ss.print();

    ss.pop();
    ss.print();
    ss.popAtIndex(2);
    ss.pop();
    ss.pop();
    ss.pop();
    
    ss.print();
    ss.pop(); //Popping from empty stack
    return 0;
}
