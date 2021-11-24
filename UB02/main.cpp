#include "fcpp.hh"
#include <iostream>

using namespace std;


// (a)
bool teiler (int teiler, int zahl) {
   return(cond(zahl % teiler == 0,
               1,
               0)
          );
}

// (b)
int teileranzahl (int index, int anzahl, int zahl) {

  return(cond( index == zahl,
               anzahl,
               cond(teiler(index, zahl) == 0,
                    teileranzahl(index+1, anzahl, zahl),
                    teileranzahl(index+1, anzahl+1,zahl))
               ));
}

// (c)
int teilersumme (int index, int summe, int zahl) {
    return(cond( index == zahl,
                 summe,
                 cond(teiler(index, zahl) == 0,
                      teilersumme(index+1, summe, zahl),
                      teilersumme(index+1, summe+index, zahl))
                 )
           );
}

// (d)
bool vollkommen (int zahl) {
  return(cond(teilersumme(1, 0, zahl)==zahl,
              1,
              0)
         );
}

// (e)
int suchevollkommen (int zahl) {
  return(cond(vollkommen(zahl) == 1,
              zahl,
              suchevollkommen(zahl+1))
         );
}

// (f)
int main(int argc, char *argv[]) {
  print("Die beiden nächstgrößeren vollkommenen Zahlen nach 28:");
  int zahl1 = suchevollkommen(28+1);
  int zahl2 = suchevollkommen(zahl1+1);
  print(zahl1);
  print(zahl2);
  return(0);
}
