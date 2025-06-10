#include <iostream>

void print_numbers(int n) {
  if (n == 0) {
    return;
  }

  print_numbers(n - 1);
  std::cout << n << ' ';
}

int main() {
  int n;
  std::cout << "Введите n: ";
  std::cin >> n;
  print_numbers(n);  
}
