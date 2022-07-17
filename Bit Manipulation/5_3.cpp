//Algorithm :   flipBitArray : Store the length of 0's at the even indices of the array and
//              length of 1's at odd indices. Since right shift operator won't work well for
//              negative numbers, we need to have the opposite mask and approach for them.
//              Count array will contain count of 0's at vec.begin() position for num>0 and 
//              count of 1's for num<0.
//              Time Complexity : O(b) ; Space complexity : O(b) where b is the number of bits
//              TODO:   flipBit : Generate a mask such that the value of bit can be found by anding it with a 
//				1 at that location. If it is 1, increment current length. If it is 0 and next bit is 0, 
//				set prev length to 0. If next bit is 1, set prev len to current length and reset curr len.
//				Shift the mask to check the next bit
//              Time Complexity : O(b); Space Complexity : O(1)

using namespace std;
#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>
#include <algorithm>

class myClass {
    public :
        void createCountArray(int num);
        int flipBitArray(int num);
        int flipBit(int num);
    private : 
        vector<int> vec;
};

void myClass :: createCountArray(int num) {
    int count = 0;
    int val = num;
    int check;
    bool pushDone = false;
    int totalCount = 0;
    bool reverse = (num<0) ? true : false;
    int mask = reverse ? pow(2,31) : 1;
    int findZero = reverse ? mask : 0;

    while ((val != 0) || !pushDone) {
        check = val&mask;
        //cout << "num : " << bitset<32>(val) << " for findZero : " << findZero << " and val&mask : " << bitset<32>(check) << " with count " << count << endl;
        if (check == findZero) {
            count++;
            val = reverse ? val << 1 : val >> 1; //For negative numbers, right shift is undefined
            pushDone = false;
            totalCount++;
        } else {
            vec.push_back(count);
            if (findZero == 0)
                findZero = reverse ? mask : 1;
            else
                findZero = 0;
            count = 0;
            pushDone = true;
        }
    }
    vec.push_back(32-totalCount);
    if (reverse) {
        cout << "Reverse Count array for integer : " << bitset<32>(num) << " is : " << endl;
        for (auto itr = vec.begin(); itr!= vec.end(); ++itr )
            cout << *itr << " ";
        cout << endl;
        vector<int> rev_vec;
        for (auto itr=vec.rbegin(); itr!=vec.rend(); ++itr)
            rev_vec.push_back(*itr); //Reverse the vector
        vec = rev_vec;
        vec.push_back(0); //As negative numbers have 1 in MSB
    }
    cout << "Count array for integer : " << bitset<32>(num) << " is : " << endl;
    for (auto itr = vec.begin(); itr!= vec.end(); ++itr )
        cout << *itr << " ";
    cout << endl;
}

int myClass :: flipBitArray(int num) {
    if (num == -1) //All 1's
        return 32;
    else if (num == 0)
        return 1;
    
    createCountArray(num);

    int prev_len, next_len, max_len, curr_len;
    max_len = 1; //As we can always flip atleast one 1.
    int first, last;
    //first stores 0 length and then +2 will have 0 length again
    for (auto itr = vec.begin(); itr != vec.end()-1; itr = itr+2) {
        prev_len = (itr == vec.begin()) ? 0 : *(itr-1);
        next_len = (itr == vec.end()-1) ? 0 : *(itr+1);
        if (*itr == 0)  
            curr_len = max(prev_len, next_len);
        else if (*itr > 1) //Cant merge but we can flip adjacent 0 to 1 to create max length
            curr_len = max(prev_len, next_len) + 1;
        else if (*itr == 1) //Can merge
            curr_len = prev_len + next_len + 1;
        max_len = max(max_len, curr_len);
        cout << "Current length for " << *itr << " is " << curr_len << endl;

    }
    return max_len;
}

int myClass :: flipBit(int num) {
    if (num == -1) //All 1's
        return 32;
    else if (num == 0)
        return 1;
    
    int val = num;
    int curr_len = 0;
    int prev_len = 0;
    int mask = (num<0) ? pow(2,31) : 1;
    int mask2 = (num<0) ? (mask>>1) : (mask<<1) ;
    int max_len = 1;
    while(val != 0) {
        if ((val&mask) == mask) 
            curr_len++;
        else if ((val&mask) == 0) {
            prev_len = ((val&mask2) == 0) ? 0 : curr_len;
            curr_len = 0;
        }
        max_len = max(max_len, prev_len+curr_len+1);
        cout << "For val " << bitset<32>(val) << " curr_len " << curr_len << " prev_len " << prev_len << " max_len " << max_len << endl;
        val = (num<0) ? val << 1 : val >> 1;
    }
    
    return max_len;
}

int main() {
    
    myClass obj;
    int x = -49;
    cout << "Array : Max length of 1's by flipping just 1 bit from 0 to 1 for num " << bitset<32>(x) << " is " << obj.flipBitArray(x) << endl;
    cout << "Max length of 1's by flipping just 1 bit from 0 to 1 for num " << bitset<32>(x) << " is " << obj.flipBit(x) << endl;

    return 0;
}
