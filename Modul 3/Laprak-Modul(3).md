# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Ghaly Firasah Pasha - 109082500147</p>

## Dasar Teori

### A. Konsep Dasar Abstract Data Type (ADT)<br/>
Abstract Data Type (ADT) adalah sebuah model konseptual yang terdiri dari sebuah tipe data (TYPE) dan sekumpulan operasi dasar (PRIMITIF) terhadap tipe tersebut[1]. Di dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari tipe serta aksioma yang berlaku[1]. ADT merupakan sebuah definisi yang bersifat statik[1].
#### 1. Definisi dan Karakteristik ADT
Abstract Data Type berfokus pada spesifikasi logis mengenai apa saja operasi yang valid terhadap suatu data tanpa harus mengekspos rincian implementasi internalnya di dalam memori[1]. Karakteristik utama ADT mencakup penyembunyian informasi (information hiding) yang membantu menciptakan batasan akses yang jelas, terstruktur, serta aman dalam pengembangan perangkat lunak[1].
#### 2. Komposisi Tipe ADT
Definisi type dari sebuah ADT dapat mengandung sebuah definisi ADT lain di dalamnya secara hierarkis[1]. Sebagai contoh, komposisi ADT dapat berupa ADT waktu yang terdiri dari gabungan ADT JAM dan ADT DATE, objek garis yang terdiri dari dua buah ADT POINT, atau struktur SEG14 yang tersusun atas pasangan dua buah POINT yaitu Top, Left dan Bottom, Right[1].
#### 3. Penerjemahan TYPE dan PRIMITIF
Dalam implementasinya, TYPE diterjemahkan menjadi tipe terdefinisi dalam bahasa pemrograman tertentu, seperti penggunaan struct pada bahasa C[1]. Sementara itu, dalam konteks prosedural, PRIMITIF diterjemahkan menjadi fungsi atau prosedur yang dikelompokkan ke dalam berbagai kategori seperti konstruktor, selector, validator, destruktor, hingga operator aritmatika dan relasional[1].

### B. Implementasi dan Struktur Modul ADT<br/>
Dalam penerapan praktisnya, konsep ADT biasanya diimplementasikan dengan memecah program ke dalam dua buah modul utama dan satu modul antarmuka program utama (driver)[1]. Pemisahan ini bertujuan agar deklarasi tipe, variabel, dan fungsi terstruktur dengan baik sehingga program lebih mudah dipelihara dan dikembangkan[1][2].
#### 1. Modul Spesifikasi / Header File (.h)
Modul spesifikasi atau header file berisi definisi tipe data sesuai kaidah bahasa pemrograman serta spesifikasi dari fungsi dan prosedur primitif[1]. Untuk prosedur, spesifikasinya mencakup kondisi awal (initial state), kondisi akhir (final state), dan proses yang dilakukan, sedangkan untuk fungsi mencakup nama, domain, range, serta prekondisi jika ada[1].
#### 2. Modul Realisasi / Body File (.cpp)
Modul realisasi berisi kode program nyata dalam bahasa C++ yang menjabarkan fungsi dan prosedur yang telah dideklarasikan sebelumnya di dalam file header[1]. Realisasi dari fungsi dan prosedur ini harus sedapat mungkin memanfaatkan fungsi selector dan konstruktor yang tersedia untuk menjaga konsistensi struktur data[1].
#### 3. Modul Antarmuka / Program Utama (main.cpp)
Modul antarmuka atau program utama (driver) berfungsi untuk mengintegrasikan penggunaan file header dan file realisasi .cpp dalam menjalankan program secara utuh[1][2]. Modul ini mengeksekusi variabel bertipe ADT serta memanggil fungsi dan prosedur primitif untuk memproses data dan menampilkan hasilnya ke perangkat keluaran[1].

## Guided 

### 1. mahasiswa

```C++
//header
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif // MAHASISWA_H_INCLUDED

//body
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs (mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "input nilai 2 = ";
    cin >> (m).nilai2;
} 

float rata2 (mahasiswa m) {
    return float(m.nilai1 + m.nilai2)/2;
}

//main
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs) ;
    return 0;
}
```
Program ini mengimplementasikan konsep Abstract Data Type (ADT) untuk mengelola data mahasiswa yang terdiri dari NIM dan dua buah nilai melalui pemisahan file header, realisasi, dan program utama. File header dan realisasi mendefinisikan tipe data struktur `mahasiswa` beserta prosedur masukan `inputMhs` dan fungsi perhitungan `rata2`. File program utama (*driver*) mengeksekusi operasi tersebut untuk menerima masukan data dari pengguna dan menampilkan hasil perhitungan nilai rata-rata ke perangkat keluaran.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts+0.4 * uas+0.3*tugas.

```C++
//header
#ifndef DATAMHS_H_INCLUDED
#define DATAMHS_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

struct daftar_mahasiswa {
    mahasiswa mhs[10];
    int n;
};

void buatDaftarMhs(daftar_mahasiswa &DM);
float hitungNilaiAkhir(float uts, float uas, float tugas);
void inputDataMhs(daftar_mahasiswa &DM);
void tampilkanDataMhs(daftar_mahasiswa DM);

#endif

//body
#include "datamhs.h"

void buatDaftarMhs(daftar_mahasiswa &DM) {
    DM.n = 0;
}

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void inputDataMhs(daftar_mahasiswa &DM) {
    cout << "Masukkan jumlah mahasiswa yang ingin diinput (maks. 10): ";
    cin >> DM.n;
    
    if (DM.n > 10) {
        DM.n = 10;
    } else if (DM.n < 1) {
        DM.n = 0;
        return;
    }

    for (int i = 0; i < DM.n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << "\n";
        cout << "Masukkan Nama        : ";
        cin.ignore();
        getline(cin, DM.mhs[i].nama);
        cout << "Masukkan NIM         : ";
        cin >> DM.mhs[i].nim;
        cout << "Masukkan Nilai UTS   : ";
        cin >> DM.mhs[i].uts;
        cout << "Masukkan Nilai UAS   : ";
        cin >> DM.mhs[i].uas;
        cout << "Masukkan Nilai Tugas : ";
        cin >> DM.mhs[i].tugas;

        DM.mhs[i].nilai_akhir = hitungNilaiAkhir(DM.mhs[i].uts, DM.mhs[i].uas, DM.mhs[i].tugas);
    }
}

void tampilkanDataMhs(daftar_mahasiswa DM) {
    if (DM.n == 0) {
        cout << "\nTidak ada data mahasiswa untuk ditampilkan.\n";
        return;
    }

    cout << "\n=========================================================================\n";
    cout << "                         DAFTAR NILAI MAHASISWA                          \n";
    cout << "=========================================================================\n";
    cout << "No.\tNIM\t\tNama\t\tUTS\tUAS\tTugas\tNilai Akhir\n";
    cout << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < DM.n; i++) {
        cout << i + 1 << "\t" 
             << DM.mhs[i].nim << "\t\t" 
             << DM.mhs[i].nama << "\t\t" 
             << DM.mhs[i].uts << "\t" 
             << DM.mhs[i].uas << "\t" 
             << DM.mhs[i].tugas << "\t" 
             << DM.mhs[i].nilai_akhir << "\n";
    }
}

//main
#include <iostream>
#include "datamhs.h"

using namespace std;

int main() {
    daftar_mahasiswa DM;
    
    buatDaftarMhs(DM);

    cout << "========================================\n";
    cout << "   PROGRAM PENGELOLAAN DATA MAHASISWA   \n";
    cout << "========================================\n";
    
    inputDataMhs(DM);
    tampilkanDataMhs(DM);

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1](https://github.com/Pshaa19/109082500147_Ghaly-Firasah-Pasha-/blob/main/Modul%203/Output/output%20unguided%201.png)

Program ini mengimplementasikan konsep Abstract Data Type (ADT) untuk mengelola data mahasiswa ke dalam array dengan memisahkan kode menjadi tiga file utama, yaitu file header, file body, dan program utama. File header dan body bertugas mendefinisikan struktur data mahasiswa beserta fungsi dan prosedur primitif seperti perhitungan nilai akhir dan penginputan data. Sementara itu, file program utama berfungsi sebagai driver untuk menjalankan alur program serta menampilkan rekapitulasi nilai mahasiswa secara terstruktur.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”: Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp” Cobalah hasil implementasi ADT pada file “main.cpp”

```C++
//header
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

//body
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

//main
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2](https://github.com/Pshaa19/109082500147_Ghaly-Firasah-Pasha-/blob/main/Modul%203/Output/output%20unguided%202.png)

Program ini mengimplementasikan konsep Abstract Data Type (ADT) untuk membuat dan menampilkan data pelajaran dengan memisahkan struktur kode ke dalam modul spesifikasi (pelajaran.h), modul realisasi (pelajaran.cpp), dan program utama (main.cpp). Di dalam file header dan body, didefinisikan tipe data struktur pelajaran beserta fungsi konstruktor create_pelajaran dan prosedur untuk mengelola data pelajaran. File main.cpp bertindak sebagai program driver yang mengeksekusi fungsi pembentukan data pelajaran dan menampilkan hasilnya ke perangkat keluaran sesuai dengan ketentuan praktikum.

### 3. Buatlah program dengan ketentuan : 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer, fungsi/prosedur yang menampilkan isi sebuah array integer 2D, fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu, fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
//header
#ifndef TUKAR_H_INCLUDED
#define TUKAR_H_INCLUDED

#include <iostream>

using namespace std;

void tampilArray2D(int arr[3][3]);
void tukarElemenArray2D(int arr1[3][3], int arr2[3][3], int r, int c);
void tukarNilaiPointer(int *ptr1, int *ptr2);

#endif

//body
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

//main
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
```
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 3](https://github.com/Pshaa19/109082500147_Ghaly-Firasah-Pasha-/blob/main/Modul%203/Output/output%20unguided%203.png)

Program ini mengimplementasikan konsep Abstract Data Type (ADT) untuk mengelola array 2D berukuran 3x3 dan variabel pointer dengan membagi kode ke dalam modul spesifikasi (tukar.h), modul realisasi (tukar.cpp), dan program utama (main.cpp). Di dalam file header dan body, didefinisikan berbagai fungsi dan prosedur primitif untuk menampilkan isi matriks, menukar elemen array 2D pada posisi tertentu, serta menukar nilai variabel yang ditunjuk oleh pointer. File main.cpp bertindak sebagai driver yang mengeksekusi seluruh operasi tersebut dan menampilkan perubahan data matriks maupun pointer ke perangkat keluaran secara terstruktur.

## Kesimpulan
Seluruh program yang dibuat berhasil menerapkan konsep Abstract Data Type (ADT) dengan memisahkan struktur data dan fungsi ke dalam modul spesifikasi, modul realisasi, dan program utama. Pendekatan modular ini mencakup implementasi pengelolaan data mahasiswa, entitas pelajaran, hingga manipulasi array 2D dan pointer secara terstruktur dan terorganisir. Penggunaan konstruktor, selector, serta fungsi dan prosedur primitif memastikan bahwa operasi dasar terhadap tipe data dapat dieksekusi dengan baik tanpa mengekspos detail implementasi internal. Melalui praktikum ini, konsep pemrograman prosedural terbukti dapat meningkatkan keterbacaan, keamanan data, serta kemudahan pemeliharaan kode program secara keseluruhan.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
