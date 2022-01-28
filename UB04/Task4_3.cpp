#include "fcpp.hh"
#include <iostream>

using namespace std;

bool prim(int zahl)
{
    double wurzel = pow(zahl,0.5);
    bool is_prim = true;

    for (int i=2; i<=floor(wurzel); i=i+1)
    {
        if (zahl%i == 0)
        {
            is_prim = false;
            break;
        }
    }

    return is_prim;
}

int prim_anzahl_while(int untere, int obere)
{
    int zahl = untere;
    int anzahl = 0;
    while (zahl <= obere)
    {
        if (prim(zahl) == 1) anzahl = anzahl + 1;
        zahl = zahl + 1;
    }
    return anzahl;
}

int prim_anzahl_for(int untere, int obere)
{
    int anzahl = 0;
    for (int i = untere; i <= obere; i = i + 1)
    {
        if (prim(i)==1) anzahl = anzahl + 1;
    }
    return anzahl;
}

int prim_anzahl_goto(int untere, int obere)
{
    int zahl = untere;
    int anzahl = 0;
    set_anzahl_if_prim: if (prim(zahl) == 1) anzahl = anzahl + 1;
    zahl = zahl + 1;
    if (zahl <= obere) goto set_anzahl_if_prim;
    return anzahl;
}

int main()
{
    print(prim(4));
    print(prim_anzahl_while(1,9));
    print(prim_anzahl_for(1,9));
    print(prim_anzahl_goto(1,9));
    return 0;
}
