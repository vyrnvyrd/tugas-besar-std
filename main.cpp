#include <iostream>
#include "mll.h"

using namespace std;

int main()
{
    // temp logic,
    mll list_dosen;
    Create_List(list_dosen);
    adr_dosen adrDosen, dataDelete;

    //make sure procedure Insert_Last_Dosen
    New_Elm_Dosen({"11111", "Ida", "ID", "Dasar-Dasar Pemograman"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"22222", "Ardi", "ARD", "Algoritma Pemrograman"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"33333", "Bima", "BM", "Kalkulus"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"44444", "Cintya", "CN", "Bhs Inggris"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);

//    Show_All_Dosen(list_dosen);
//    dataDelete = Delete_DosenX(list_dosen, "BM");
//    Show_All_Dosen(list_dosen);
//    cout << "data yang didelete: " << info(dataDelete).nama << endl;

//    showDosenData(list_dosen,"ARD");


    return 0;
}
