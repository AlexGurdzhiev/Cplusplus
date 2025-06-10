#include <cstdint>
#include <iostream>

uint32_t sum_of_digit(uint32_t n) {
  if (n == 0) {
    return 0;
  }
  return n % 10 + sum_of_digit(n / 10);
}

int main() {
  uint32_t n;
  std::cin >> n;
  std::cout << sum_of_digit(n);
}
