#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>

#define info(P) (P)->info
#define nextDosen(P) (P)->nextDosen
#define nextMahasiswa(Q) (Q)->nextMahasiswa
#define first(L) (L).first
#define nil NULL

using namespace std;

typedef struct elm_mahasiswa *adr_mahasiswa;
struct mahasiswa {
    string nim, nama, judulTugasAkhir;
};
struct elm_mahasiswa {
    mahasiswa info;
    adr_mahasiswa nextMahasiswa;
};

typedef struct elm_dosen *adr_dosen;
struct dosen {
    string nik, nama, kode_dosen, matkul;
};
struct elm_dosen {
    dosen info;
    adr_mahasiswa nextMahasiswa;
    adr_dosen nextDosen;
};

struct mll {
    adr_dosen first;
};

void Create_List(mll &list_dosen);
void New_Elm_Dosen(dosen dataDosen, adr_dosen &adrDosen);
void Insert_Last_Dosen(mll &list_dosen, adr_dosen adrDosen);
adr_dosen Delete_First_Dosen(mll &list_dosen);
adr_dosen Delete_Last_Dosen(mll &list_dosen);
adr_dosen Delete_After_Dosen(mll &list_dosen, adr_dosen prev, adr_dosen curr);
void Show_Dosen_Data(adr_dosen dosen);
adr_dosen Delete_DosenX(mll &list_dosen, adr_dosen adrDosen);
void Show_All_Dosen(mll list_dosen);
adr_dosen Search_Dosen_By_Code(mll list_dosen, string kode_dosen);
bool Is_List_Dosen_Empty(mll list_dosen, string kode_dosen);
void Show_Mahasiswa_From_Dosen(adr_dosen adrDosen);
void New_Elm_Mahasiswa(mahasiswa dataMahasiswa, adr_mahasiswa &adrMahasiswa);
void Insert_New_Mahasiswa(mll &list_dosen, adr_dosen adrDosen, adr_mahasiswa adrMahasiswa);
int Count_Mahasiswa_From_Dosen(adr_dosen adrDosen);
adr_mahasiswa Search_Mahasiswa_From_Dosen(adr_dosen dosen, string nim_mhs);
void Delete_Relation_Dosen_and_Mahasiswa(mll &list_dosen, adr_dosen adrDosen, adr_mahasiswa adrMahasiswa);
void Delete_Mahasiswa_Bimbingan_From_Dosen(mll &list_dosen, adr_dosen adrDosen, adr_mahasiswa adrMahasiswa);
void Show_Largest_Mahasiswa(mll list_dosen);
string Search_Nama_Dospem_From_Mahasiswa(mll list_dosen, string nim_mhs);
void Show_Mahasiswa_Data(adr_mahasiswa mahasiswa);

// menu
void Back_To_Menu(int &input);
void Menu_Exit();
void Menu_Tambah_Dosen(mll &list_dosen, int &input);
void Menu_Hapus_Dosen(mll &list_dosen, int &input);
void Menu_Tambah_Mahasiswa_Ke_Dosen(mll &list_dosen, int &input);
void Menu_Tampilkan_Mahasiswa_Dari_Dosen(mll &list_dosen, int &input);
void Menu_Mahasiswa_Terbanyak(mll &list_dosen, int &input);
void Menu_Menampilkan_Dosen_X(mll list_dosen, int &input);
void Menu_Cari_Dosen_X(mll list_dosen, int &input);
void Menu_Hapus_Mahasiswa_Y_Dari_Dosen_X(mll &list_dosen, int &input);
void Menu_Search_Mahasiswa_Y_Dari_Dosen_X(mll list_dosen, int &input);
void Menu_Cari_Dosen_Dari_Mahasiswa_X(mll list_dosen, int &input);


#endif // MLL_H_INCLUDED
