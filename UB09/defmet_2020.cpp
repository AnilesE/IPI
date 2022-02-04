// Programm zu Aufgabe Objektverhalten in C++
// Volker Reichenberger, Sommersemester 2001

/* @VERBON */

#include "fcpp.hh"

class Zahl
{
public:
  Zahl();                // Null-Konstruktor
  Zahl( const int& n );  // Wert-Konstruktor
  Zahl( const Zahl& n ); // Copy-Konstruktor
  ~Zahl();               // Destruktor
  // Wert-Zuweisung
  Zahl& operator=( const int& n );
  // Objekt-Zuweisung
  Zahl& operator=( const Zahl& n );
  // Addition
  Zahl operator+( const Zahl& n );
private:
  int z;
};

Zahl::Zahl() {
    print("Null-Konstruktor");
    z = 0;
}
Zahl::Zahl( const int& n )  {
    print("Wert-Konstruktor");
    z = n;
}
Zahl::Zahl( const Zahl& n ) {
    print("Copy-Konstruktor");
    z = n.z;
}
Zahl::~Zahl() {
    print("Destruktor");
}
Zahl& Zahl::operator=( const int& n )
{ z=n;   return *this; }
Zahl& Zahl::operator=( const Zahl& n )
{ z=n.z; return *this; }
Zahl Zahl::operator+( const Zahl& n ) {
    print("Addition");
    return Zahl(z+n.z);
}

Zahl f( Zahl a, Zahl& b) { return a+b; }

/*
int main()
{
  Zahl a(3), b(4);
  Zahl c(a), d, e;
  d = 5;
  d = f(d,c);
  e = d + a + b;
  return 0;
}
*/
int main(){
    Zahl a(3), b(4);
    Zahl c = a+b;
    return 0;
}

/* @VERBOFF */
