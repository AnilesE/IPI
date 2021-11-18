#include "fcpp.hh"

// a)
bool ungerade(int x) {
    return cond(x % 2, 0, 1);
}

// d)
int multisignal (int y, int z) {
    printf("Weitere Multiplikation \n");
    return y * z;
}

// b) & c)
int quadrat (int x) {
    return cond(x<0, 0, cond(x==0, 1, pow(x,2)));
}

// b) & d)
int exponentation(int b, int ex) {
    return cond(ex==0,1,cond(ungerade(ex), multisignal(b, pow(b, ex-1)), multisignal(pow(b, ex/2), pow(b, ex/2))));
    //return cond(ex==0,1,cond(ungerade(ex), b * pow(b, ex-1), quadrat(pow(b, ex/2))));
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
