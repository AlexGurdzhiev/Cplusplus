#include <cstdint>
#include <iostream>

void print_prime_divs(uint32_t n, uint32_t div, bool print_current_div) {
  if (n == 1) {
    return;
  } 
  if (div * div > n) {
    std::cout << n << ' ';
    return;
  }

  if (n % div == 0) {
    if (print_current_div) {
      std::cout << div << ' ';
    }
    n /= div;
    print_prime_divs(n, div, false);
  } else {
    print_prime_divs(n, div + 1, true);
  }
}
  

int main() {
  uint32_t n;
  std::cout << "Введите n: ";
  std::cin >> n;
  print_prime_divs(n, 2, true);
}
