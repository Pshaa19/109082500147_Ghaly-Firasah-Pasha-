#include <iostream>
#include <string>

using namespace std;

int main() {
    int angka;
    cin >> angka;

    string kata[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    cout << angka << " : ";

    if (angka == 0) {
        cout << "nol";
    } else if (angka < 12) {
        cout << kata[angka];
    } else if (angka < 20) {
        cout << kata[angka - 10] << " belas";
    } else if (angka < 100) {
        cout << kata[angka / 10] << " puluh";
        if (angka % 10 != 0) {
            cout << " " << kata[angka % 10];
        }
    } else if (angka == 100) {
        cout << "seratus";
    }

    cout << endl;
    return 0;
}