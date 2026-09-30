# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Ghaly Firasah Pasha - 109082500147</p>

## Dasar Teori
Code Blocks merupakan kakas Integrated Development Environment (IDE) bersifat free, open-source, dan cross-platform yang berorientasi pada bahasa pemrograman C, C++, dan Fortran. Bahasa C++ diciptakan oleh Bjarne Stroustrup pada awal tahun 1980-an sebagai bentuk penyempurnaan bahasa C ANSI yang mendukung berbagai tipe data dasar seperti char, int, long, float, dan double. Alur eksekusi program C++ diatur melalui fungsi kondisional maupun perulangan, serta didukung oleh penggunaan struktur (struct) untuk mengelompokkan data berlainan tipe.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cin >> a >> b;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;
    
    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < (n - i) * 2; s++) {
            cout << " ";
        }
        
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "*";
        
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
