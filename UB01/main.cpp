#include "fcpp.hh"

// a)
bool ungerade(int x) {
    // ... implement me!
    //return ???;
}

// d)
int multisignal (int y, int z) {
    // ... implement me!
    //return ???;
}

// b) & c)
int quadrat (int x) {
    // ... implement me!
    //return ???;
}

// b) & d)
int exponentation(int b, int ex) {
    // ... implement me!
    //return ???;
}


int main(int argc, char* argv[]) {
    // mithilfe der Funktion enter_int aus fcpp.hh
    // können wir Werte für Basis und Exponent
    // über die Konsole einlesen und das
    // ganze sogar funktional verpacken!
    // Wichtig ist dann aber, dass du dieses Programm über eine Konsole ausführst!
    return print(
                exponentation(enter_int("Basis: "), enter_int("Exponent: "))
                );

    // Alternativ können wir auch die beiden Argumente Basis und Exponent
    // dem programm als Übergabeparameter (argv) übergeben und mit readarg_int einlesen.
    // return print(exponentation(readarg_int(argc,argv,1), readarg_int(argc,argv,2)));
}
