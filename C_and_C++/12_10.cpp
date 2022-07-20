//Algorithm : 	allignedMalloc : Malloc a memory of size+alignment. There will be one address that starts with
//				the alignment. Pick that address and return it. Store the original ptr that allocates the memory
//				at one location above the aligned address. Thus we can delete it easily.
//Space Complexity : O(M+A) where M=size of memory; A = alignemnt

#include <iostream>
using namespace std;

void* alignedMalloc(size_t size, size_t alignment) {
	int offset = alignment-1+sizeof(void*);
	void* p = (void*)malloc(size+offset);
	cout << "p=" << size_t(p) << endl;
	if (p == NULL) {
		cout << "Not enough space!" << endl;
		return NULL;
	}
	void* q = (void*) ((size_t(p)+offset)&~(alignment-1));  	//p+offset as that is the biggest number.
													//anding with 111..00.. will reduce the number
	((void**)q)[-1] = p; //void** is an array of void pointers
	return q;

}

void alignedFree(void* startAddr) {
	void* p = ((void**)startAddr)[-1];
	cout << "p=" << size_t(p) << endl;
	free(p);
}

int main() {
	void* k = alignedMalloc(1000, 128);
	cout << "Aligned address is " << size_t(k) << endl;
	alignedFree(k);
	return 0;
}
