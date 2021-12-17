// Group: Valeriia Dragan, Ben Ishaia, Selina Ernst
#include <iostream>
using namespace std;
#include "fcpp.hh"

const int ggroesse = 10;  // globale Variable ggroesse
int gfeld[ggroesse];    // globale Variable feld vom Typ Feld enthält die Liste

void feld_ausgeben   (int anzahl)
{  // Gibt gfeld[0] bis gfeld[anzahl-1] in einer Zeile aus
    std::cout << "Die Liste im Feld gfeld sieht wie folgt aus: ";
    for ( int i = 1; i <= anzahl; i = i+1 )
           std::cout << gfeld[i-1] << " ";
    std::cout << std::endl;
}

void feld_bubblesort ( int anzahl )
{
    int temp;
    for(int i = 0; i < anzahl - 1; i++){    //gehe durch das Feld
        if(gfeld[i]>gfeld[i+1]){    //vergleiche die benachbarten Werte miteinander an Positionen i & i+1
            temp = gfeld[i];    //tausche die Werte an Positionen i & i+1, wobei Wert aus Position i in einer temporären Variable gespeichert wird
            gfeld[i] = gfeld[i+1];
            gfeld[i+1] = temp;
            }
        }
    }

void feld_insertionsort ( int anzahl )
{
    int k, i, j;
    for (k = 1; k < anzahl; k++)    //gehe durch das Feld
    {
        i = gfeld[k];
        j = k - 1;
        while (j >= 0 && gfeld[j] > i)  //füge den neuen elemnt in die sortierte Folge ein
        {
            gfeld[j + 1] = gfeld[j];
            j = j - 1;
        }
        gfeld[j + 1] = i;   //wähle das nächste neue Element, das noch nicht sortiert wurde
    }
}

int main( int argc, char *argv[] ){
    int anzahl = argc-1;
    // anzahl ist Anzahl der eingegebenen Listenelemente
    if ( anzahl <= ggroesse ){
         for ( int i = 1; i <= anzahl; i = i+1 ) // trage die Liste in gfeld ein
            gfeld[i-1] = readarg_int( argc, argv, i );
         feld_bubblesort( anzahl );
         feld_insertionsort( anzahl );
         feld_ausgeben( anzahl );
    }
    else  std::cout << "Bitte nicht mehr als " << ggroesse << " Werte." <<  std::endl;
}



