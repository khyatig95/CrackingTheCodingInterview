{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green40\blue128;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	Total no. of +\ul ve\ulnone  numbers is 2^31 = 2 billion integers\cf0 \
\cf2 //				Since file contains 4 billion +\ul ve\ulnone  integers => there are duplicates\cf0 \
\cf2 //				1GB of memory => 2^30bytes = 8*2^30 bits = 2^33bits.\cf0 \
\cf2 //				If we set a bit for a number, we only need 2 billion bits = 2^30 to return a missing number\cf0 \
\cf2 //				Follow-up -\cf0 \
\cf2 //				We have 10MB and the integers are not unique\cf0 \
\cf2 //				1) Consider an array that stores the count of numbers within each block\cf0 \
\cf2 //				Size of array = Total \ul mem\ulnone /Size of each element <= 8*2^20bytes/4bytes <= 2^21\cf0 \
\cf2 //				Size of block/range = Total numbers/Number of blocks = 2^31/2^21 >= 2^10 (greater than as max number of blocks used)\cf0 \
\cf2 //				Whenever the count of a block < block size => number is missing there.\cf0 \
\cf2 //				To find the missing number in the block -\cf0 \
\cf2 //				2) We have 10MB = 2^6*2^20 bits\cf0 \
\cf2 //				=> block size <= 2^26\cf0 \
\cf2 //				Hence, 2^10 <= block size <= 2^26\cf0 \
\cf2 //				To use less memory, pick a number in middle.\cf0 \
\cf2 //Time Complexity : O(N)\cf0 \
\cf2 //Assumption : Only +\ul ve\ulnone  integers are handled\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <math.h>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b scanBitVector
\f0\b0 (
\f1\b \cf3 bool
\f0\b0 \cf0 * bitvec, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i< size; i++) \{\
		cout << \cf4 "Searching if "\cf0  << i << \cf4 " exists in \ul bitvector\ulnone "\cf0  << endl;\
		
\f1\b \cf3 if
\f0\b0 \cf0  (!bitvec[i]) \cf2 //Still 0\cf0 \
			
\f1\b \cf3 return
\f0\b0 \cf0  i;\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b findMissing
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  bitsize = 5;  \cf2 //We have 1 GB of \ul mem\ulnone  but need only 2 billion bits. For example, we consider a smaller number\cf0 \
	
\f1\b \cf3 bool
\f0\b0 \cf0  bitvector[bitsize]; \cf2 //By default, initialized to 0\cf0 \
\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i = 0; i < size; i++) \{\
		bitvector[arr[i]] = 
\f1\b \cf3 true
\f0\b0 \cf0 ;\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0 (scanBitVector(bitvector, bitsize));\
\}\
\
\pard\pardeftab720
\cf2 //Assumption : Only distinct integers here in \ul arr\cf0 \ulnone \
\pard\pardeftab720

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b findMissingWithBlock
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  blockSize = 3;  \cf2 //Assume this is the block size\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  numBlocks = 
\f1\b \cf5 ceil
\f0\b0 \cf0 (size/blockSize);\
	
\f1\b \cf3 int
\f0\b0 \cf0  countArray[numBlocks];\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<numBlocks; i++)\
		countArray[i] = 0;\
\
	\cf2 //Populate counts of each block\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  blockID;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++) \{\
		blockID = arr[i]/blockSize;\
		cout << arr[i] << \cf4 " has a \ul blockid\ulnone  = "\cf0  << blockID << endl;\
		countArray[blockID]++;\
	\}\
\
	\cf2 //Find which block's count < blockSize\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  missingBlock = -1;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i = 0; i<numBlocks; i++) \{\
		cout << \cf4 "count of block "\cf0  << i << \cf4 " is "\cf0  <<  countArray[i] << endl;\
		
\f1\b \cf3 if
\f0\b0 \cf0  (countArray[i] < blockSize) \{\
			missingBlock = i;\
			
\f1\b \cf3 break
\f0\b0 \cf0 ;\
		\}\
	\}\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (missingBlock == -1) \{ \cf2 //No numbers are missing\cf0 \
		cout << \cf4 "No numbers are missing "\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
	\}\
\
	\cf2 //Find which number in missing block is missing\cf0 \
	
\f1\b \cf3 bool
\f0\b0 \cf0  bitvector[blockSize];\
	
\f1\b \cf3 int
\f0\b0 \cf0  low = missingBlock*blockSize;\
	
\f1\b \cf3 int
\f0\b0 \cf0  high = (missingBlock+1)*blockSize -1;\
	cout << \cf4 "Missing block = "\cf0  << missingBlock << \cf4 " with low="\cf0  << low << \cf4 " and high="\cf0  << high << endl;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (low <= arr[i] <= high)\
			bitvector[arr[i] - low] = 
\f1\b \cf3 true
\f0\b0 \cf0 ;\
	\}\
	
\f1\b \cf3 int
\f0\b0 \cf0  offset = scanBitVector(bitvector, blockSize);\
	
\f1\b \cf3 return
\f0\b0 \cf0 (offset+low);\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  arr[] = \{1, 2, 9, 4, 0, 7, 8, 3, 5\};\
	
\f1\b \cf3 int
\f0\b0 \cf0  res = findMissingWithBlock(arr, 
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr)/
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr[0]));\
	cout << \cf4 "Missing "\cf0  << res << endl;\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}