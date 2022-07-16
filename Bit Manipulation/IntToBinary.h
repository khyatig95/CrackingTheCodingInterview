#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class IntToBinary {
    public :
        string convertToBinary(int num);
        int convertToInt(string str);
};

string IntToBinary :: convertToBinary(int num) {
    int val = num;
    string Result;
    bool first = true;
    while (val != 0) {
        if (first)
            Result.push_back('0'+val%2);
        else
            Result.insert(Result.begin(), '0'+val%2);
        first = false;
        val = val/2;
    }
    cout << "Num is " << num << " and binary string is " << Result << endl;
    return(Result);
}

int IntToBinary :: convertToInt(string str) {
    int num = 0;
    int power = str.size() - 1;

    for (int i=0; i<str.size(); i++) {
        num += (str[i]-'0')*pow(2,power);
        power--;
    }
    cout << "For binary : " << str << " value is " << num << endl;
    return(num);
}
