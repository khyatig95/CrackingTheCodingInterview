//Algorithm :   validateBST : Recursively pass min/max values of each node to satisfy BST
//              Time Complexity : O(N) ; Space Complexity : O(H) where H is the height of tree due to recursion
//              isBST : Returns true if validateBST returns true
//Assumption : Node vals are integers

using namespace std;
#include <iostream>
#include "BinaryTree.h"
#include <limits.h>

bool validateBST(Node<int>* n, int min, int max) {
    if (n == NULL) {
        return true;
    } 
    if (n->val > min && n->val <= max) {
        if (!validateBST(n->left, min, n->val))
            return false;
        if (!validateBST(n->right, n->val, max))
            return false;
        return true;
    } else 
        return false;
}

bool isBST(BinaryTree<int>* tree) {
    if (tree->root == NULL) {
        cout << "ERROR: Tree is empty!" << endl;
        return false;
    }
    return(validateBST(tree->root, INT_MIN, INT_MAX));
}
    
int main() {
    //Creating test tree manually
    //        10
    //      /    \ 
    //    11      9
    //   /  \    / 
    //  7   12  15    
    //           \
    //           13
    BinaryTree<int> tree1;
    
    tree1.root = new Node<int>(10);
    tree1.root->left = new Node<int>(11);
    tree1.root->left->left = new Node<int>(7);
    tree1.root->left->right = new Node<int>(12);
    tree1.root->right = new Node<int>(9);
    tree1.root->right->left = new Node<int>(15);
    tree1.root->right->left->right = new Node<int>(13);

    //Creating test tree manually
    //         8
    //      /    \
    //     5      25
    //   /  \    / 
    // -1    8  15    
    //           \
    //           16
    BinaryTree<int> tree2;
    
    tree2.root = new Node<int>(8);
    tree2.root->left = new Node<int>(5);
    tree2.root->left->left = new Node<int>(-1);
    tree2.root->left->right = new Node<int>(8);
    tree2.root->right = new Node<int>(25);
    tree2.root->right->left = new Node<int>(15);
    tree2.root->right->left->right = new Node<int>(16);

    //No element
    //Single element
    //BST tree
    //Non-BST Tree
    
    if (isBST(&tree2))
        cout << "Tree is BST" << endl;
    else
        cout << "Tree is NOT BST" << endl;
 
    return 0;
}
