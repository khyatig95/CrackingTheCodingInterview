{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	DeepCopyNode : Maintain a map of nodes that are copied. Key =original node, \ul val\ulnone  = copied\cf0 \
\cf2 //							   If it doesn't exist, recursively add all child nodes to the map\cf0 \
\cf2 //Time Complexity : O(N) where N is the number of nodes\cf0 \
\cf2 //Space Complexity : O(N) as we are exactly copying the data structure\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <map>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\

\f1\b \cf3 class
\f0\b0 \cf0  \cf5 Node\cf0  \{\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	\cf5 Node\cf0 * \cf6 n1\cf0 ;\
	\cf5 Node\cf0 * \cf6 n2\cf0 ;\
	
\f1\b Node
\f0\b0 ()\{\
		\cf6 n1\cf0  = NULL;\
		\cf6 n2\cf0  = NULL;\
	\}\
\};\
\
\pard\pardeftab720
\cf5 Node\cf0 * 
\f1\b DeepCopyNode
\f0\b0 (\cf5 Node\cf0 * orig, \cf5 map\cf0 <\cf5 Node\cf0 *, \cf5 Node\cf0 *> m1) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (orig == NULL)\
		
\f1\b \cf3 return
\f0\b0 \cf0  NULL;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (m1.find(orig) != m1.end()) \cf2 //If map contains \ul orig\ulnone , return the map\cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0 (m1[orig]);\
\
	\cf5 Node\cf0 * n = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Node\cf0 ();\
	m1[orig] = n;\
	n->\cf6 n1\cf0  = DeepCopyNode(orig->\cf6 n1\cf0 , m1);\
	n->\cf6 n2\cf0  = DeepCopyNode(orig->\cf6 n2\cf0 , m1);\
	
\f1\b \cf3 return
\f0\b0 \cf0 (n);\
\}\
\
\cf5 Node\cf0 * 
\f1\b copyNode
\f0\b0 (\cf5 Node\cf0 * orig) \{\
	\cf5 map\cf0 <\cf5 Node\cf0 *, \cf5 Node\cf0 *> NodeMap;\
	
\f1\b \cf3 return
\f0\b0 \cf0 (DeepCopyNode(orig, NodeMap));\
\}\
\
\pard\pardeftab720

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf5 Node\cf0 * root = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Node\cf0 ();\
	root->\cf6 n1\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Node\cf0 ();\
	root->\cf6 n2\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Node\cf0 ();\
	root->\cf6 n1\cf0 ->\cf6 n1\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Node\cf0 ();\
	root->\cf6 n1\cf0 ->\cf6 n2\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Node\cf0 ();\
	root->\cf6 n2\cf0 ->\cf6 n1\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Node\cf0 ();\
\
	\cf5 Node\cf0 * res = copyNode(root);\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res == NULL)\
		cout << \cf4 "Root is null"\cf0  << endl;\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << \cf4 "Root is NOT null"\cf0  << endl;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res->\cf6 n1\cf0  == NULL)\
		cout << \cf4 "Root->n1 is null"\cf0  << endl;\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << \cf4 "Root->n1 is NOT null"\cf0  << endl;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res->\cf6 n2\cf0  == NULL)\
		cout << \cf4 "Root->n2 is null"\cf0  << endl;\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << \cf4 "Root->n2 is NOT null"\cf0  << endl;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res->\cf6 n1\cf0 ->\cf6 n1\cf0  == NULL)\
		cout << \cf4 "Root->n1->n1 is null"\cf0  << endl;\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << \cf4 "Root->n1->n1 is NOT null"\cf0  << endl;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res->\cf6 n1\cf0 ->\cf6 n2\cf0  == NULL)\
		cout << \cf4 "Root->n1->n2 is null"\cf0  << endl;\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << \cf4 "Root->n1->n2 is NOT null"\cf0  << endl;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res->\cf6 n2\cf0 ->\cf6 n1\cf0  == NULL)\
			cout << \cf4 "Root->n2->n1 is null"\cf0  << endl;\
		
\f1\b \cf3 else
\f0\b0 \cf0 \
			cout << \cf4 "Root->n2->n1 is NOT null"\cf0  << endl;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res->\cf6 n2\cf0 ->\cf6 n2\cf0  == NULL)\
			cout << \cf4 "Root->n2->n2 is null"\cf0  << endl;\
		
\f1\b \cf3 else
\f0\b0 \cf0 \
			cout << \cf4 "Root->n2->n2 is NOT null"\cf0  << endl;\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}