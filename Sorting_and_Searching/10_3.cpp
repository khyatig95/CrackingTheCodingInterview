{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	findRotated : Use modified binary search.\cf0 \
\cf2 //				If half array is sorted and element lies in it, search there\cf0 \
\cf2 //				If other half is not sorted, search the whole array\cf0 \
\cf2 //Time Complexity : O(N) (worst case)\cf0 \
\cf2 //Space Complexity : O(1)\cf0 \
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
\f1\b printArr
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	cout << \cf4 "[ "\cf0  ;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++)\
		cout << arr[i] << \cf4 " "\cf0 ;\
	cout << \cf4 "]"\cf0  << endl;\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b findRotated
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0 * arr, 
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
	cout << \cf4 "Mid value = "\cf0  << arr[mid] << endl;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] == val)\
		
\f1\b \cf3 return
\f0\b0 \cf0  mid;\
	\cf2 //First Half\cf0 \
	 
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] >= arr[start]) \{ \cf2 //First half is sorted\cf0 \
		 
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] > val && val >= arr[start])\
			 
\f1\b \cf3 return
\f0\b0 \cf0 (findRotated(arr, start, mid-1, val));\
		 
\f1\b \cf3 else
\f0\b0 \cf0 \
			 
\f1\b \cf3 return
\f0\b0 \cf0 (findRotated(arr, mid+1, end, val));\
	 \} 
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] < arr[start]) \{ \cf2 //First half is not sorted\cf0 \
		 \cf2 //If second half is sorted, search there\cf0 \
		 
\f1\b \cf3 if
\f0\b0 \cf0  (arr[end] >= arr[mid]) \{\
			 
\f1\b \cf3 if
\f0\b0 \cf0  (arr[end] >= val && arr[mid] < val)\
				 
\f1\b \cf3 return
\f0\b0 \cf0 (findRotated(arr, mid+1, end, val));\
			 
\f1\b \cf3 else
\f0\b0 \cf0 \
				 
\f1\b \cf3 return
\f0\b0 \cf0 (findRotated(arr, start, mid-1, val));\
		 \}\
	 \}\
	 \cf2 //Both are not sorted\cf0 \
	 cout << \cf4 "ERROR : Array was NOT sorted when rotated "\cf0  << endl;\
	 
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //Arbitrary rotations\cf0 \
	\cf2 //\ul int\ulnone  \ul arr\ulnone [12] = \{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14\};\cf0 \
\
	\cf2 //no rotations\cf0 \
	\cf2 //\ul int\ulnone  \ul arr\ulnone [12] = \{ 1, 3, 4, 5, 7, 10, 14, 15, 16, 19, 20, 25\};\cf0 \
\
	\cf2 //Completely rotated\cf0 \
	\cf2 //\ul int\ulnone  \ul arr\ulnone [12] = \{3, 4, 5, 7, 10, 14, 15, 16, 19, 20, 25, 1\};\cf0 \
\
	\cf2 //Repetitions\cf0 \
	
\f1\b \cf3 int
\f0\b0 \cf0  arr[6] = \{2, 2, 2, 3, 4, 2\};\
\
	
\f1\b \cf3 int
\f0\b0 \cf0  search = 4;\
	
\f1\b \cf3 int
\f0\b0 \cf0  res = findRotated(arr, 0, 5, search);\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res == -1)\
		cout << search << \cf4 " not found!"\cf0  << endl;\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << search << \cf4 " found at "\cf0  << res << endl;\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
\
}