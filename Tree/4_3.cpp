//Algorithm :  ListofDepthsBFS : Does BFS. Not recursive. Iterates through
//             children of the current nodes to generate the list of nodes
//             in the next level
//             Time Complexity : O(N) ; Space Complexity : O(1) 
//             ListofDepthsDFS : Does DFS. Recursive. Each node stores its 
//             children in the next level index by passing its index.
//             Time Complexity : O(N) ; Space Complexity : O(H) where H is height of tree due to recursion

using namespace std;
#include <iostream>
#include <vector>
#include <list>
#include "BinaryTree.h"

template <typename T>
void ListofDepthsBFS(BinaryTree<T>* tree, vector<list<Node<T>*>>* vec) {
    if (tree->root == NULL) {
        cout << "ERROR: Tree is empty!" << endl;
        return;
    }
    list<Node<T>*> current;
    current.push_back(tree->root);
    while(!current.empty()) {
        list<Node<T>*> parent;
        parent = current;
        vec->push_back(current);
        current.clear(); //Empty current list
        for(auto itr = parent.begin(); itr != parent.end(); ++itr) {
            Node<T>* temp = *itr;
            if (temp->left != NULL)
                current.push_back(temp->left);
            if (temp->right != NULL)
                current.push_back(temp->right);
        }
    }
}

template <typename T>
void ListofDepthsDFS(Node<T>* n, int level, vector<list<Node<T>*>>* vec) {
    if (n == NULL)
        return;
    vector<list<Node<T>*>> actualVec = *vec; //Dereference to get the actual vector
    if (vec->size() <= level) { //No entry for this level in vector
        list<Node<T>*> temp;
        temp.push_back(n);
        vec->push_back(temp);
    } else {
        actualVec[level].push_back(n);
        vec = &actualVec;
    }
    if (n->left != NULL)
        ListofDepthsDFS(n->left, level+1, vec);
    if (n->right != NULL)
        ListofDepthsDFS(n->right, level+1, vec);
}    
    
int main() {
    //Creating test tree manually
    //        10
    //      /    \
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
    //Perfect tree
    //Random Tree
    vector<list<Node<int>*>> vec;
    ListofDepthsBFS(&tree1, &vec);
    cout << "BFS result : " << endl;
    for(int i=0; i < vec.size(); ++i) {
        cout << "Nodes at level " << i << " : " << endl;
        for (auto itr = vec[i].begin(); itr != vec[i].end(); ++itr) {
            Node<int>* ntemp = *itr;
            cout << ntemp->val << " ";
        }
        cout << endl;
    }
    cout << endl;
    ListofDepthsDFS(tree1.root, 0, &vec);
    cout << "DFS result : " << endl;
    for(int i=0; i < vec.size(); ++i) {
        cout << "Nodes at level " << i << " : " << endl;
        for (auto itr = vec[i].begin(); itr != vec[i].end(); ++itr) {
            Node<int>* ntemp = *itr;
            cout << ntemp->val << " ";
        }
        cout << endl;
    }
    return 0;
}
