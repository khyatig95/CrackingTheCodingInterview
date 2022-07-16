{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	ReverseString : Calculate the length of the string. Then swap in a for loop\cf0 \
\cf2 //Time Complexity : O(N) where N is the length of the string\cf0 \
\cf2 //Space Complexity : O(1) as we are reversing the string in place\cf0 \
\cf2 //Assumption : The string will always be terminated with '\\0'\cf0 \
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

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b swap
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * x, 
\f1\b \cf5 T
\f0\b0 \cf0 * y) \{\
	
\f1\b \cf5 T
\f0\b0 \cf0  temp = *x;\
	*x = *y;\
	*y = temp;\
\}\
\

\f1\b \cf3 char
\f0\b0 \cf0 * 
\f1\b ReverseString
\f0\b0  (
\f1\b \cf3 char
\f0\b0 \cf0 * str) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  len = 0;\
	
\f1\b \cf3 while
\f0\b0 \cf0 (str[len] != \cf4 '\\0'\cf0 ) \{\
		len++;\
	\}\
\
	
\f1\b \cf3 int
\f0\b0 \cf0  start = 0;\
	
\f1\b \cf3 int
\f0\b0 \cf0  end = len-1;\
\
	
\f1\b \cf3 while
\f0\b0 \cf0 (start < end) \{\
		swap<
\f1\b \cf3 char
\f0\b0 \cf0 >(str[start], str[end]); \cf2 //We don't need & here as \ul str\ulnone  is already an address\cf0 \
		start++;\
		end--;\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  str;\
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
\f1\b printArr
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	cout << \cf4 "[ "\cf0 ;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++)\
		cout << arr[i] << \cf4 ", "\cf0  ;\
	cout << \cf4 " ]"\cf0  << endl;\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	
\f1\b \cf3 char
\f0\b0 \cf0  ex[7] = \{\cf4 'K'\cf0 , \cf4 'H'\cf0 , \cf4 'Y'\cf0 , \cf4 'A'\cf0 , \cf4 'T'\cf0 , \cf4 'I'\cf0 , \cf4 '\\0'\cf0 \};\
	printArr<
\f1\b \cf3 char
\f0\b0 \cf0 >(ReverseString(ex), 6);\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}