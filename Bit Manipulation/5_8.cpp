//Assumption :  To accomodate array of 1 byte, we use char array
//Algorithm :   DrawLine :  Since x1 and x2 may be multiple bytes apart, find 
//              how far apart they are by calculating their byte id.
//              Set whole bytes to 1. Then work on the individual bytes of x1 
//              and x2 to set the individual bits in their bytes to 1.

using namespace std;
#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>
#define W 4

class myClass {
    public :
        void DrawLine(int x1, int x2, int y);
    private :
        uint8_t arr[16] = {0};
};

void myClass :: DrawLine(int x1, int x2, int y) {
    if (x1 > W*8 || x2 > W*8 || y > W || x1 > x2) {
        cout << "ERROR: Coordinates specified are out of range!" << endl;
        return;
    }
    int start = y*W + (x1/8);
    int last = y*W + (x2/8);
    uint8_t val = 0;
    int super;
    int shift;
    cout << "Start is " << start << " and last is " << last << endl;
    if (start == last) { //Both x1 and x2 are in the same byte
        val = pow(2, x2-x1) - 1;
        arr[start] = val >> x1;
    } else {
        if (x1%8 != 0) {
            super = 8 - (x1%8);
            val = pow(2, super)-1;
            arr[start] = val;
            start++;
        }
        //x2 : You can also generate as many 1's as 0's and then just flip. No shift needed
        shift = 7 - x2%8;
        super = 8 - shift;
        val = pow(2, super) - 1;
        val = val << shift;
        arr[last] = val;
        last--;
        
        for (int i=start; i<=last; i++)
            arr[i] = -1; //All ones
    }
    
    for (int i=0; i<16; i++) {
        if (i%W == 0)
            cout << endl;
        cout << bitset<8>(arr[i]) << "t";
    }
    cout << endl;
}

int main() {
    
    myClass obj;
    int x1 = 8;
    int x2 = 16;
    int y = 2;
    cout << "x1 = " << x1 << " x2 = " << x2 << " y = " << y << endl;
    obj.DrawLine(x1, x2, y);

    return 0;
}
