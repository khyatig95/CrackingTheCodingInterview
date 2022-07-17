//Algorithm : 	Total no. of +ve numbers is 2^31 = 2 billion integers
//				Since file contains 4 billion +ve integers => there are duplicates
//				1GB of memory => 2^30bytes = 8*2^30 bits = 2^33bits.
//				If we set a bit for a number, we only need 2 billion bits = 2^30 to return a missing number
//				Follow-up -
//				We have 10MB and the integers are not unique
//				1) Consider an array that stores the count of numbers within each block
//				Size of array = Total mem/Size of each element <= 8*2^20bytes/4bytes <= 2^21
//				Size of block/range = Total numbers/Number of blocks = 2^31/2^21 >= 2^10 (greater than as max number of blocks used)
//				Whenever the count of a block < block size => number is missing there.
//				To find the missing number in the block -
//				2) We have 10MB = 2^6*2^20 bits
//				=> block size <= 2^26
//				Hence, 2^10 <= block size <= 2^26
//				To use less memory, pick a number in middle.
//Time Complexity : O(N)
//Assumption : Only +ve integers are handled

#include <iostream>
#include <math.h>
using namespace std;

int scanBitVector(bool* bitvec, int size) {
	for (int i=0; i< size; i++) {
		cout << "Searching if " << i << " exists in bitvector" << endl;
		if (!bitvec[i]) //Still 0
			return i;
	}
	return -1;
}

int findMissing(int* arr, int size) {
	int bitsize = 5;  //We have 1 GB of mem but need only 2 billion bits. For example, we consider a smaller number
	bool bitvector[bitsize]; //By default, initialized to 0

	for (int i = 0; i < size; i++) {
		bitvector[arr[i]] = true;
	}
	return(scanBitVector(bitvector, bitsize));
}

//Assumption : Only distinct integers here in arr
int findMissingWithBlock(int* arr, int size) {
	int blockSize = 3;  //Assume this is the block size
	int numBlocks = ceil(size/blockSize);
	int countArray[numBlocks];
	for (int i=0; i<numBlocks; i++)
		countArray[i] = 0;

	//Populate counts of each block
	int blockID;
	for (int i=0; i<size; i++) {
		blockID = arr[i]/blockSize;
		cout << arr[i] << " has a blockid = " << blockID << endl;
		countArray[blockID]++;
	}

	//Find which block's count < blockSize
	int missingBlock = -1;
	for (int i = 0; i<numBlocks; i++) {
		cout << "count of block " << i << " is " <<  countArray[i] << endl;
		if (countArray[i] < blockSize) {
			missingBlock = i;
			break;
		}
	}

	if (missingBlock == -1) { //No numbers are missing
		cout << "No numbers are missing " << endl;
		return -1;
	}

	//Find which number in missing block is missing
	bool bitvector[blockSize];
	int low = missingBlock*blockSize;
	int high = (missingBlock+1)*blockSize -1;
	cout << "Missing block = " << missingBlock << " with low=" << low << " and high=" << high << endl;
	for (int i=0; i<size; i++) {
		if (low <= arr[i] <= high)
			bitvector[arr[i] - low] = true;
	}
	int offset = scanBitVector(bitvector, blockSize);
	return(offset+low);
}

int main() {
	int arr[] = {1, 2, 9, 4, 0, 7, 8, 3, 5};
	int res = findMissingWithBlock(arr, sizeof(arr)/sizeof(arr[0]));
	cout << "Missing " << res << endl;

	return 0;
}
