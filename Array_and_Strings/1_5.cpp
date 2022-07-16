#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
using namespace std;
//Assumption:   No white spaces. Case insensitive. isOneEdit does not care about relative ordering!!!
//Algorithm :   isOneEdit : Use an int array to store frequency of all char of longer
//              string. Then subtract from same array for string 2.
//              Time : O(N) where N is length of small string; Space : O(c) where c=num char
//              OneEditType : Identifies if the two strings are one edit away and type of edit.
//              Time : O(N);    Space : O(1)

class myClass {
    public :
            bool isOneEdit(string str1, string str2);
            string OneEditType(string str1, string str2);
    private :
            array<int,26> charCount;
            int index, index1, index2, difference;
            bool isDifferent;
};

bool myClass::isOneEdit(string str1, string str2) {
    charCount.fill(0);
    index = 0;
    isDifferent = false;
    difference = str1.size() - str2.size();
    if (abs(difference) > 1) //Strings should not differ by more than 1 in length
        return false;

    //Store the character count of longer string
    string::iterator first = str1.size() > str2.size() ? str1.begin() : str2.begin();
    string::iterator last = str1.size() > str2.size() ? str1.end() : str2.end();
    for(auto itr=first; itr!=last; ++itr) {
        index = int(*itr) - int('a');
        charCount[index] ++;
    }

    //Manipulate previous character count with shorter string
    first = str1.size() > str2.size() ? str2.begin() : str1.begin();
    last = str1.size() > str2.size() ? str2.end() : str1.end();
    for(auto itr=first; itr!=last; ++itr) {
        index = int(*itr) - int('a');
        --charCount[index];
        if (charCount[index] < 0) {
            if (str1.size() == str2.size()) { //Replace
                if (isDifferent)
                    return false; //2 differences;
                else
                    isDifferent = true;
            } else  //Insertion
                return false;
        }
    }
    return true;
}

string myClass :: OneEditType(string str1, string str2) {
    difference = str1.size() - str2.size();
    if (abs(difference) > 1) //Strings should not differ by more than 1 in length
        return "false";

    isDifferent = false;
    index1 = 0;
    index2 = 0;

    while(index1 < str1.size() && index2 < str2.size()) {
        if (str1[index1] != str2[index2]) {
            cout << str1[index1] << " is not equal to " << str2[index2] << endl;
            if (isDifferent) //More than one difference
                return "false";
            else
                isDifferent = true;
            if (str1.size() >= str2.size()) {
				cout << "incr index1" << endl;
				index1++;
			}
		  if (str2.size() >= str1.size()) {
				cout << "incr index2" << endl;
				index2++;
	       }
        } else {
			cout << "incr both" << endl;
        	index1++;
        	index2++;
        }

    }
    if (str1.size() == str2.size())
        return "Replace";
    else
        return "Insert";
}

int main()
{
    myClass obj;
    string test1 = "paaale";
    string test2 = "pale";

    if (obj.isOneEdit(test1, test2))
        cout << "String " << test1 << " is a one edit of string " << test2 << endl;
    else
        cout << "String " << test1 << " is NOT a one edit of string " << test2 << endl;

    cout << "Strings are related as: " << endl << obj.OneEditType(test1, test2) << endl;

    return 0;
}
