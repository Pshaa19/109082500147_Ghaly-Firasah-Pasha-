#include <iostream>
#define SIZE 3
using namespace std;

void tambahMatrix(int matA[SIZE][SIZE], int matB[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void kurangMatrix(int matA[SIZE][SIZE], int matB[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

void kaliMatrix(int matA[SIZE][SIZE], int matB[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                hasil[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void cetakMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int A[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[SIZE][SIZE] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int hasil[SIZE][SIZE];

    cout << "=== Penjumlahan ===" << endl;
    tambahMatrix(A, B, hasil);
    cetakMatrix(hasil);

    cout << "\n=== Pengurangan ===" << endl;
    kurangMatrix(A, B, hasil);
    cetakMatrix(hasil);

    cout << "\n=== Perkalian ===" << endl;
    kaliMatrix(A, B, hasil);
    cetakMatrix(hasil);

    return 0;
}