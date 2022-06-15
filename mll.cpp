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

void Show_Dosen_Data(adr_dosen dosen) {
    cout << "Nama                   : " << info(dosen).nama << endl;
    cout << "NIK                    : " << info(dosen).nik << endl;
    cout << "Mata Kuliah Pengampu   : " << info(dosen).matkul << endl;
    cout << "Kode Dosen             : " << info(dosen).kode_dosen << endl;

    cout << "Daftar Mahasiswa Yang Dimbimbing : " << endl;
    Show_Mahasiswa_From_Dosen(dosen);
}

void Show_Mahasiswa_Data(adr_mahasiswa mahasiswa) {
    cout << "Nama                   : " << info(mahasiswa).nama << endl;
    cout << "NIK                    : " << info(mahasiswa).nim << endl;
    cout << "Mata Kuliah Pengampu   : " << info(mahasiswa).judulTugasAkhir << endl;
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
                        nextMahasiswa(currMhs) = nextMahasiswa(nextMahasiswa(currMhs));
                    }
                }else{
                    nextMahasiswa(currDosen) = nextMahasiswa(currMhs);
                }
            }
        }
    }
}


string Search_Nama_Dospem_From_Mahasiswa(mll list_dosen, string nim_mhs){
    adr_dosen currDosen = first(list_dosen);

    if (currDosen == nil){
        cout << "Data Dosen Kosong" << endl;
        return "";
    }else{
        do {
            adr_mahasiswa currMhs = nextMahasiswa(currDosen);
            while(currMhs != nil && info(currMhs).nim != nim_mhs){
                currMhs = nextMahasiswa(currMhs);
            }
            if (currMhs != nil && info(currMhs).nim == nim_mhs){
                    return info(currDosen).nama;
            }else{
                currDosen = nextDosen(currDosen);
            }
        }while(currDosen != nil);
    }

    cout << "Tidak ada mahasiswa dengan NIM " << nim_mhs << endl;

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
        Show_Dosen_Data(maxDosen);
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
    cout << "2. 1301218683 - Mazid Ahmad" << endl;
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

void Menu_Menampilkan_Dosen_X(mll list_dosen, int &input){
    string kodeDosen;
    adr_dosen searchedDosen;

    cout << "Masukkan Kode Dosen yang ingin dicari" << endl;
    cout << endl;
    cout << "Kode Dosen: "; cin >> kodeDosen; cout << endl;
    searchedDosen = Search_Dosen_By_Code(list_dosen, kodeDosen);

    if (searchedDosen != nil){
        Show_Dosen_Data(searchedDosen);
    }else{
        cout << "Dosen dengan kode dosen " << kodeDosen << " tidak Ditemukan" << endl;
    }
    cout << endl;

    Back_To_Menu(input);
}

void Menu_Cari_Dosen_X(mll list_dosen, int &input){
    string kodeDosen;
    adr_dosen searchedDosen;


    cout << "Masukkan Kode Dosen yang ingin dicari" << endl;
    cout << endl;
    cout << "Kode Dosen: "; cin >> kodeDosen; cout << endl;
    searchedDosen = Search_Dosen_By_Code(list_dosen, kodeDosen);

    if (searchedDosen != nil){
        cout << "Dosen dengan kode " << kodeDosen << " ditemukan." << endl;

        char decision;

        decision = 'l';
        while (decision != 'Y' && decision != 'y' && decision != 'N' && decision != 'n') {
            cout << "Tampilkan data dosen tersebut? " << " [Y/N] : "; cin >> decision;
            cout << endl;
        }
        if (decision == 'Y' || decision == 'y'){
            Show_Dosen_Data(searchedDosen);
        }
    }else{
        cout << "Dosen dengan kode dosen " << kodeDosen << " tidak Ditemukan" << endl;
    }
    cout << endl;

    Back_To_Menu(input);
}

void Menu_Hapus_Mahasiswa_Y_Dari_Dosen_X(mll &list_dosen, int &input){
    string kodeDosen;
    string nimMhs;
    adr_dosen searchedDosen;
    adr_mahasiswa searchedMahasiswa;

    cout << "Masukkan Kode Dosen yang ingin dicari" << endl;
    cout << endl;
    cout << "Kode Dosen: "; cin >> kodeDosen; cout << endl;
    searchedDosen = Search_Dosen_By_Code(list_dosen, kodeDosen);
    Show_Dosen_Data(searchedDosen);
    cout << endl;
    if (searchedDosen != nil){
        cout << "Masukkan NIM Mahasiswa yang ingin dihapus" << endl;
        cout << endl;
        cout << "NIM : "; cin >> nimMhs; cout << endl;
        searchedMahasiswa = Search_Mahasiswa_From_Dosen(searchedDosen, nimMhs);

        if (searchedMahasiswa != nil){
            Delete_Mahasiswa_Bimbingan_From_Dosen(list_dosen, searchedDosen, searchedMahasiswa);
            cout << "Mahasiswa dengan NIM " << nimMhs << " berhasil dihapus dari dosen." << endl;
            cout << endl;
            Show_Dosen_Data(searchedDosen);
        }else{
            cout << "Mahasiswa dengan NIM " << nimMhs << " tidak Ditemukan" << endl;
        }
    }else{
        cout << "Dosen dengan kode dosen " << kodeDosen << " tidak Ditemukan" << endl;
    }
    cout << endl;

    Back_To_Menu(input);
}

void Menu_Search_Mahasiswa_Y_Dari_Dosen_X(mll list_dosen, int &input){
    string kodeDosen;
    string nimMhs;
    adr_dosen searchedDosen;
    adr_mahasiswa searchedMahasiswa;

    cout << "Masukkan Kode Dosen yang ingin dicari" << endl;
    cout << endl;
    cout << "Kode Dosen: "; cin >> kodeDosen; cout << endl;
    searchedDosen = Search_Dosen_By_Code(list_dosen, kodeDosen);
    cout << endl;
    if (searchedDosen != nil){
        cout << "Masukkan NIM Mahasiswa yang dicari" << endl;
        cout << endl;
        cout << "NIM : "; cin >> nimMhs; cout << endl;
        searchedMahasiswa = Search_Mahasiswa_From_Dosen(searchedDosen, nimMhs);

        if (searchedMahasiswa != nil){
            Show_Mahasiswa_Data(searchedMahasiswa);
        }else{
            cout << "Mahasiswa dengan NIM " << nimMhs << " tidak Ditemukan" << endl;
        }
    }else{
        cout << "Dosen dengan kode dosen " << kodeDosen << " tidak Ditemukan" << endl;
    }
    cout << endl;

    Back_To_Menu(input);
}

void Menu_Cari_Dosen_Dari_Mahasiswa_X(mll list_dosen, int &input){
    string kodeDosen;
    string nimMhs;
    adr_dosen searchedDosen;
    adr_mahasiswa searchedMahasiswa;

    cout << "Masukkan NIM mahasiswa untuk mencari dosen pembimbingnya" << endl;
    cout << endl;
    cout << "NIM : "; cin >> nimMhs; cout << endl;

    string namaDosen = Search_Nama_Dospem_From_Mahasiswa(list_dosen, nimMhs);

    if (namaDosen != ""){
        cout << "Nama Dosen : " << namaDosen << endl;
    }

    cout << endl;

    Back_To_Menu(input);
}
