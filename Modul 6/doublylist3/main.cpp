#include "doublylist3.h"

int main() {
    List L;
    CreateList(L);

    infotype k1 = {"D001", "hitam", 90};
    infotype k2 = {"D003", "putih", 70};
    infotype k3 = {"D004", "kuning", 90};

    insertLast(L, alokasi(k1));
    insertLast(L, alokasi(k2));
    insertLast(L, alokasi(k3));

    infotype hapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    cin >> hapus.nopol;

    address PTarget = findElm(L, hapus);
    if (PTarget != Nil) {
        address P = Nil;
        if (PTarget == L.First) {
            deleteFirst(L, P);
        } else if (PTarget == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(PTarget->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << hapus.nopol << " berhasil dihapus." << endl << endl;
    } else {
        cout << "Data dengan nomor polisi " << hapus.nopol << " tidak ditemukan." << endl << endl;
    }

    printInfo(L);

    return 0;
}