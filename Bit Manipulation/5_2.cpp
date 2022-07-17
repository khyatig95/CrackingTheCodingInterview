//Assumption :  Real number should be between 0 and 1. The 32 bits include the 0. for 
//              representation.
//Algorithm :   Multiply real with 2 repeatedly. If number is greater than 1,
//              append 1 in string else 0. Subtract 1 from num if it is greater than 1
//              Break loop is num becomes equal to 0 or if string size > 32

using namespace std;
#include <iostream>
#include <bitset>
#include <string>

class myClass {
    public : 
        void BinaryToString(double num);
};

void myClass :: BinaryToString(double num) {
    string Result;
    double val = num;
    Result.push_back('0');
    Result.push_back('.');
    while (val != 0) {
        cout << "Val is " << val << endl;
        val = val*2;
        if (val >= 1) {
            Result.push_back('1');
            val = val-1; //Only need decimal part
        } else 
            Result.push_back('0');
        if (Result.size() == 32) {
            cout << "ERROR: real number needs more than 32 bits" << endl;
            cout << "Binary representation of " << num << " so far is " << Result << endl;
            return;
        }
    }
    cout << "Binary representation of " << num << " is " << Result << endl;
}


int main() {
    
    myClass obj;
    obj.BinaryToString(0.72);
    return 0;
}
