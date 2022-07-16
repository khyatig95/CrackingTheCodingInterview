//Algorithm :  createMinimalTree : This will push the mid element into the root. 
//             All elements before the mid element go in the left subtree and vice versa. 
//             Time Complexity : O(N) ; Space Complexity : O(H) where H is height of tree due to recursive calls
//Assumption : We know the size of the array and the array is sorted

using namespace std;
#include <iostream>
#include "BinaryTree.h"

template <typename T>
Node<T>* createMinimalBST(T* arr, int start, int end, int SIZE) {
    Node<T>* root = NULL;

    if (SIZE == 0) {
        cout << "Array is empty, return NULL tree" << endl;
        return root;
    } 
    //Base case
    if (end < start) 
        return root; //return NULL
    
    int mid = (end-start)/2 + start;
    root = new Node<T>(arr[mid]);
    root->left = createMinimalBST(arr, start, mid-1, SIZE);
    root->right = createMinimalBST(arr, mid+1, end, SIZE);
    return root;
}

int main() {
    //No element
    //Single element
    //Two elements
    //Three elements
    //Perfect tree
    //Even size
    //Odd size
    int SIZE = 7;
    int test[SIZE] = {0, 1, 2, 3, 4, 5, 6};
    BinaryTree<int> tree1; 
    tree1.root = createMinimalBST<int>(test, 0, SIZE-1, SIZE);
    cout << "Minimal BST : " << endl;
    tree1.inOrderTraversal(tree1.root);
    cout << endl;

    return 0;
}
