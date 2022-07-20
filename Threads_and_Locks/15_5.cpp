//Algorithm : 	CallInOrder : Use 2 different mutexes for second and third. Unlock in first and second.

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Foo {
private :
    mutex m1;
    mutex m2;
        
public :
    Foo() {
        m1.lock();
        m2.lock();
    }
    void first() {
        cout << "Hi I am in first" << endl;
        m1.unlock();
    }    
    void second() {
        cout << "Entered second" << endl;
        m1.lock();
        cout << "Hi I am in second" << endl;
        m2.unlock();
    }
    void third() {
        cout << "Entered third" << endl;
        m2.lock();
        cout << "Hi I am in third" << endl;
    }
};

int main() {
    Foo* f = new Foo();
    
    thread t1(&Foo::first, f);
    thread t2(&Foo::second, f);
    thread t3(&Foo::third, f);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
