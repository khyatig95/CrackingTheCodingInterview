{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	SortedMerge : Keep populating A from the end by comparing A and B's element from the end\cf0 \
\cf2 //Time Complexity : O(N*M) where N= \ul num\ulnone  elements in A\cf0 \
\cf2 //								 M= \ul num\ulnone  elements in B\cf0 \
\cf2 //Space Complexity : O(N*M) due to recursion (worst case when A>B)\cf0 \
\cf2 //Assumption : A's size is \ul num\ulnone  non-empty elements in A + size of B.\cf0 \
\cf2 //			   B doesn't have any empty elements\cf0 \
\cf2 //			   Both arrays are sorted\cf0 \
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
\pard\pardeftab720

\f1\b \cf5 T
\f0\b0 \cf0 * 
\f1\b SortedMerge
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * bigArr, 
\f1\b \cf3 int
\f0\b0 \cf0  bigSize, 
\f1\b \cf5 T
\f0\b0 \cf0 * smallArr, 
\f1\b \cf3 int
\f0\b0 \cf0  smallSize) \{\
	\cf2 //Base Case\cf0 \
	
\f1\b \cf3 if
\f0\b0 \cf0 (smallSize <= 0) \{\
		
\f1\b \cf3 return
\f0\b0 \cf0  bigArr;\
	\}\
	\cf2 //\ul cout\ulnone  << "Comparing a= " << bigArr[bigSize-smallSize-1] << " to b= " << smallArr[smallSize-1] << \ul endl\ulnone ;\cf0 \
	
\f1\b \cf3 if
\f0\b0 \cf0  (bigArr[bigSize-smallSize-1] > smallArr[smallSize-1])\
		bigArr[bigSize-1] = bigArr[bigSize-smallSize-1];\
	
\f1\b \cf3 else
\f0\b0 \cf0  \{\
		bigArr[bigSize-1] = smallArr[smallSize-1];\
		smallSize --;\
	\}\
	cout << \cf4 "Bigger element "\cf0  << bigArr[bigSize-1] << endl;\
	bigSize--;\
	\cf2 //Recurse\cf0 \
	
\f1\b \cf3 return
\f0\b0 \cf0  (SortedMerge(bigArr, bigSize, smallArr, smallSize)); \cf2 //recurse\cf0 \
\
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
\f1\b printArr
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	cout << \cf4 "[ "\cf0  ;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++)\
		cout << arr[i] << \cf4 " "\cf0 ;\
	cout << \cf4 "]"\cf0  << endl;\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //Repetitions\cf0 \
	\cf2 //\ul int\ulnone  a[10] = \{ 2, 3, 3, 4, 6\};\cf0 \
	\cf2 //\ul int\ulnone  b[5] = \{ 1, 3, 6, 7, 9\};\cf0 \
\
	\cf2 //B>a\cf0 \
	\cf2 //\ul int\ulnone  a[10] = \{ 2, 3, 3, 4, 6\};\cf0 \
	\cf2 //\ul int\ulnone  b[5] = \{6, 7, 8, 8, 11\};\cf0 \
\
	\cf2 //a>B\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  a[10] = \{6, 7, 8, 8, 11\};\
	
\f1\b \cf3 int
\f0\b0 \cf0  b[5] = \{ 2, 3, 3, 4, 6\};\
\
	
\f1\b \cf3 int
\f0\b0 \cf0 * res;\
	res = SortedMerge<
\f1\b \cf3 int
\f0\b0 \cf0 >(a, 10, b, 5);\
	printArr<
\f1\b \cf3 int
\f0\b0 \cf0 >(a, 10);\
\}\
}