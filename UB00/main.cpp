#include <iostream>
#include "fcpp.hh"

using namespace std;

void hello()
{
    printf("Hello World! I am using C++! \n");
}


bool is_zero(int zahl)
{
    return zahl == 0;
 }

int sum(int n)
{
    return cond(n == 0, 0, n + sum(n-1));
}


int main()
{
    hello();
    is_zero(1);

    int a = -10;
    int b = 0;
    cout<<cond(a==b, 0, cond(a>b, 1, -1))<<endl;
}


