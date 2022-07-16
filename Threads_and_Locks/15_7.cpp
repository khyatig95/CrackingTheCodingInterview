{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;\red100\green40\blue128;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	FizzBuzz : Have a parent thread that does incrementing and \ul num\ulnone  printing.\cf0 \
\cf2 //              Launch children thread to print the appropriate string\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <thread>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <mutex>\cf0 \
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b printFizzBuzz
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  count) \{\
    
\f1\b \cf3 if
\f0\b0 \cf0  ((count%3 == 0) && (count%5 == 0)) cout << \cf4 "FizzBuzz"\cf0 ;\
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b printFizz
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  count) \{\
    
\f1\b \cf3 if
\f0\b0 \cf0  ((count%3 == 0) && (count%5 != 0)) cout << \cf4 "\ul Fizz\ulnone "\cf0 ;\
    \
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b printBuzz
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  count) \{\
    
\f1\b \cf3 if
\f0\b0 \cf0  ((count%3 != 0) && (count%5 == 0)) cout << \cf4 "Buzz"\cf0 ;\
\}\
\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
    \
    
\f1\b \cf3 auto
\f0\b0 \cf0  lambda = [](
\f1\b \cf3 int
\f0\b0 \cf0  n) \{\
        
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  count = 0; count <= n ; count++) \{\
            cout << endl << count << \cf4 " "\cf0 ;\
            \
            \cf5 thread\cf0  t1(printFizzBuzz, count);\
            \cf5 thread\cf0  t2(printFizz, count);\
            \cf5 thread\cf0  t3(printBuzz, count);\
            t1.
\f1\b \cf6 join
\f0\b0 \cf0 ();\
            t2.
\f1\b \cf6 join
\f0\b0 \cf0 ();\
            t3.
\f1\b \cf6 join
\f0\b0 \cf0 ();\
        \}\
    \};\
    \
    \cf5 thread\cf0  tnum(lambda, 15);\
    tnum.
\f1\b \cf6 join
\f0\b0 \cf0 ();\
    \
    
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}}