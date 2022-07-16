{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;\red0\green0\blue192;\red100\green40\blue128;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	CallInOrder : Use 2 different \ul mutexes\ulnone  for second and third. Unlock in first and second.\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <mutex>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <thread>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\

\f1\b \cf3 class
\f0\b0 \cf0  \cf5 Foo\cf0  \{\

\f1\b \cf3 private
\f0\b0 \cf0  :\
    \cf5 mutex\cf0  \cf6 m1\cf0 ;\
    \cf5 mutex\cf0  \cf6 m2\cf0 ;\
        \

\f1\b \cf3 public
\f0\b0 \cf0  :\
    
\f1\b Foo
\f0\b0 () \{\
        \cf6 m1\cf0 .
\f1\b \cf7 lock
\f0\b0 \cf0 ();\
        \cf6 m2\cf0 .
\f1\b \cf7 lock
\f0\b0 \cf0 ();\
    \}\
    
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b first
\f0\b0 () \{\
        cout << \cf4 "\ul Hi\ulnone  I am in first"\cf0  << endl;\
        \cf6 m1\cf0 .
\f1\b \cf7 unlock
\f0\b0 \cf0 ();\
    \}    \
    
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b second
\f0\b0 () \{\
        cout << \cf4 "Entered second"\cf0  << endl;\
        \cf6 m1\cf0 .
\f1\b \cf7 lock
\f0\b0 \cf0 ();\
        cout << \cf4 "\ul Hi\ulnone  I am in second"\cf0  << endl;\
        \cf6 m2\cf0 .
\f1\b \cf7 unlock
\f0\b0 \cf0 ();\
    \}\
    
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b third
\f0\b0 () \{\
        cout << \cf4 "Entered third"\cf0  << endl;\
        \cf6 m2\cf0 .
\f1\b \cf7 lock
\f0\b0 \cf0 ();\
        cout << \cf4 "\ul Hi\ulnone  I am in third"\cf0  << endl;\
    \}\
\};\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
    \cf5 Foo\cf0 * f = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Foo\cf0 ();\
    \
    \cf5 thread\cf0  t1(&\cf5 Foo\cf0 ::first, f);\
    \cf5 thread\cf0  t2(&\cf5 Foo\cf0 ::second, f);\
    \cf5 thread\cf0  t3(&\cf5 Foo\cf0 ::third, f);\
    \
    t1.
\f1\b \cf7 join
\f0\b0 \cf0 ();\
    t2.
\f1\b \cf7 join
\f0\b0 \cf0 ();\
    t3.
\f1\b \cf7 join
\f0\b0 \cf0 ();\
    \
    
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}}