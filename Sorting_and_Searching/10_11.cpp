{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	pNv : Add the largest number in the mid position for a contiguous 3 index. We have an overlap\cf0 \
\cf2 //					with the leftmost element as that is a smaller element. We will just replace it with a\cf0 \
\cf2 //					smaller value in future (as we only swap if that element is bigger)\cf0 \
\cf2 //Time Complexity : O(N)\cf0 \
\cf2 //Space Complexity : O(1)\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <algorithm>\cf0 \

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

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b swap
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * x, 
\f1\b \cf5 T
\f0\b0 \cf0 * y) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  temp = *x;\
	*x = *y;\
	*y = temp;\
\}\
\
\

\f1\b \cf3 int
\f0\b0 \cf0 * 
\f1\b pNv
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  maxVal;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<=size-3; i=i+2) \{\
		maxVal = max(max(arr[i], arr[i+1]), arr[i+2]);\
		
\f1\b \cf3 if
\f0\b0 \cf0  (arr[i+1] != maxVal) \{\
			
\f1\b \cf3 if
\f0\b0 \cf0 (arr[i] == maxVal)\
				swap(arr[i], arr[i+1]);\
			
\f1\b \cf3 else
\f0\b0 \cf0 \
				swap(arr[i+2], arr[i+1]);\
		\}\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  arr;\
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b printArr
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (size <= 0)\
		
\f1\b \cf3 return
\f0\b0 \cf0 ;\
	cout << \cf4 "[ "\cf0 ;\
	
\f1\b \cf3 for
\f0\b0 \cf0 (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++)\
		cout << arr[i] << \cf4 ", "\cf0 ;\
	cout << \cf4 "]"\cf0  << endl;\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //\ul int\ulnone  \ul arr\ulnone [] = \{0, 1, 4, 7, 8, 9\};\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  arr[] = \{5, 3, 1, 2, 3\};\
	cout << \cf4 "Original array"\cf0  << endl;\
	printArr(arr, 
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr)/
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr[0]));\
\
	
\f1\b \cf3 int
\f0\b0 \cf0 * res = pNv(arr, 
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr)/
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr[0]));\
	cout << \cf4 "Result array"\cf0  << endl;\
	printArr(res, 
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr)/
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr[0]));\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}