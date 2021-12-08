#include "fcpp.hh"
#include <iostream>

using namespace std;


float zins(float z, int n)
{
    float x = 1 + (z/n);
    float z_eff = pow(x, n) - 1;
    return z_eff;
}

double zins(double z, int n)
{
    double x = 1 + (z/n);
    double z_eff = pow(x, n) - 1;
    return z_eff;
}

void info(int n)
{
    double z_double = 0.06;
    float z_float = 0.06;

    int Abrechnungsvorgaenge = n;

    float z_eff_float = zins(z_float,1);
    float z_eff_diff_float = exp(z_float) - 1 - z_eff_float;

    double z_eff_double = zins(z_double,1);
    double z_eff_diff_double = exp(z_double) - 1 - z_eff_double;

    print("----------------------------------");
    print(Abrechnungsvorgaenge);
    print(z_eff_float);
    print(z_eff_diff_float);
    print(z_eff_double);
    print(z_eff_diff_double);
}

int main()
{
    info(1);
    info(12);
    info(365);
    info(365*24);
    info(365*24*60);
    info(365*24*60*60);

    return 0;
}
