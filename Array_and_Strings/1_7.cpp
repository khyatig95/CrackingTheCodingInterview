{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Bold;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red127\green0\blue85;\red42\green0\blue255;\red63\green127\blue95;
\red0\green80\blue50;\red0\green0\blue192;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\b\fs24 \cf2 #include
\f1\b0 \cf0  \cf3 <iostream>\cf0  \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std; \

\f0\b \cf2 #define
\f1\b0 \cf0  N 4\

\f0\b \cf2 #define
\f1\b0 \cf0  ROW N\

\f0\b \cf2 #define
\f1\b0 \cf0  COL N\
\pard\pardeftab720
\cf4 //Algorithm :   RotateMatrix : \cf0 \
\cf4 //              Time : O(N^2) for NxN matrix ; Space : O(1) as we do swap per integer\cf0 \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  :\
        
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b RotateMatrix
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]);  \
        
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b printMatrix
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]);\
    
\f0\b \cf2 private
\f1\b0 \cf0  :\
        
\f0\b \cf2 int
\f1\b0 \cf0  \cf6 first\cf0 , \cf6 last\cf0 , \cf6 temp\cf0 ;\
\};\
\

\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b myClass :: RotateMatrix
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  matrix[ROW][COL]) \{\
    
\f0\b \cf2 int
\f1\b0 \cf0  offset = 0;\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  layer=0; layer<N/2; layer++) \{\
        \cf6 first\cf0  = layer;\
        \cf6 last\cf0  = N-1-layer;\
      \
        
\f0\b \cf2 for
\f1\b0 \cf0 (
\f0\b \cf2 int
\f1\b0 \cf0  num=\cf6 first\cf0 ; num<\cf6 last\cf0 ; num++)  \{\
            offset = \cf6 last\cf0 -num + layer;\
            \cf6 temp\cf0  = matrix[num][\cf6 last\cf0 ]; \cf4 //Store the right variable\cf0 \
            matrix[num][\cf6 last\cf0 ] = matrix[\cf6 first\cf0 ][num]; \cf4 //Top->Right\cf0 \
            matrix[\cf6 first\cf0 ][num] = matrix[offset][\cf6 first\cf0 ];\cf4 //Left->Top\cf0 \
            matrix[offset][\cf6 first\cf0 ] = matrix[\cf6 last\cf0 ][offset]; \cf4 //Bottom->Left\cf0 \
            matrix[\cf6 last\cf0 ][offset] = \cf6 temp\cf0 ; \cf4 //Right->Bottom\cf0 \
        \}\
\
        printMatrix(matrix);\
        \
        \
        \
    \}\
\}\
\

\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b myClass :: printMatrix
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]) \{\
    cout << \cf3 "Matrix is n"\cf0 ;\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  i=0; i<ROW; i++) \{\
        
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  j=0; j<COL; j++) \{\
            cout << matrix[i][j] << \cf3 "t"\cf0 ;\
        \}\
        cout << endl;\
    \} \
    cout << endl;\
\}\
\

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 () \{\
    \cf5 myClass\cf0  obj;\
    \
    
\f0\b \cf2 int
\f1\b0 \cf0  M[ROW][COL] = \{ \{ 1, 2, 3, 4\},\
                        \{ 3, 9, 7, 8\},\
                        \{ 1, 0, 11, 12\},\
                        \{ 2, 14, 15, 16\},\
                      \};\
    \cf4 //\ul int\ulnone  M[ROW][COL] = \{ \{ 1, 2, 3, 4, 3\},\cf0 \
    \cf4 //                    \{ 3, 9, 7, 8, 6\},\cf0 \
    \cf4 //                    \{ 1, 0, 11, 12, 9\},\cf0 \
    \cf4 //                    \{ 2, 14, 15, 16, 11\},\cf0 \
    \cf4 //                    \{ 6, 5, 1, 4, 1\},\cf0 \
    \cf4 //                  \};\cf0 \
    obj.printMatrix(M);\
    obj.RotateMatrix(M);\
        \
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}