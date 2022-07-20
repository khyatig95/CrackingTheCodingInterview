//Algorithm : 	FizzBuzz : Have a parent thread that does incrementing and num printing.
//              Launch children thread to print the appropriate string

#include <iostream>
#include <thread>
using namespace std;
#include <mutex>

void printFizzBuzz(int count) {
    if ((count%3 == 0) && (count%5 == 0)) cout << "FizzBuzz";
}

void printFizz(int count) {
    if ((count%3 == 0) && (count%5 != 0)) cout << "Fizz";
    
}

void printBuzz(int count) {
    if ((count%3 != 0) && (count%5 == 0)) cout << "Buzz";
}


int main() {
    
    auto lambda = [](int n) {
        for (int count = 0; count <= n ; count++) {
            cout << endl << count << " ";
            
            thread t1(printFizzBuzz, count);
            thread t2(printFizz, count);
            thread t3(printBuzz, count);
            t1.join();
            t2.join();
            t3.join();
        }
    };
    
    thread tnum(lambda, 15);
    tnum.join();
    
    return 0;
}
