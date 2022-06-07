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
    string nik, nama;
};
struct elm_dosen {
    dosen info;
    adr_mahasiswa nextMahasiswa;
    adr_dosen nextDosen;
};

struct mll {
    adr_dosen first;
};

#endif // MLL_H_INCLUDED
