//Algorithm :   Conversion :  Perform bitwise XOR between 2 numbers to find where they differ
//              This will be indicated by 1's at those locations. 
//              To count number of 1's, perform n&(n-1) repeatedly. #of times you perform
//              that till you get 0 => number of 1's in the integer

using namespace std;
#include <iostream>
#include <bitset>

class myClass {
    public :
        int Conversion(int x1, int x2);
};

int myClass :: Conversion(int x1, int x2) {
    int res = x1 ^ x2;
    //cout << "Res is " << bitset<32>(res) << endl;
    int count = 0;
    while (res != 0) {
        res = res&(res-1);
        count++;
    }

    return count;
}

int main() {
    
    myClass obj;
    int a = 126789;
    int b = 15;
    cout << "Number of bits you need to flip to convert " << endl << bitset<32>(a) << " to " << endl << bitset<32>(b) << " are " << obj.Conversion(a, b) << endl;

    return 0;
}
