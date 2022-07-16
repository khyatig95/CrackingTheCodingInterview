{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Bold;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red127\green0\blue85;\red42\green0\blue255;\red63\green127\blue95;
\red0\green80\blue50;\red0\green0\blue192;\red100\green40\blue128;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\b\fs24 \cf2 #include
\f1\b0 \cf0  \cf3 <iostream>\cf0  \

\f0\b \cf2 #include
\f1\b0 \cf0  \cf3 <string>\cf0 \

\f0\b \cf2 #include
\f1\b0 \cf0  \cf3 <algorithm>\cf0 \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std; \
\pard\pardeftab720
\cf4 //Assumption:   No white spaces. Case insensitive\cf0 \
\cf4 //Algorithm :   Compress : Use another string to store the compressed string. \cf0 \
\cf4 //              Returns whichever string is smaller\cf0 \
\cf4 //              Time : O(N); Space : O(N) as we need a new string\cf0 \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  : \
            \cf5 string\cf0  
\f0\b Compress
\f1\b0 (\cf5 string\cf0  str);\
    
\f0\b \cf2 private
\f1\b0 \cf0  :\
            \cf5 string\cf0  \cf6 compressed\cf0 ;\
            
\f0\b \cf2 int
\f1\b0 \cf0  \cf6 count\cf0 , \cf6 n\cf0 ;\
            
\f0\b \cf2 char
\f1\b0 \cf0  \cf6 count_str\cf0 [32];\
\
            \
\};\
\
\pard\pardeftab720
\cf5 string\cf0  
\f0\b myClass::Compress
\f1\b0 (\cf5 string\cf0  str) \{\
    \cf6 count\cf0  = 1;\
    cout << \cf3 "The string is "\cf0  << str << endl;\
  \
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 auto
\f1\b0 \cf0  itr=str.begin(); itr!=str.end(); ++itr) \{\
        
\f0\b \cf2 if
\f1\b0 \cf0  (*itr == *(itr+1))\
            ++\cf6 count\cf0 ;\
        
\f0\b \cf2 else
\f1\b0 \cf0  \{\
            \cf6 compressed\cf0 .push_back(*itr);\
            \cf6 n\cf0 =
\f0\b \cf7 sprintf
\f1\b0 \cf0 (\cf6 count_str\cf0 , \cf3 "%d"\cf0 , \cf6 count\cf0 );\
            cout << \cf3 "Count string is "\cf0  << \cf6 count_str\cf0  << endl;\
            \cf6 compressed\cf0 .append(\cf6 count_str\cf0 );\
            \cf6 count\cf0  = 1;\
        \}\
    \}\
    cout << \cf3 "The compressed string is "\cf0  << \cf6 compressed\cf0  << endl;\
    
\f0\b \cf2 if
\f1\b0 \cf0  (str.size() > \cf6 compressed\cf0 .size())\
        
\f0\b \cf2 return
\f1\b0 \cf0  \cf6 compressed\cf0 ;\
    
\f0\b \cf2 else
\f1\b0 \cf0  \
        
\f0\b \cf2 return
\f1\b0 \cf0  str;\
\}\
\
\pard\pardeftab720

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 () \
\{ \
    \cf5 myClass\cf0  obj;\
    \cf5 string\cf0  test1 = \cf3 "\ul abcddeeeee\ulnone "\cf0 ;\
    \
    cout << \cf3 "Compressed string is "\cf0  << obj.Compress(test1) << endl;\
    \
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}