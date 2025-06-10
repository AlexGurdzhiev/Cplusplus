#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <regex>

bool is_correct_phone_number(std::string &str) {
  std::regex reg(R"(\d{2}-\d{2}-\d{2})");
  return std::regex_match(str, reg);
}

int main() {
  size_t count;
  std::cout << "Кол-во номеров: ";
  std::cin >> count;
  std::vector<std::string> phones(count);
  for (auto &elem : phones) {
    std::cout << "Введите номер телефона в форматике XX-XX-XX: ";
    std::cin >> elem;
    if (!is_correct_phone_number(elem)) {
      std::cerr << "Некорректный номер телефона.\n";
      exit(-1);
    }    
  }
  
  for (size_t i = 0; i < count; ++i) {
    for (size_t j = i + 1; j < count; ++j) {
      if (phones[i] > phones[j]) {
        std::swap(phones[i], phones[j]);
      }
    }   
  }

  for (auto &elem : phones) {
    std::cout << elem << '\n';
  }
}
