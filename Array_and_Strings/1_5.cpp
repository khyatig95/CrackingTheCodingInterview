{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Bold;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red127\green0\blue85;\red42\green0\blue255;\red63\green127\blue95;
\red0\green80\blue50;\red0\green0\blue192;\red100\green40\blue128;}
\margl1440\margr1440\vieww28300\viewh14680\viewkind0
\deftab720
\pard\pardeftab720

\f0\b\fs24 \cf2 #include
\f1\b0 \cf0  \cf3 <iostream>\cf0 \

\f0\b \cf2 #include
\f1\b0 \cf0  \cf3 <cstdlib>\cf0 \

\f0\b \cf2 #include
\f1\b0 \cf0  \cf3 <string>\cf0 \

\f0\b \cf2 #include
\f1\b0 \cf0  \cf3 <array>\cf0 \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std;\
\pard\pardeftab720
\cf4 //Assumption:   No white spaces. Case insensitive. isOneEdit does not care about relative ordering!!!\cf0 \
\cf4 //Algorithm :   isOneEdit : Use an \ul int\ulnone  array to store frequency of all char of longer\cf0 \
\cf4 //              string. Then subtract from same array for string 2.\cf0 \
\cf4 //              Time : O(N) where N is length of small string; Space : O(c) where c=\ul num\ulnone  char\cf0 \
\cf4 //              OneEditType : Identifies if the two strings are one edit away and type of edit.\cf0 \
\cf4 //              Time : O(N);    Space : O(1)\cf0 \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  :\
            
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b isOneEdit
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2);\
            \cf5 string\cf0  
\f0\b OneEditType
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2);\
    
\f0\b \cf2 private
\f1\b0 \cf0  :\
            \cf5 array\cf0 <
\f0\b \cf2 int
\f1\b0 \cf0 ,26> \cf6 charCount\cf0 ;\
            
\f0\b \cf2 int
\f1\b0 \cf0  \cf6 index\cf0 , \cf6 index1\cf0 , \cf6 index2\cf0 , \cf6 difference\cf0 ;\
            
\f0\b \cf2 bool
\f1\b0 \cf0  \cf6 isDifferent\cf0 ;\
\};\
\

\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b myClass::isOneEdit
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2) \{\
    \cf6 charCount\cf0 .fill(0);\
    \cf6 index\cf0  = 0;\
    \cf6 isDifferent\cf0  = 
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    \cf6 difference\cf0  = str1.size() - str2.size();\
    
\f0\b \cf2 if
\f1\b0 \cf0  (
\f0\b \cf7 abs
\f1\b0 \cf0 (\cf6 difference\cf0 ) > 1) \cf4 //Strings should not differ by more than 1 in length\cf0 \
        
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
\
    \cf4 //Store the character count of longer string\cf0 \
    \cf5 string\cf0 ::\cf5 iterator\cf0  first = str1.size() > str2.size() ? str1.begin() : str2.begin();\
    \cf5 string\cf0 ::\cf5 iterator\cf0  last = str1.size() > str2.size() ? str1.end() : str2.end();\
    
\f0\b \cf2 \ul \ulc2 for
\f1\b0 \cf0 \ulc0 (
\f0\b \cf2 \ulc2 auto
\f1\b0 \cf0 \ulc0  itr=first; itr!=last; ++itr) \{\ulnone \
        \cf6 index\cf0  = 
\f0\b \cf2 int
\f1\b0 \cf0 (*itr) - 
\f0\b \cf2 int
\f1\b0 \cf0 (\cf3 'a'\cf0 );\
        \cf6 charCount\cf0 [\cf6 index\cf0 ] ++;\
    \}\
\
    \cf4 //Manipulate previous character count with shorter string\cf0 \
    first = str1.size() > str2.size() ? str2.begin() : str1.begin();\
    last = str1.size() > str2.size() ? str2.end() : str1.end();\
    
\f0\b \cf2 \ul \ulc2 for
\f1\b0 \cf0 \ulc0 (
\f0\b \cf2 \ulc2 auto
\f1\b0 \cf0 \ulc0  itr=first; itr!=last; ++itr) \{\ulnone \
        \cf6 index\cf0  = 
\f0\b \cf2 int
\f1\b0 \cf0 (*itr) - 
\f0\b \cf2 int
\f1\b0 \cf0 (\cf3 'a'\cf0 );\
        --\cf6 charCount\cf0 [\cf6 index\cf0 ];\
        
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 charCount\cf0 [\cf6 index\cf0 ] < 0) \{\
            
\f0\b \cf2 if
\f1\b0 \cf0  (str1.size() == str2.size()) \{ \cf4 //Replace\cf0 \
                
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 isDifferent\cf0 )\
                    
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ; \cf4 //2 differences;\cf0 \
                
\f0\b \cf2 else
\f1\b0 \cf0 \
                    \cf6 isDifferent\cf0  = 
\f0\b \cf2 true
\f1\b0 \cf0 ;\
            \} 
\f0\b \cf2 else
\f1\b0 \cf0   \cf4 //Insertion\cf0 \
                
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
\pard\pardeftab720
\cf5 string\cf0  
\f0\b myClass :: OneEditType
\f1\b0 (\cf5 string\cf0  str1, \cf5 string\cf0  str2) \{\
    \cf6 difference\cf0  = str1.size() - str2.size();\
    
\f0\b \cf2 if
\f1\b0 \cf0  (
\f0\b \cf7 abs
\f1\b0 \cf0 (\cf6 difference\cf0 ) > 1) \cf4 //Strings should not differ by more than 1 in length\cf0 \
        
\f0\b \cf2 return
\f1\b0 \cf0  \cf3 "false"\cf0 ;\
\
    \cf6 isDifferent\cf0  = 
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    \cf6 index1\cf0  = 0;\
    \cf6 index2\cf0  = 0;\
\
    
\f0\b \cf2 while
\f1\b0 \cf0 (\cf6 index1\cf0  < str1.size() && \cf6 index2\cf0  < str2.size()) \{\
        
\f0\b \cf2 if
\f1\b0 \cf0  (str1[\cf6 index1\cf0 ] != str2[\cf6 index2\cf0 ]) \{\
            cout << str1[\cf6 index1\cf0 ] << \cf3 " is not equal to "\cf0  << str2[\cf6 index2\cf0 ] << endl;\
            
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 isDifferent\cf0 ) \cf4 //More than one difference\cf0 \
                
\f0\b \cf2 return
\f1\b0 \cf0  \cf3 "false"\cf0 ;\
            
\f0\b \cf2 else
\f1\b0 \cf0 \
                \cf6 isDifferent\cf0  = 
\f0\b \cf2 true
\f1\b0 \cf0 ;\
            
\f0\b \cf2 if
\f1\b0 \cf0  (str1.size() >= str2.size()) \{\
				cout << \cf3 "\ul incr\ulnone  index1"\cf0  << endl;\
				\cf6 index1\cf0 ++;\
			\}\
		  
\f0\b \cf2 if
\f1\b0 \cf0  (str2.size() >= str1.size()) \{\
				cout << \cf3 "\ul incr\ulnone  index2"\cf0  << endl;\
				\cf6 index2\cf0 ++;\
	       \}\
        \} 
\f0\b \cf2 else
\f1\b0 \cf0  \{\
			cout << \cf3 "\ul incr\ulnone  both"\cf0  << endl;\
        	\cf6 index1\cf0 ++;\
        	\cf6 index2\cf0 ++;\
        \}\
\
    \}\
    
\f0\b \cf2 if
\f1\b0 \cf0  (str1.size() == str2.size())\
        
\f0\b \cf2 return
\f1\b0 \cf0  \cf3 "Replace"\cf0 ;\
    
\f0\b \cf2 else
\f1\b0 \cf0 \
        
\f0\b \cf2 return
\f1\b0 \cf0  \cf3 "Insert"\cf0 ;\
\}\
\
\pard\pardeftab720

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 ()\
\{\
    \cf5 myClass\cf0  obj;\
    \cf5 string\cf0  test1 = \cf3 "\ul paaale\ulnone "\cf0 ;\
    \cf5 string\cf0  test2 = \cf3 "pale"\cf0 ;\
\
    
\f0\b \cf2 if
\f1\b0 \cf0  (obj.isOneEdit(test1, test2))\
        cout << \cf3 "String "\cf0  << test1 << \cf3 " is a one edit of string "\cf0  << test2 << endl;\
    
\f0\b \cf2 else
\f1\b0 \cf0 \
        cout << \cf3 "String "\cf0  << test1 << \cf3 " is NOT a one edit of string "\cf0  << test2 << endl;\
\
    cout << \cf3 "Strings are related as: "\cf0  << endl << obj.OneEditType(test1, test2) << endl;\
\
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}