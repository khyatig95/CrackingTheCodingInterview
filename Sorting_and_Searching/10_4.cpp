{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	findElement : Guess the size by starting with 2, 4 and going exponential.\
\pard\pardeftab720
\cf2 //Time Complexity : O(logN) \
//Space Complexity : O(1)\cf0 \
\pard\pardeftab720
\cf2 //			BinarySearch : Do binary search\cf0 \
\cf2 //Time Complexity : O(logN) \
//Space Complexity : O(1)\cf0 \
\cf2 //Assumption : \ul Listy\ulnone  will always be sorted.\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 "Listy.h"\cf0 \
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b BinarySearch
\f0\b0 (\cf5 Listy\cf0 * lis, 
\f1\b \cf3 int
\f0\b0 \cf0  start, 
\f1\b \cf3 int
\f0\b0 \cf0  end, 
\f1\b \cf3 int
\f0\b0 \cf0  val) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (start > end)\
		
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
\
	
\f1\b \cf3 int
\f0\b0 \cf0  mid = (start+end)/2;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (lis->elementAt(mid) == val)\
		
\f1\b \cf3 return
\f0\b0 \cf0  mid;\
	
\f1\b \cf3 if
\f0\b0 \cf0  ((lis->elementAt(mid) > val) || (lis->elementAt(mid) == -1))\
		
\f1\b \cf3 return
\f0\b0 \cf0 (BinarySearch(lis, start, mid-1, val));\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0  (BinarySearch(lis, mid+1, end, val));\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b findElement
\f0\b0 (\cf5 Listy\cf0 * lis, 
\f1\b \cf3 int
\f0\b0 \cf0  val) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (val < 0) \{ \cf2 //\ul Listy\ulnone  contains only +\ul ve\ulnone  numbers\cf0 \
		cout << \cf4 "ERROR : Trying to find a negative number "\cf0  << val << \cf4 " in \ul Listy\ulnone "\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
	\}\
\
	\cf2 //Find Size\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  guess = 1;\
	
\f1\b \cf3 while
\f0\b0 \cf0 ((lis->elementAt(guess) != - 1) && (lis->elementAt(guess) < val))\
		guess = guess*2;\
	cout << \cf4 "Guess is "\cf0  << guess << \cf4 " with element at guess = "\cf0  << lis->elementAt(guess) << endl;\
\
	\cf2 //BinarySearch\cf0 \
	
\f1\b \cf3 return
\f0\b0 \cf0 (BinarySearch(lis, guess/2, guess, val)); \cf2 //guess can be either be out of bound or >= \ul val\cf0 \ulnone \
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  arr[7] = \{0, 2, 5, 7, 34, 52, 105\};\
	\cf5 Listy\cf0 * listy = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Listy\cf0 ();\
	listy->assignListy(arr, 7);\
\
	\cf2 //\ul val\ulnone  is negative\cf0 \
	\cf2 //\ul val\ulnone  is edge\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  val = 105;\
	
\f1\b \cf3 int
\f0\b0 \cf0  res = findElement(listy, val);\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res == -1)\
		cout << val << \cf4 " not found!"\cf0  << endl;\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << val << \cf4 " found at "\cf0  << res << endl;\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}