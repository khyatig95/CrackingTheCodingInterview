//Algorithm : 	DeepCopyNode : Maintain a map of nodes that are copied. Key =original node, val = copied
//							   If it doesn't exist, recursively add all child nodes to the map
//Time Complexity : O(N) where N is the number of nodes
//Space Complexity : O(N) as we are exactly copying the data structure

#include <iostream>
#include <map>
using namespace std;

class Node {
public :
	Node* n1;
	Node* n2;
	Node(){
		n1 = NULL;
		n2 = NULL;
	}
};

Node* DeepCopyNode(Node* orig, map<Node*, Node*> m1) {
	if (orig == NULL)
		return NULL;

	if (m1.find(orig) != m1.end()) //If map contains orig, return the map
		return(m1[orig]);

	Node* n = new Node();
	m1[orig] = n;
	n->n1 = DeepCopyNode(orig->n1, m1);
	n->n2 = DeepCopyNode(orig->n2, m1);
	return(n);
}

Node* copyNode(Node* orig) {
	map<Node*, Node*> NodeMap;
	return(DeepCopyNode(orig, NodeMap));
}

int main() {
	Node* root = new Node();
	root->n1 = new Node();
	root->n2 = new Node();
	root->n1->n1 = new Node();
	root->n1->n2 = new Node();
	root->n2->n1 = new Node();

	Node* res = copyNode(root);
	if (res == NULL)
		cout << "Root is null" << endl;
	else
		cout << "Root is NOT null" << endl;

	if (res->n1 == NULL)
		cout << "Root->n1 is null" << endl;
	else
		cout << "Root->n1 is NOT null" << endl;

	if (res->n2 == NULL)
		cout << "Root->n2 is null" << endl;
	else
		cout << "Root->n2 is NOT null" << endl;

	if (res->n1->n1 == NULL)
		cout << "Root->n1->n1 is null" << endl;
	else
		cout << "Root->n1->n1 is NOT null" << endl;

	if (res->n1->n2 == NULL)
		cout << "Root->n1->n2 is null" << endl;
	else
		cout << "Root->n1->n2 is NOT null" << endl;

	if (res->n2->n1 == NULL)
			cout << "Root->n2->n1 is null" << endl;
		else
			cout << "Root->n2->n1 is NOT null" << endl;

	if (res->n2->n2 == NULL)
			cout << "Root->n2->n2 is null" << endl;
		else
			cout << "Root->n2->n2 is NOT null" << endl;
	return 0;
}
