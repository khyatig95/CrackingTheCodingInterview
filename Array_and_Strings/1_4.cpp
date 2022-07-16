#include <iostream> 
#include <string>  
#include <cctype>
using namespace std; 
//Assumption : Case insensitive
//Algorithm :   isPalindrome : Use an int variable and switch 1 and 0 when the char
//              occurs. All letters should occur even number of times if non white 
//              space char in string are even. => int should be 0
//              Only one letter should appear odd times if non white space char in 
//              string length are odd =>int should have just one 1 in the bit vector
//              
//              Time : O(N) ; Space : O(c) where c=num char

class myClass {
    public : 
            bool isPalindrome(string str);
    private :
            int charCount;
            int nonWhiteCount;
};

bool myClass::isPalindrome(string str) {
    charCount = 0;
    nonWhiteCount = 0;
    int index;
    for (auto itr = str.begin(); itr!=str.end(); ++itr) {
        index = int(*itr) - int('a'); //We want to store char a count at the 0th bit
        if (!isspace(*itr)) {
            nonWhiteCount++;
            cout << "Processing non-whitespace char " << *itr << endl;
            if (charCount & 1<<index) { //Already occured odd times
                cout << *itr << " has occured odd times. Making it even" << endl;
                charCount -= 1<<index; //Make the value at that bit 0 to indicate even occurences
            } else {
                cout << *itr << " has occured even times. Making it odd" << endl;
                charCount += 1<<index; //Make the value at that bit 1 to indicate even occurences
            }
        }
    }
    if (nonWhiteCount%2 == 0) { //even length string
        cout << "String is even length" << endl;
        if (charCount == 0)
            return true;
        else 
            return false;
    } else {                //odd length string
        cout << "String is odd length" << endl;
        if (((charCount-1) & charCount) == 0)  //1000-1 = 0111 => 1000 & 0111=0
            return true;
        else
            return false;
    }
}

int main() 
{ 
    myClass obj;
    string test1 = "khyati";

    if (obj.isPalindrome(test1))
        cout << "String " << test1 << " is a permutation of Palindrome" << endl;
    else 
        cout << "String " << test1 << " is NOT a permutation of Palindrome" << endl;
        
    return 0;
}
