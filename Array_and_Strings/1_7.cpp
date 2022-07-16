#include <iostream> 
using namespace std; 
#define N 4
#define ROW N
#define COL N
//Algorithm :   RotateMatrix : 
//              Time : O(N^2) for NxN matrix ; Space : O(1) as we do swap per integer

class myClass {
    public :
        void RotateMatrix(int matrix [ROW][COL]);  
        void printMatrix(int matrix [ROW][COL]);
    private :
        int first, last, temp;
};

void myClass :: RotateMatrix(int matrix[ROW][COL]) {
    int offset = 0;
    for (int layer=0; layer<N/2; layer++) {
        first = layer;
        last = N-1-layer;
      
        for(int num=first; num<last; num++)  {
            offset = last-num + layer;
            temp = matrix[num][last]; //Store the right variable
            matrix[num][last] = matrix[first][num]; //Top->Right
            matrix[first][num] = matrix[offset][first];//Left->Top
            matrix[offset][first] = matrix[last][offset]; //Bottom->Left
            matrix[last][offset] = temp; //Right->Bottom
        }

        printMatrix(matrix);
        
        
        
    }
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

int main() {
    myClass obj;
    
    int M[ROW][COL] = { { 1, 2, 3, 4},
                        { 3, 9, 7, 8},
                        { 1, 0, 11, 12},
                        { 2, 14, 15, 16},
                      };
    //int M[ROW][COL] = { { 1, 2, 3, 4, 3},
    //                    { 3, 9, 7, 8, 6},
    //                    { 1, 0, 11, 12, 9},
    //                    { 2, 14, 15, 16, 11},
    //                    { 6, 5, 1, 4, 1},
    //                  };
    obj.printMatrix(M);
    obj.RotateMatrix(M);
        
    return 0;
}
