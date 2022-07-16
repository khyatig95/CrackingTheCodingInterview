{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm :   commonAncestorBST : Recurse from the node and determine when n1 and n2\cf0 \
\cf2 //				are on different subtrees\cf0 \
\cf2 //				Time Complexity : O(n)\cf0 \
\cf2 //              Space Complexity : O(t) due to recursion\cf0 \
\cf2 //Assumption :  Tree is made of integers. Tree is BST\cf0 \
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
\f0\b0 \cf0  \cf6 Node\cf0  \{\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	
\f1\b \cf5 T
\f0\b0 \cf0  \cf7 val\cf0 ;\
	\cf6 Node\cf0 * \cf7 left\cf0 ;\
	\cf6 Node\cf0 * \cf7 right\cf0 ;\
\
	
\f1\b Node
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0  x) \{\
		\cf7 val\cf0  = x;\
		\cf7 left\cf0  = NULL;\
		\cf7 right\cf0  = NULL;\
	\}\
\};\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b covers
\f0\b0 (\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* root, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n) \{\
    
\f1\b \cf3 if
\f0\b0 \cf0  (root == NULL || n == NULL)\
        
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
    cout << \cf4 "Checking if "\cf0  << root->\cf7 val\cf0  << \cf4 " covers "\cf0  << n->\cf7 val\cf0  << endl;\
    
\f1\b \cf3 if
\f0\b0 \cf0  (root == n) \{\
    	cout << \cf4 "Covered "\cf0  << endl;\
        
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ;\
    \} 
\f1\b \cf3 else
\f0\b0 \cf0 \
        
\f1\b \cf3 return
\f0\b0 \cf0 (covers(root->\cf7 left\cf0 , n) || covers(root->\cf7 right\cf0 , n));\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\
\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b commonAncestorBST
\f0\b0 (\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* root, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n1, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n2) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (root == NULL) \{\
		cout << \cf4 "ERROR : Tree is Empty!"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  NULL;\
	\}\
	
\f1\b \cf3 if
\f0\b0 \cf0  ((n1 == NULL) || (n2 == NULL)) \{\
		cout << \cf4 "ERROR : n1 and/or are NULL"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  NULL;\
	\}\
	
\f1\b \cf3 if
\f0\b0 \cf0  ((!covers(root, n1)) || (!covers(root, n2))) \{\
		cout << \cf4 "ERROR : n1 and/or are not present in the tree"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  NULL;\
	\}\
\
	
\f1\b \cf3 return
\f0\b0 \cf0 (findAncestor(root, n1, n2));\
\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\
\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* 
\f1\b findAncestor
\f0\b0 (\cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* root, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n1, \cf6 Node\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 >* n2) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (root == NULL) \
		
\f1\b \cf3 return
\f0\b0 \cf0  NULL;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (n1 == n2)\
		
\f1\b \cf3 return
\f0\b0 \cf0  n1;\
	
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  ((n1->\cf7 val\cf0  <= root->\cf7 val\cf0 ) && (n2->\cf7 val\cf0  <= root->\cf7 val\cf0 ))\
		
\f1\b \cf3 return
\f0\b0 \cf0  (findAncestor(root->\cf7 left\cf0 , n1, n2));\
	
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  ((n1->\cf7 val\cf0  > root->\cf7 val\cf0 ) && (n2->\cf7 val\cf0  > root->\cf7 val\cf0 ))\
		
\f1\b \cf3 return
\f0\b0 \cf0  (findAncestor(root->\cf7 right\cf0 , n1, n2));\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0  root;\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
    \cf2 //Creating test tree manually\cf0 \
    \cf2 //         8\cf0 \
    \cf2 //      /    \\\cf0 \
\pard\pardeftab720
\cf2     //     5      25\cf0 \
    \cf2 //   /  \\    /\cf0 \
    \cf2 // -1    8  15\cf0 \
    \cf2 //           \\\cf0 \
\cf2     //           16\cf0 \
    \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* root;\
\
    root = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(8);\
    root->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(5);\
    root->\cf7 left\cf0 ->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(-1);\
    root->\cf7 left\cf0 ->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(8);\
    root->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(25);\
    root->\cf7 right\cf0 ->\cf7 left\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(15);\
    root->\cf7 right\cf0 ->\cf7 left\cf0 ->\cf7 right\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >(16);\
\
\
    \cf2 //n1 covers n2\cf0 \
    \cf2 //n2 covers n1\cf0 \
    \cf2 //n1 / n2 not in the tree\cf0 \
    \cf2 //Tree is empty\cf0 \
    \cf2 //n1 == n2\cf0 \
    \cf2 //n1 == n2 == root\cf0 \
    \cf2 //n1 and n2 in different subtrees at different levels\cf0 \
    \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* n1 = root;\
    \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* n2 = root;\
    cout << \cf4 "Common ancestor of "\cf0  << n1->\cf7 val\cf0  << \cf4 " and "\cf0  << n2->\cf7 val\cf0  << \cf4 " is :"\cf0  << endl;\
    \cf6 Node\cf0 <
\f1\b \cf3 int
\f0\b0 \cf0 >* res = commonAncestorBST(root, n1, n2);\
    
\f1\b \cf3 if
\f0\b0 \cf0  (res == NULL)\
        cout << \cf4 "NONE"\cf0  << endl;\
    
\f1\b \cf3 else
\f0\b0 \cf0 \
        cout << res->\cf7 val\cf0  << endl;\
\
    
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}