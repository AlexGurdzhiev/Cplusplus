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
  int n;
  std::cin >> n;
  std::vector<int> cost(n);
  for (auto &elem : cost) {
    std::cin >> elem;
  }
  std::vector<std::vector<int>> graph(n, std::vector<int> (n));
  int m;
  std::cin >> m;
  while (m--) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    graph[u][v] = cost[u];
    graph[v][u] = cost[v];
  }
  std::cout << djikstra(graph, n, 0, n - 1);
}
