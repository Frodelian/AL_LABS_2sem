#include <algorithm>
#include <deque>
#include <fstream>
#include <vector>

#include "student.h"

int main() {
  std::vector<Student> studs;
  std::ifstream fin("input.txt");
  int N;
  fin >> N;
  for (int i = 0; i < N; ++i) {
    std::string name;
    std::string group;
    int num;
    int marks[4];
    fin >> name >> group >> num;
    for (int j = 0; j < 4; ++j) {
      fin >> marks[j];
    }
    studs.emplace_back(name, group, num, marks);
  }
  fin.close();
  std::deque<Student> deque(N);
  std::sort(studs.begin(), studs.end());
  std::copy(studs.begin(), studs.end(), deque.begin());
  // auto dest = deque.begin();
  // for (auto it = studs.begin; it != studs.end(); ++it) {
  //   (*dest) = *it;
  //    ++dest;
  // }
  std::ofstream fout("output.txt");
  for (int i = 0; i < N; ++i) {
    fout << deque[i] << "\n";
  }
  fout.close();
}
