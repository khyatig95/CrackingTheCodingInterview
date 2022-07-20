//Algorithm : 	LastKLines : Use a circular array of size K and keep overwriting the oldest one.
//Time Complexity : O(N) where N=lines in the file
//Space Complexity : O(K)

#include <iostream>
#include <fstream>
#include <string>
#include "CircularArray.h"
using namespace std;

void LastKLines(int K) {
	if (K==0)
		return;
	string line;
	int index = 0;
	CircularArray<string>* circ = new CircularArray<string>(K);
	ifstream infile("/Users/Khyati/eclipse-workspace/Sample/src/example.txt");
	if (infile.is_open()) {
		while(getline(infile, line)) {
			circ->setArr(index%K, line);
			index++;
		}
		circ->print();
	} else
		cout << "ERROR : Unable to open file" << endl;

	//delete the ptr created always
	delete circ;
}

int main() {

	LastKLines(0);

	return 0;
}
