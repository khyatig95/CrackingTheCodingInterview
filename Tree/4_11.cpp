{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;\red0\green80\blue50;\red0\green0\blue192;\red100\green40\blue128;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm :   getRandomNode : Store the size of subtree for each node. Generate a random number.\cf0 \
\cf2 //				When size of a node == random number, return that node\cf0 \
\cf2 //				Time Complexity : O(d) where d=depth of tree\cf0 \
\cf2 //              Space Complexity : O(d) due to recursion where d=depth of tree\cf0 \
\cf2 //Assumption :  Tree is made of integers. Tree is BST\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <cstdlib>\cf0 \
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 class
\f0\b0 \cf0  \cf6 Node\cf0  \{\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	
\f1\b \cf5 T
\f0\b0 \cf0  \cf7 val\cf0 ;\
	\cf6 Node\cf0 * \cf7 left\cf0 ;\
	\cf6 Node\cf0 * \cf7 right\cf0 ;\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf7 size\cf0 ;\
\
	
\f1\b Node
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  x) \{\
		\cf7 val\cf0  = x;\
		\cf7 left\cf0  = NULL;\
		\cf7 right\cf0  = NULL;\
		\cf7 size\cf0  = 1;\
	\}\
\};\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 class
\f0\b0 \cf0  \cf6 BinaryTree\cf0  \{\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* \cf7 root\cf0 ;\
	
\f1\b BinaryTree
\f0\b0 () \{\
		\cf7 root\cf0  = NULL;\
	\}\
\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b insertNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  newVal, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* start);\
	
\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b findNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  newVal);\
	\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b getRandomNode
\f0\b0 ();\
	\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b getIthNode
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  index, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* start);\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b inOrderTraversal
\f0\b0 (\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n);\
\};\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\
\pard\pardeftab720
\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b BinaryTree<T> :: getRandomNode
\f0\b0 () \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (\cf7 root\cf0  == NULL) \{\
		cout << \cf4 "ERROR: Tree is NULL"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  NULL;\
	\}\
	
\f1\b \cf8 srand
\f0\b0 \cf0 (
\f1\b \cf8 time
\f0\b0 \cf0 (0));\
\
	
\f1\b \cf3 int
\f0\b0 \cf0  i = 1 + (
\f1\b \cf8 rand
\f0\b0 \cf0 () % \cf7 root\cf0 ->\cf7 size\cf0 );\
	cout << \cf4 "Random number is "\cf0  << i << endl;\
	
\f1\b \cf3 return
\f0\b0 \cf0 (getIthNode(i, \cf7 root\cf0 ));\
\}\
\
\pard\pardeftab720

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\
\pard\pardeftab720
\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b BinaryTree<T> :: getIthNode
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  index, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* start) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  leftSize = (start->\cf7 left\cf0  == NULL) ? 0 : start->\cf7 left\cf0 ->\cf7 size\cf0 ;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (index == start->\cf7 size\cf0 )\
		
\f1\b \cf3 return
\f0\b0 \cf0  start;\
	
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  (index <= leftSize)\
		
\f1\b \cf3 return
\f0\b0 \cf0 (getIthNode(index, start->\cf7 left\cf0 ));\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0 (getIthNode((start->\cf7 size\cf0 -index), start->\cf7 right\cf0 ));\
\}\
\
\pard\pardeftab720

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b BinaryTree<T> :: insertNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  newVal, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* start) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (\cf7 root\cf0  == NULL) \{\
		\cf7 root\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >(newVal);\
		
\f1\b \cf3 return
\f0\b0 \cf0 ;\
	\}\
	start->\cf7 size\cf0 ++;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (newVal <= start->\cf7 val\cf0 ) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (start->\cf7 left\cf0  == NULL) \{\
			start->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >(newVal);\
			
\f1\b \cf3 return
\f0\b0 \cf0 ;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0 \
			insertNode(newVal, start->\cf7 left\cf0 );\
	\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (start->\cf7 right\cf0  == NULL) \{\
			start->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >(newVal);\
			
\f1\b \cf3 return
\f0\b0 \cf0 ;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0 \
			insertNode(newVal, start->\cf7 right\cf0 );\
	\}\
\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b BinaryTree<T> :: findNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  newVal) \{\
	\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n = \cf7 root\cf0 ;\
	
\f1\b \cf3 while
\f0\b0 \cf0 (n != NULL) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (n->\cf7 val\cf0  == newVal)\
			
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ;\
		
\f1\b \cf3 if
\f0\b0 \cf0  (newVal < n->\cf7 val\cf0 )\
			n = n->\cf7 left\cf0 ;\
		
\f1\b \cf3 else
\f0\b0 \cf0 \
			n = n->\cf7 right\cf0 ;\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b BinaryTree<T> :: inOrderTraversal
\f0\b0 (\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n) \{\
    
\f1\b \cf3 if
\f0\b0 \cf0  (n == NULL)\
        
\f1\b \cf3 return
\f0\b0 \cf0 ;\
    inOrderTraversal(n->\cf7 left\cf0 );\
    cout << n->\cf7 val\cf0  << \cf4 ", "\cf0 ;\
    inOrderTraversal(n->\cf7 right\cf0 );\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //Creating test tree\cf0 \
	\cf2 //        8(6)\cf0 \
	\cf2 //      /   \\\cf0 \
\pard\pardeftab720
\cf2 	//     5(2) 25(3)\cf0 \
	\cf2 //    /      /\cf0 \
	\cf2 //  -1(1)   15(2)\cf0 \
	\cf2 //           \\\cf0 \
\cf2 	//           16(1)\cf0 \
\
	\cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* tree1 = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >();\
	tree1->insertNode(8, tree1->\cf7 root\cf0 );\
	tree1->insertNode(5, tree1->\cf7 root\cf0 );\
	tree1->insertNode(-1, tree1->\cf7 root\cf0 );\
	tree1->insertNode(25, tree1->\cf7 root\cf0 );\
	tree1->insertNode(15, tree1->\cf7 root\cf0 );\
	tree1->insertNode(16, tree1->\cf7 root\cf0 );\
\
	cout << \cf4 "Root is "\cf0  << tree1->\cf7 root\cf0 ->\cf7 val\cf0  << \cf4 " with size = "\cf0  << tree1->\cf7 root\cf0 ->\cf7 size\cf0  << endl;\
	cout << \cf4 "Root->left is "\cf0  << tree1->\cf7 root\cf0 ->\cf7 left\cf0 ->\cf7 val\cf0  << \cf4 " with size = "\cf0  << tree1->\cf7 root\cf0 ->\cf7 left\cf0 ->\cf7 size\cf0  << endl;\
	cout << \cf4 "Root->right is "\cf0  << tree1->\cf7 root\cf0 ->\cf7 right\cf0 ->\cf7 val\cf0  << \cf4 " with size = "\cf0  << tree1->\cf7 root\cf0 ->\cf7 right\cf0 ->\cf7 size\cf0  << endl;\
	cout << \cf4 "Root->left->left is "\cf0  << tree1->\cf7 root\cf0 ->\cf7 left\cf0 ->\cf7 left\cf0 ->\cf7 val\cf0  << \cf4 " with size = "\cf0  << tree1->\cf7 root\cf0 ->\cf7 left\cf0 ->\cf7 left\cf0 ->\cf7 size\cf0  << endl;\
	cout << \cf4 "Root->right->left is "\cf0  << tree1->\cf7 root\cf0 ->\cf7 right\cf0 ->\cf7 left\cf0 ->\cf7 val\cf0  << \cf4 " with size = "\cf0  << tree1->\cf7 root\cf0 ->\cf7 right\cf0 ->\cf7 left\cf0 ->\cf7 size\cf0  << endl;\
	cout << \cf4 "Root->right->left->right is "\cf0  << tree1->\cf7 root\cf0 ->\cf7 right\cf0 ->\cf7 left\cf0 ->\cf7 right\cf0 ->\cf7 val\cf0  << \cf4 " with size = "\cf0  << tree1->\cf7 root\cf0 ->\cf7 right\cf0 ->\cf7 left\cf0 ->right->size << endl;\
\
	tree1->inOrderTraversal(tree1->\cf7 root\cf0 );\
	cout << endl;\
\
	\cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* res = tree1->getRandomNode();\
	cout << \cf4 "Random node is "\cf0  << res->\cf7 val\cf0  << endl;\
    
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}