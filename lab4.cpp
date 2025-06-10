#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> table;
  while (true) {
    int x;
    std::cin >> x;
    if (x == 0) {
      break;
    }
    if (x > 0) {
      table.insert(x);
    } else {
      table.erase(-x);
    } 
  }

  for (auto &elem : table) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}
