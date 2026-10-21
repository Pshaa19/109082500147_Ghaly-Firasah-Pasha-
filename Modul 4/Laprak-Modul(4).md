# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama) </h1>
<p align="center">Ghaly Firasah Pasha - 109082500147</p>

## Dasar Teori
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data berupa serangkaian elemen data yang saling berkait dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Linked list dapat diimplementasikan menggunakan array dan pointer, di mana penggunaan pointer lebih dipilih karena sifatnya yang dinamis dan fleksibel dalam menangani hubungan antar elemen data.

### A. Konsep Dasar dan Komponen Singly Linked List<br/>
Singly linked list merupakan model ADT linked list yang hanya memiliki satu arah pointer.
#### 1. Karakteristik Singly Linked List
• Singly linked list hanya memerlukan satu buah pointer.
• Node akhir menunjuk ke nilai Nil kecuali untuk list circular.
• Pembacaan data pada list ini hanya dapat dilakukan secara maju.
#### 2. Komponen Elemen Singly Linked List
• Elemen pada singly linked list terdiri dari segmen data dan suksesor.
• Bagian data berfungsi untuk menyimpan informasi utama yang tersimpan dalam sebuah elemen.
• Bagian suksesor berfungsi sebagai penghubung antar elemen.
#### 3. Istilah Penting dalam Singly Linked List
• first atau head adalah pointer pada list yang menunjuk alamat elemen pertama.
• next adalah pointer pada elemen yang berfungsi sebagai penunjuk alamat elemen di depannya.
• NULL atau Nil menyatakan bahwa suatu pointer tidak memiliki nilai atau tidak mengacu ke mana pun.

### B. NULL atau Nil menyatakan bahwa suatu pointer tidak memiliki nilai atau tidak mengacu ke mana pun.<br/>
Operasi dasar pada linked list mencakup penciptaan dan inisialisasi list, penyisipan elemen, penghapusan elemen, penelusuran, pencarian, serta pengubahan isi elemen.
#### 1. Pembentukan dan Alokasi Memori
• Pembentukan list baru dilakukan melalui fungsi createList() untuk mengeset nilai awal first dengan nilai Nil.
• Alokasi memori untuk elemen baru pada bahasa C++ dapat dilakukan menggunakan operator new.
• Dealokasi dilakukan untuk menghapus dan mengembalikan memori yang telah digunakan oleh elemen ke sistem menggunakan syntax delete.
#### 2. Operasi Penyisipan Elemen (Insert)
• Insert First merupakan metode memasukkan elemen data ke dalam list yang diletakkan pada awal list.
• Insert Last merupakan metode memasukkan elemen data baru ke dalam list yang diletakkan pada akhir list.
• Insert After merupakan metode memasukkan data ke dalam list setelah node tertentu yang ditunjuk oleh user.
#### 3. Operasi Penghapusan dan Manajemen Memori
• Delete First adalah proses pengambilan atau penghapusan sebuah elemen pada awal list.   
• Delete Last merupakan pengambilan atau penghapusan suatu elemen dari akhir list.
• Delete After adalah pengambilan atau penghapusan node setelah node tertentu.

## Guided 

### 1. List

```C++
//header
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct LinkedList {
    address first;
};

bool isEmpty(LinkedList list);
void createList(LinkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(LinkedList list);
void insertFirst(LinkedList &list, address nodeBaru);
void insertAfter(LinkedList &list, address nodeBaru, address Prev);
void insertLast(LinkedList &list, address nodeBaru);

void delFirst(LinkedList &list);
void delLast(LinkedList &list);
void delAfter(LinkedList &list, address nodeHapus, address nodePrev);
int nbList(LinkedList list);
void deleteList(LinkedList &list);

#endif

//body
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(LinkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

void createList(LinkedList &list) {
    list.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(LinkedList &list, address nodeBaru) {
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(LinkedList &list, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(LinkedList &list, address nodeBaru) {
    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(LinkedList &list){
    address nodeHapus;
    if (isEmpty(list) == false) {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &list){
    address nodeHapus, nodePrev;
    if(isEmpty(list) == false) {
        nodeHapus = list.first;
        if(nodeHapus->next == Nil){
            list.first = Nil; 
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(LinkedList &list, address nodeHapus, address nodePrev){
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else 
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
}

void printList(LinkedList list) {
    if (isEmpty(list)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(LinkedList list) {
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(LinkedList &list){
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while(nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

//main
#include "list.h"
#include <iostream>
using namespace std;

int main(){
    LinkedList List;
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

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
Program ini mengimplementasikan struktur data Singly Linked List di C++ untuk mengelola data mahasiswa yang mencakup nama, NIM, dan usia. File header dan body mendefinisikan serta menjalankan berbagai operasi primitif seperti alokasi, penyisipan (first, last, after), penghapusan, dan penelusuran list. Bagian utama (main) mendemonstrasikan eksekusi fungsi-fungsi tersebut mulai dari memasukkan data, menghapus beberapa node, hingga membersihkan seluruh isi list.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”. Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut.

```C++
//header
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif

//body
#include "singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

//main
#include "singlylist.h"

int main() {
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

##### Output 1
![Screenshot Output Unguided 1](https://github.com/Pshaa19/109082500147_Ghaly-Firasah-Pasha-/blob/main/Modul%204/output/output%20unguided%201.png)

Program ini mengimplementasikan struktur data Singly Linked List dalam C++ yang terbagi menjadi file header, file implementasi, dan program utama. Sistem menyediakan operasi primitif seperti pembuatan list, alokasi memori, dealokasi, penambahan elemen di awal (insertFirst), serta pencetakan elemen. Melalui fungsi utama (main), program menyisipkan data secara berurutan untuk menampilkan output nilai sesuai dengan ketentuan modul praktikum.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

```C++
//header
#ifndef SINGLYLIST2_H_INCLUDED
#define SINGLYLIST2_H_INCLUDED

#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif

//body
#include "singlylist2.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = (L.first)->next;
    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    address Q = L.first;
    if (Q->next == Nil) {
        L.first = Nil;
        P = Q;
    } else {
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}

//main
#include "singlylist2.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    address P;
    
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
    
    deleteFirst(L, P);
    dealokasi(P);
    
    deleteLast(L, P);
    dealokasi(P);
    
    deleteAfter(L, P, L.first);
    dealokasi(P);
    
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;
    
    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/Pshaa19/109082500147_Ghaly-Firasah-Pasha-/blob/main/Modul%204/output/output%20unguided%202.png)

Program ini mengimplementasikan operasi penghapusan node seperti deleteFirst, deleteLast, dan deleteAfter pada struktur data Singly Linked List. Fungsi nbList dan deleteList digunakan untuk menghitung sisa node serta menghapus seluruh elemen di dalam list. File utama (main2.cpp) menjalankan seluruh tahapan penghapusan tersebut untuk menampilkan output akhir sesuai dengan instruksi praktikum.

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Fakultas Informatika. Modul 4 Singly Linked List (Bagian Pertama). Bandung: Telkom University.
