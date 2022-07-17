#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <bitset>

class helper {
    public :
        void createCountArray(int num);
        vector<int> vec;
};

void helper :: createCountArray(int num) {
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
