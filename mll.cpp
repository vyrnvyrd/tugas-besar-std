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
    return first(list_dosen) == nil;
}

adr_dosen searchDosenByCode(mll list_dosen, string kode_dosen) {
    adr_dosen curr;

    if (isListDosenEmpty(list_dosen)){
        cout << "Daftar Dosen Kosong!" << endl;
    }else{
        curr = first(list_dosen);
        while(curr != nil && info(curr).kode_dosen != kode_dosen){
            curr = nextDosen(curr);
        }
    }
    return curr;
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

adr_dosen Delete_First_Dosen(mll &list_dosen){
    adr_dosen P, data;

    P = first(list_dosen);
    data = first(list_dosen);
    first(list_dosen) = nextDosen(P);
    nextDosen(P) = nil;

    return data;
}

adr_dosen Delete_Last_Dosen(mll &list_dosen){
    adr_dosen P, Q;

    P = first(list_dosen);
    while (nextDosen(nextDosen(P)) != nil) {
        P = nextDosen(P);
    }
    Q = nextDosen(P);
    nextDosen(P) = nil;

    return Q;
}

adr_dosen Delete_After_Dosen(mll &list_dosen, adr_dosen prev, adr_dosen curr){
    curr = nextDosen(prev);
    nextDosen(prev) = nextDosen(curr);
    nextDosen(curr) = nil;

    return curr;
};

adr_dosen Delete_DosenX(mll &list_dosen, string kode_dosen){
    adr_dosen curr, prev, data;

    prev = nil;
    data = nil;
    curr = first(list_dosen);
    while(curr != nil && info(curr).kode_dosen != kode_dosen){
        prev = curr;
        curr = nextDosen(curr);
    }

    if (curr != nil){
        if (prev == nil && curr == first(list_dosen)) {
            data = Delete_First_Dosen(list_dosen);
        } else if (nextDosen(curr) == nil) {
            data = Delete_Last_Dosen(list_dosen);
        } else {
            data = Delete_After_Dosen(list_dosen, prev, curr);
        }
    } else {
        cout << "Data Dosen tidak ditemukan!" << endl;
    }

    return data;
}

void Show_All_Dosen(mll list_dosen){
    adr_dosen p = first(list_dosen);
    while(p != nil){
        cout << info(p).nik << " - " << info(p).kode_dosen << " - " << info(p).nama << " - " << info(p).matkul << endl;
        p = nextDosen(p);
    }
    cout << endl;
}
