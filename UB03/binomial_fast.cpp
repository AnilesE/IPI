#include "fcpp.hh"
#include <iostream>

using namespace std;


int mult_intervall(int a, int b)
{
    return(cond(0<a && a<=b,
                cond(a!=b,
                     a * mult_intervall(a+1,b),
                     b),
                0));
}

int binomial(int n, int k)
{
    return(cond(0<=k && k<=n,
                mult_intervall(1,n)/(mult_intervall(1,k)*mult_intervall(1,n-k)),
                0)
           );
}

int main()
{
    return print(
                binomial(enter_int("n: "), enter_int("k: "))
                );
}
