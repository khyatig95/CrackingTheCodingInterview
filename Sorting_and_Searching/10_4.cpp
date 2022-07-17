//Algorithm : 	findElement : Guess the size by starting with 2, 4 and going exponential.
//Time Complexity : O(logN) 
//Space Complexity : O(1)
//			BinarySearch : Do binary search
//Time Complexity : O(logN) 
//Space Complexity : O(1)
//Assumption : Listy will always be sorted.

#include <iostream>
using namespace std;
#include "Listy.h"

int BinarySearch(Listy* lis, int start, int end, int val) {
	if (start > end)
		return -1;

	int mid = (start+end)/2;
	if (lis->elementAt(mid) == val)
		return mid;
	if ((lis->elementAt(mid) > val) || (lis->elementAt(mid) == -1))
		return(BinarySearch(lis, start, mid-1, val));
	else
		return (BinarySearch(lis, mid+1, end, val));
}

int findElement(Listy* lis, int val) {
	if (val < 0) { //Listy contains only +ve numbers
		cout << "ERROR : Trying to find a negative number " << val << " in Listy" << endl;
		return -1;
	}

	//Find Size
	int guess = 1;
	while((lis->elementAt(guess) != - 1) && (lis->elementAt(guess) < val))
		guess = guess*2;
	cout << "Guess is " << guess << " with element at guess = " << lis->elementAt(guess) << endl;

	//BinarySearch
	return(BinarySearch(lis, guess/2, guess, val)); //guess can be either be out of bound or >= val
}

int main() {
	int arr[7] = {0, 2, 5, 7, 34, 52, 105};
	Listy* listy = new Listy();
	listy->assignListy(arr, 7);

	//val is negative
	//val is edge
	int val = 105;
	int res = findElement(listy, val);
	if (res == -1)
		cout << val << " not found!" << endl;
	else
		cout << val << " found at " << res << endl;

	return 0;
}
