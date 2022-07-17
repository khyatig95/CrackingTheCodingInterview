//Algorithm : 	findRotated : Use modified binary search.
//				If half array is sorted and element lies in it, search there
//				If other half is not sorted, search the whole array
//Time Complexity : O(N) (worst case)
//Space Complexity : O(1)

#include <iostream>
using namespace std;

template <typename T>
void printArr(T* arr, int size) {
	cout << "[ " ;
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

int findRotated(int* arr, int start, int end, int val) {
	if (start > end)
		return -1;

	int mid = (start+end)/2;
	cout << "Mid value = " << arr[mid] << endl;
	if (arr[mid] == val)
		return mid;
	//First Half
	 if (arr[mid] >= arr[start]) { //First half is sorted
		 if (arr[mid] > val && val >= arr[start])
			 return(findRotated(arr, start, mid-1, val));
		 else
			 return(findRotated(arr, mid+1, end, val));
	 } else if (arr[mid] < arr[start]) { //First half is not sorted
		 //If second half is sorted, search there
		 if (arr[end] >= arr[mid]) {
			 if (arr[end] >= val && arr[mid] < val)
				 return(findRotated(arr, mid+1, end, val));
			 else
				 return(findRotated(arr, start, mid-1, val));
		 }
	 }
	 //Both are not sorted
	 cout << "ERROR : Array was NOT sorted when rotated " << endl;
	 return -1;
}

int main() {
	//Arbitrary rotations
	//int arr[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

	//no rotations
	//int arr[12] = { 1, 3, 4, 5, 7, 10, 14, 15, 16, 19, 20, 25};

	//Completely rotated
	//int arr[12] = {3, 4, 5, 7, 10, 14, 15, 16, 19, 20, 25, 1};

	//Repetitions
	int arr[6] = {2, 2, 2, 3, 4, 2};

	int search = 4;
	int res = findRotated(arr, 0, 5, search);
	if (res == -1)
		cout << search << " not found!" << endl;
	else
		cout << search << " found at " << res << endl;

	return 0;
}

