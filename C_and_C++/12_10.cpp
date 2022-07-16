{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;\red100\green40\blue128;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	allignedMalloc : \ul Malloc\ulnone  a memory of size+alignment. There will be one address that starts with\cf0 \
\cf2 //				the alignment. Pick that address and return it. Store the original \ul ptr\ulnone  that allocates the memory\cf0 \
\cf2 //				at one location above the aligned address. Thus we can delete it easily.\cf0 \
\cf2 //Space Complexity : O(M+A) where M=size of memory; A = \ul alignemnt\cf0 \ulnone \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\

\f1\b \cf3 void
\f0\b0 \cf0 * 
\f1\b alignedMalloc
\f0\b0 (\cf5 size_t\cf0  size, \cf5 size_t\cf0  alignment) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  offset = alignment-1+
\f1\b \cf3 sizeof
\f0\b0 \cf0 (
\f1\b \cf3 void
\f0\b0 \cf0 *);\
	
\f1\b \cf3 void
\f0\b0 \cf0 * p = (
\f1\b \cf3 void
\f0\b0 \cf0 *)
\f1\b \cf6 malloc
\f0\b0 \cf0 (size+offset);\
	cout << \cf4 "p="\cf0  << \cf5 size_t\cf0 (p) << endl;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (p == NULL) \{\
		cout << \cf4 "Not enough space!"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  NULL;\
	\}\
	
\f1\b \cf3 void
\f0\b0 \cf0 * q = (
\f1\b \cf3 void
\f0\b0 \cf0 *) ((\cf5 size_t\cf0 (p)+offset)&~(alignment-1));  	\cf2 //p+offset as that is the biggest number.\cf0 \
													\cf2 //anding with 111..00.. will reduce the number\cf0 \
	((
\f1\b \cf3 void
\f0\b0 \cf0 **)q)[-1] = p; \cf2 //void** is an array of void pointers\cf0 \
	
\f1\b \cf3 return
\f0\b0 \cf0  q;\
\
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b alignedFree
\f0\b0 (
\f1\b \cf3 void
\f0\b0 \cf0 * startAddr) \{\
	
\f1\b \cf3 void
\f0\b0 \cf0 * p = ((
\f1\b \cf3 void
\f0\b0 \cf0 **)startAddr)[-1];\
	cout << \cf4 "p="\cf0  << \cf5 size_t\cf0 (p) << endl;\
	
\f1\b \cf6 free
\f0\b0 \cf0 (p);\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	
\f1\b \cf3 void
\f0\b0 \cf0 * k = alignedMalloc(1000, 128);\
	cout << \cf4 "Aligned address is "\cf0  << \cf5 size_t\cf0 (k) << endl;\
	alignedFree(k);\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}