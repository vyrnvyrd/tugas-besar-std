#include <iostream>
#include <string>
#include "mll.h"

using namespace std;

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

bool Is_List_Dosen_Empty(mll list_dosen){
    return first(list_dosen) == nil;
}

adr_dosen Search_Dosen_By_Code(mll list_dosen, string kode_dosen) {
    adr_dosen curr;

    if (Is_List_Dosen_Empty(list_dosen)){
        cout << "Daftar Dosen Kosong!" << endl;
    }else{
        curr = first(list_dosen);
        while(curr != nil && info(curr).kode_dosen != kode_dosen){
            curr = nextDosen(curr);
        }
    }
    return curr;
}

void Show_Dosen_Data(mll list_dosen, string kode_dosen) {
    adr_dosen searched = Search_Dosen_By_Code(list_dosen, kode_dosen);
    if (searched == nil){
        cout << "Dosen dengan kode dosen " << kode_dosen << " tidak Ditemukan" << endl;
    }else{
        cout << "Nama                   : " << info(searched).nama << endl;
        cout << "NIK                    : " << info(searched).nik << endl;
        cout << "Mata Kuliah Pengampu   : " << info(searched).matkul << endl;
        cout << "Kode Dosen             : " << info(searched).kode_dosen << endl;

        cout << "Daftar Mahasiswa Yang Dimbimbing : " << endl;
        Show_Mahasiswa_From_Dosen(searched);
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

adr_dosen Delete_DosenX(mll &list_dosen, adr_dosen adrDosen){
    adr_dosen firstData, prev, data;

    data = nil;
    firstData = first(list_dosen);

    if (firstData != nil){
        if (firstData == adrDosen) {
            data = Delete_First_Dosen(list_dosen);
        } else if (nextDosen(firstData) == nil) {
            data = Delete_Last_Dosen(list_dosen);
        } else {
            prev = first(list_dosen);
            while (nextDosen(prev) != adrDosen) {
                prev = nextDosen(prev);
            }
            data = Delete_After_Dosen(list_dosen, prev, firstData);
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

void Insert_New_Mahasiswa(mll &list_dosen, adr_dosen adrDosen, adr_mahasiswa adrMahasiswa){
    if (adrDosen != nil) {
        if (nextMahasiswa(adrDosen) == nil){
            nextMahasiswa(adrDosen) = adrMahasiswa;
        } else {
            adr_mahasiswa mahasiswa = nextMahasiswa(adrDosen);
            while(nextMahasiswa(mahasiswa) != nil){
                mahasiswa = nextMahasiswa(mahasiswa);
            }
            if (info(mahasiswa).nim != info(adrMahasiswa).nim && info(mahasiswa).nama != info(adrMahasiswa).nama) {
                nextMahasiswa(mahasiswa) = adrMahasiswa;
            } else {
                cout << "Maaf mahasiswa sudah tergabung!" << endl;
            }
        }
    } else {
        cout << "Maaf kode dosen tidak ditemukan!" << endl;
    }
}

void New_Elm_Mahasiswa(mahasiswa dataMahasiswa, adr_mahasiswa &adrMahasiswa){
    adrMahasiswa = new elm_mahasiswa;
    nextMahasiswa(adrMahasiswa) = nil;
    info(adrMahasiswa) = dataMahasiswa;
}

adr_mahasiswa Search_Mahasiswa_From_Dosen(adr_dosen dosen, string nim_mhs){
    adr_mahasiswa currMhs = nextMahasiswa(dosen);

    do{
        if (currMhs != nil && info(currMhs).nim == nim_mhs){
            return currMhs;
        }
        currMhs = nextMahasiswa(currMhs);
    }while(currMhs != nil);

    cout << "Tidak ada mahasiswa yang dibimbing oleh dosen " << info(dosen).nama << endl;

    return currMhs;
}

void Delete_Relation_Dosen_and_Mahasiswa(mll &list_dosen, adr_dosen adrDosen, adr_mahasiswa adrMahasiswa){
    if (adrDosen != nil && adrMahasiswa != nil){
        adr_dosen currDosen = first(list_dosen);
        if (currDosen != nil){
            while(currDosen != adrDosen){
                currDosen = nextDosen(currDosen);
            }
            if (currDosen != nil){
                adr_mahasiswa currMhs = nextMahasiswa(currDosen);
                if (currMhs != adrMahasiswa){
                    while(currMhs != nil && nextMahasiswa(currMhs) != adrMahasiswa){
                        currMhs == nextMahasiswa(currMhs);
                    }
                    if (currMhs != nil){
                            cout << info(currMhs).nama << endl;
                        nextMahasiswa(currMhs) = nextMahasiswa(nextMahasiswa(currMhs));
                    }
                }else{
                    nextMahasiswa(currDosen) = nextMahasiswa(currMhs);
                }
            }
        }
    }
}

void Delete_Mahasiswa_Bimbingan_From_Dosen(mll &list_dosen, adr_dosen adrDosen, adr_mahasiswa adrMahasiswa){
    if (adrDosen != nil && adrMahasiswa != nil){
        adr_dosen currDosen = first(list_dosen);
        if (currDosen != nil){
            while(currDosen != adrDosen){
                currDosen = nextDosen(currDosen);
            }
            if (currDosen != nil){
                adr_mahasiswa currMhs = nextMahasiswa(currDosen);
                if (currMhs != adrMahasiswa){
                    while(currMhs != nil && nextMahasiswa(currMhs) != adrMahasiswa){
                        currMhs == nextMahasiswa(currMhs);
                    }
                    if (currMhs != nil){
                            cout << info(currMhs).nama << endl;
                        nextMahasiswa(currMhs) = nextMahasiswa(nextMahasiswa(currMhs));
                    }
                }else{
                    nextMahasiswa(currDosen) = nextMahasiswa(currMhs);
                }
            }
        }
    }
}


string Search_Nama_Dospem_From_Mahasiswa(mll list_dosen, adr_mahasiswa adrMahasiswa){
    adr_dosen currDosen = first(list_dosen);

    if (currDosen == nil){
        cout << "Data Dosen Kosong" << endl;
        return "";
    }else{
        do {
            adr_mahasiswa currMhs = nextMahasiswa(currDosen);
            cout << info(currMhs).nama << endl;
            while(currMhs != nil && currMhs != adrMahasiswa){
                currMhs = nextMahasiswa(currMhs);
            }
            if (currMhs == adrMahasiswa){
                    return info(currDosen).nama;
            }else{
                currDosen = nextDosen(currDosen);
            }
        }while(currDosen == nil);
    }

    cout << "Tidak ada dosen pembimbing dari mahasiswa " << info(adrMahasiswa).nama << endl;

    return "";
}

void Show_Mahasiswa_From_Dosen(adr_dosen adrDosen){
    if (nextMahasiswa(adrDosen) != nil) {
        adr_mahasiswa mhsDibimbing;

        mhsDibimbing = nextMahasiswa(adrDosen);
        while (mhsDibimbing != nil) {
            cout << "  - " << info(mhsDibimbing).nim << " " << info(mhsDibimbing).nama << " Judul TA: " << info(mhsDibimbing).judulTugasAkhir << endl;
            mhsDibimbing = nextMahasiswa(mhsDibimbing);
        }
    } else {
        cout << "Tidak ada mahasiswa yang terdaftar!" << endl;
    }
}

int Count_Mahasiswa_From_Dosen(adr_dosen adrDosen){
    int total;

    total = 0;
    if (nextMahasiswa(adrDosen) != nil) {
        adr_mahasiswa mhsDibimbing;

        mhsDibimbing = nextMahasiswa(adrDosen);
        while (mhsDibimbing != nil) {
            total = total + 1;
            mhsDibimbing = nextMahasiswa(mhsDibimbing);
        }
    }

    return total;
}

void Show_Largest_Mahasiswa(mll list_dosen){
    adr_dosen p, maxDosen;
    int maxTotal, tempTotal;


    maxTotal = 0;
    tempTotal = 0;
    maxDosen = nil;
    p = first(list_dosen);

    while(p != nil){
        tempTotal = Count_Mahasiswa_From_Dosen(p);
        if (tempTotal > maxTotal){
            maxTotal = tempTotal;
            maxDosen = p;
        }
        p = nextDosen(p);
    }

    if (maxDosen == nil && maxTotal == 0){
        cout << "Tidak ada dosen dengan jumlah mahasiswa terbanyak!" << endl;
    } else {
        cout << "Total Mahasiswa: " << maxTotal << endl;
        cout << endl;
        Show_Dosen_Data(list_dosen, info(maxDosen).kode_dosen);
    }
}

void Back_To_Menu(int &input){
    char decision;

    decision = 'l';
    while (decision != 'Y' && decision != 'y' && decision != 'N' && decision != 'n') {
        cout << "Back to Menu? [Y/N] : "; cin >> decision;
        cout << endl;
    }
    if (decision == 'n' || decision == 'N'){
        input = 99;
    }

    system("CLS");
}

void Menu_Exit(){
    cout << "TERIMAKASIH" << endl;
    cout << "\nDevelop By: " << endl;
    cout << "1. 1301218681 - Firna Firdiani" << endl;
    cout << "1. 1301218683 - Mazid Ahmad" << endl;
}

void Menu_Tambah_Dosen(mll &list_dosen, int &input){
    dosen dataInput;
    adr_dosen adrDosen;

    cout << "Lengkapi Data Berikut!" << endl;
    cout << "NIK         : "; cin.ignore(1,'\n'); getline(cin, dataInput.nik, '\n') ;
    cout << "Kode Dosen  : "; cin.ignore(0,'\n'); getline(cin, dataInput.kode_dosen, '\n');
    cout << "Nama        : "; cin.ignore(0,'\n'); getline(cin, dataInput.nama, '\n');
    cout << "Mata Kuliah : "; cin.ignore(0,'\n'); getline(cin, dataInput.matkul, '\n');

    New_Elm_Dosen(dataInput, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);

    cout << "\nBerhasil Menambahkan Data Dosen!" << endl;
    Back_To_Menu(input);
}

void Menu_Hapus_Dosen(mll &list_dosen, int &input) {
    string kodeDosen;
    adr_dosen found;

    cout << "Masukkan Kode Dosen: "; cin >> kodeDosen;
    found = Search_Dosen_By_Code(list_dosen, kodeDosen);
    if (found != nil){
        Delete_DosenX(list_dosen, found);

        cout << "\nBerhasil Menghapus Data Dosen!" << endl;
    } else {
        cout << "\nKode Dosen Tidak Ditemukan!" << endl;
    }

    Back_To_Menu(input);
}

void Menu_Tambah_Mahasiswa_Ke_Dosen(mll &list_dosen, int &input){
    mahasiswa dataInput;
    adr_mahasiswa adrMahasiswa;
    string kodeDosen;

    cout << "Lengkapi Data Berikut!" << endl;
    cout << "NIM         : "; cin.ignore(1,'\n'); getline(cin, dataInput.nim, '\n') ;
    cout << "Nama        : "; cin.ignore(0,'\n'); getline(cin, dataInput.nama, '\n');
    cout << "Judul TA    : "; cin.ignore(0,'\n'); getline(cin, dataInput.judulTugasAkhir, '\n');
    cout << "Kode Dosen  : "; cin >> kodeDosen;

    New_Elm_Mahasiswa(dataInput, adrMahasiswa);
    Insert_New_Mahasiswa(list_dosen, Search_Dosen_By_Code(list_dosen, kodeDosen), adrMahasiswa);

    cout << "\nBerhasil Menambahkan Data Mahasiswa ke Kode Dosen: " << kodeDosen << endl;
    Back_To_Menu(input);

}

void Menu_Tampilkan_Mahasiswa_Dari_Dosen(mll &list_dosen, int &input){
    string kodeDosen;
    adr_dosen found;

    cout << "Masukkan Kode Dosen: "; cin >> kodeDosen;

    found = Search_Dosen_By_Code(list_dosen, kodeDosen);
    if (found != nil){
        Show_Mahasiswa_From_Dosen(found);
        cout << endl;
    } else {
        cout << "\nKode Dosen Tidak Ditemukan!" << endl;
    }

    Back_To_Menu(input);
}

void Menu_Mahasiswa_Terbanyak(mll &list_dosen, int &input){
    cout << "----------------------------------------------------------" << endl;
    cout << "Dosen dengan Mahasiswa Bimbingan Terbanyak" << endl;
    cout << "----------------------------------------------------------" << endl;
    Show_Largest_Mahasiswa(list_dosen);


    cout << endl;
    Back_To_Menu(input);
}
