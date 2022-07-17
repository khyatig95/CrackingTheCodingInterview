//Algorithm :   Mask : Use the difference between start and end positions to calculate 
//              the power of 2. Subtract 1 from this number so you get as many 1's 
//              as start-end+1. Shift this start times and invert. You now have 0's
//              between the start and end position.
//              Clear : mask & input integer
//              Generate Output : Shift the number to be inserted start times and 'or' it
//              with the masked input integer.
//Assumption : start = where the LSB of the mask (i). end = where the MSB of the mask (j)
//			

using namespace std;
#include <iostream>
#include <bitset>
#include <math.h>

class myClass {
    public : 
        int Insertion(int insertInto, int insert, int start, int end);
};

int myClass :: Insertion(int insertInto, int insert, int start, int end) {
    int power = end - start + 1; 
    int mask = pow(2, power) - 1;
    cout << "Start position is " << start << " and end position is " << end << endl;
    cout << "Mask is " << bitset<32>(mask) << endl;
    mask = mask << start;
    cout << "Shifted mask is " << bitset<32>(mask) << endl;
    mask = ~mask;
    cout << "Actual mask is " << bitset<32>(mask) << endl;
    
    cout << "insertInto = " << bitset<32>(insertInto) << " and insert is " << bitset<32>(insert) << endl;
    insertInto = insertInto & mask;
    cout << "Masked insertInto is " << bitset<32>(insertInto) << endl;
    
    insertInto = insertInto | (insert << start);
    cout << "Final result " << bitset<32>(insertInto) << endl;
    return(insertInto);
}

int main() {
    
    myClass obj;
    int res = obj.Insertion(154, 7, 2, 7);
    return 0;
}
