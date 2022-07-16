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
\f1\b0 \cf0  \cf3 <cctype>\cf0 \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std; \
\pard\pardeftab720
\cf4 //Assumption : Case insensitive\cf0 \
\cf4 //Algorithm :   isPalindrome : Use an \ul int\ulnone  variable and switch 1 and 0 when the char\cf0 \
\cf4 //              occurs. All letters should occur even number of times if non white \cf0 \
\cf4 //              space char in string are even. => \ul int\ulnone  should be 0\cf0 \
\cf4 //              Only one letter should appear odd times if non white space char in \cf0 \
\cf4 //              string length are odd =>\ul int\ulnone  should have just one 1 in the bit vector\cf0 \
\cf4 //              \cf0 \
\cf4 //              Time : O(N) ; Space : O(c) where c=\ul num\ulnone  char\cf0 \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  : \
            
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b isPalindrome
\f1\b0 (\cf5 string\cf0  str);\
    
\f0\b \cf2 private
\f1\b0 \cf0  :\
            
\f0\b \cf2 int
\f1\b0 \cf0  \cf6 charCount\cf0 ;\
            
\f0\b \cf2 int
\f1\b0 \cf0  \cf6 nonWhiteCount\cf0 ;\
\};\
\

\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b myClass::isPalindrome
\f1\b0 (\cf5 string\cf0  str) \{\
    \cf6 charCount\cf0  = 0;\
    \cf6 nonWhiteCount\cf0  = 0;\
    
\f0\b \cf2 int
\f1\b0 \cf0  index;\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 auto
\f1\b0 \cf0  itr = str.begin(); itr!=str.end(); ++itr) \{\
        index = 
\f0\b \cf2 int
\f1\b0 \cf0 (*itr) - 
\f0\b \cf2 int
\f1\b0 \cf0 (\cf3 'a'\cf0 ); \cf4 //We want to store char a count at the 0th bit\cf0 \
        
\f0\b \cf2 if
\f1\b0 \cf0  (!isspace(*itr)) \{\
            \cf6 nonWhiteCount\cf0 ++;\
            cout << \cf3 "Processing non-whitespace char "\cf0  << *itr << endl;\
            
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 charCount\cf0  & 1<<index) \{ \cf4 //Already \ul occured\ulnone  odd times\cf0 \
                cout << *itr << \cf3 " has \ul occured\ulnone  odd times. Making it even"\cf0  << endl;\
                \cf6 charCount\cf0  -= 1<<index; \cf4 //Make the value at that bit 0 to indicate even \ul occurences\cf0 \ulnone \
            \} 
\f0\b \cf2 else
\f1\b0 \cf0  \{\
                cout << *itr << \cf3 " has \ul occured\ulnone  even times. Making it odd"\cf0  << endl;\
                \cf6 charCount\cf0  += 1<<index; \cf4 //Make the value at that bit 1 to indicate even \ul occurences\cf0 \ulnone \
            \}\
        \}\
    \}\
    
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 nonWhiteCount\cf0 %2 == 0) \{ \cf4 //even length string\cf0 \
        cout << \cf3 "String is even length"\cf0  << endl;\
        
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 charCount\cf0  == 0)\
            
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 true
\f1\b0 \cf0 ;\
        
\f0\b \cf2 else
\f1\b0 \cf0  \
            
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    \} 
\f0\b \cf2 else
\f1\b0 \cf0  \{                \cf4 //odd length string\cf0 \
        cout << \cf3 "String is odd length"\cf0  << endl;\
        
\f0\b \cf2 if
\f1\b0 \cf0  (((\cf6 charCount\cf0 -1) & \cf6 charCount\cf0 ) == 0)  \cf4 //1000-1 = 0111 => 1000 & 0111=0\cf0 \
            
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 true
\f1\b0 \cf0 ;\
        
\f0\b \cf2 else
\f1\b0 \cf0 \
            
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    \}\
\}\
\

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 () \
\{ \
    \cf5 myClass\cf0  obj;\
    \cf5 string\cf0  test1 = \cf3 "\ul khyati\ulnone "\cf0 ;\
\
    
\f0\b \cf2 if
\f1\b0 \cf0  (obj.isPalindrome(test1))\
        cout << \cf3 "String "\cf0  << test1 << \cf3 " is a permutation of \ul Palindrome\ulnone "\cf0  << endl;\
    
\f0\b \cf2 else
\f1\b0 \cf0  \
        cout << \cf3 "String "\cf0  << test1 << \cf3 " is NOT a permutation of \ul Palindrome\ulnone "\cf0  << endl;\
        \
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}