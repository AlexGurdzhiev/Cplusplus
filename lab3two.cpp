#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

int order(std::vector<int> &a, int l, int r) {
  // распределяем элементы, меньшие влево, большие вправо.
  int i = l - 1;

  while (l < r) {
    if (a[l] <= a[r]) {
      ++i;
      std::swap(a[i], a[l]);
    }
    ++l;
  }

  std::swap(a[i + 1], a[r]);
  return i + 1;
}

void quick_sort(std::vector<int> &a, int l, int r) {
  if (l < r) {
    int i = order(a, l, r);
    quick_sort(a, l, i - 1);
    quick_sort(a, i + 1, r);
  }
}

int main() {
  const int MAX_SZ = 100, MIN = 50, MAX = 100;
  std::random_device rd;
  std::mt19937 generator(rd());
  std::vector<int> a(generator() % MAX_SZ + 1);
  for (auto &elem : a) {
    elem = MIN + generator() % (MAX - MIN);
  }
  for (auto &elem : a) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  quick_sort(a, 0, a.size() - 1);
  for (auto &elem : a) {
    std::cout << elem << ' ';
  }
}
