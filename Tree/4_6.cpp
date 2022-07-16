//Algorithm :   getNext : The next node is decided by the in order traversal
//              Time Complexity : O(1) ; Space Complexity : O(1) 
//Assumption : Input tree is a BST. Vals are integers. Links to parents are available

using namespace std;
#include <iostream>

class Node {
    public : 
        int val;
        Node* left;
        Node* right;
        Node* parent;
        
        Node(int x) {
            val = x;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
};

Node* getLeftMostChild(Node* n) {
    while (n->left != NULL)
        n = n->left;
    return n;
}

Node* getNext(Node* n) {
    if (n->right != NULL)
        return getLeftMostChild(n->right);
    Node* p = n->parent;
    if (p == NULL)
        return NULL;
    if (p->left == n) //current node is the left child
        return p;
    if (p->right == n) { //current node is the right child
        Node* gp = p->parent;
        return gp;
    }
}



int main() {

    //Creating test tree manually
    //         8
    //      /    
    //     5      25
    //   /      / 
    // -1    8  15    
    //           
    //           16
    Node* root;
    
    root = new Node(8);
    root->left = new Node(5);
    root->left->parent = root;
    root->left->left = new Node(-1);
    root->left->left->parent = root->left;
    root->left->right = new Node(8);
    root->left->right->parent = root->left;
    root->right = new Node(25);
    root->right->parent = root;
    root->right->left = new Node(15);
    root->right->left->parent = root->right;
    root->right->left->right = new Node(16);
    root->right->left->right->parent = root->right->left;

    //Root 
    //Leftmost
    //Rightmost
    //Any random
    Node* now = root->right->left->right;
    if (getNext(now) == NULL)
        cout << "Next element to " << now->val << " is NULL" << endl;
    else
        cout << "Next element to " << now->val << " is " << getNext(now)->val << endl;
 
    return 0;
}
