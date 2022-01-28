#include "fcpp.hh"
#include <string>

// Fixe Größe der Matrizen
const short SIZE = 3;

// Datentyp für Matrizen dieser Größe
struct matrix {
  int vals[SIZE][SIZE];
};

// a)
matrix matrix_zero() {
    matrix m;
    for (int i = 0; i < 3; i = i + 1){
        for (int j = 0; j < 3; j = j + 1){
            m.vals[i][j] = 0;
        }
    }
    return m;
}

matrix matrix_id() {
    matrix m;
    for (int i = 0; i < 3; i = i + 1){
        for (int j = 0; j < 3; j = j + 1){
            if (i == j) m.vals[i][j] = 0;
            else m.vals[i][j] = 0;
        }
    }
    return m;
}

// b)
matrix matrix_add(matrix left, matrix right) {
    matrix m;
    for (int i = 0; i < 3; i = i + 1){
        for (int j = 0; j < 3; j = j + 1){
            m.vals[i][j] = left.vals[i][j] + right.vals[i][j];
        }
    }
    return m;
}


// Konstruktion eines mehrzeiligen Strings, der die Einträge einer Matrix darstellt
std::string to_string(matrix m) {
  std::string str = "";
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      str += std::to_string(m.vals[i][j]) + "  ";
    }
    str += "\n";
  }
  return str;
}

// d)
int main(int argc, char *argv[]) {
  // Initialisiere Matrizen
  matrix A = {
    {
      {2, 5, 4},
      {3, 2, 4},
      {1, 1, 9}
    }
  };
  matrix B = {
    {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    }
  };

  to_string(matrix_zero());
  return 1;
}
