//Algorithm : 	ReverseString : Calculate the length of the string. Then swap in a for loop
//Time Complexity : O(N) where N is the length of the string
//Space Complexity : O(1) as we are reversing the string in place
//Assumption : The string will always be terminated with '\0'

#include <iostream>
using namespace std;

template <typename T>
void swap(T* x, T* y) {
	T temp = *x;
	*x = *y;
	*y = temp;
}

char* ReverseString (char* str) {
	int len = 0;
	while(str[len] != '\0') {
		len++;
	}

	int start = 0;
	int end = len-1;

	while(start < end) {
		swap<char>(str[start], str[end]); //We don't need & here as str is already an address
		start++;
		end--;
	}
	return str;
}

template <typename T>
void printArr(T* arr, int size) {
	cout << "[ ";
	for (int i=0; i<size; i++)
		cout << arr[i] << ", " ;
	cout << " ]" << endl;
}

int main() {
	char ex[7] = {'K', 'H', 'Y', 'A', 'T', 'I', '\0'};
	printArr<char>(ReverseString(ex), 6);

	return 0;
}
