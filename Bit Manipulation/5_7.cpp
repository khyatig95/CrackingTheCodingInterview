//Algorithm :   PairwiseSwap :  Mask odd bits. Shift even bits on the left by 1.
//              Mask even bits and shift odd bits on the right by 1.
//              Add/Or these 2 values

using namespace std;
#include <iostream>
#include <bitset>

class myClass {
    public :
        int PairwiseSwap(int num);
};

int myClass :: PairwiseSwap(int num) {
    int maskEven = 0xAAAAAAAA; //1010
    int maskOdd = 0x55555555; //0101
    int valOdd = num&maskEven;
    valOdd = valOdd >> 1;
    int valEven = num&maskOdd;
    valEven = valEven << 1;

    return(valEven|valOdd);
}

int main() {

    myClass obj;
    int x = 124567;
    int res = obj.PairwiseSwap(x);
    cout << "Swapped numbers are " << endl << bitset<32>(x) << endl << bitset<32>(res);

    return 0;
}
