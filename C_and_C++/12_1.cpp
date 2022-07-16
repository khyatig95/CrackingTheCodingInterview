{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	LastKLines : Use a circular array of size K and keep overwriting the oldest one.\cf0 \
\cf2 //Time Complexity : O(N) where N=lines in the file\cf0 \
\cf2 //Space Complexity : O(K)\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <fstream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <string>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 "CircularArray.h"\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b LastKLines
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  K) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (K==0)\
		
\f1\b \cf3 return
\f0\b0 \cf0 ;\
	\cf5 string\cf0  line;\
	
\f1\b \cf3 int
\f0\b0 \cf0  index = 0;\
	\cf5 CircularArray\cf0 <\cf5 string\cf0 >* circ = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 CircularArray\cf0 <\cf5 string\cf0 >(K);\
	\cf5 ifstream\cf0  infile(\cf4 "/Users/\ul Khyati\ulnone /eclipse-workspace/Sample/\ul src\ulnone /example.txt"\cf0 );\
	
\f1\b \cf3 if
\f0\b0 \cf0  (infile.is_open()) \{\
		
\f1\b \cf3 while
\f0\b0 \cf0 (getline(infile, line)) \{\
			circ->setArr(index%K, line);\
			index++;\
		\}\
		circ->print();\
	\} 
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << \cf4 "ERROR : Unable to open file"\cf0  << endl;\
\
\pard\pardeftab720
\cf0 	\cf2 //delete the \ul ptr\ulnone  created always\cf0 \
	
\f1\b \cf3 delete
\f0\b0 \cf0  circ;\
\pard\pardeftab720
\cf0 \}\
\
\pard\pardeftab720

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
\
	LastKLines(0);\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}