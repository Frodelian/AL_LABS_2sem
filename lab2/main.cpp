#include <fstream>

#include "vector.h"

void foo(std::ofstream &file, Vector vec) {}

Vector bar() { return Vector(10); }

int main() {
  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");
  int n;
  fin >> n;

  double *lhs = new double[n];
  for (int i = 0; i < n; ++i) {
    fin >> lhs[i];
  }

  Vector rhs;
  fin >> rhs;

  Vector res = lhs + rhs;
  fout << res << "\n";

  Vector res2 = Vector(10);
  res2 = std::move(res);

  delete[] lhs;
}
