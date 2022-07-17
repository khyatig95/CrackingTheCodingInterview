//Algorithm :   Assume the temp stack is sorted such that largest element is on
//              top. Store unsorted stack top element in temp variable. 
//              Pop temp elements into the unsorted stack  till you find the temp
//              variable greater than the top of sorted stack
//              Time Complexity : O(N^2); Space Complexity : O(N)

using namespace std;
#include <iostream>
#include "Stack.h"

class SortedStack {
    private :
        Stack<int> temp;
        int tempdata;
    public :
        Stack<int> stk;
        void sort();
        void print() {
            stk.printStack();
        }
};

void SortedStack :: sort() {
    if (stk.isEmpty()) {
        cout << "ERROR: Stack is empty! Can't Sort" << endl;
        return;
    }
    if (temp.isEmpty()) {
        temp.push(stk.peek()->data);
        stk.pop();
    }
    while (!stk.isEmpty()) {
        tempdata = stk.peek()->data;
        stk.pop(); //Pop the element from stack
        while(temp.peek()->data > tempdata) {
            stk.push(temp.peek()->data); //Push the elements greater than tempdata into OG stack.
            temp.pop();
            if (temp.isEmpty())
                break;
        }
        temp.push(tempdata); //Store the tempdata into temp 
    }
    while(!temp.isEmpty()) {
        stk.push(temp.peek()->data);
        temp.pop();
    }
}

int main() {
    SortedStack ss;
    ss.stk.push(1);
    ss.stk.push(33);
    ss.stk.push(45);
    ss.stk.push(67);
    ss.stk.push(100);
    ss.print();
    
    cout << "Sorting .." << endl;
    ss.sort();
    cout << "Sorted stack " << endl;
    ss.print();

}
