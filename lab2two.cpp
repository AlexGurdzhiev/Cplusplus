#include <iostream>

void print_segment(int a, int b) {
  std::cout << a << ' ';
  if (a != b) {
    print_segment(a + ((a > b) ? -1 : 1), b);
  }
}

int main() {
  int a, b;
  std::cout << "Введите A: ";
  std::cin >> a;
  std::cout << "Введите B: ";
  std::cin >> b;

  print_segment(a, b);
}
