
// funktionale Programmierung: Header #include "fcpp.hh"
#include "fcpp.hh"

bool ungerade(int zahl){
    int rest = zahl % 2;
    if (rest == 0)
        // kein Rest -> durch 2 teilbar
        return false;
    else
        return true;
}

// als erste aufgerufene Funktion: main
int main()
{
    return ungerade(2);
}




