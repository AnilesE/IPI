#include "fcpp.hh"
// Group: Valeriia Dragan, Ben Ishaia, Selina Ernst

// a)

int binomial(int n, int k){
    return cond(k == 0 || k == n, 1, cond(k > 0 & k < n, binomial(n - 1, k - 1) + binomial(n - 1, k), 0));
}

// b)

int mult_intervall(int a, int b){
    return cond(a <= 0 & a > b, 0, cond(b < a, 1, b* mult_intervall(a, b-1)));
}
/*int binomial_fast(int n, int k){
 * return binomial + milti_intervall
}*/

int main() {
    print(binomial(8,5));
    print(mult_intervall(3, 5));
    return 0;
}
