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
\f1\b0 \cf0  \cf3 <string>\cf0 \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std; \
\pard\pardeftab720
\cf4 //Assumption:   No white spaces\cf0 \
\cf4 //Algorithm :   isRotation : Create a new string that is concatenation of str1 \cf0 \
\cf4 //              with itself. Check if str2 is a \ul substr\ulnone  of the new string\cf0 \
\cf4 //              Time : O(substring \ul algo\ulnone ) = O(N); Space : O(N) as creating new string\cf0 \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  :\
        
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b isRotation
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2);\
        
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b isSubstr
\f1\b0 (\cf5 string\cf0  ls, \cf5 string\cf0  ss);  \
    
\f0\b \cf2 private
\f1\b0 \cf0  :\
        \cf5 string\cf0  \cf6 concat\cf0 ;\
\};\
\

\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b myClass :: isRotation
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2) \{\
    
\f0\b \cf2 if
\f1\b0 \cf0  (str1.size() != str2.size()) \cf4 //Have to be of the same length for rotation\cf0 \
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    
\f0\b \cf2 if
\f1\b0 \cf0  (str1.empty() || str2.empty()) \cf4 //Can't be empty\cf0 \
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
        \
    \cf6 concat\cf0  = str1 + str1;\
    cout << \cf3 "Concatenated string is "\cf0  << \cf6 concat\cf0  << endl;\
    
\f0\b \cf2 if
\f1\b0 \cf0  (isSubstr(\cf6 concat\cf0 , str2))\
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 true
\f1\b0 \cf0 ;\
    
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
\}\
\

\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b myClass :: isSubstr
\f1\b0 (\cf5 string\cf0  ls, \cf5 string\cf0  ss) \{\
    
\f0\b \cf2 int
\f1\b0 \cf0  index1 = 0;\
    
\f0\b \cf2 while
\f1\b0 \cf0  (index1 < ls.size()) \{\
        
\f0\b \cf2 if
\f1\b0 \cf0  (ls[index1] == ss[0]) \{\
            cout << ls[index1] << \cf3 " in longer string is equal to "\cf0  << ss[0] << \cf3 " in shorter string "\cf0  << endl;\
            
\f0\b \cf2 if
\f1\b0 \cf0  (ls.substr(index1, ss.size()) == ss) \{\
                
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 true
\f1\b0 \cf0 ;\
            \} 
\f0\b \cf2 else
\f1\b0 \cf0  \{\
                cout << \cf3 "No substring at this long string index "\cf0  << endl;\
            \}\
        \}\
        index1++;\
    \}\
    
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
\}\
\
\

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 () \{\
    \cf5 myClass\cf0  obj;\
    \
    \cf5 string\cf0  test1 = \cf3 "\ul waterbottle\ulnone "\cf0 ;\
    \cf5 string\cf0  test2 = \cf3 "\ul terbottlewa\ulnone "\cf0 ;\
    \
    
\f0\b \cf2 if
\f1\b0 \cf0  (obj.isRotation(test1, test2))\
        cout << \cf3 "Strings are rotated"\cf0  << endl;\
    
\f0\b \cf2 else
\f1\b0 \cf0  \
        cout << \cf3 "Strings are NOT rotated"\cf0  << endl;\
\
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\};\ul \}}