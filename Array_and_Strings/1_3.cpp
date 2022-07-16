{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Bold;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red127\green0\blue85;\red42\green0\blue255;\red63\green127\blue95;
\red0\green80\blue50;}
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
\cf4 //Algorithm :   URLify : Iterate from the rear to shift non-white space \cf0 \
\cf4 //              characters to the end and then add the %20 whenever space \cf0 \
\cf4 //              is encountered\cf0 \
\cf4 //              Time : O(N) ; Space : O(1) as not using extra data structure\cf0 \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  : \
            \cf5 string\cf0  
\f0\b URLify
\f1\b0 (\cf5 string\cf0  str);\
\};\
\
\pard\pardeftab720
\cf5 string\cf0  
\f0\b myClass::URLify
\f1\b0 (\cf5 string\cf0  str) \{\
    
\f0\b \cf2 bool
\f1\b0 \cf0  true_length = 
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    \cf5 string\cf0 ::\cf5 iterator\cf0  tail = str.end()-1; \cf4 //The end() points to a location after the end. That's why -1 is needed\cf0 \
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 auto
\f1\b0 \cf0  itr=str.rbegin(); itr!=str.rend(); ++itr) \{\
        cout << \cf3 "Processing char "\cf0  << *itr ;\
        
\f0\b \cf2 if
\f1\b0 \cf0  (isspace(*itr)) \{\
            cout << \cf3 " which is a white space"\cf0  << endl;\
            
\f0\b \cf2 if
\f1\b0 \cf0  (!true_length)\
                
\f0\b \cf2 continue
\f1\b0 \cf0 ;\
            
\f0\b \cf2 else
\f1\b0 \cf0  \{\
                *tail = \cf3 '0'\cf0 ;\
                --tail;\
                *tail = \cf3 '2'\cf0 ;\
                --tail;\
                *tail = \cf3 '%'\cf0 ;\
                --tail;\
            \}\
        \} 
\f0\b \cf2 else
\f1\b0 \cf0  \{\
            cout << \cf3 " which is NOT a whitespace"\cf0  << endl;\
            
\f0\b \cf2 if
\f1\b0 \cf0  (!true_length) \{\
                cout << \cf3 "Set true_length to true "\cf0  << endl;\
                true_length = 
\f0\b \cf2 true
\f1\b0 \cf0 ;\
            \}\
            *tail = *itr;\
            --tail;\
            *itr = \cf3 ' '\cf0 ;         \cf4 //This is needed to delete the char from original position\cf0 \
        \}\
        cout << \cf3 "String is "\cf0  << str << endl;\
    \}\
    
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
    \cf5 string\cf0  test1 = \cf3 " \ul Khyati\ulnone  is coding         "\cf0 ;\
\
    \cf5 string\cf0  test2 = obj.URLify(test1);\
    cout << \cf3 "String1 is "\cf0  << test1 << \cf3 " and its URLified version is "\cf0  << test2 << endl;\
    \
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}