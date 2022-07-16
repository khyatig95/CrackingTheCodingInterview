using namespace std;
#include <iostream>
#include <vector>

//FIFO. Insert at Tail. Delete at Head
template <typename T>
class Queue {
    private :
        vector<T> q;
    public : 
        void pop();
        void push(T val);
        T peek();
        bool isEmpty();
        void printQueue();
};

template <typename T>
void Queue<T> :: pop() {
    if (q.empty()) {
        cout << "ERROR : Can't pop from empty queue" << endl;
        return;
    }
    q.erase(q.begin());
}

template <typename T>
void Queue<T> :: push(T val) {
    q.push_back(val);
}

template <typename T>
T Queue<T> :: peek() {
    return(q.front());
}

template <typename T>
bool Queue<T> :: isEmpty() {
    return(q.empty());
}

template <typename T>
void Queue<T> :: printQueue() {
    for (auto itr=q.rbegin(); itr!=q.rend(); ++itr) 
        cout << *itr << endl << "|" << endl ;
    cout << endl;
}