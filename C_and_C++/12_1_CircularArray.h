{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	CircularArray is implemented just by storing a head index that points to the start if the\cf0 \
\cf2 //				\ul circ\ulnone  array instead of rotating as rotating is expensive.\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <vector>\cf0 \

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

\f1\b \cf3 class
\f0\b0 \cf0  \cf6 CircularArray\cf0  \{\

\f1\b \cf3 private
\f0\b0 \cf0 :\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf7 size\cf0 ;\
	\cf6 vector\cf0 <
\f1\b \cf5 T
\f0\b0 \cf0 > \cf7 arr\cf0 ;\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf7 head\cf0 ; \cf2 //Head is \ul int\ulnone  as that refers to the index\cf0 \
\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	
\f1\b CircularArray
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  len) \{\
		\cf7 size\cf0  = len;\
		\cf7 arr\cf0 .reserve(len);\
		\cf7 head\cf0  = 0;\
	\}\
	
\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b getArrIndex
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  circIndex);\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b setArr
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  circIndex, 
\f1\b \cf5 T
\f0\b0 \cf0  val);\
	
\f1\b \cf5 T
\f0\b0 \cf0  
\f1\b getArr
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  circIndex);\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b rotate
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  shiftRight);\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b print
\f0\b0 ();\
\};\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b CircularArray<T> :: getArrIndex
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  circIndex) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (circIndex < 0) \{\
		circIndex += \cf7 size\cf0 ;\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0 ((\cf7 head\cf0 +circIndex)%\cf7 size\cf0 );\
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
\f1\b CircularArray<T> :: setArr
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  circIndex, 
\f1\b \cf5 T
\f0\b0 \cf0  val) \{\
	\cf7 arr\cf0 [getArrIndex(circIndex)] = val;\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\
\pard\pardeftab720

\f1\b \cf5 T
\f0\b0 \cf0  
\f1\b CircularArray<T> :: getArr
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  circIndex) \{\
	
\f1\b \cf3 return
\f0\b0 \cf0 (\cf7 arr\cf0 [getArrIndex(circIndex)]);\
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
\f1\b CircularArray<T> :: rotate
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  shiftRight) \{\
	\cf7 head\cf0  = getArrIndex(shiftRight);\
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
\f1\b CircularArray<T> :: print
\f0\b0 () \{\
	cout << \cf4 "[ "\cf0  << endl;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=\cf7 size\cf0 -1; i>=0; i--)\
		cout << \cf4 " 	"\cf0  << \cf7 arr\cf0 [getArrIndex(i)] << endl;\
	cout << \cf4 " ]"\cf0  << endl;\
\}\
\
\
}