{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Bold;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red127\green0\blue85;\red42\green0\blue255;\red63\green127\blue95;
\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\b\fs24 \cf2 #include
\f1\b0 \cf0  \cf3 <iostream>\cf0  \

\f0\b \cf2 #include
\f1\b0 \cf0  \cf3 <string>\cf0   \

\f0\b \cf2 #include
\f1\b0 \cf0  \cf3 <array>\cf0 \

\f0\b \cf2 #include
\f1\b0 \cf0  \cf3 <algorithm>\cf0 \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std; \
\pard\pardeftab720
\cf4 //Assumption :  String is made of the 26 alphabets/characters only. \cf0 \
\cf4 //              Case \ul insentive\cf0 \ulnone \
\cf4 //Algorithm :   isPermute : Uses an array to store the frequency\cf0 \
\cf4 //              of each character in string1 and then compares with string2. \cf0 \
\cf4 //              Time : O(N) ; Space : O(c) where c = \ul num\ulnone  characters \cf0 \
\cf4 //              isPermute_sort : Sorts both the strings and compares them.\cf0 \
\cf4 //              Doesn't need additional data structure. \cf0 \
\cf4 //              Time : O(NlogN) ; Space : That of the sorting \ul algo\cf0 \ulnone \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  : \
            
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b isPermute
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  \ul str2\ulnone );\
            
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b isPermute_sort
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2);\
    
\f0\b \cf2 private
\f1\b0 \cf0  :\
            \cf5 array\cf0 <
\f0\b \cf2 int
\f1\b0 \cf0 ,26> \cf6 charCount\cf0 ;\
\};\
\

\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b myClass::isPermute
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2) \{\
    
\f0\b \cf2 int
\f1\b0 \cf0  index;\
    \cf6 charCount\cf0 .fill(0); \cf4 //Assign all zeroes\cf0 \
    
\f0\b \cf2 if
\f1\b0 \cf0  (str1.size() != str2.size()) \{ \cf4 //If string size not same, can't be permutations\cf0 \
        cout << \cf3 "String1 size is "\cf0  << str1.size() << \cf3 " which is not equal to String2 size "\cf0  << str2.size() << endl; \
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;  \
    \}\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 auto
\f1\b0 \cf0  itr=str1.begin(); itr!=str1.end(); ++itr) \{\
        index = 
\f0\b \cf2 int
\f1\b0 \cf0 (*itr) - 
\f0\b \cf2 int
\f1\b0 \cf0 (\cf3 'a'\cf0 ); \cf4 //'a' is \ul strored\ulnone  at the 0th position\cf0 \
        cout << \cf3 "index of char "\cf0  << *itr << \cf3 " is "\cf0  << index; \
        \cf6 charCount\cf0 [index]++;\
        cout << \cf3 " Count of char "\cf0  << *itr << \cf3 " is "\cf0  << \cf6 charCount\cf0 [index] << endl; \
    \}\
    cout << endl << \cf3 "Starting String2"\cf0  << endl;\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 auto
\f1\b0 \cf0  itr=str2.begin(); itr!=str2.end(); ++itr) \{\
        index = 
\f0\b \cf2 int
\f1\b0 \cf0 (*itr) - 
\f0\b \cf2 int
\f1\b0 \cf0 (\cf3 'a'\cf0 ); \cf4 //'a' is \ul strored\ulnone  at the 0th position\cf0 \
        cout << \cf3 "index of char "\cf0  << *itr << \cf3 " is "\cf0  << index; \
        \cf6 charCount\cf0 [index]--;\
        cout << \cf3 " Count of char "\cf0  << *itr << \cf3 " is "\cf0  << \cf6 charCount\cf0 [index] << endl; \
        
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 charCount\cf0 [index] < 0) \{\
            cout << \cf3 "Char count of char "\cf0  << *itr << \cf3 " doesn't match!"\cf0  << endl; \
            
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
        \}\
    \}\
    
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 true
\f1\b0 \cf0 ;\
\}\
\

\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b myClass :: isPermute_sort
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2) \{\
    
\f0\b \cf2 if
\f1\b0 \cf0  (str1.size() != str2.size()) \{ \cf4 //If string size not same, can't be permutations\cf0 \
        cout << \cf3 "String1 size is "\cf0  << str1.size() << \cf3 " which is not equal to String2 size "\cf0  << str2.size() << endl; \
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;  \
    \}\
    sort(str1.begin(), str1.end());\
    sort(str2.begin(), str2.end());\
    cout << \cf3 "Sorted string1 is "\cf0  << str1 << endl; \
    cout << \cf3 "Sorted string2 is "\cf0  << str2 << endl; \
\
    
\f0\b \cf2 if
\f1\b0 \cf0  (str1 != str2) \
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 true
\f1\b0 \cf0 ;\
\}\
\

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 () \
\{ \
    \cf5 myClass\cf0  obj;\
    \cf5 string\cf0  test1 = \cf3 "\ul abcdxyzde\ulnone "\cf0 ;\
    \cf5 string\cf0  test2 = \cf3 "\ul abcdedzyx\ulnone "\cf0 ;\
    
\f0\b \cf2 if
\f1\b0 \cf0  (obj.isPermute_sort(test1, test2)) \
        cout << \cf3 "String "\cf0  << test1 << \cf3 " is a permutation of String "\cf0  << test2 << endl;\
    
\f0\b \cf2 else
\f1\b0 \cf0  \
        cout << \cf3 "String "\cf0  << test1 << \cf3 " is NOT a permutation of String "\cf0  << test2 << endl;\
        \
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}