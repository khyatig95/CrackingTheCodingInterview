{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm :   isSubtree : Iterate through n elements. Whenever \ul val\ulnone  is same as root of \ul val\ulnone  of subTree,\cf0 \
\cf2 //				iterate through all elements in subTree and compare all elements\cf0 \
\cf2 //				Time Complexity : O(n+\ul km\ulnone ) where n is \ul num\ulnone  elements in Tree and m is \ul num\ulnone  elements in subTree\cf0 \
\cf2 //              Space Complexity : O(n*m) due to recursion of checkSubtree and compareSmall\cf0 \
\cf2 //Assumption :  Tree is made of integers.\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 "BinaryTree.h"\cf0 \
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\
\pard\pardeftab720

\f1\b \cf3 \ul \ulc3 bool
\f0\b0 \cf0 \ulnone  
\f1\b compareSmall
\f0\b0 (\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n1, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n2) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (n2 == NULL)\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (n1 == NULL)\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
	cout << \cf4 "Compare small "\cf0  << n2->\cf7 val\cf0  << \cf4 " with big "\cf0  << n1->\cf7 val\cf0  << endl;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (n1->\cf7 val\cf0  != n2->\cf7 val\cf0 )\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (n1->\cf7 val\cf0  == n2->\cf7 val\cf0 ) \{\
		
\f1\b \cf3 return
\f0\b0 \cf0 (compareSmall(n1->\cf7 left\cf0 , n2->\cf7 left\cf0 ) && (compareSmall(n1->\cf7 right\cf0 , n2->\cf7 right\cf0 )));\
	\}\
\}\
\
\pard\pardeftab720

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b checkSubtree
\f0\b0 (\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* nbig, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* nsmall) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (nbig == NULL) \cf2 //Base Case\cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
	cout << \cf4 "Iterating through big tree's "\cf0  << nbig->\cf7 val\cf0  << endl;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (nbig->\cf7 val\cf0  == nsmall->\cf7 val\cf0  && compareSmall(nbig, nsmall)) \{\
		cout << \cf4 "Found subtree at "\cf0  << nbig->\cf7 val\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ;\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0 (checkSubtree(nbig->\cf7 left\cf0 , nsmall) || checkSubtree(nbig->\cf7 right\cf0 , nsmall));\
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
\f1\b isSubtree
\f0\b0 (\cf6 BinaryTree\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* big, \cf6 BinaryTree\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* small) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (big->\cf7 root\cf0  == NULL) \{\
		cout << \cf4 "ERROR: Bigger tree is NULL!"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
	\}\
	
\f1\b \cf3 if
\f0\b0 \cf0  (small->\cf7 root\cf0  == NULL)\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ; \cf2 //NULL tree is technically a subtree\cf0 \
\
	
\f1\b \cf3 return
\f0\b0 \cf0 (checkSubtree(big->\cf7 root\cf0 , small->\cf7 root\cf0 ));\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
    \cf2 //Creating test tree manually\cf0 \
    \cf2 //        11\cf0 \
    \cf2 //      /    \\\cf0 \
\pard\pardeftab720
\cf2     //    11      9\cf0 \
    \cf2 //   /  \\    /\cf0 \
    \cf2 //  7   12  15\cf0 \
    \cf2 //           \\\cf0 \
\cf2     //           13\cf0 \
    \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* tree1 = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >();\
    tree1->\cf7 root\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(11);\
    tree1->\cf7 root\cf0 ->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(11);\
    tree1->\cf7 root\cf0 ->\cf7 left\cf0 ->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(7);\
    tree1->\cf7 root\cf0 ->\cf7 left\cf0 ->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(12);\
    tree1->\cf7 root\cf0 ->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(9);\
    tree1->\cf7 root\cf0 ->\cf7 right\cf0 ->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(15);\
    tree1->\cf7 root\cf0 ->\cf7 right\cf0 ->\cf7 left\cf0 ->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(13);\
\
    \cf2 //Creating test tree manually\cf0 \
    \cf2 //    11\cf0 \
    \cf2 //   /  \\\cf0 \
\cf2     //  7   12\cf0 \
    \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* tree2 = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >();\
    tree2->\cf7 root\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(11);\
    tree2->\cf7 root\cf0 ->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(7);\
    tree2->\cf7 root\cf0 ->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(12);\
\
    \cf2 //Creating test tree manually\cf0 \
    \cf2 //    11\cf0 \
    \cf2 //   /  \\\cf0 \
\cf2     //  7   13\cf0 \
    \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* tree3 = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >();\
    tree3->\cf7 root\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(11);\
    tree3->\cf7 root\cf0 ->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(7);\
    tree3->\cf7 root\cf0 ->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(13);\
\
    \cf2 //Creating test tree manually\cf0 \
    \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* tree4 = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >();\
\
    \cf2 //Creating test tree manually\cf0 \
    \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* tree5 = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 BinaryTree\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >();\
    tree5->\cf7 root\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(111);\
\
    \cf2 //Check is subtree when multiple elements = root of the small tree\cf0 \
    \cf2 //Not a subtree\cf0 \
    \cf2 //NULL tree\cf0 \
    \cf2 //NULL subtree\cf0 \
    \cf2 //Single element subtree\cf0 \
    
\f1\b \cf3 if
\f0\b0 \cf0  (isSubtree(tree1,tree5))\
    	cout << \cf4 "Tree2 is a subtree of tree1"\cf0  << endl;\
    
\f1\b \cf3 else
\f0\b0 \cf0 \
    	cout << \cf4 "Tree2 is NOT a subtree of tree1"\cf0  << endl;\
\
    
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}