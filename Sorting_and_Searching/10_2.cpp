{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	groupAnagrams : Create a \ul hashmap\ulnone  with key=sorted string and value=linked list of all\cf0 \
\cf2 //								strings that sort to that key\cf0 \
\cf2 //								M = \ul num\ulnone  elements in B\cf0 \
\cf2 //Time Complexity : O(MNlogN) due to sorting where M = number of strings in the array and N=\ul avg\ulnone  size of string\cf0 \
\cf2 //Space Complexity : O(NM)\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <unordered_map>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <forward_list>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <string>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <algorithm>\cf0 \
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
\pard\pardeftab720
\cf6 string\cf0 * 
\f1\b groupAnagrams
\f0\b0 (\cf6 string\cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	\cf6 unordered_map\cf0 <\cf6 string\cf0 , \cf6 forward_list\cf0 <\cf6 string\cf0 > > umap;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++) \{\
		\cf6 forward_list\cf0 <\cf6 string\cf0 > lis;\
\
		\cf2 //Sort the string\cf0 \
		\cf6 string\cf0  temp = arr[i];\
		sort(temp.begin(), temp.end());\
		cout << \cf4 "Processing string "\cf0  << arr[i] << \cf4 " that sorts to "\cf0  << temp << endl;\
		
\f1\b \cf3 if
\f0\b0 \cf0  (umap.find(temp) != umap.end()) \{  \cf2 //Sorted string exists\cf0 \
			lis = umap[temp];  \cf2 //Get the list pointer\cf0 \
			cout << \cf4 "The sorted string already exists"\cf0  << endl;\
		\}\
		\cf2 //Add the current string to the list\cf0 \
		lis.push_front(arr[i]);\
		cout << \cf4 "List at "\cf0  << temp << \cf4 " : "\cf0 ;\
		
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 auto
\f0\b0 \cf0  itr=lis.begin(); itr!=lis.end(); itr++) \{\
			cout << *itr << \cf4 " "\cf0 ;\
		\}\
		cout << endl;\
		\cf2 //Add the list pointer to \ul hashmap\cf0 \ulnone \
		umap[temp] = lis;\
	\}\
\
	\cf2 //Iterate through \ul hashmap\cf0 \ulnone \
	
\f1\b \cf3 int
\f0\b0 \cf0  index = 0;\
	
\f1\b \cf3 for
\f0\b0 \cf0 (
\f1\b \cf3 auto
\f0\b0 \cf0  x : umap) \{\
		\cf6 forward_list\cf0 <\cf6 string\cf0 > lis = x.\cf7 second\cf0 ;  \cf2 //NOTE!!! NO () after second\cf0 \
		
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 auto
\f0\b0 \cf0  itr=lis.begin(); itr!=lis.end(); itr++) \{\
			arr[index] = *itr;\
			index++;\
		\}\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  arr;\
\}\
\
\pard\pardeftab720

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //Has anagrams\cf0 \
	\cf2 //string \ul arr\ulnone [7] = \{ "calm", "dead", "why", "\ul adde\ulnone ", "\ul kilo\ulnone ", "\ul mlca\ulnone ", "one"\};\cf0 \
 	\cf2 //\ul Doesnt\ulnone  have anagrams\cf0 \
	\cf6 string\cf0  arr[7] = \{\cf4 "calm"\cf0 , \cf4 "dead"\cf0 , \cf4 "why"\cf0 , \cf4 "\ul tho\ulnone "\cf0 , \cf4 "\ul kay\ulnone "\cf0 , \cf4 "nope"\cf0 , \cf4 "six"\cf0  \};\
\
	cout << \cf4 "Original array : "\cf0  << endl;\
	printArr<\cf6 string\cf0 >(arr, 7);\
	\cf6 string\cf0 * res = groupAnagrams(arr, 7);\
	cout << endl << \cf4 "Sorted string array : "\cf0  << endl;\
	printArr<\cf6 string\cf0 >(res, 7);\
\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
\
}