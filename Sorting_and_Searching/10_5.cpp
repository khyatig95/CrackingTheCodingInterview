{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	SparseSearch : Do Binary Search but if you encounter space,\cf0 \
\cf2 //				keep searching till you find the closest non-empty string\cf0 \
\cf2 //Time Complexity : O(logN)\cf0 \
\cf2 //Space Complexity : O(1)\cf0 \
\cf2 //Assumption : Input array of strings will be sorted\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <string>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <string>\cf0 \
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b SparseSearch
\f0\b0 (\cf5 string\cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  start, 
\f1\b \cf3 int
\f0\b0 \cf0  end, \cf5 string\cf0  val) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (start>end)\
		
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (val == \cf4 ""\cf0 ) \{\
		cout << \cf4 "ERROR: \ul val\ulnone  is empty!!"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
	\}\
	cout << \cf4 "SparseSearch with start="\cf0  << arr[start] << \cf4 " and end="\cf0  << arr[end] << endl;\
	
\f1\b \cf3 int
\f0\b0 \cf0  mid = (start+end)/2;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] == \cf4 ""\cf0 ) \{ \cf2 //Find the closest non-empty mid\cf0 \
		cout << mid << \cf4 " location has empty string!"\cf0  << endl;\
		
\f1\b \cf3 int
\f0\b0 \cf0  left = mid - 1;\
		
\f1\b \cf3 int
\f0\b0 \cf0  right = mid + 1;\
		
\f1\b \cf3 while
\f0\b0 \cf0 (left >= start && right<=end) \{\
			
\f1\b \cf3 if
\f0\b0 \cf0  ((arr[left] != \cf4 ""\cf0 ) || (arr[right] != \cf4 ""\cf0 )) \{\
				mid = (arr[left] != \cf4 ""\cf0 ) ? left : right;\
				cout << \cf4 "Found new mid string "\cf0  << arr[mid] << \cf4 " with mid "\cf0  << mid << endl;\
				
\f1\b \cf3 break
\f0\b0 \cf0 ;\
			\}\
			left--;\
			right++;\
		\}\
		
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] == \cf4 ""\cf0 ) \{\
			
\f1\b \cf3 if
\f0\b0 \cf0  (left<start && right>end)  \cf2 //Exhausted both ends\cf0 \
					
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
			
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  (left<start) \{\
				
\f1\b \cf3 while
\f0\b0 \cf0 (right<=end) \{\
					
\f1\b \cf3 if
\f0\b0 \cf0  (arr[right] != \cf4 ""\cf0 ) \{\
						mid = right;\
						cout << \cf4 "Found new mid string "\cf0  << arr[mid] << \cf4 " with mid "\cf0  << mid << endl;\
						
\f1\b \cf3 break
\f0\b0 \cf0 ;\
					\}\
					right++;\
				\}\
			\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
				
\f1\b \cf3 while
\f0\b0 \cf0 (left>=start) \{\
					
\f1\b \cf3 if
\f0\b0 \cf0  (arr[left] != \cf4 ""\cf0 ) \{\
						mid = left;\
						cout << \cf4 "Found new mid string "\cf0  << arr[mid] << \cf4 " with mid "\cf0  << mid << endl;\
						
\f1\b \cf3 break
\f0\b0 \cf0 ;\
					\}\
					left--;\
				\}\
			\}\
		\}\
		
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] == \cf4 ""\cf0 )\
			
\f1\b \cf3 return
\f0\b0 \cf0  -1;\
	\}\
	
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] == val)\
		
\f1\b \cf3 return
\f0\b0 \cf0  mid;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (val.compare(arr[mid]) < 0)\
		
\f1\b \cf3 return
\f0\b0 \cf0 (SparseSearch(arr, start, mid-1, val));\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		
\f1\b \cf3 return
\f0\b0 \cf0 (SparseSearch(arr, mid+1, end, val));\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
\
	\cf2 //string \ul arr\ulnone [] = \{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""\};\cf0 \
	\cf5 string\cf0  arr[] = \{\cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 ""\cf0 , \cf4 "k"\cf0 \};\
 	\cf5 string\cf0  val = \cf4 "ball"\cf0 ;\
	
\f1\b \cf3 int
\f0\b0 \cf0  res = SparseSearch(arr, 0, 11, val);\
	
\f1\b \cf3 if
\f0\b0 \cf0  (res==-1)\
		cout << val << \cf4 " not found!"\cf0  << endl;\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		cout << val << \cf4 " found at "\cf0  << res << endl;\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}