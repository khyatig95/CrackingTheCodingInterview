#include <iostream> 
#include <string>  
#include <array>
#include <algorithm>
using namespace std; 
//Assumption :  String is made of the 26 alphabets/characters only. 
//              Case insentive
//Algorithm :   isPermute : Uses an array to store the frequency
//              of each character in string1 and then compares with string2. 
//              Time : O(N) ; Space : O(c) where c = num characters 
//              isPermute_sort : Sorts both the strings and compares them.
//              Doesn't need additional data structure. 
//              Time : O(NlogN) ; Space : That of the sorting algo

class myClass {
    public : 
            bool isPermute(string str1, string str2);
            bool isPermute_sort(string str1, string str2);
    private :
            array<int,26> charCount;
};

bool myClass::isPermute(string str1, string str2) {
    int index;
    charCount.fill(0); //Assign all zeroes
    if (str1.size() != str2.size()) { //If string size not same, can't be permutations
        cout << "String1 size is " << str1.size() << " which is not equal to String2 size " << str2.size() << endl; 
        return false;  
    }
    for (auto itr=str1.begin(); itr!=str1.end(); ++itr) {
        index = int(*itr) - int('a'); //'a' is strored at the 0th position
        cout << "index of char " << *itr << " is " << index; 
        charCount[index]++;
        cout << " Count of char " << *itr << " is " << charCount[index] << endl; 
    }
    cout << endl << "Starting String2" << endl;
    for (auto itr=str2.begin(); itr!=str2.end(); ++itr) {
        index = int(*itr) - int('a'); //'a' is strored at the 0th position
        cout << "index of char " << *itr << " is " << index; 
        charCount[index]--;
        cout << " Count of char " << *itr << " is " << charCount[index] << endl; 
        if (charCount[index] < 0) {
            cout << "Char count of char " << *itr << " doesn't match!" << endl; 
            return false;
        }
    }
    return true;
}

bool myClass :: isPermute_sort(string str1, string str2) {
    if (str1.size() != str2.size()) { //If string size not same, can't be permutations
        cout << "String1 size is " << str1.size() << " which is not equal to String2 size " << str2.size() << endl; 
        return false;  
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    cout << "Sorted string1 is " << str1 << endl; 
    cout << "Sorted string2 is " << str2 << endl; 

    if (str1 != str2) 
        return false;
    return true;
}

int main() 
{ 
    myClass obj;
    string test1 = "abcdxyzde";
    string test2 = "abcdedzyx";
    if (obj.isPermute_sort(test1, test2)) 
        cout << "String " << test1 << " is a permutation of String " << test2 << endl;
    else 
        cout << "String " << test1 << " is NOT a permutation of String " << test2 << endl;
        
    return 0;
}
