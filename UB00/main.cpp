#include <iostream>
#include "fcpp.hh"

using namespace std;

void hello()
{
    printf("Hello World! I am using C++! \n");
}


bool is_zero(int zahl)
{
    if (zahl == 0)
        return true;
    else
        return false;
}

int main()
{
    hello();

    int a = -10;
    int b = 0;
    cout<<cond(a==b, 0, cond(a>b, 1, -1))<<endl;
}


