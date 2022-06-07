#include <iostream>
#include "mll.h"

using namespace std;

int main()
{
    // temp logic,
    mll list_dosen;
    Create_List(list_dosen);
    adr_dosen adrDosen;

    //make sure procedure Insert_Last_Dosen
    New_Elm_Dosen({"11111", "Ida"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);
    New_Elm_Dosen({"22222", "Ardi"}, adrDosen);
    Insert_Last_Dosen(list_dosen, adrDosen);

    return 0;
}
