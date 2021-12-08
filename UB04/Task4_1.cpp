#include "fcpp.hh"
#include <iostream>

using namespace std;

float determinante_float(float a, float b, float c, float d)
{
    return(a*d-c*b);
}

double determinante_double(double a, double b, double c, double d)
{
    return(a*d-c*b);
}

float addition1(float a , float b, float c)
{
    return (a + b) + c;
}

float addition2(float a, float b, float c)
{
    return a + (b + c);
}

void ad(int b, int n)
{
    printf("-------");
    print(b);

    while (n>=0)
    {
      printf("---");
      print(n);

      float ad_version1 = addition1(pow(b,n), pow(-b,n), pow(b,-n));
      float ad_version2 = addition2(pow(b,n), pow(-b,n), pow(b,-n));

      print(ad_version1);
      print(ad_version2);
      print(ad_version1 == ad_version2);
      n=n-1;
    }
}




int main()
{
    print("-----------------------------task1a");
    print("Matrix A:");
    print(determinante_float(100,0.01,-0.01,100));
    print(determinante_double(100,0.01,-0.01,100));

    print("Matrix B:");
    print(determinante_float(1,1,0.9,1.9));
    print(determinante_double(1,1,0.9,1.9));
    print("-----------------------------task1b");
    ad(10,14);
    ad(2,14);
    return 0;
}
