#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int cariMaksimum(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    cout << "Rata - rata = " << total / n << endl;
}

void tampilkanArray(int arr[], int n) {
    cout << "Isi Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10;
    int pilihan;

    cout << "--- Menu Program Array ---" << endl;
    cout << "1. Tampilkan isi array" << endl;
    cout << "2. cari nilai maksimum" << endl;
    cout << "3. cari nilai minimum" << endl;
    cout << "4. Hitung nilai rata - rata" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    cout << endl;

    switch (pilihan) {
        case 1:
            tampilkanArray(arrA, n);
            break;
        case 2:
            cout << "Nilai maksimum = " << cariMaksimum(arrA, n) << endl;
            break;
        case 3:
            cout << "Nilai minimum = " << cariMinimum(arrA, n) << endl;
            break;
        case 4:
            hitungRataRata(arrA, n);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}