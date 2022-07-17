//Algorithm : 	track(X) : Insert an element into BST. Store the size of its left subtree.
//				Time Complexity : O(logN)
// 				getRank(X) : Do inorder traversal and increment rank whenever smaller than/equal to.
//				We start init rank with -1 so it returns with -1 if element doesnt exist and doesnt
//				count towards rank for the number itself
// 				Time Complexity : O(X)

#include <iostream>
using namespace std;

template <typename T>
class RankNode {
public :
	T val;
	RankNode* left;
	RankNode* right;
	int leftSize;
	RankNode(T x) {
		val = x;
		left = NULL;
		right = NULL;
		leftSize = 0;
	}
};

template <typename T>
class RankBST {
private :
	int getRank(T val, RankNode<T>* n, int rank);

public :
	RankNode<T>* root;
	RankBST() {
		root = NULL;
	}
	void insertRankNode(T newVal, RankNode<T>* start);
	bool findRankNode(T newVal);
	RankNode<T>* deleteRankNode(T delVal, RankNode<T>* start);  //returns replacement of the RankNode deleted
	RankNode<T>* getSmallest(RankNode<T>* n);
	void inOrderTraversal(RankNode<T>* n);
	int getRank(T val);
};

template <typename T>
void RankBST<T> :: insertRankNode(T newVal, RankNode<T>* start) {
	if (root == NULL) {
		root = new RankNode<T>(newVal);
		return;
	}

	if (newVal <= start->val) {
		start->leftSize++;
		if (start->left == NULL) {
			start->left = new RankNode<T>(newVal);
			return;
		} else
			insertRankNode(newVal, start->left);
	} else {
		if (start->right == NULL) {
			start->right = new RankNode<T>(newVal);
			return;
		} else
			insertRankNode(newVal, start->right);
	}
}

template <typename T>
bool RankBST<T> :: findRankNode(T newVal) {
	RankNode<T>* n = root;
	while(n != NULL) {
		if (n->val == newVal)
			return true;
		if (newVal < n->val)
			n = n->left;
		else
			n = n->right;
	}
	return false;
}

template <typename T>
RankNode<T>* RankBST<T> :: deleteRankNode(T delVal, RankNode<T>* start) {
	if (root == NULL) {
		cout << "ERROR : Cant delete from an empty tree" << endl;
		return root;
	}

	if (delVal < start->val)
		start->left = deleteRankNode(delVal, start->left);
	else if (delVal > start->val)
		start->right = deleteRankNode(delVal, start->right);
	else { //start's val == delVal
		if (start->left == NULL && start->right == NULL) {
			cout << "Deleting " << delVal << " with no children" << endl;
			delete start;
			return NULL;
		} else if (start->left == NULL) {
			RankNode<T>* temp = start->right;
			cout << "Deleting " << delVal << " with no left child and replacing with " << temp->val << endl;
			delete start;
			return temp;
		} else if (start->right == NULL) {
			RankNode<T>* temp = start->left;
			cout << "Deleting " << delVal << " with no right child and replacing with " << temp->val << endl;
			delete start;
			return temp;
		} else {
		   RankNode<T>* temp = getSmallest(start->right);
		   start->val= temp->val;
		   cout << "Deleting " << delVal << " with both children and replacing with " << temp->val << endl;
		   start->right = deleteRankNode(temp->val, start->right); //Delete the element we are replacing
		}
	}
	return start;
}

template <typename T>
RankNode<T>* RankBST<T> :: getSmallest(RankNode<T>* n) {
	while(n->left != NULL)
		n = n->left;
	return n;
}

template <typename T>
void RankBST<T> :: inOrderTraversal(RankNode<T>* n) {
    if (n == NULL)
        return;
    inOrderTraversal(n->left);
    cout << n->val << ", ";
    inOrderTraversal(n->right);
}

template <typename T>
int RankBST<T> :: getRank(T val) {
	int rank = -1;
	RankNode<T>* n = root;
	if (findRankNode(val)) //exists in the tree
		return(getRank(val, n, rank));
	else
		return rank;
}

template <typename T>
int RankBST<T> :: getRank(T val, RankNode<T>* n, int rank) {
	if (n == NULL)
		return rank;

	if (n->val <= val) {
		cout << "Processing " << n->val << " with leftSize " << n->leftSize << endl;
		rank += n->leftSize+1;
		return(getRank(val, n->right, rank));
	} else
		return(getRank(val, n->left, rank));

}

int main() {
	RankBST<int> tree;

	tree.insertRankNode(5, tree.root);
	tree.insertRankNode(1, tree.root);
	tree.insertRankNode(4, tree.root);
	tree.insertRankNode(4, tree.root);
	tree.insertRankNode(5, tree.root);
	tree.insertRankNode(9, tree.root);
	tree.insertRankNode(7, tree.root);
	tree.insertRankNode(13, tree.root);
	tree.insertRankNode(3, tree.root);
	// 				5
	//			 /     \
	//          1       9
	//           \     / \
	//            4   7   13
	//           / \
	//          4   5
	//         /
	//        3


	cout << "Tree is " << endl;
	tree.inOrderTraversal(tree.root);
	cout << endl;


	int val = 100;
	int res = tree.getRank(val);
	cout << "Rank of " << val << " is " << res << endl;

	return 0;
}
