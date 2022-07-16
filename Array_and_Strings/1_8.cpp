#include <iostream> 
using namespace std; 
#define ROW 4
#define COL 5
//Assumption:   Integer matrix
//Algorithm :   ZeroMatrix : Check 0th row and oth column for zero and
//              store that in separate flags. Then use the first row and column
//              to store which have 0's throughout the isZeroMatrix
//              Time : O(MN) for MxN matrix ; Space : O(1)

class myClass {
    public :
        void ZeroMatrix(int matrix [ROW][COL]);  
        void printMatrix(int matrix [ROW][COL]);
        void NullifyRow(int row, int matrix [ROW][COL]);
        void NullifyCol(int col, int matrix [ROW][COL]);
    private :
        bool RowHasZero, ColHasZero;
        int start;
};

void myClass :: ZeroMatrix(int matrix[ROW][COL]) {
    RowHasZero = false;
    ColHasZero = false;
    
    //Check if row0 has zeroes
    for (int j=0; j<COL; j++) {
        if (matrix[0][j] == 0) {
            cout << "Row0 has zeroes" << endl;
            RowHasZero = true;
            break;
        }
    }
    //Check if col0 has zeroes
    for (int i=0; i<ROW; i++) {
        if (matrix[i][0] == 0) {
            cout << "Col0 has zeroes" << endl;
            ColHasZero = true;
            break;
        }
    }
    //Find rows and columns of the elements that are 0's
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;    
                matrix[i][0] = 0;
            }
        }
    }
    //Generate zero matrix
    cout << "Zero locations : " << endl;
    for (int j=1; j<COL; j++) {
        if (matrix[0][j] == 0) { // Col j has a zero somewhere
            cout << j << " column has a zero" << endl;
            NullifyCol(j, matrix);
        }
    }
    for (int i=1; i<ROW; i++) {
        if (matrix[i][0] == 0) { // Row i has a zero somewhere
            cout << i << " row has a zero " << endl;
            NullifyRow(i, matrix);
        }
    }
    if (RowHasZero)
        NullifyRow(0, matrix);
    if (ColHasZero)
        NullifyCol(0, matrix);
    
    printMatrix(matrix);
}

void myClass :: printMatrix(int matrix [ROW][COL]) {
    cout << "Matrix is n";
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            cout << matrix[i][j] << "t";
        }
        cout << endl;
    } 
    cout << endl;
}

void myClass :: NullifyRow(int row, int matrix [ROW][COL]) {
    if (row != 0) 
        start = 1;
    else 
        start = 0;
        
    for (int j=start; j<COL; j++) 
        matrix[row][j] = 0;
}

void myClass :: NullifyCol(int col, int matrix [ROW][COL]) {
    if (col != 0) 
        start = 1;
    else 
        start = 0;
        
    for (int i=start; i<ROW; i++) 
        matrix[i][col] = 0;
}

int main() {
    myClass obj;
    
    int M[ROW][COL] = { { 1, 2, 3, 4, 0},
                        { 3, 9, 7, 8, 3},
                        { 1, 0, 11, 12, 6 },
                        { 2, 14, 15, 16, 3 },
                      };
    obj.printMatrix(M);
    obj.ZeroMatrix(M);
        
    return 0;
}
