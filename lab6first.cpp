#include <cstdint>
#include <iostream>
#include <vector>

int djikstra(std::vector<std::vector<int>> &graph, int n, int start, int finish) {
  std::vector<int> distance(n, INT32_MAX);
  distance[start] = 0;

  std::vector<bool> used(n, false);

  for (int i = 0; i < n; ++i) {
    int from = -1;
    for (int v = 0; v < n; ++v) {
      if (!used[v] && (from == -1 || distance[v] < distance[from])) {
        from = v;
      }
    }
  
    std::cerr << from << '\n';

    used[from] = true;
    for (int to = 0; to < n; ++to) {
      if (graph[from][to] != -1 && (distance[from] + graph[from][to] < distance[to])) {
        distance[to] = distance[from] + graph[from][to];
      }
    }
  }

  return distance[finish];
}

int main() {
  int n, s, f;
  std::cin >> n >> s >> f;
  std::vector<std::vector<int>> graph(n, std::vector<int> (n));
  
  for (auto &i : graph) {
    for (auto &j : i) {
      std::cin >> j;
    }
  }
  
  --s;
  --f;

  std::cout << djikstra(graph, n, s, f);
}
