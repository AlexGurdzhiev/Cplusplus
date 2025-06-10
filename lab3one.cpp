#include <cstddef>
#include <iostream>
#include <array>

#ifdef DEBUG
const size_t N = 5;
#else
const size_t N = 1000;
#endif

int order(std::array<int, N> &a, int l, int r) {
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

void quick_sort(std::array<int, N> &a, int l, int r) {
  if (l < r) {
    int i = order(a, l, r);
    quick_sort(a, l, i - 1);
    quick_sort(a, i + 1, r);
  }
}

int main() {
  std::array<int, N> a;
  for (auto &elem : a) {
    std::cin >> elem;
  }

  quick_sort(a, 0, N - 1); 
  
  for (auto &elem : a) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}
