//Algorithm : 	SortedMerge : Keep populating A from the end by comparing A and B's element from the end
//Time Complexity : O(N*M) where N= num elements in A
//								 M= num elements in B
//Space Complexity : O(N*M) due to recursion (worst case when A>B)
//Assumption : A's size is num non-empty elements in A + size of B.
//			   B doesn't have any empty elements
//			   Both arrays are sorted

#include <iostream>
using namespace std;

template <typename T>
T* SortedMerge(T* bigArr, int bigSize, T* smallArr, int smallSize) {
	//Base Case
	if(smallSize <= 0) {
		return bigArr;
	}
	//cout << "Comparing a= " << bigArr[bigSize-smallSize-1] << " to b= " << smallArr[smallSize-1] << endl;
	if (bigArr[bigSize-smallSize-1] > smallArr[smallSize-1])
		bigArr[bigSize-1] = bigArr[bigSize-smallSize-1];
	else {
		bigArr[bigSize-1] = smallArr[smallSize-1];
		smallSize --;
	}
	cout << "Bigger element " << bigArr[bigSize-1] << endl;
	bigSize--;
	//Recurse
	return (SortedMerge(bigArr, bigSize, smallArr, smallSize)); //recurse

}

template <typename T>
void printArr(T* arr, int size) {
	cout << "[ " ;
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

int main() {
	//Repetitions
	//int a[10] = { 2, 3, 3, 4, 6};
	//int b[5] = { 1, 3, 6, 7, 9};

	//B>a
	//int a[10] = { 2, 3, 3, 4, 6};
	//int b[5] = {6, 7, 8, 8, 11};

	//a>B
	int a[10] = {6, 7, 8, 8, 11};
	int b[5] = { 2, 3, 3, 4, 6};

	int* res;
	res = SortedMerge<int>(a, 10, b, 5);
	printArr<int>(a, 10);
}
