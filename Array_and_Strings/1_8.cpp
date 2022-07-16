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
\f1\b0 \cf0  ROW 4\

\f0\b \cf2 #define
\f1\b0 \cf0  COL 5\
\pard\pardeftab720
\cf4 //Assumption:   Integer matrix\cf0 \
\cf4 //Algorithm :   ZeroMatrix : Check 0th row and \ul oth\ulnone  column for zero and\cf0 \
\cf4 //              store that in separate flags. Then use the first row and column\cf0 \
\cf4 //              to store which have 0's throughout the isZeroMatrix\cf0 \
\cf4 //              Time : O(MN) for MxN matrix ; Space : O(1)\cf0 \
\
\pard\pardeftab720

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 myClass\cf0  \{\
    
\f0\b \cf2 public
\f1\b0 \cf0  :\
        
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b ZeroMatrix
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]);  \
        
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b printMatrix
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]);\
        
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b NullifyRow
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  row, 
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]);\
        
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b NullifyCol
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  col, 
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]);\
    
\f0\b \cf2 private
\f1\b0 \cf0  :\
        
\f0\b \cf2 bool
\f1\b0 \cf0  \cf6 RowHasZero\cf0 , \cf6 ColHasZero\cf0 ;\
        
\f0\b \cf2 int
\f1\b0 \cf0  \cf6 start\cf0 ;\
\};\
\

\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b myClass :: ZeroMatrix
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  matrix[ROW][COL]) \{\
    \cf6 RowHasZero\cf0  = 
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    \cf6 ColHasZero\cf0  = 
\f0\b \cf2 false
\f1\b0 \cf0 ;\
    \
    \cf4 //Check if row0 has zeroes\cf0 \
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  j=0; j<COL; j++) \{\
        
\f0\b \cf2 if
\f1\b0 \cf0  (matrix[0][j] == 0) \{\
            cout << \cf3 "Row0 has zeroes"\cf0  << endl;\
            \cf6 RowHasZero\cf0  = 
\f0\b \cf2 true
\f1\b0 \cf0 ;\
            
\f0\b \cf2 break
\f1\b0 \cf0 ;\
        \}\
    \}\
    \cf4 //Check if col0 has zeroes\cf0 \
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  i=0; i<ROW; i++) \{\
        
\f0\b \cf2 if
\f1\b0 \cf0  (matrix[i][0] == 0) \{\
            cout << \cf3 "Col0 has zeroes"\cf0  << endl;\
            \cf6 ColHasZero\cf0  = 
\f0\b \cf2 true
\f1\b0 \cf0 ;\
            
\f0\b \cf2 break
\f1\b0 \cf0 ;\
        \}\
    \}\
    \cf4 //Find rows and columns of the elements that are 0's\cf0 \
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  i=0; i<ROW; i++) \{\
        
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  j=0; j<COL; j++) \{\
            
\f0\b \cf2 if
\f1\b0 \cf0  (matrix[i][j] == 0) \{\
                matrix[0][j] = 0;    \
                matrix[i][0] = 0;\
            \}\
        \}\
    \}\
    \cf4 //Generate zero matrix\cf0 \
    cout << \cf3 "Zero locations : "\cf0  << endl;\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  j=1; j<COL; j++) \{\
        
\f0\b \cf2 if
\f1\b0 \cf0  (matrix[0][j] == 0) \{ \cf4 // \ul Col\ulnone  j has a zero somewhere\cf0 \
            cout << j << \cf3 " column has a zero"\cf0  << endl;\
            NullifyCol(j, matrix);\
        \}\
    \}\
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  i=1; i<ROW; i++) \{\
        
\f0\b \cf2 if
\f1\b0 \cf0  (matrix[i][0] == 0) \{ \cf4 // Row i has a zero somewhere\cf0 \
            cout << i << \cf3 " row has a zero "\cf0  << endl;\
            NullifyRow(i, matrix);\
        \}\
    \}\
    
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 RowHasZero\cf0 )\
        NullifyRow(0, matrix);\
    
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 ColHasZero\cf0 )\
        NullifyCol(0, matrix);\
    \
    printMatrix(matrix);\
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

\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b myClass :: NullifyRow
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  row, 
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]) \{\
    
\f0\b \cf2 if
\f1\b0 \cf0  (row != 0) \
        \cf6 start\cf0  = 1;\
    
\f0\b \cf2 else
\f1\b0 \cf0  \
        \cf6 start\cf0  = 0;\
        \
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  j=\cf6 start\cf0 ; j<COL; j++) \
        matrix[row][j] = 0;\
\}\
\

\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b myClass :: NullifyCol
\f1\b0 (
\f0\b \cf2 int
\f1\b0 \cf0  col, 
\f0\b \cf2 int
\f1\b0 \cf0  matrix [ROW][COL]) \{\
    
\f0\b \cf2 if
\f1\b0 \cf0  (col != 0) \
        \cf6 start\cf0  = 1;\
    
\f0\b \cf2 else
\f1\b0 \cf0  \
        \cf6 start\cf0  = 0;\
        \
    
\f0\b \cf2 for
\f1\b0 \cf0  (
\f0\b \cf2 int
\f1\b0 \cf0  i=\cf6 start\cf0 ; i<ROW; i++) \
        matrix[i][col] = 0;\
\}\
\

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 () \{\
    \cf5 myClass\cf0  obj;\
    \
    
\f0\b \cf2 int
\f1\b0 \cf0  M[ROW][COL] = \{ \{ 1, 2, 3, 4, 0\},\
                        \{ 3, 9, 7, 8, 3\},\
                        \{ 1, 0, 11, 12, 6 \},\
                        \{ 2, 14, 15, 16, 3 \},\
                      \};\
    obj.printMatrix(M);\
    obj.ZeroMatrix(M);\
        \
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}