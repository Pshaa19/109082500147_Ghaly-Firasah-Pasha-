# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Ghaly Firasah Pasha - 109082500147</p>

## Dasar Teori
Bahasa pemrograman C++ menyediakan berbagai mekanisme pengorganisasian data dan modularisasi program yang efisien, di antaranya melalui pengoperasian memori secara langsung dan pembagian blok fungsi[1]. Penguasaan terhadap alokasi memori, manipulasi elemen data terstruktur, serta alur eksekusi subprogram menjadi landasan utama dalam mengimplementasikan berbagai struktur data kompleks[2].

### A. Array<br/>
Array merupakan struktur data linier statis yang menyimpan sekumpulan elemen bertipe data sama di dalam lokasi memori yang berurutan (contiguous memory locations)[1]. Setiap elemen di dalam array diakses menggunakan indeks numerik berbasis nol (zero-based indexing)[1].
#### 1. Array Satu Dimensi
Array satu dimensi adalah larik data sederhana yang hanya memiliki satu tingkatan indeks[1]. Deklarasi array satu dimensi menentukan tipe data elemen serta batas maksimum alokasi memori yang disiapkan[1].
#### 2. Array Dua Dimensi
Array dua dimensi merupakan struktur data berbentuk tabel yang terdiri atas baris dan kolom[1]. Pengaksesan data dilakukan menggunakan dua buah indeks, yaitu indeks pertama mewakili posisi baris dan indeks kedua mewakili posisi kolom[1].
#### 3. Array Berdimensi Banyak
Array berdimensi banyak (multidimensional array) memiliki lebih dari dua indeks untuk merepresentasikan data berdimensi kompleks[2]. Meskipun secara visual bertingkat, dalam memori komputer array ini tetap disimpan secara linier berurutan[1].

### B. Pointer dan Memori<br/>
Pointer adalah variabel khusus yang berfungsi menyimpan alamat memori dari variabel lain, bukan menyimpan nilai datanya secara langsung[1, 3]. Pemrosesan pointer memungkinkan manipulasi data langsung pada level sistem memori (RAM)[1, 3].
#### 1. Konsep Alamat Memori
Setiap variabel yang dideklarasikan dalam C++ akan dialokasikan pada sel memori berukuran tertentu oleh sistem operasi[1]. Alamat lokasi memori suatu variabel dapat diperoleh menggunakan operator address-of (&)[1, 3].
#### 2. Operator Dereference
Operator dereference (*) digunakan untuk mengakses atau memodifikasi nilai data yang tersimpan pada alamat memori yang ditunjuk oleh sebuah pointer[1, 3].
#### 3. Pointer pada Array dan String
Nama array secara internal diperlakukan sebagai konstanta pointer yang menunjuk ke elemen pertamanya (&array[0])[1, 4]. Sementara itu, string di dalam C++ didefinisikan sebagai array dari karakter (char) yang diakhiri oleh karakter null ('\0')[1].

### C. Pemrograman Terstruktur (Fungsi dan Prosedur)<br/>
Pengorganisasian program menjadi modul-modul kecil (subprogram) bertujuan untuk meningkatkan keterbacaan kode, memudahkan pemeliharaan, serta menghindari duplikasi perintah (code reuse)[1].
#### 1. Fungsi (Function)
Fungsi adalah blok kode terisolasi yang menerima parameter masukan, mengolah data, dan mengembalikan suatu nilai balik (return value) spesifik kepada pemanggilnya[1].
#### 2. Prosedur (Void Function)
Prosedur merupakan blok fungsi yang bertugas menjalankan serangkaian instruksi khusus tanpa memberikan nilai balik (return value), yang ditandai dengan penggunaan tipe kembalian void[1].
#### 3. Melewatkan Parameter (Call by Value, Pointer, & Reference)
Pengiriman data ke dalam subprogram dapat dilakukan melalui tiga mekanisme: Call by Value (menciptakan salinan nilai)[1], Call by Pointer (mengirimkan alamat memori melalui pointer)[1, 3], dan Call by Reference (mengirimkan nama alias variabel menggunakan operator &)[1].

## Guided 

### 1. Array 1

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = " 
             << nilai[i] << endl; 
    }

    return 0;
}
```
Kode ini menginisialisasi sebuah array satu dimensi bernama nilai bertipe integer dengan ukuran 5 elemen yang masing-masing diisi angka tertentu. Selanjutnya, perulangan for digunakan untuk mencetak seluruh isi array tersebut beserta nomor urutnya ke layar secara berurutan.

### 2. Array 2

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        
        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl; 
    return 0;
}
```
Kode ini mendeklarasikan dan menginisialisasi array dua dimensi berukuran 3x3 yang berisi kumpulan nilai integer. Selanjutnya, program menampilkan seluruh elemen array dalam bentuk matriks menggunakan perulangan bersarang, lalu mencetak elemen pada baris ke-2 kolom ke-3 (indeks [1][2]) yaitu angka 88.

### 3. Array 3

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };

    cout << data[0][1][2] << endl;

    return 0; 
}
```
Kode ini mendeklarasikan dan menginisialisasi array tiga dimensi berukuran 2x2x3 yang menyimpan sekumpulan data integer. Selanjutnya, program mengakses dan mencetak elemen pada blok pertama, baris kedua, dan kolom ketiga (indeks [0][1][2]), yaitu nilai 60.

### 4. Address

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "Nilai angka = " << angka << endl;
    cout << "Alamat angka = " << &angka << endl;

    return 0;
}
```
Kode ini mendeklarasikan sebuah variabel integer angka bernilai 100, lalu menampilkan nilai tersebut serta alamat memorinya di RAM ke layar. Penggunaan operator & sebelum nama variabel digunakan untuk mengambil dan mencetak alamat lokasi memori tempat variabel angka tersimpan.

### 5. Pointer 1

```C++
#include <iostream>
using namespace std;

int main() {
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl; //value
    cout << &(arr[4]) << endl; //alamat memory atau address

    return 0;
}
```
Kode ini menginisialisasi array karakter arr berukuran 6 elemen dan mengisinya dengan karakter 'a' hingga 'e'. Selanjutnya, program mencetak nilai karakter pada indeks ke-3 (yaitu 'b') serta alamat memori tempat elemen indeks ke-4 tersimpan menggunakan operator &.

### 6. Pointer 2

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;
    int *pointer;

    pointer = &angka;

    cout << "Nilai angka         : " << angka << endl; //100
    cout << "Alamat angka        : " << &angka << endl; //address 
    cout << "Isi pointer         : " << pointer << endl; //address angka 
    cout << "Nilai dari pointer  : " << *pointer << endl; //value dari angka yaitu 100

    return 0;
}
```
Kode ini mendeklarasikan variabel integer angka bernilai 100 dan sebuah pointer pointer yang diisi dengan alamat memori dari angka. Selanjutnya, program menampilkan nilai angka, alamat memori angka, nilai yang tersimpan di dalam pointer (alamat angka), serta nilai yang ditunjuk oleh pointer menggunakan operator dereference (*) yang menghasilkan nilai 100.

### 7. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max) {
        temp_max = b;
    }

    if(c > temp_max) {
        temp_max = c;
    }
    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1: ";
    cin >> x;
    cout << "Masukkan nilai 2: ";
    cin >> y;
    cout << "Masukkan nilai 3: ";
    cin >> z;

    cout << "Nilai maksimum = " 
         << maks3(x, y, z);

    return 0;
}
```
Kode ini mendefinisikan fungsi maks3 yang menerima tiga parameter integer untuk menentukan nilai terbesar melalui serangkaian pengecekan kondisi if. Pada fungsi main, program menerima tiga input nilai dari pengguna, memanggil fungsi maks3, lalu menampilkan hasil nilai maksimum tersebut ke layar.

### 8. Procedure

```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di Praktikum Struktur Data" << endl;
}

int main() {
    sapa();
    return 0;
}
```
Kode ini mendefinisikan sebuah prosedur (fungsi void) bernama sapa() yang bertugas mencetak teks pesan penyambutan ke layar. Pada fungsi main(), prosedur sapa() dipanggil sehingga pesan "Selamat datang di Praktikum Struktur Data" ditampilkan saat program dijalankan.

### 9. Call By Value, Pointer & Reference

```C++
#include <iostream>
using namespace std;

//call by value
void tukar(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(a, b);

    cout <<"\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

//call by pointer
void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout <<"\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

//call by reference
void tukar(int &x, int &y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(a, b);

    cout <<"\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
```
Pada metode Call by Value, nilai dari parameter aktual disalin ke parameter formal, sehingga perubahan nilai di dalam fungsi tidak akan memengaruhi variabel aslinya di luar fungsi. Pada metode Call by Pointer, fungsi menerima alamat memori menggunakan pointer (*) dan dipanggil menggunakan operator alamat (&), sehingga perubahan di dalam fungsi akan langsung mengubah variabel aslinya. Sementara itu, metode Call by Reference memiliki dampak yang sama dengan pointer dalam mengubah variabel asli, namun dengan sintaks pemanggilan yang lebih sederhana karena tidak memerlukan operator tambahan saat fungsi dipanggil.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini menggunakan prosedur (void) terpisah untuk menghitung penjumlahan, pengurangan, dan perkalian dua buah matriks 3x3 yang disimpan dalam array dua dimensi. Penggunaan prosedur cetakMatrix secara berulang membantu memperkasing penulisan kode saat menampilkan setiap hasil operasi ke layar. Selain itu, manipulasi data matriks di dalam prosedur langsung memperbarui variabel hasil pada fungsi main karena pengiriman array sebagai parameter mengacu pada alamat memori yang sama.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel 

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
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
[1] Tim Dosen Struktur Data. (2024). Modul 2: Pengenalan Bahasa C++ (Bagian Kedua). Laboratorium Informatika, Fakultas Informatika, Telkom University.
<br>[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
<br>[3] Prasatya. (2024). Belajar Pointer C++: Dasar-Dasar, Fungsi, dan Contoh Kode. CodePolitan.
<br>[4] Saniyatul. (2021). Praktikum ASD: Array, Pointer dan Struktur. Politeknik Elektronika Negeri Surabaya (PENS).