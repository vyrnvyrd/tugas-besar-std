#include <iostream>
#include <stdlib.h>
#include "mll.h"

using namespace std;

int main()
{
    mll list_dosen;
    adr_dosen adrDosen;
    adr_mahasiswa adrMahasiswa;
    int input;

    Create_List(list_dosen);

    // initial dosen
    New_Elm_Dosen({"11111", "Ida", "ID", "Dasar-Dasar Pemograman"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"22222", "Ardi", "ARD", "Algoritma Pemrograman"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"33333", "Bima", "BM", "Kalkulus"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"44444", "Cintya", "CN", "Bhs Inggris"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);

    // initial mahasiswa
    New_Elm_Mahasiswa({"12345", "Firna", "Pengembangan TI"}, adrMahasiswa);
    Insert_New_Mahasiswa(list_dosen, Search_Dosen_By_Code(list_dosen, "ARD"), adrMahasiswa);
    New_Elm_Mahasiswa({"23456", "Mazid", "Sistem Informasi Pajak"}, adrMahasiswa);
    Insert_New_Mahasiswa(list_dosen, Search_Dosen_By_Code(list_dosen, "ID"), adrMahasiswa);
    New_Elm_Mahasiswa({"22121", "Ali", "Anterin Makan"}, adrMahasiswa);
    Insert_New_Mahasiswa(list_dosen, Search_Dosen_By_Code(list_dosen, "ID"), adrMahasiswa);


    input = 1;
    while (input != 99) {
        cout << "=========================================================" << endl;
        cout << "=                                                       =" << endl;
        cout << "=  SISTEM INFORMASI DATA MAHASISWA DAN DOSEN BIMBINGAN  =" << endl;
        cout << "=                                                       =" << endl;
        cout << "=========================================================" << endl;
        cout << "  Menu " << endl;
        cout << "  1. Tambah Data Dosen X" << endl;
        cout << "  2. Menampilkan Data Dosen X" << endl;
        cout << "  3. Hapus Dosen X" << endl;
        cout << "  4. Cari Dosen X" << endl;
        cout << "  5. Tambah Mahasiswa Y untuk Dosen X" << endl;
        cout << "  6. Hapus Mahasiswa Y dari Dosen X" << endl;
        cout << "  7. Menampilkan Seluruh Mahasiswa dari Dosen X" << endl;
        cout << "  8. Mencari Mahasiswa X dari Dosen Y" << endl;
        cout << "  9. Membuat Relasi antara Dosen X dan Mahasiswa Y" << endl;
        cout << "  10. Menghapus Relasi antara Dosen X dan Mahasiswa Y" << endl;
        cout << "  11. Menampilkan Mahasiswa terbanyak dari Dosen X" << endl;
        cout << "  12. Mencari Dosen X dari Mahasiswa Y" << endl;
        cout << "  99. Exit" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> input;

        system("CLS");
        switch (input) {
            case 1:
                Menu_Tambah_Dosen(list_dosen, input);
                break;
            case 2:
                Menu_Menampilkan_Dosen_X(list_dosen, input);
                break;
            case 3:
                Menu_Hapus_Dosen(list_dosen, input);
                break;
            case 4:
                Menu_Cari_Dosen_X(list_dosen, input);
                break;
            case 5:
                Menu_Tambah_Mahasiswa_Ke_Dosen(list_dosen, input);
                break;
            case 6:
                Menu_Hapus_Mahasiswa_Y_Dari_Dosen_X(list_dosen, input);
                break;
            case 7:
                Menu_Tampilkan_Mahasiswa_Dari_Dosen(list_dosen, input);
                break;
            case 8:
                Menu_Search_Mahasiswa_Y_Dari_Dosen_X(list_dosen, input);
                break;
            case 9:
                Menu_Tambah_Mahasiswa_Ke_Dosen(list_dosen, input);
                break;
            case 10:
                Menu_Hapus_Mahasiswa_Y_Dari_Dosen_X(list_dosen, input);
                break;
            case 11:
                Menu_Mahasiswa_Terbanyak(list_dosen, input);
                break;
            case 12:
                Menu_Cari_Dosen_Dari_Mahasiswa_X(list_dosen, input);
                break;
        }

        if (input == 99) {
            Menu_Exit();
        }
    }

    return 0;
}
