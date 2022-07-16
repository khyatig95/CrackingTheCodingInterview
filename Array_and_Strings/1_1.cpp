#include <iostream> 
#include <string>  
#include <algorithm>
using namespace std; 
//Assumption :  String is made of the 26 alphabets/characters only. 
//              Case insentive
//Algorithm :   isUnique : Uses int variable to store the frequency
//              of each character in the string. 
//              Time : O(N) ; Space : O(c) where c = total num characters 
//              isUnique_sort : Sorts the string and compares immediate
//              neighbors. Doesn't need additional data structure. 
//              Time : O(NlogN) ; Space : That of the sorting algo

class myClass {
    public : 
            bool isUnique(string str);
            bool isUnique_sort(string str);
    private :
            int charCount;
};

bool myClass::isUnique(string str) {
    int index;
    charCount = 0;
    if (str.size() > 26) { //No way that it is unique as we only have 26 characters
        cout << "String size is " << str.size() << " which is greater than num char" << endl; //DEBUG
        return false;  
    }
    for (auto itr=str.begin(); itr!=str.end(); ++itr) {
        index = int(*itr) - int('a'); //'a' is strored at the 0th position
        cout << "index of char " << *itr << " is " << index << endl; //DEBUG
        cout << "Current charCount is " << charCount << endl; //DEBUG
        if (charCount & (1<<index)) { //This character has already been encountered
            return false;
        } else {
            charCount = charCount + (1<<index);
            cout << "New charCount is " << charCount << endl; //DEBUG
        }
    }
    return true;
}

bool myClass :: isUnique_sort(string str) {
    if (str.size() > 26) { //No way that it is unique as we only have 26 characters
        cout << "String size is " << str.size() << " which is greater than num char" << endl; //DEBUG
        return false;  
    }
    sort(str.begin(), str.end());
    cout << "Sorted string is " << str << endl;
    for (auto itr=str.begin(); itr!=(str.end()-1); ++itr) {
        cout << "Processing char " << *itr << endl; //DEBUG
        if (*itr == *(itr+1)) //Same as next char
            return false;
    }
    return true;
}

int main() 
{ 
    myClass obj;
    string test = "abcdxyzd";
    if (obj.isUnique_sort(test)) 
        cout << "String " << test << " is Unique" << endl;
    else 
        cout << "String " << test << " is NOT Unique" << endl;
        
    return 0;
}
