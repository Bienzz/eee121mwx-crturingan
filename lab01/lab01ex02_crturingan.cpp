#include <iostream>
using namespace std;

const int SIZE = 5;

//print the matrix result
void printMatrix(int arr[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

//add two matrices
void addMatrix(int m1[][SIZE], int m2[][SIZE], int result1[][SIZE]){
    //loop to every row and column of the two matrices
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            //add the correspoding elements in the two matrices
            result1[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

//dot product the two matrices
void dotProductMatrix(int m1[][SIZE], int m2[][SIZE], int result2[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result2[i][j] = 0;
            for(int k = 0; k < SIZE; k++){
                result2[i][j] += m1[i][j] * m2[j][i];
            }
        }
    }
}

void createMatrix(int arr[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
          cin >> arr[i][j];
        }
    }
}

int main() {
    int result1[SIZE][SIZE];
    int result2[SIZE][SIZE];
    int array1[SIZE][SIZE];
    int array2[SIZE][SIZE];
    
    createMatrix(array1);
    createMatrix(array2);
    addMatrix(array1, array2, result1);
    printMatrix(result1);
    dotProductMatrix(array1, array2, result2);
    printMatrix(result2);

    return 0;
}
