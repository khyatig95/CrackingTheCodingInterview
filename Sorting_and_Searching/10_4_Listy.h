{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red0\green80\blue50;
\red0\green0\blue192;\red42\green0\blue255;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //You are given an array-like data structure \ul Listy\ulnone  which lacks a size method.\cf0 \
\cf2 //It does, however, have an elementAt ( i) method that returns the element at index i in 0( 1) time.\cf0 \
\cf2 //If i is beyond the bounds of the data structure, it returns -1.\cf0 \
\cf2 //(For this reason, the data structure only supports positive integers.)\cf0 \
\cf2 //Assumption : \ul Listy\ulnone  only contains integers\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 class
\f0\b0 \cf0  \cf4 Listy\cf0  \{\
	
\f1\b \cf3 private
\f0\b0 \cf0  :\
		
\f1\b \cf3 int
\f0\b0 \cf0 * \cf5 ListyArr\cf0 ; \cf2 //Dynamic Array\cf0 \
		
\f1\b \cf3 int
\f0\b0 \cf0  \cf5 ListySize\cf0 ;\
	
\f1\b \cf3 public
\f0\b0 \cf0  :\
		
\f1\b \ul Listy
\f0\b0 () \{\ulnone \
\pard\pardeftab720
\cf0 \ul \ulc0 			\cf5 \ulc5 ListySize\cf0 \ulc0  = 0;\ulnone \
\ul 		\}\ulnone \
		
\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b elementAt
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  index);\
		
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b assignListy
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  *arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size);\
		
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b printArr
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size);\
\};\
\
\pard\pardeftab720

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b Listy :: elementAt
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  index) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (index >= \cf5 ListySize\cf0 )\
		
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
	
\f1\b \cf3 return
\f0\b0 \cf0 (\cf5 ListyArr\cf0 [index]);\
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b Listy :: assignListy
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  *arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	cout << \cf6 "Input array is "\cf0  << endl;\
	printArr(arr, size);\
	\cf5 ListySize\cf0  = size;\
	\cf5 ListyArr\cf0  = 
\f1\b \cf3 new
\f0\b0 \cf0  
\f1\b \cf3 int
\f0\b0 \cf0 (\cf5 ListySize\cf0 );\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i = 0; i < size ; i++) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (arr[i] < 0)\
			\cf5 ListyArr\cf0 [i] = arr[i]*(-1); \cf2 //\ul Listy\ulnone  supports only +\ul ve\ulnone  \ul vals\cf0 \ulnone \
		
\f1\b \cf3 else
\f0\b0 \cf0 \
			\cf5 ListyArr\cf0 [i] = arr[i];\
	\}\
	printArr(\cf5 ListyArr\cf0 , \cf5 ListySize\cf0 );\
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b Listy :: printArr
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	cout << \cf6 "[ "\cf0  ;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++)\
		cout << arr[i] << \cf6 " "\cf0 ;\
	cout << \cf6 "]"\cf0  << endl;\
\}\
}