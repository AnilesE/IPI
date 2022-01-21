#include "fcpp.hh"

const short SIZE = 5;

typedef struct vector {
    float vals[SIZE];
} vector;

void vector_copy(vector* v, vector* target) {
    for(int i = 0; i < SIZE; i++) {
        target->vals[i] = v->vals[i];
    }
    return;
}

// 7.2 b
float buffered_vector_product(const char buffer[]) {
    // implement me...
    float sum = 0;
    vector* x = (vector*) buffer;

    for(int i = 0; i < SIZE; i++) {
        float m = x -> vals[i] ;
        float n = x -> vals[i + SIZE];
        float produkt = m * n;
        sum = sum + produkt;
    }

    return sum;
}

int main() {
    char buffer[sizeof(vector) + SIZE]; // 7.2 b: Berechne genauere Buffergröße.
    vector A = {{1,1.5,2,2.5,3}};
    vector B = {{0.5,-1,1.5,-2,2.5}};

    vector_copy(&A, (vector*) buffer);
    vector_copy(&B, (vector*) (buffer + sizeof(vector)));

    // 7.2 b
    print(buffered_vector_product(buffer));

    return 0;
}
