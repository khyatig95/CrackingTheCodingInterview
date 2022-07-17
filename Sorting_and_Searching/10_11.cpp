//Algorithm : 	pNv : Add the largest number in the mid position for a contiguous 3 index. We have an overlap
//					with the leftmost element as that is a smaller element. We will just replace it with a
//					smaller value in future (as we only swap if that element is bigger)
//Time Complexity : O(N)
//Space Complexity : O(1)

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void swap(T* x, T* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}


int* pNv(int* arr, int size) {
	int maxVal;
	for (int i=0; i<=size-3; i=i+2) {
		maxVal = max(max(arr[i], arr[i+1]), arr[i+2]);
		if (arr[i+1] != maxVal) {
			if(arr[i] == maxVal)
				swap(arr[i], arr[i+1]);
			else
				swap(arr[i+2], arr[i+1]);
		}
	}
	return arr;
}

void printArr(int* arr, int size) {
	if (size <= 0)
		return;
	cout << "[ ";
	for(int i=0; i<size; i++)
		cout << arr[i] << ", ";
	cout << "]" << endl;
}

int main() {
	//int arr[] = {0, 1, 4, 7, 8, 9};
	int arr[] = {5, 3, 1, 2, 3};
	cout << "Original array" << endl;
	printArr(arr, sizeof(arr)/sizeof(arr[0]));

	int* res = pNv(arr, sizeof(arr)/sizeof(arr[0]));
	cout << "Result array" << endl;
	printArr(res, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
