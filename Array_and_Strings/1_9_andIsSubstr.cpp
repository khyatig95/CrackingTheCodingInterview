#include <iostream> 
#include <string>
using namespace std; 
//Assumption:   No white spaces
//Algorithm :   isRotation : Create a new string that is concatenation of str1 
//              with itself. Check if str2 is a substr of the new string
//              Time : O(substring algo) = O(N); Space : O(N) as creating new string

class myClass {
    public :
        bool isRotation(string str1, string str2);
        bool isSubstr(string ls, string ss);  
    private :
        string concat;
};

bool myClass :: isRotation(string str1, string str2) {
    if (str1.size() != str2.size()) //Have to be of the same length for rotation
        return false;
    if (str1.empty() || str2.empty()) //Can't be empty
        return false;
        
    concat = str1 + str1;
    cout << "Concatenated string is " << concat << endl;
    if (isSubstr(concat, str2))
        return true;
    return false;
}

bool myClass :: isSubstr(string ls, string ss) {
    int index1 = 0;
    while (index1 < ls.size()) {
        if (ls[index1] == ss[0]) {
            cout << ls[index1] << " in longer string is equal to " << ss[0] << " in shorter string " << endl;
            if (ls.substr(index1, ss.size()) == ss) {
                return true;
            } else {
                cout << "No substring at this long string index " << endl;
            }
        }
        index1++;
    }
    return false;
}


int main() {
    myClass obj;
    
    string test1 = "waterbottle";
    string test2 = "terbottlewa";
    
    if (obj.isRotation(test1, test2))
        cout << "Strings are rotated" << endl;
    else 
        cout << "Strings are NOT rotated" << endl;

    return 0;
};}
