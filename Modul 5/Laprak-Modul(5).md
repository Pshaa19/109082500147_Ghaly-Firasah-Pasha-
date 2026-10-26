# <h1 align="center">Laporan Praktikum Modul 5 -  Singly Linked List (Bagian Kedua)</h1>
<p align="center">Ghaly Firasah Pasha - 109082500147</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas [1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer [2]. Pada Singly Linked List (senarai berantai tunggal), setiap simpul hanya memiliki satu variabel pointer (next) yang menunjuk ke simpul berikutnya, di mana elemen pertama ditunjuk oleh pointer first dan simpul terakhir menunjuk ke nilai Nil atau NULL sebagai penanda akhir senarai [3]. Dalam bahasa pemrograman C/C++, struktur data ini diimplementasikan sebagai Abstract Data Type (ADT) yang memisahkan definisi tipe data serta prototipe fungsi pada file header (*.h) dengan realisasi algoritmanya pada file implementasi (*.c atau *.cpp) [2].

### A. Representasi Struktur Data dan Manajemen Memori pada Singly Linked List<br/>
Representasi fisik Singly Linked List menggunakan pointer memungkinkan alokasi memori dilakukan secara dinamis saat program berjalan (runtime), sehingga ukuran senarai dapat bertambah atau berkurang sesuai kebutuhan tanpa batas ukuran statis seperti pada array [4].
#### 1. Struktur Simpul (Node) dan Pointer Penunjuk (first)
Setiap simpul (elmlist) dalam Singly Linked List direpresentasikan sebagai sebuah record atau struct yang terdiri atas dua medan utama, yaitu medan informasi (info) bertipe infotype untuk menyimpan nilai data dan medan tautan (next) bertipe address (pointer ke elmlist) untuk menyimpan alamat memori simpul selanjutnya [1]. Struktur list itu sendiri cukup menyimpan satu pointer utama bernama first yang memegang alamat elemen pertama, di mana kondisi senarai kosong ditandai ketika L.first bernilai Nil (NULL). Melalui operator akses pointer (->), setiap komponen simpul yang ditunjuk oleh alamat P dapat diakses secara langsung menggunakan notasi P->info untuk nilai datanya dan P->next untuk alamat simpul berikutnya [2].
#### 2. Pembuatan Senarai Kosong (CreateList) dan Pengecekan (ListEmpty)
Sebelum sebuah linked list dapat dioperasikan, senarai harus diinisialisasi terlebih dahulu melalui prosedur CreateList(L) yang mengatur nilai L.first = Nil sehingga terbentuk senarai kosong yang valid di memori [3]. Untuk memastikan apakah senarai sedang memiliki elemen atau tidak sebelum melakukan operasi penghapusan maupun penelusuran, fungsi ListEmpty(L) digunakan untuk memeriksa apakah L.first == Nil dan mengembalikan nilai boolean true apabila senarai kosong serta false apabila senarai berisi minimal satu simpul.
#### 3. Alokasi (alokasi) dan Dealokasi Memori (dealokasi)
Manajemen memori dinamis pada Singly Linked List mencakup dua operasi dasar, yakni fungsi alokasi(X) untuk memesan ruang memori baru bagi sebuah simpul, mengisi medan P->info dengan nilai X, mengatur P->next = Nil, serta mengembalikan alamat simpul P tersebut [4]. Sebaliknya, ketika sebuah simpul dihapus dan tidak lagi digunakan dalam senarai, prosedur dealokasi(P) bertugas mengembalikan ruang memori yang ditempati oleh alamat P kembali ke sistem agar tidak terjadi kebocoran memori (memory leak) [2].

### B. Operasi Pencarian (Searching) dan Manipulasi Elemen pada Singly Linked List<br/>
Karena elemen-elemen pada Singly Linked List tidak disimpan pada blok memori yang bersebelahan secara fisik, akses terhadap elemen tertentu tidak dapat dilakukan menggunakan indeks secara langsung, melainkan harus melalui penelusuran sekuensial (traversal) mulai dari simpul first [5].
#### 1. Operasi Pencarian Elemen (Searching)
Searching merupakan operasi dasar pada linked list untuk menemukan simpul tertentu dengan cara mengunjungi setiap node satu per satu dari awal senarai (L.first) hingga node yang dicari ditemukan atau penelusuran mencapai akhir senarai (Nil) [1]. Dalam ADT Singly Linked List, operasi pencarian ini memiliki beberapa variasi fungsi:
* **Pencarian Berdasarkan Nilai (`findElm(L, X)`)**: Mencari simpul yang memiliki nilai `P->info == X` dan mengembalikan alamat (`address`) simpul tersebut jika ditemukan, atau mengembalikan `Nil` jika nilai `X` tidak ditemukan di dalam senarai.
* **Pencarian Berdasarkan Alamat (`fFindElm(L, P)`)**: Memeriksa apakah simpul dengan alamat memori `P` benar-benar terdaftar sebagai bagian dari senarai `L`, lalu mengembalikan nilai `true` jika ditemukan dan `false` jika sebaliknya.
* **Pencarian Simpul Pendahulu (`findBefore(L, P)`)**: Mencari dan mengembalikan alamat simpul pendahulu (predecessor) yang berada tepat sebelum simpul beralamat `P`, atau mengembalikan `Nil` apabila `P` berada di awal senarai. Keberadaan operasi searching ini mempermudah pelaksanaan operasi lain seperti insert after, delete after, dan pembaruan data (update) [5].
#### 2. Operasi Penyisipan (Insertion) dan Penghapusan (Deletion)
Penambahan simpul baru yang telah dialokasikan (P) ke dalam senarai dapat dilakukan pada tiga posisi utama, yaitu di awal senarai menggunakan insertFirst(L, P) dengan mengarahkan P->next ke L.first lalu memperbarui L.first = P, di tengah senarai sesudah simpul Prec menggunakan insertAfter(L, P, Prec), serta di akhir senarai menggunakan insertLast(L, P) [3]. Sebaliknya, pelepasan simpul dari senarai dilakukan melalui prosedur delFirst(L, P) untuk menghapus elemen pertama, delLast(L, P) untuk menghapus elemen terakhir, delAfter(L, P, Prec) untuk menghapus simpul tepat sesudah Prec (Prec->next), serta delP(L, X) yang memadukan pencarian nilai X dengan penghapusan sekaligus dealokasi simpul yang bersangkutan [1].
#### 3. Operasi Penelusuran (Traversal), Agregasi, dan Transformasi Senarai
Selain manipulasi per simpul, ADT Singly Linked List juga menyediakan operasi yang memproses seluruh elemen di dalam senarai secara menyeluruh [5]:
* **Pencetakan, Perhitungan, dan Penjumlahan Info (`printInfo`, `nbList`, & Total Info)**: Prosedur `printInfo(L)` menelusuri seluruh simpul dari `L.first` hingga `Nil` untuk menampilkan setiap nilai `info` ke layar, sedangkan fungsi `nbList(L)` menghitung jumlah simpul dan operasi agregasi menjumlahkan seluruh nilai `P->info` menggunakan variabel akumulator selama proses traversal.
* **Penghapusan Massal dan Pembalikan Urutan (`delAll` & `invertList`)**: Prosedur `delAll(L)` menghapus serta mendealokasi seluruh elemen hingga senarai kembali kosong, sementara `invertList(L)` membalik arah tautan pointer antar-simpul sehingga urutan elemen dalam senarai menjadi terbalik tanpa perlu mengalokasikan simpul baru.
* **Penyalinan Senarai (`copyList` & `fCopyList`)**: Prosedur `copyList(L1, L2)` menyalin penunjuk awal sehingga `L1` dan `L2` menunjuk pada rangkaian elemen yang sama (shallow copy), sedangkan fungsi `fCopyList(L)` menghasilkan salinan senarai baru yang terpisah secara memori (deep copy).

## Guided 

### 1. listBuah

```C++
//Header
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif

//Body
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

//Main
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program di atas merupakan implementasi Abstract Data Type (ADT) Singly Linked List untuk mengelola data buah (nama, jumlah, dan harga) yang dibagi ke dalam tiga bagian, yaitu file header (listBuah.h) untuk deklarasi struktur data dan prototipe fungsi, file body (listBuah.cpp) untuk realisasi algoritma, serta file main.cpp sebagai program utama. Selain menyediakan operasi dasar pembuatan list, alokasi-dealokasi memori, penyisipan (insertFirst, insertAfter, insertLast), dan penghapusan (delFirst, delLast, delAfter, deleteList), program ini mengimplementasikan materi Modul 5 berupa pembaruan data (updateFirst, updateLast, updateAfter) serta pencarian simpul berdasarkan nama buah (FindNodeByData), alamat memori (FindNodeByAddress), dan rentang harga (FindNodeByRange). Pada fungsi main(), kelima data buah dialokasikan dan disisipkan ke dalam list, kemudian diuji secara berurutan mulai dari proses penampilan isi list, pengubahan data (update), pencarian elemen (searching), hingga penghapusan simpul satu per satu maupun seluruh list sekaligus.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”, Kemudian buat implementasi ADT Singly Linked list pada file “Singlylist.cpp”.

```C++
//Header
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
//Body
#include "singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

void createList(List &L) {
    CreateList(L);
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
//Main
#include "Singlylist.h"

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1]()

Program di atas mengimplementasikan Abstract Data Type (ADT) Singly Linked List bertipe data integer yang terbagi ke dalam tiga bagian, yaitu file header (Singlylist.h) untuk deklarasi struktur simpul ElmList, struktur List, serta prototipe fungsi, dan file body (Singlylist.cpp) untuk realisasi algoritmanya. File implementasi tersebut menyediakan operasi dasar yang meliputi pembuatan list kosong (CreateList), alokasi simpul baru di memori dinamis menggunakan operator new (alokasi), penghapusan memori simpul (dealokasi), penyisipan elemen di awal list (insertFirst), serta penelusuran untuk mencetak isi list (printInfo). Pada fungsi main(), program menginisialisasi list kosong L lalu mengalokasikan dan menyisipkan lima elemen (2, 0, 8, 12, dan 9) secara berurutan menggunakan prosedur insertFirst, sehingga elemen yang terakhir disisipkan berada di posisi paling depan dan menghasilkan keluaran 9 12 8 0 2 saat ditampilkan.

### 2. Carilah elemen dengan info 8 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address

```C++
//Header
#ifndef SINGLYLIST2_H
#define SINGLYLIST2_H

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);

#endif
//Body
#include "singlylist2.h"

void CreateList(List &L) {
    L.First = Nil;
}

void createList(List &L) {
    CreateList(L);
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
//Main
#include "singlylist2.h"

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    address PFound = findElm(L, 8);
    if (PFound != Nil) {
        cout << PFound->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2]()

Program di atas menambahkan operasi pencarian elemen pada ADT Singly Linked List yang dipisahkan ke dalam tiga file, yaitu singlylist2.h sebagai header, singlylist2.cpp sebagai body implementasi, dan main2.cpp sebagai program utama. Fungsi findElm(List L, infotype x) pada file implementasi bekerja dengan menelusuri setiap simpul mulai dari L.First hingga Nil dan mengembalikan alamat memori simpul (address) apabila ditemukan simpul dengan nilai P->info yang sama dengan x. Pada fungsi main(), setelah kelima elemen (9, 12, 8, 0, 2) disisipkan ke dalam list L, program memanggil findElm(L, 8) dan menampilkan pesan "8 ditemukan dalam list" karena alamat simpul yang dikembalikan tidak bernilai Nil.

### 3. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).

```C++
//Header
#ifndef SINGLYLIST3_H
#define SINGLYLIST3_H

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif
//Body
#include "singlylist3.h"

void CreateList(List &L) {
    L.First = Nil;
}

void createList(List &L) {
    CreateList(L);
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
//Main
#include "singlylist3.h"

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 3]()

Program di atas menambahkan operasi perhitungan total nilai elemen pada ADT Singly Linked List yang dipisahkan ke dalam tiga file, yaitu singlylist3.h sebagai header, singlylist3.cpp sebagai body implementasi, dan main3.cpp sebagai program utama. Fungsi totalInfo(List L) pada file implementasi bekerja dengan menginisialisasi variabel total = 0, kemudian menelusuri seluruh simpul mulai dari L.First hingga Nil menggunakan perulangan while sembari mengakumulasikan nilai P->info dari setiap simpul. Pada fungsi main(), setelah kelima elemen (9, 12, 8, 0, dan 2) dialokasikan dan disisipkan ke dalam list L, program memanggil fungsi totalInfo(L) sehingga menghasilkan keluaran "Total info dari kelima elemen adalah 31".

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Meidelfi, Dwiny., dkk. (2024). "BUKU AJAR ALGORITMA DAN STRUKTUR DATA". Bandung: Widina Media Utama. Diakses melalui https://www.researchgate.net/publication/377306812_BUKU_AJAR_ALGORITMA_DAN_STRUKTUR_DATA.
<br>[4] Pratama, A., dkk. (2024). "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List". Jurnal Pendidikan Teknologi Informasi (JUTECH), 5(2), 484–499. Diakses melalui https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263.
<br>[5] Musridho, R. (2024). "Diktat Struktur Data". Bangkinang: Universitas Pahlawan Tuanku Tambusai. Diakses melalui https://www.google.com/search?q=https://repository.universitaspahlawan.ac.id/1887/1/%25282024%2529%2520Musridho%2520-%2520Diktat%2520Struktur%2520Data.pdf.
