{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww28300\viewh14680\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	track(X) : Insert an element into BST. Store the size of its left subtree.\cf0 \
\cf2 //				Time Complexity : O(logN)\cf0 \
\cf2 // 				getRank(X) : Do \ul inorder\ulnone  traversal and increment rank whenever smaller than/equal to.\cf0 \
\cf2 //				We start \ul init\ulnone  rank with -1 so it returns with -1 if element \ul doesnt\ulnone  exist and \ul doesnt\cf0 \ulnone \
\cf2 //				count towards rank for the number itself\cf0 \
\cf2 // 				Time Complexity : O(X)\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 class
\f0\b0 \cf0  \cf6 RankNode\cf0  \{\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	
\f1\b \cf5 T
\f0\b0 \cf0  \cf7 val\cf0 ;\
	\cf6 RankNode\cf0 * \cf7 left\cf0 ;\
	\cf6 RankNode\cf0 * \cf7 right\cf0 ;\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf7 leftSize\cf0 ;\
	
\f1\b RankNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  x) \{\
		\cf7 val\cf0  = x;\
		\cf7 left\cf0  = NULL;\
		\cf7 right\cf0  = NULL;\
		\cf7 leftSize\cf0  = 0;\
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
\f0\b0 \cf0  \cf6 RankBST\cf0  \{\

\f1\b \cf3 private
\f0\b0 \cf0  :\
	
\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b getRank
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  val, \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n, 
\f1\b \cf3 int
\f0\b0 \cf0  rank);\
\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* \cf7 root\cf0 ;\
	
\f1\b RankBST
\f0\b0 () \{\
		\cf7 root\cf0  = NULL;\
	\}\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b insertRankNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  newVal, \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* start);\
	
\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b findRankNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  newVal);\
	\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b deleteRankNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  delVal, \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* start);  \cf2 //returns replacement of the RankNode deleted\cf0 \
	\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b getSmallest
\f0\b0 (\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n);\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b inOrderTraversal
\f0\b0 (\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n);\
	
\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b getRank
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  val);\
\};\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b RankBST<T> :: insertRankNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  newVal, \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* start) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (\cf7 root\cf0  == NULL) \{\
		\cf7 root\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >(newVal);\
		
\f1\b \cf3 return
\f0\b0 \cf0 ;\
	\}\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (newVal <= start->\cf7 val\cf0 ) \{\
		start->\cf7 leftSize\cf0 ++;\
		
\f1\b \cf3 if
\f0\b0 \cf0  (start->\cf7 left\cf0  == NULL) \{\
			start->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >(newVal);\
			
\f1\b \cf3 return
\f0\b0 \cf0 ;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0 \
			insertRankNode(newVal, start->\cf7 left\cf0 );\
	\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (start->\cf7 right\cf0  == NULL) \{\
			start->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >(newVal);\
			
\f1\b \cf3 return
\f0\b0 \cf0 ;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0 \
			insertRankNode(newVal, start->\cf7 right\cf0 );\
	\}\
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
\f1\b RankBST<T> :: findRankNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  newVal) \{\
	\cf6 RankNode\cf0 <
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
\pard\pardeftab720
\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b RankBST<T> :: deleteRankNode
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  delVal, \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* start) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (\cf7 root\cf0  == NULL) \{\
		cout << \cf4 "ERROR : \ul Cant\ulnone  delete from an empty tree"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  \cf7 root\cf0 ;\
	\}\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (delVal < start->\cf7 val\cf0 )\
		start->\cf7 left\cf0  = deleteRankNode(delVal, start->\cf7 left\cf0 );\
	
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  (delVal > start->\cf7 val\cf0 )\
		start->\cf7 right\cf0  = deleteRankNode(delVal, start->\cf7 right\cf0 );\
	
\f1\b \cf3 else
\f0\b0 \cf0  \{ \cf2 //start's \ul val\ulnone  == delVal\cf0 \
		
\f1\b \cf3 if
\f0\b0 \cf0  (start->\cf7 left\cf0  == NULL && start->\cf7 right\cf0  == NULL) \{\
			cout << \cf4 "Deleting "\cf0  << delVal << \cf4 " with no children"\cf0  << endl;\
			
\f1\b \cf3 delete
\f0\b0 \cf0  start;\
			
\f1\b \cf3 return
\f0\b0 \cf0  NULL;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  (start->\cf7 left\cf0  == NULL) \{\
			\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* temp = start->\cf7 right\cf0 ;\
			cout << \cf4 "Deleting "\cf0  << delVal << \cf4 " with no left child and replacing with "\cf0  << temp->\cf7 val\cf0  << endl;\
			
\f1\b \cf3 delete
\f0\b0 \cf0  start;\
			
\f1\b \cf3 return
\f0\b0 \cf0  temp;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  (start->\cf7 right\cf0  == NULL) \{\
			\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* temp = start->\cf7 left\cf0 ;\
			cout << \cf4 "Deleting "\cf0  << delVal << \cf4 " with no right child and replacing with "\cf0  << temp->\cf7 val\cf0  << endl;\
			
\f1\b \cf3 delete
\f0\b0 \cf0  start;\
			
\f1\b \cf3 return
\f0\b0 \cf0  temp;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
		   \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* temp = getSmallest(start->\cf7 right\cf0 );\
		   start->\cf7 val\cf0 = temp->\cf7 val\cf0 ;\
		   cout << \cf4 "Deleting "\cf0  << delVal << \cf4 " with both children and replacing with "\cf0  << temp->\cf7 val\cf0  << endl;\
		   start->\cf7 right\cf0  = deleteRankNode(temp->\cf7 val\cf0 , start->\cf7 right\cf0 ); \cf2 //Delete the element we are replacing\cf0 \
		\}\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  start;\
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
\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b RankBST<T> :: getSmallest
\f0\b0 (\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n) \{\
	
\f1\b \cf3 while
\f0\b0 \cf0 (n->\cf7 left\cf0  != NULL)\
		n = n->\cf7 left\cf0 ;\
	
\f1\b \cf3 return
\f0\b0 \cf0  n;\
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
\f1\b RankBST<T> :: inOrderTraversal
\f0\b0 (\cf6 RankNode\cf0 <
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

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b RankBST<T> :: getRank
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  val) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  rank = -1;\
	\cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n = \cf7 root\cf0 ;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (findRankNode(val)) \cf2 //exists in the tree\cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0 (getRank(val, n, rank));\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0  rank;\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b RankBST<T> :: getRank
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  val, \cf6 RankNode\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n, 
\f1\b \cf3 int
\f0\b0 \cf0  rank) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (n == NULL)\
		
\f1\b \cf3 return
\f0\b0 \cf0  rank;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (n->\cf7 val\cf0  <= val) \{\
		cout << \cf4 "Processing "\cf0  << n->\cf7 val\cf0  << \cf4 " with leftSize "\cf0  << n->\cf7 leftSize\cf0  << endl;\
		rank += n->\cf7 leftSize\cf0 +1;\
		
\f1\b \cf3 return
\f0\b0 \cf0 (getRank(val, n->\cf7 right\cf0 , rank));\
	\} 
\f1\b \cf3 else
\f0\b0 \cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0 (getRank(val, n->\cf7 left\cf0 , rank));\
\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf6 RankBST\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 > tree;\
\
	tree.insertRankNode(5, tree.\cf7 root\cf0 );\
	tree.insertRankNode(1, tree.\cf7 root\cf0 );\
	tree.insertRankNode(4, tree.\cf7 root\cf0 );\
	tree.insertRankNode(4, tree.\cf7 root\cf0 );\
	tree.insertRankNode(5, tree.\cf7 root\cf0 );\
	tree.insertRankNode(9, tree.\cf7 root\cf0 );\
	tree.insertRankNode(7, tree.\cf7 root\cf0 );\
	tree.insertRankNode(13, tree.\cf7 root\cf0 );\
	tree.insertRankNode(3, tree.\cf7 root\cf0 );\
	\cf2 // 				5\cf0 \
	\cf2 //			 /     \\\cf0 \
\pard\pardeftab720
\cf2 	//          1       9\cf0 \
	\cf2 //           \\     / \\\cf0 \
\cf2 	//            4   7   13\cf0 \
	\cf2 //           / \\\cf0 \
\cf2 	//          4   5\cf0 \
	\cf2 //         /\cf0 \
	\cf2 //        3\cf0 \
\
\
	cout << \cf4 "Tree is "\cf0  << endl;\
	tree.inOrderTraversal(tree.\cf7 root\cf0 );\
	cout << endl;\
\
\
	
\f1\b \cf3 int
\f0\b0 \cf0  val = 100;\
	
\f1\b \cf3 int
\f0\b0 \cf0  res = tree.getRank(val);\
	cout << \cf4 "Rank of "\cf0  << val << \cf4 " is "\cf0  << res << endl;\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}