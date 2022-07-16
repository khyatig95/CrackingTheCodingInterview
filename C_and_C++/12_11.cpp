{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green40\blue128;\red0\green80\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	2DAlloc : Create an array of pointers with size = rows*(\ul int\ulnone *). Create a contiguous block of memory\cf0 \
\cf2 //				with size = row*\ul col\ulnone *\ul sizeof\ulnone (\ul int\ulnone ). This way, you only delete the \ul rowptr\cf0 \ulnone \
\cf2 //Assumption : Arrays are of type \ul int\cf0 \ulnone \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\

\f1\b \cf3 int
\f0\b0 \cf0 ** 
\f1\b TwoDAlloc
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  rows, 
\f1\b \cf3 int
\f0\b0 \cf0  cols) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  sizeRowPtr = rows*
\f1\b \cf3 sizeof
\f0\b0 \cf0 (
\f1\b \cf3 int
\f0\b0 \cf0 *); \cf2 //Contains pointers to each row\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  sizeMatrix = rows*cols*
\f1\b \cf3 sizeof
\f0\b0 \cf0 (
\f1\b \cf3 int
\f0\b0 \cf0 ); \cf2 //Contains all the elements of the Matrix\cf0 \
\
	
\f1\b \cf3 int
\f0\b0 \cf0 ** rowptr = (
\f1\b \cf3 int
\f0\b0 \cf0 **) 
\f1\b \cf5 malloc
\f0\b0 \cf0 (sizeRowPtr+sizeMatrix);\
\
	
\f1\b \cf3 int
\f0\b0 \cf0 * offset = (
\f1\b \cf3 int
\f0\b0 \cf0 *) (rowptr+rows); \cf2 //Index of \ul ptr\ulnone  to the first element in the matrix\cf0 \
	
\f1\b \cf3 for
\f0\b0 \cf0 (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<rows; i++)\
		rowptr[i] = offset + i*cols;\
	
\f1\b \cf3 return
\f0\b0 \cf0  rowptr;\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  rows = 5;\
	
\f1\b \cf3 int
\f0\b0 \cf0  cols = 6;\
	
\f1\b \cf3 int
\f0\b0 \cf0 ** ptr = TwoDAlloc(rows, cols);\
	cout << \cf4 "Size of \ul int\ulnone * = "\cf0  << 
\f1\b \cf3 sizeof
\f0\b0 \cf0 (
\f1\b \cf3 int
\f0\b0 \cf0 *) << endl;\
	cout << \cf4 "Size of \ul int\ulnone  = "\cf0  << 
\f1\b \cf3 sizeof
\f0\b0 \cf0 (
\f1\b \cf3 int
\f0\b0 \cf0 ) << endl;\
\
	cout << \cf4 "These should be spaced by \ul cols\ulnone *\ul sizeof\ulnone (\ul int\ulnone )"\cf0  << endl;\
	
\f1\b \cf3 for
\f0\b0 \cf0 (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<rows; i++)\
		cout << \cf4 "Row "\cf0  << i << \cf4 " = "\cf0  << \cf6 size_t\cf0 (ptr[i]) << endl;\
\
	\cf2 //Free up space\cf0 \
\pard\pardeftab720
\cf0 	
\f1\b \cf3 delete
\f0\b0 \cf0  ptr;\
\
\pard\pardeftab720
\cf0 	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}