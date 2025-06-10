#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

int order(std::vector<std::vector<int>> &a, int l, int r) {
  // распределяем элементы, меньшие влево, большие вправо.
  int i = l - 1;

  while (l < r) {
    if (a[l][0] <= a[r][0]) {
      ++i;
      std::swap(a[i][0], a[l][0]);
    }
    ++l;
  }

  std::swap(a[i + 1][0], a[r][0]);
  return i + 1;
}

void quick_sort(std::vector<std::vector<int>> &a, int l, int r) {
  if (l < r) {
    int i = order(a, l, r);
    quick_sort(a, l, i - 1);
    quick_sort(a, i + 1, r);
  }
}

int main() {
  const int MAX_SZ = 10, MIN = 5, MAX = 61;
  std::random_device rd;
  std::mt19937 generator(rd());

  std::vector<std::vector<int>> a(generator() % MAX_SZ + 1, std::vector<int> (generator() % MAX_SZ + 1));
  for (auto &row : a) {
    for (auto &elem : row) {
      elem = MIN + generator() % (MAX - MIN);
      std::cout << elem << ' ';
    }
    std::cout << '\n';
  }

  std::cout << '\n';
  quick_sort(a, 0, a.size() - 1);

  for (auto &row : a) {
    for (auto &elem : row) {
      std::cout << elem << ' ';
    }
    std::cout << '\n';
  }  

}
