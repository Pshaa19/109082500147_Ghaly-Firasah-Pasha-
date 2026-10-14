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