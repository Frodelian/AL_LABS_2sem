#include <algorithm>
#include <deque>
#include <fstream>
#include <set>
#include <unordered_set>
#include <vector>

#include "student.h"

int main() {
  std::vector<Student> studs;
  std::ifstream fin("input.txt");
  int N;
  fin >> N;
  for (int i = 0; i < N; ++i) {
    std::string name, group;
    int num;
    int marks[4];
    fin >> name >> group >> num;
    for (int j = 0; j < 4; ++j) {
      fin >> marks[j];
    }
    studs.emplace_back(name, group, num, marks);
  }
  fin.close();
  std::set<Student> set;
  for (int i = 0; i < N; ++i) {
    set.insert(studs[i]);
  }
  std::ofstream fout("output.txt");  // ост
  for (auto &i : set) {
    fout << i << std::endl;
  }
  // std::unordered_set<Student> uset;
  // for (int i = 0; i < N; ++i) {
  //   uset.insert(studs[i]);
  // }
  // std::cout << (uset.find(studs[0]) != uset.end()) << "\n";
  // for (auto &i : uset) {
  //   fout << i << std::endl;
  // }
  fout.close();
}