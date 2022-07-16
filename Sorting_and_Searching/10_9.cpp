{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	sortedMatrixSearch : Check the diagonal mid and mid-1 index. Search through the 2 quadrants\cf0 \
\cf2 //				recursively\cf0 \
\cf2 //Time complexity : O(M*N)\cf0 \
\cf2 //Assumption : 	The matrix will be sorted and made of integers.\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\pard\pardeftab720
\cf2 //Rectangle Matrix\cf0 \
\cf2 //Square Matrix\cf0 \
\pard\pardeftab720

\f1\b \cf3 #define
\f0\b0 \cf0  ROWS 4\

\f1\b \cf3 #define
\f0\b0 \cf0  COLS 5\
\

\f1\b \cf3 class
\f0\b0 \cf0  \cf5 Coordinate\cf0  \{\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf6 row\cf0 ;\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf6 col\cf0 ;\
	
\f1\b Coordinate
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  r, 
\f1\b \cf3 int
\f0\b0 \cf0  c) \{\
		\cf6 row\cf0  = r;\
		\cf6 col\cf0  = c;\
	\}\
	
\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b isGreater
\f0\b0 (\cf5 Coordinate\cf0 * x) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  ((x->\cf6 row\cf0  < \cf6 row\cf0 ) || (x->\cf6 col\cf0  < \cf6 col\cf0 ))\
			
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ;\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
	\}\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b print
\f0\b0 () \{\
		cout << \cf4 "("\cf0  << \cf6 row\cf0  << \cf4 ", "\cf0  << \cf6 col\cf0  << \cf4 ")"\cf0  << endl;\
	\}\
	
\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b isEqual
\f0\b0 (\cf5 Coordinate\cf0 * x) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  ((x->\cf6 row\cf0  == \cf6 row\cf0 ) && (x->\cf6 col\cf0  == \cf6 col\cf0 ))\
			
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ;\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
	\}\
	
\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b isLegal
\f0\b0 () \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (\cf6 row\cf0  < 0 || \cf6 col\cf0  <0)\
			
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
		
\f1\b \cf3 if
\f0\b0 \cf0  (\cf6 row\cf0 >=ROWS || \cf6 col\cf0 >=COLS)\
			
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ;\
	\}\
\};\
\
\pard\pardeftab720
\cf5 Coordinate\cf0 * 
\f1\b sortedMatrixSearch
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  (&arr)[ROWS][COLS], 
\f1\b \cf3 int
\f0\b0 \cf0  x, \cf5 Coordinate\cf0 * origin, \cf5 Coordinate\cf0 * dest) \{\
	cout << endl;\
	\cf5 Coordinate\cf0 * error= 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (-1, -1);\
	
\f1\b \cf3 if
\f0\b0 \cf0  (origin->isGreater(dest)) \{\
		
\f1\b \cf3 return
\f0\b0 \cf0  error;\
	\}\
	
\f1\b \cf3 if
\f0\b0 \cf0  (!origin->isLegal() || !dest->isLegal())\
		
\f1\b \cf3 return
\f0\b0 \cf0  error;\
	cout << \cf4 "origin : "\cf0  << arr[origin->\cf6 row\cf0 ][origin->\cf6 col\cf0 ] << \cf4 " at "\cf0  << endl;\
		origin->print();\
	cout << \cf4 "\ul dest\ulnone  : "\cf0  << arr[dest->\cf6 row\cf0 ][dest->\cf6 col\cf0 ] << \cf4 " at "\cf0  << endl;\
		dest->print();\
\
		\cf2 //If Matrix is just one element\cf0 \
	
\f1\b \cf3 if
\f0\b0 \cf0  (origin->isEqual(dest)) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (arr[origin->\cf6 row\cf0 ][origin->\cf6 col\cf0 ] == x)\
			
\f1\b \cf3 return
\f0\b0 \cf0  origin;\
		
\f1\b \cf3 else
\f0\b0 \cf0 \
			
\f1\b \cf3 return
\f0\b0 \cf0  error;\
	\}\
\
\
	\cf5 Coordinate\cf0 * mid = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 ((origin->\cf6 row\cf0 +dest->\cf6 row\cf0 )/2, (origin->\cf6 col\cf0 +dest->\cf6 col\cf0 )/2);\
	cout << \cf4 "mid : "\cf0  << arr[mid->\cf6 row\cf0 ][mid->\cf6 col\cf0 ] << \cf4 " at "\cf0  << endl;\
	mid->print();\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid->\cf6 row\cf0 ][mid->\cf6 col\cf0 ] == x)\
			
\f1\b \cf3 return
\f0\b0 \cf0  mid;\
\
	
\f1\b \cf3 if
\f0\b0 \cf0  (x > arr[mid->\cf6 row\cf0 ][mid->\cf6 col\cf0 ]) \{\
		\cf2 //Search Lower\cf0 \
		cout << \cf4 "Search Lower"\cf0  << endl;\
		\cf5 Coordinate\cf0 * LOrigin = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (mid->\cf6 row\cf0 +1, origin->\cf6 col\cf0 );\
		\cf5 Coordinate\cf0 * LDest = dest;\
		\cf5 Coordinate\cf0 * res = sortedMatrixSearch(arr, x, LOrigin, LDest);\
		
\f1\b \cf3 if
\f0\b0 \cf0  (res->isEqual(error)) \{\
			\cf2 //Search Upper Right\cf0 \
			cout << \cf4 "Search Upper Right"\cf0  << endl;\
			\cf5 Coordinate\cf0 * UROrigin = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (origin->\cf6 row\cf0 , mid->\cf6 col\cf0 +1);\
			\cf5 Coordinate\cf0 * URDest = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (mid->\cf6 row\cf0 , dest->\cf6 col\cf0 );\
			
\f1\b \cf3 return
\f0\b0 \cf0 (sortedMatrixSearch(arr, x, UROrigin, URDest));\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0 \
			
\f1\b \cf3 return
\f0\b0 \cf0  res;\
	\} 
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  (x < arr[mid->\cf6 row\cf0 ][mid->\cf6 col\cf0 ]) \{\
		\cf2 //Search Upper\cf0 \
		cout << \cf4 "Search Upper"\cf0  << endl;\
		\cf5 Coordinate\cf0 * UOrigin = origin;\
		\cf5 Coordinate\cf0 * UDest = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (mid->\cf6 row\cf0 -1, dest->\cf6 col\cf0 );\
		\cf5 Coordinate\cf0 * res = sortedMatrixSearch(arr, x, UOrigin, UDest);\
		
\f1\b \cf3 if
\f0\b0 \cf0  (res->isEqual(error)) \{\
			\cf2 //Search Lower Left\cf0 \
			cout << \cf4 "Search Lower Left"\cf0  << endl;\
			\cf5 Coordinate\cf0 * LLOrigin = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (mid->\cf6 row\cf0 , origin->\cf6 col\cf0 );\
			\cf5 Coordinate\cf0 * LLDest = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (dest->\cf6 row\cf0 , mid->\cf6 col\cf0 -1);\
			
\f1\b \cf3 return
\f0\b0 \cf0 (sortedMatrixSearch(arr, x, LLOrigin, LLDest));\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0 \
			
\f1\b \cf3 return
\f0\b0 \cf0  res;\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  error;\
\}\
\
\
\pard\pardeftab720

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //With Duplicates : Square\cf0 \
	\cf2 /*\ul int\ulnone  matrix[ROWS][COLS] = \{	\{15, 20, 70, 85\},\cf0 \
\pard\pardeftab720
\cf2 								\{25, 35, 80, 95\},\cf0 \
\cf2 								\{30, 55, 95, 105\},\cf0 \
\cf2 								\{40, 80, 120, 120\}\cf0 \
\cf2 							 \};\cf0 \
\cf2 	*/\cf0 \
	\cf2 //With Duplicates : Rectangle (rows>\ul cols\ulnone )\cf0 \
	\cf2 /*\ul int\ulnone  matrix[ROWS][COLS] = \{	\{15, 20, 70, 85\},\cf0 \
\cf2 								\{25, 35, 80, 95\},\cf0 \
\cf2 								\{30, 55, 95, 105\},\cf0 \
\cf2 								\{40, 80, 120, 120\},\cf0 \
\cf2 								\{45, 85, 125, 130\}\cf0 \
\cf2 							 \};\cf0 \
\cf2 	*/\cf0 \
	\cf2 //With Duplicates : Rectangle (\ul cols\ulnone >rows)\cf0 \
	\cf2 /*\ul int\ulnone  matrix[ROWS][COLS] = \{	\{15, 20, 70, 85, 100\},\cf0 \
\cf2 								\{25, 35, 80, 95, 105\},\cf0 \
\cf2 								\{30, 55, 95, 105, 110\},\cf0 \
\cf2 								\{40, 80, 120, 120, 130\}\cf0 \
\cf2 							\};*/\cf0 \
	\cf2 //Without Duplicates : Square\cf0 \
	\cf2 /*\ul int\ulnone  matrix[ROWS][COLS] = \{	\{15, 20, 70, 85\},\cf0 \
\cf2 								\{25, 35, 80, 95\},\cf0 \
\cf2 								\{30, 55, 104,105\},\cf0 \
\cf2 								\{40, 100,110,120\}\cf0 \
\cf2 							 \};*/\cf0 \
	\cf2 //Without Duplicates : Rectangle (rows>\ul cols\ulnone )\cf0 \
	\cf2 /*\ul int\ulnone  matrix[ROWS][COLS] = \{	\{15, 20, 70, 85\},\cf0 \
\cf2 								\{25, 35, 80, 95\},\cf0 \
\cf2 								\{30, 55, 104,105\},\cf0 \
\cf2 								\{40, 100,110,120\},\cf0 \
\cf2 								\{45, 106,125,130\}\cf0 \
\cf2 							 \};*/\cf0 \
	\cf2 //Without Duplicates : Rectangle (\ul cols\ulnone >rows)\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  matrix[ROWS][COLS] = \{	\{15, 20, 70, 85, 86\},\
								\{25, 35, 80, 95, 96\},\
								\{30, 55, 104,105, 106\},\
								\{40, 100,110,120, 121\},\
							 \};\
	\cf5 Coordinate\cf0 * origin = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (0, 0);\
	\cf5 Coordinate\cf0 * dest = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Coordinate\cf0 (ROWS-1, COLS-1);\
	
\f1\b \cf3 int
\f0\b0 \cf0  val = 121;\
	\cf5 Coordinate\cf0 * res = sortedMatrixSearch(matrix, val, origin, dest);\
	cout << \cf4 "Found "\cf0  << val << \cf4 " at "\cf0  << endl;\
	res->print();\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}