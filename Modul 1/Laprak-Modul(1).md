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

##### Output 
![Screenshot Output Unguided 1](https://github.com/Pshaa19/109082500147_Ghaly-Firasah-Pasha-/blob/main/Modul%201/Output/Screenshot%20Output%20Unguided%201.png)

penjelasan unguided 1 
Program C++ ini menerima dua masukan bilangan pecahan (float) dari pengguna melalui perintah cin. Selanjutnya, program menghitung serta menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian dari kedua bilangan tersebut secara berurutan.

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

##### Output 
![Screenshot Output Unguided 2](https://github.com/Pshaa19/109082500147_Ghaly-Firasah-Pasha-/blob/main/Modul%201/Output/Screenshot%20Output%20Unguided%202.png)

penjelasan unguided 2
Program C++ ini menerima masukan bilangan bulat dari pengguna untuk dikonversi menjadi sebutan teks terbilang dalam rentang 0 hingga 100. Menggunakan struktur percabangan if-else dan array kata dasar, program mengecek rentang nilai angka tersebut lalu mencetak hasil konversinya secara tepat.

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

##### Output 
![Screenshot Output Unguided 3](https://github.com/Pshaa19/109082500147_Ghaly-Firasah-Pasha-/blob/main/Modul%201/Output/Screenshot%20Output%20Unguided%203.png)

penjelasan unguided 3
Program C++ ini mencetak pola angka simetris berbentuk piramida terbalik dengan pusat karakter bintang * berdasarkan masukan nilai n. Menggunakan struktur perulangan bersarang, program mengatur jumlah spasi di setiap baris serta mencetak urutan angka menurun di sebelah kiri dan menaik di sebelah kanan.

## Kesimpulan
Ketiga program C++ ini mengimplementasikan konsep dasar pemrograman, dimulai dari penggunaan operator aritmatika untuk memproses tipe data float. Program kedua mengembangkan logika alur program melalui struktur percabangan dan array untuk mengonversi nilai angka menjadi teks terbilang. Program ketiga menerapkan perulangan bersarang guna memanipulasi spasi dan penulisan karakter dalam membentuk pola angka simetris. 

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
