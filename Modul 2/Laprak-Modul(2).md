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

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

### 4. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

### 5. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

### 6. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

### 7. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

### 8. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

### 9. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

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