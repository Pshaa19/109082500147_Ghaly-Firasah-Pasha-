#include "tukar.h"

void tampilArray2D(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarElemenArray2D(int arr1[3][3], int arr2[3][3], int r, int c) {
    int temp = arr1[r][c];
    arr1[r][c] = arr2[r][c];
    arr2[r][c] = temp;
}

void tukarNilaiPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}