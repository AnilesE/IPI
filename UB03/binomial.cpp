#include "fcpp.hh"
#include <iostream>

using namespace std;

int binomial(int n, int k)
{
    return (cond(
                0<=k && k<=n,
                cond(0<k && k<n,
                     binomial(n-1,k-1) + binomial(n-1,k),
                     1),
                0)
            );
}

int main()
{
    return print(
                binomial(enter_int("n: "), enter_int("k: "))
                );
}
