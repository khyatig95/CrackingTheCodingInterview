//Assumption :  Assuming only +ve integers to avoid complications with shift
//Algorithm :   GetNext = Scan from LSB to MSB. Flip the first non-streaming (should have 1's in LSB) 0 at position p to 1. 
//              Then clear 0 to p-1. Insert all (x-1) 1's at the LSB positions where x=original number of 1's between 0 and p-1
//              GetPrev = Scan from LSB to MSB. Flip the first non-streaming 1 at position p to 0.
//              Then clear 0 to p-1. Insert all (x+1) 1's at the MSB position of the cleared area.
//              getNumBin : Binary Manipulation to get the desired numbers
//              getNumArith : Arithmetic Manipulation to get the desired numbers

using namespace std;
#include <iostream>
#include <vector>
#include "helper.h"
#include <math.h>

class myClass : public helper {
    public :
        void getNumBin(int num);
        void getNumArith(int num);
};

void myClass :: getNumBin(int num) {
    int val = num;
    int index, mask;
    createCountArray(num); //Create the count Array
    
    //GetNext
    index = vec[0] + vec[1];    //Position of the first non-streaming 0
    val = val + pow(2, index);      //Set the index location from 0 to 1
    mask = pow(2, index) - 1;   
    mask = ~mask;                   
    val = val&mask;                 //Clear out bits from 0 to (index-1)
    mask = pow(2, (vec[1]-1)) - 1;
    val = val | mask;               //Add the vec[1]-1 1's in the LSB
    
    cout << "Number is " << bitset<32>(num) << " and the next number is " << bitset<32>(val) << endl;
    
    //GetPrev
    val = num;
    index = (vec[0] == 0) ? (vec[1]+vec[2]) : vec[0];   //Find the location of the first non-streaming 1
    mask = pow(2, index+1) - 1;                         //Mask for index to 0 and Clear all bits from 0 to (index-1)
    mask = ~mask;      
    val = val&mask;                                     //Set bits from 0 to index as 0.
    mask = (vec[0] == 0) ? pow(2, vec[1]+1) - 1 : 1;   //We need as many 1's as between 0-(index-1)+1
    int shift = (vec[0] == 0) ? vec[2]-1 : vec[0]-1;   //We shift by as many 0's between 0-(index-1) - 1
    mask = mask << shift;                               //Insert vec[0]-1 0's on the left
    val = val | mask;
    cout << "Number is " << bitset<32>(num) << " and the prev number is " << bitset<32>(val) << endl;
}

void myClass :: getNumArith(int num) {
    int val = num;
    
    //GetNext
    val += pow(2, vec[0]);        //Add to the number such that there is 1 at index and 0's after
    val += pow(2, vec[1]-1) - 1;    //Add to the number such that there are (vec[1]-1) 1's on the right
    cout << "Number is " << bitset<32>(num) << " and the next number is " << bitset<32>(val) << endl;
    
    //GetPrev
    val = num;
    int sub = (vec[0] == 0) ? pow(2, vec[1]) - 1 : 0 ;
    val = val - sub;                //Subtract from number such that there is 1 at index and 0's after
    val = val - 1;                  //Subtract 1 to get 0 at index followed by all 1's 
    cout << "Val is " << val << endl;
    sub = (vec[0] == 0) ? pow(2, vec[2]-1) - 1 : pow(2, vec[0]-1) - 1;
    val = val - sub;    //Eliminate vec[0]-1 1's 
    cout << "Number is " << bitset<32>(num) << " and the prev number is " << bitset<32>(val) << endl;

}

int main() {
    
    myClass obj;
    int x = 19; //NOTE the difference for 15, 7 etc.
    cout << endl << "------Binary Manipulation------" << endl;
    obj.getNumBin(x);
    cout << endl << "------Arithmetic Manipulation------" << endl;
    obj.getNumArith(x);

    return 0;
}
