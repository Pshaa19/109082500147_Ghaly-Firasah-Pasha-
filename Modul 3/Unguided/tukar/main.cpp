#include <iostream>
#include "tukar.h"

using namespace std;

int main() {
    int matriks1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int matriks2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int a = 10;
    int b = 20;
    int *p1 = &a;
    int *p2 = &b;

    cout << "Array 2D Pertama:\n";
    tampilArray2D(matriks1);

    cout << "\nArray 2D Kedua:\n";
    tampilArray2D(matriks2);

    tukarElemenArray2D(matriks1, matriks2, 1, 1);

    cout << "\nSetelah penukaran posisi (1,1) antara Array 2D 1 dan 2:\n";
    cout << "Array 2D Pertama:\n";
    tampilArray2D(matriks1);
    cout << "Array 2D Kedua:\n";
    tampilArray2D(matriks2);

    cout << "\nNilai awal variabel pointer:\n";
    cout << "p1 = " << *p1 << ", p2 = " << *p2 << endl;

    tukarNilaiPointer(p1, p2);

    cout << "Setelah penukaran nilai pointer:\n";
    cout << "p1 = " << *p1 << ", p2 = " << *p2 << endl;

    return 0;
}