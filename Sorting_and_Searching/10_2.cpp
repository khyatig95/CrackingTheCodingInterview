//Algorithm : 	groupAnagrams : Create a hashmap with key=sorted string and value=linked list of all
//								strings that sort to that key
//								M = num elements in B
//Time Complexity : O(MNlogN) due to sorting where M = number of strings in the array and N=avg size of string
//Space Complexity : O(NM)

#include <iostream>
using namespace std;
#include <unordered_map>
#include <forward_list>
#include <string>
#include <algorithm>

template <typename T>
void printArr(T* arr, int size) {
	cout << "[ " ;
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

string* groupAnagrams(string* arr, int size) {
	unordered_map<string, forward_list<string> > umap;
	for (int i=0; i<size; i++) {
		forward_list<string> lis;

		//Sort the string
		string temp = arr[i];
		sort(temp.begin(), temp.end());
		cout << "Processing string " << arr[i] << " that sorts to " << temp << endl;
		if (umap.find(temp) != umap.end()) {  //Sorted string exists
			lis = umap[temp];  //Get the list pointer
			cout << "The sorted string already exists" << endl;
		}
		//Add the current string to the list
		lis.push_front(arr[i]);
		cout << "List at " << temp << " : ";
		for (auto itr=lis.begin(); itr!=lis.end(); itr++) {
			cout << *itr << " ";
		}
		cout << endl;
		//Add the list pointer to hashmap
		umap[temp] = lis;
	}

	//Iterate through hashmap
	int index = 0;
	for(auto x : umap) {
		forward_list<string> lis = x.second;  //NOTE!!! NO () after second
		for (auto itr=lis.begin(); itr!=lis.end(); itr++) {
			arr[index] = *itr;
			index++;
		}
	}
	return arr;
}

int main() {
	//Has anagrams
	//string arr[7] = { "calm", "dead", "why", "adde", "kilo", "mlca", "one"};
 	//Doesnt have anagrams
	string arr[7] = {"calm", "dead", "why", "tho", "kay", "nope", "six" };

	cout << "Original array : " << endl;
	printArr<string>(arr, 7);
	string* res = groupAnagrams(arr, 7);
	cout << endl << "Sorted string array : " << endl;
	printArr<string>(res, 7);

	return 0;
}

