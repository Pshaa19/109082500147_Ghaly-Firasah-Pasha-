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