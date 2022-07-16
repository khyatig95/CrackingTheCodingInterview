#include <iostream> 
#include <string>  
#include <cctype>
using namespace std; 
//Algorithm :   URLify : Iterate from the rear to shift non-white space 
//              characters to the end and then add the %20 whenever space 
//              is encountered
//              Time : O(N) ; Space : O(1) as not using extra data structure

class myClass {
    public : 
            string URLify(string str);
};

string myClass::URLify(string str) {
    bool true_length = false;
    string::iterator tail = str.end()-1; //The end() points to a location after the end. That's why -1 is needed
    for (auto itr=str.rbegin(); itr!=str.rend(); ++itr) {
        cout << "Processing char " << *itr ;
        if (isspace(*itr)) {
            cout << " which is a white space" << endl;
            if (!true_length)
                continue;
            else {
                *tail = '0';
                --tail;
                *tail = '2';
                --tail;
                *tail = '%';
                --tail;
            }
        } else {
            cout << " which is NOT a whitespace" << endl;
            if (!true_length) {
                cout << "Set true_length to true " << endl;
                true_length = true;
            }
            *tail = *itr;
            --tail;
            *itr = ' ';         //This is needed to delete the char from original position
        }
        cout << "String is " << str << endl;
    }
    return str;
}

int main() 
{ 
    myClass obj;
    string test1 = " Khyati is coding         ";

    string test2 = obj.URLify(test1);
    cout << "String1 is " << test1 << " and its URLified version is " << test2 << endl;
    
    return 0;
}
