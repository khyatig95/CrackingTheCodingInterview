{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	printDuplicates : We have 4kB => 32768 bits. Since N <= 32000, we use a bitVector that is set\cf0 \
\cf2 //				when corresponding number appears. If we see the flag is already 1, we print the duplicate entry.\cf0 \
\cf2 //				Note : We store val's flag at val-1 index in the bitVector\cf0 \
\cf2 //Time complexity : O(N)\cf0 \
\cf2 //Space Complexity : O(N) [bits]\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\

\f1\b \cf3 #define
\f0\b0 \cf0  N 32000\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b printDuplicates
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0 * NumArr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  ((size == 0) || (size == 1)) \{ \cf2 // Duplicates not possible\cf0 \
		cout << \cf4 "No duplicates possible"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0 ;\
	\}\
	
\f1\b \cf3 bool
\f0\b0 \cf0  bitVector[N] = \{ 
\f1\b \cf3 false
\f0\b0 \cf0  \};\
	cout << \cf4 "The duplicate elements are : "\cf0  << endl;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  ((NumArr[i] < 1) || (NumArr[i] > N)) \{\
			cout << \cf4 "ERROR: "\cf0  << NumArr[i] << \cf4 " does NOT lie between 1 and "\cf0  << N << endl;\
			
\f1\b \cf3 return
\f0\b0 \cf0 ;\
		\}\
		\cf2 //NumArr[i]-1 index in bitVector corresponds to NumArr[i] corresponds to\cf0 \
		
\f1\b \cf3 if
\f0\b0 \cf0  (bitVector[NumArr[i] - 1])\
			cout << NumArr[i] << \cf4 " "\cf0 ;\
		
\f1\b \cf3 else
\f0\b0 \cf0 \
			bitVector[NumArr[i]-1] = 
\f1\b \cf3 true
\f0\b0 \cf0 ;\
\
	\}\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //No duplicates\cf0 \
	\cf2 //\ul int\ulnone  \ul arr\ulnone [] = \{25, 67, 89, 32000, 1, 42, 36, 69\};\cf0 \
	\cf2 //Some duplicates\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  arr[] = \{25, 67, 89, 32000, 1, 32000, 1, 42, 36, 69, 67\};\
	\cf2 //All duplicates\cf0 \
	\cf2 //\ul int\ulnone  \ul arr\ulnone [] = \{1, 1, 1, 1, 1, 1, 1\};\cf0 \
	\cf2 //Empty array\cf0 \
	\cf2 //\ul int\ulnone  \ul arr\ulnone [] = \{\};\cf0 \
	\cf2 //Outside the range\cf0 \
	\cf2 //\ul int\ulnone  \ul arr\ulnone [] = \{25, 67, 89, 32000, 1, 0, 1, 42, 36, 69, 67\};\cf0 \
\
	printDuplicates(arr, 
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr)/
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr[0]));\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}