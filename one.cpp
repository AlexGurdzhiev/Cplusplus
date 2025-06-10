#include <iostream>
#include <vector>
#include <random>

int main() {
  std::random_device rd;
  std::mt19937 generator(rd());
  const size_t MAX_N = 20, MINIMUM = 2, MAXIMUM = 103;

  std::vector<int> numbers(generator() % MAX_N);
  for (auto &elem : numbers) {
    elem = MINIMUM + generator() % (MAXIMUM - MINIMUM);
  }

  for (auto &elem : numbers) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  for (size_t i = 0; i < numbers.size(); ++i) {
    for (size_t j = i + 1; j < numbers.size(); ++j) {
      if (numbers[i] > numbers[j]) {
        std::swap(numbers[i], numbers[j]);
      }
    }
  }

  for (auto &elem : numbers) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}
