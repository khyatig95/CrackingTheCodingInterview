//Assumption :  Stack contains int elements only
//Algorithm :   Min: Returns the min element where at every push,
//              you store the min element so far so at pop, you 
//              still know the new min element. (You can use a linkedlist to store val and min)
//              Time Complexity : O(1); Space Complexity : O(N)

using namespace std;
#include <iostream>
#include "Stack.h"

class minStack {
    public : 
        void push(int val);
        void pop();
        int Min();
        void print();
    private : 
        Stack<int> stk;
        Stack<int> minStk;
};

void minStack :: push(int val) {
    if (minStk.isEmpty()) 
        minStk.push(val);
    else {
        if (minStk.peek()->data > val)  //This is the new min
            minStk.push(val); 
        else 
            minStk.push(minStk.peek()->data);
    } 
    stk.push(val);
    cout << "Pushed val " << val << " and the current min is " << minStk.peek()->data << endl; 
}

void minStack :: pop() {
    minStk.pop();
    stk.pop();
}

int minStack :: Min() {
    if (minStk.isEmpty()) {
        cout << "ERROR: Stack is empty! Can't find min element" << endl;
        return -1;
    } else
        return(minStk.peek()->data);
}

void minStack :: print() {
    stk.printStack();
}

int main() {
    minStack obj;
    obj.push(53);
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.push(45);
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.push(81);
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.push(32);
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.push(22);
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.print();
    obj.pop();
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.pop();
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.print();
    obj.pop();
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.pop();
    cout << "Min in the stack is " << obj.Min() << endl;
    obj.pop();
    cout << "Min in the stack is " << obj.Min() << endl;

    return 0;
}
