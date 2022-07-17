//You are given an array-like data structure Listy which lacks a size method.
//It does, however, have an elementAt ( i) method that returns the element at index i in 0( 1) time.
//If i is beyond the bounds of the data structure, it returns -1.
//(For this reason, the data structure only supports positive integers.)
//Assumption : Listy only contains integers

class Listy {
	private :
		int* ListyArr; //Dynamic Array
		int ListySize;
	public :
		Listy() {
			ListySize = 0;
		}
		int elementAt(int index);
		void assignListy(int *arr, int size);
		void printArr(int* arr, int size);
};

int Listy :: elementAt(int index) {
	if (index >= ListySize)
		return -1;
	return(ListyArr[index]);
}

void Listy :: assignListy(int *arr, int size) {
	cout << "Input array is " << endl;
	printArr(arr, size);
	ListySize = size;
	ListyArr = new int(ListySize);
	for (int i = 0; i < size ; i++) {
		if (arr[i] < 0)
			ListyArr[i] = arr[i]*(-1); //Listy supports only +ve vals
		else
			ListyArr[i] = arr[i];
	}
	printArr(ListyArr, ListySize);
}

void Listy :: printArr(int* arr, int size) {
	cout << "[ " ;
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}
