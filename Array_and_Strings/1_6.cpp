#include <iostream> 
#include <string>
#include <algorithm>
using namespace std; 
//Assumption:   No white spaces. Case insensitive
//Algorithm :   Compress : Use another string to store the compressed string. 
//              Returns whichever string is smaller
//              Time : O(N); Space : O(N) as we need a new string

class myClass {
    public : 
            string Compress(string str);
    private :
            string compressed;
            int count, n;
            char count_str[32];

            
};

string myClass::Compress(string str) {
    count = 1;
    cout << "The string is " << str << endl;
  
    for (auto itr=str.begin(); itr!=str.end(); ++itr) {
        if (*itr == *(itr+1))
            ++count;
        else {
            compressed.push_back(*itr);
            n=sprintf(count_str, "%d", count);
            cout << "Count string is " << count_str << endl;
            compressed.append(count_str);
            count = 1;
        }
    }
    cout << "The compressed string is " << compressed << endl;
    if (str.size() > compressed.size())
        return compressed;
    else 
        return str;
}

int main() 
{ 
    myClass obj;
    string test1 = "abcddeeeee";
    
    cout << "Compressed string is " << obj.Compress(test1) << endl;
    
    return 0;
}
