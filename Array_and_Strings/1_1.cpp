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

\f0\b \cf2 #incl\cf0 ude 
\f1\b0 \cf3 <algorithm>\cf0 \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std; \
\pard\pardeftab720
\cf4 //Assumption :  String is made of the 26 alphabets/characters only. \cf0 \
\cf4 //              Case \ul insentive\cf0 \ulnone \
\cf4 //Algorithm :   isUnique : Uses \ul int\ulnone  variable to store the frequency\cf0 \
\cf4 //              of each character in the string. \cf0 \
\cf4 //              Time : O(N) ; Space : O(c) where c = total \ul num\ulnone  characters \cf0 \
\cf4 //              isUnique_sort : Sorts the string and compares immediate\cf0 \
\cf4 //              neighbors. Doesn't need additional data structure. \cf0 \
\cf4 //              Time : O(NlogN) ; Space : That of the sorting \ul algo\cf0 \ulnone \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  : \
            
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b isUnique
\f1\b0 (\cf5 string\cf0  str);\
            
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b isUnique_sort
\f1\b0 (\cf5 string\cf0  str);\
    
\f0\b \cf2 private
\f1\b0 \cf0  :\
            
\f0\b \cf2 int
\f1\b0 \cf0  \cf6 charCount\cf0 ;\
\};\
\

\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b myClass::isUnique
\f1\b0 (\cf5 string\cf0  str) \{\
    
\f0\b \cf2 int
\f1\b0 \cf0  index;\
    \cf6 charCount\cf0  = 0;\
    
\f0\b \cf2 if
\f1\b0 \cf0  (str.size() > 26) \{ \cf4 //No way that it is unique as we only have 26 characters\cf0 \
        cout << \cf3 "String size is "\cf0  << str.size() << \cf3 " which is greater than \ul num\ulnone  char"\cf0  << endl; \cf4 //DEBUG\cf0 \
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;  \
    \}\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 auto
\f1\b0 \cf0  itr=str.begin(); itr!=str.end(); ++itr) \{\
        index = 
\f0\b \cf2 int
\f1\b0 \cf0 (*itr) - 
\f0\b \cf2 int
\f1\b0 \cf0 (\cf3 'a'\cf0 ); \cf4 //'a' is \ul strored\ulnone  at the 0th position\cf0 \
        cout << \cf3 "index of char "\cf0  << *itr << \cf3 " is "\cf0  << index << endl; \cf4 //DEBUG\cf0 \
        cout << \cf3 "Current charCount is "\cf0  << \cf6 charCount\cf0  << endl; \cf4 //DEBUG\cf0 \
        
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 charCount\cf0  & (1<<index)) \{ \cf4 //This character has already been encountered\cf0 \
            
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
        \} 
\f0\b \cf2 else
\f1\b0 \cf0  \{\
            \cf6 charCount\cf0  = \cf6 charCount\cf0  + (1<<index);\
            cout << \cf3 "New charCount is "\cf0  << \cf6 charCount\cf0  << endl; \cf4 //DEBUG\cf0 \
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
\f0\b myClass :: isUnique_sort
\f1\b0 (\cf5 string\cf0  str) \{\
    
\f0\b \cf2 if
\f1\b0 \cf0  (str.size() > 26) \{ \cf4 //No way that it is unique as we only have 26 characters\cf0 \
        cout << \cf3 "String size is "\cf0  << str.size() << \cf3 " which is greater than \ul num\ulnone  char"\cf0  << endl; \cf4 //DEBUG\cf0 \
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;  \
    \}\
    sort(str.begin(), str.end());\
    cout << \cf3 "Sorted string is "\cf0  << str << endl;\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 auto
\f1\b0 \cf0  itr=str.begin(); itr!=(str.end()-1); ++itr) \{\
        cout << \cf3 "Processing char "\cf0  << *itr << endl; \cf4 //DEBUG\cf0 \
        
\f0\b \cf2 if
\f1\b0 \cf0  (*itr == *(itr+1)) \cf4 //Same as next char\cf0 \
            
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    \}\
    
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
    \cf5 string\cf0  test = \cf3 "\ul abcdxyzd\ulnone "\cf0 ;\
    
\f0\b \cf2 if
\f1\b0 \cf0  (obj.isUnique_sort(test)) \
        cout << \cf3 "String "\cf0  << test << \cf3 " is Unique"\cf0  << endl;\
    
\f0\b \cf2 else
\f1\b0 \cf0  \
        cout << \cf3 "String "\cf0  << test << \cf3 " is NOT Unique"\cf0  << endl;\
        \
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}}