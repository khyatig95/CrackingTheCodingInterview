//Algorithm : 	printDuplicates : We have 4kB => 32768 bits. Since N <= 32000, we use a bitVector that is set
//				when corresponding number appears. If we see the flag is already 1, we print the duplicate entry.
//				Note : We store val's flag at val-1 index in the bitVector
//Time complexity : O(N)
//Space Complexity : O(N) [bits]

#include <iostream>
using namespace std;
#define N 32000

void printDuplicates(int* NumArr, int size) {
	if ((size == 0) || (size == 1)) { // Duplicates not possible
		cout << "No duplicates possible" << endl;
		return;
	}
	bool bitVector[N] = { false };
	cout << "The duplicate elements are : " << endl;
	for (int i=0; i<size; i++) {
		if ((NumArr[i] < 1) || (NumArr[i] > N)) {
			cout << "ERROR: " << NumArr[i] << " does NOT lie between 1 and " << N << endl;
			return;
		}
		//NumArr[i]-1 index in bitVector corresponds to NumArr[i] corresponds to
		if (bitVector[NumArr[i] - 1])
			cout << NumArr[i] << " ";
		else
			bitVector[NumArr[i]-1] = true;

	}
}

int main() {
	//No duplicates
	//int arr[] = {25, 67, 89, 32000, 1, 42, 36, 69};
	//Some duplicates
	int arr[] = {25, 67, 89, 32000, 1, 32000, 1, 42, 36, 69, 67};
	//All duplicates
	//int arr[] = {1, 1, 1, 1, 1, 1, 1};
	//Empty array
	//int arr[] = {};
	//Outside the range
	//int arr[] = {25, 67, 89, 32000, 1, 0, 1, 42, 36, 69, 67};

	printDuplicates(arr, sizeof(arr)/sizeof(arr[0]));

	return 0;
}
