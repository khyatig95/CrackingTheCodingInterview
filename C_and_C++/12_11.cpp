//Algorithm : 	2DAlloc : Create an array of pointers with size = rows*(int*). Create a contiguous block of memory
//				with size = row*col*sizeof(int). This way, you only delete the rowptr
//Assumption : Arrays are of type int

#include <iostream>
using namespace std;

int** TwoDAlloc(int rows, int cols) {
	int sizeRowPtr = rows*sizeof(int*); //Contains pointers to each row
	int sizeMatrix = rows*cols*sizeof(int); //Contains all the elements of the Matrix

	int** rowptr = (int**) malloc(sizeRowPtr+sizeMatrix);

	int* offset = (int*) (rowptr+rows); //Index of ptr to the first element in the matrix
	for(int i=0; i<rows; i++)
		rowptr[i] = offset + i*cols;
	return rowptr;
}

int main() {
	int rows = 5;
	int cols = 6;
	int** ptr = TwoDAlloc(rows, cols);
	cout << "Size of int* = " << sizeof(int*) << endl;
	cout << "Size of int = " << sizeof(int) << endl;

	cout << "These should be spaced by cols*sizeof(int)" << endl;
	for(int i=0; i<rows; i++)
		cout << "Row " << i << " = " << size_t(ptr[i]) << endl;

	//Free up space
	delete ptr;

	return 0;
}
