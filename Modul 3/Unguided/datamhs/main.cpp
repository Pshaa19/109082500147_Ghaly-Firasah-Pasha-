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