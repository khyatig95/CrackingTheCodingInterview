//Algorithm : 	sortedMatrixSearch : Check the diagonal mid and mid-1 index. Search through the 2 quadrants
//				recursively
//Time complexity : O(M*N)
//Assumption : 	The matrix will be sorted and made of integers.

#include <iostream>
using namespace std;
//Rectangle Matrix
//Square Matrix
#define ROWS 4
#define COLS 5

class Coordinate {
public :
	int row;
	int col;
	Coordinate(int r, int c) {
		row = r;
		col = c;
	}
	bool isGreater(Coordinate* x) {
		if ((x->row < row) || (x->col < col))
			return true;
		return false;
	}
	void print() {
		cout << "(" << row << ", " << col << ")" << endl;
	}
	bool isEqual(Coordinate* x) {
		if ((x->row == row) && (x->col == col))
			return true;
		return false;
	}
	bool isLegal() {
		if (row < 0 || col <0)
			return false;
		if (row>=ROWS || col>=COLS)
			return false;
		return true;
	}
};

Coordinate* sortedMatrixSearch(int (&arr)[ROWS][COLS], int x, Coordinate* origin, Coordinate* dest) {
	cout << endl;
	Coordinate* error= new Coordinate(-1, -1);
	if (origin->isGreater(dest)) {
		return error;
	}
	if (!origin->isLegal() || !dest->isLegal())
		return error;
	cout << "origin : " << arr[origin->row][origin->col] << " at " << endl;
		origin->print();
	cout << "dest : " << arr[dest->row][dest->col] << " at " << endl;
		dest->print();

		//If Matrix is just one element
	if (origin->isEqual(dest)) {
		if (arr[origin->row][origin->col] == x)
			return origin;
		else
			return error;
	}


	Coordinate* mid = new Coordinate((origin->row+dest->row)/2, (origin->col+dest->col)/2);
	cout << "mid : " << arr[mid->row][mid->col] << " at " << endl;
	mid->print();

	if (arr[mid->row][mid->col] == x)
			return mid;

	if (x > arr[mid->row][mid->col]) {
		//Search Lower
		cout << "Search Lower" << endl;
		Coordinate* LOrigin = new Coordinate(mid->row+1, origin->col);
		Coordinate* LDest = dest;
		Coordinate* res = sortedMatrixSearch(arr, x, LOrigin, LDest);
		if (res->isEqual(error)) {
			//Search Upper Right
			cout << "Search Upper Right" << endl;
			Coordinate* UROrigin = new Coordinate(origin->row, mid->col+1);
			Coordinate* URDest = new Coordinate(mid->row, dest->col);
			return(sortedMatrixSearch(arr, x, UROrigin, URDest));
		} else
			return res;
	} else if (x < arr[mid->row][mid->col]) {
		//Search Upper
		cout << "Search Upper" << endl;
		Coordinate* UOrigin = origin;
		Coordinate* UDest = new Coordinate(mid->row-1, dest->col);
		Coordinate* res = sortedMatrixSearch(arr, x, UOrigin, UDest);
		if (res->isEqual(error)) {
			//Search Lower Left
			cout << "Search Lower Left" << endl;
			Coordinate* LLOrigin = new Coordinate(mid->row, origin->col);
			Coordinate* LLDest = new Coordinate(dest->row, mid->col-1);
			return(sortedMatrixSearch(arr, x, LLOrigin, LLDest));
		} else
			return res;
	}
	return error;
}


int main() {
	//With Duplicates : Square
	/*int matrix[ROWS][COLS] = {	{15, 20, 70, 85},
								{25, 35, 80, 95},
								{30, 55, 95, 105},
								{40, 80, 120, 120}
							 };
	*/
	//With Duplicates : Rectangle (rows>cols)
	/*int matrix[ROWS][COLS] = {	{15, 20, 70, 85},
								{25, 35, 80, 95},
								{30, 55, 95, 105},
								{40, 80, 120, 120},
								{45, 85, 125, 130}
							 };
	*/
	//With Duplicates : Rectangle (cols>rows)
	/*int matrix[ROWS][COLS] = {	{15, 20, 70, 85, 100},
								{25, 35, 80, 95, 105},
								{30, 55, 95, 105, 110},
								{40, 80, 120, 120, 130}
							};*/
	//Without Duplicates : Square
	/*int matrix[ROWS][COLS] = {	{15, 20, 70, 85},
								{25, 35, 80, 95},
								{30, 55, 104,105},
								{40, 100,110,120}
							 };*/
	//Without Duplicates : Rectangle (rows>cols)
	/*int matrix[ROWS][COLS] = {	{15, 20, 70, 85},
								{25, 35, 80, 95},
								{30, 55, 104,105},
								{40, 100,110,120},
								{45, 106,125,130}
							 };*/
	//Without Duplicates : Rectangle (cols>rows)
	int matrix[ROWS][COLS] = {	{15, 20, 70, 85, 86},
								{25, 35, 80, 95, 96},
								{30, 55, 104,105, 106},
								{40, 100,110,120, 121},
							 };
	Coordinate* origin = new Coordinate(0, 0);
	Coordinate* dest = new Coordinate(ROWS-1, COLS-1);
	int val = 121;
	Coordinate* res = sortedMatrixSearch(matrix, val, origin, dest);
	cout << "Found " << val << " at " << endl;
	res->print();
	return 0;
}
