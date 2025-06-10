#include <cstdint>
#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <array>

bool cmp(std::pair<uint32_t, uint32_t> &a, std::pair<uint32_t, uint32_t> &b) {
  if (a.second - a.first != b.second - b.first) {
    return a.second - a.first < b.second - b.first;
  }
  return a.first < b.first;
}

int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::pair<uint32_t, uint32_t>> sf(n);
  for (auto &seg : sf) {
    std::cin >> seg.first >> seg.second;
  }
  std::sort(sf.begin(), sf.end(), cmp);
  uint32_t count = 0;
  std::array<bool, 1441> used = {false};
  for (auto &seg : sf) {
    bool flag = true;
    for (uint32_t i = seg.first; i < seg.second; ++i) {
      if (used[i]) {
        flag = false; 
      }
    }

    if (flag) {
      for (uint32_t i = seg.first; i < seg.second; ++i) {
        used[i] = true;
      }
      ++count;
    }
  }
  std::cout << count;
}
