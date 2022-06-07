#include <iostream>
#include "mll.h"

void Create_List(mll &list_dosen){
    first(list_dosen) = nil;
}

void New_Elm_Dosen(dosen dataDosen, adr_dosen &adrDosen) {
    adrDosen = new elm_dosen;
    nextDosen(adrDosen) = nil;
    nextMahasiswa(adrDosen) = nil;
    info(adrDosen) = dataDosen;
}

void Insert_Last_Dosen(mll &list_dosen, adr_dosen adrDosen) {
    if (first(list_dosen) == nil) {
        first(list_dosen) = adrDosen;
    } else {
        adr_dosen P = first(list_dosen);
        while (nextDosen(P) != nil) {
            P = nextDosen(P);
        }
        nextDosen(P) = adrDosen;
    }
}

bool isListDosenEmpty(mll list_dosen){
    if (list_dosen.first == nil){
        return true;
    }else{
        return false;
    }
}

adr_dosen searchDosenByCode(mll list_dosen, string kode_dosen) {
    adr_dosen curr;

    if (isListDosenEmpty(list_dosen)){
        cout << "Daftar Dosen Kosong!" << endl;
    }else{
        curr = list_dosen.first;
        while(curr != nil && info(curr).kode_dosen != kode_dosen){
            curr = nextDosen(curr);
        }
        return curr;
    }
}

void showDosenData(mll list_dosen, string kode_dosen) {
    adr_dosen searched = searchDosenByCode(list_dosen, kode_dosen);
    if (searched == nil){
        cout << "Dosen dengan kode dosen " << kode_dosen << " tidak Ditemukan" << endl;
    }else{
        cout << "Nama                   : " << info(searched).nama << endl;
        cout << "NIK                    : " << info(searched).nik << endl;
        cout << "Mata Kuliah Pengampu   : " << info(searched).matkul << endl;
        cout << "Kode Dosen             : " << info(searched).kode_dosen << endl;
    }
}
