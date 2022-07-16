//Algorithm :   calcH : Does a DFS to calculate height. If at any level
//              the subtrees are not balanced, we return ERRORVAL that is passed
//              to above recursion calls. 
//              Time Complexity : O(N) ; Space Complexity : O(H) where H is height of tree due to recursion stack 
//              isBalanced : checks return value of calcH. If it is equal to ERRORVAL =>not balanced

using namespace std;
#include <iostream>
#include "BinaryTree.h"
#define ERRORVAL -200
#include <cstdlib>
#include <algorithm>

template <typename T>
int calcH(Node<T>* n) {
    if (n == NULL)
        return 0;
        
    int leftH = calcH(n->left);
    if (leftH == ERRORVAL)
        return ERRORVAL;
    int rightH = calcH(n->right);
    if (rightH == ERRORVAL)
        return ERRORVAL;
    
    if(abs(leftH-rightH) > 1)
        return ERRORVAL;
    else
        return(max(leftH, rightH) + 1);
}    

template <typename T> 
bool isBalanced(BinaryTree<T>* tree) {
    if (tree->root == NULL) {
        cout << "ERROR: Tree is empty!!" << endl;
        return false;
    }
    if (calcH(tree->root) == ERRORVAL) {
        cout << "Tree is NOT balanced" << endl;
        return false;
    } 
    cout << "Tree is balanced" << endl;
    return true;
}
    
int main() {
    //Creating test tree manually
    //        10
    //      /    
    //    11      9
    //   /      / 
    //  7   12  15    
    //           
    //           13
    BinaryTree<int> tree1;
    tree1.root = new Node<int>(10);
    tree1.root->left = new Node<int>(11);
    tree1.root->left->left = new Node<int>(7);
    tree1.root->left->right = new Node<int>(12);
    tree1.root->right = new Node<int>(9);
    tree1.root->right->left = new Node<int>(15);
    tree1.root->right->left->right = new Node<int>(13);

    //No element
    //Single element
    //Balanced tree
    //Unbalanced Tree
    
    isBalanced(&tree1);
 
    return 0;
}
