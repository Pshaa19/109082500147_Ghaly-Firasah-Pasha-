#include "doublylist2.h"

int main() {
    List L;
    CreateList(L);

    infotype k1 = {"D001", "hitam", 90};
    infotype k2 = {"D003", "putih", 70};
    infotype k3 = {"D004", "kuning", 90};

    insertLast(L, alokasi(k1));
    insertLast(L, alokasi(k2));
    insertLast(L, alokasi(k3));

    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> cari.nopol;
    cout << endl;

    address PFound = findElm(L, cari);
    if (PFound != Nil) {
        cout << "Nomor Polisi : " << PFound->info.nopol << endl;
        cout << "Warna        : " << PFound->info.warna << endl;
        cout << "Tahun        : " << PFound->info.thnBuat << endl;
    } else {
        cout << "Nomor Polisi " << cari.nopol << " tidak ditemukan." << endl;
    }

    return 0;
}