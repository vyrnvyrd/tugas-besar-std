#include <iostream>
#include "mll.h"

using namespace std;

int main()
{
    // temp logic add dosen
    mll list_dosen;
    Create_List(list_dosen);
    adr_dosen adrDosen, found, dataDelete;
    New_Elm_Dosen({"11111", "Ida", "ID", "Dasar-Dasar Pemograman"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"22222", "Ardi", "ARD", "Algoritma Pemrograman"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"33333", "Bima", "BM", "Kalkulus"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"44444", "Cintya", "CN", "Bhs Inggris"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);

    // temp logic add mahasiswa
    adr_mahasiswa adrMahasiswa;
    New_Elm_Mahasiswa({"12345", "Firna", "Pengembangan TI"}, adrMahasiswa);
    Insert_New_Mahasiswa(list_dosen, searchDosenByCode(list_dosen, "ARD"), adrMahasiswa);
    New_Elm_Mahasiswa({"23456", "Mazid", "Pengembangan TI"}, adrMahasiswa);
    Insert_New_Mahasiswa(list_dosen, searchDosenByCode(list_dosen, "ID"), adrMahasiswa);

    cout << "----------------------------------------------------------" << endl;
    showDosenData(list_dosen,"ARD");
    cout << "----------------------------------------------------------" << endl;
    Show_All_Dosen(list_dosen);
    found = searchDosenByCode(list_dosen, "ARD");
    cout << "ketemu: " << info(found).nama << endl;
    if (found != nil) {
        dataDelete = Delete_DosenX(list_dosen, found);
    }
    Show_All_Dosen(list_dosen);
    cout << "data yang didelete: " << info(dataDelete).nama << endl;
    cout << "---------------------------------------------------------" << endl;
    return 0;
}
