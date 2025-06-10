#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

int main() {
  std::unordered_map<char, std::string> graph;
  graph['H'] = "IGF";
  graph['I'] = "HJ";
  graph['F'] = "HG";
  graph['G'] = "FHJ";
  graph['J'] = "IGC";
  graph['E'] = "GAS";
  graph['A'] = "ES";
  graph['S'] = "AEDB";
  graph['D'] = "SB";
  graph['B'] = "SDC";
  graph['C'] = "BJ";
  
  char start = 'I', finish = 'S';

  std::unordered_map<char, int> distance;
  for (auto &u : graph) {
    distance[u.first] = -1;
  }
  distance[start] = 0;
  std::unordered_map<char, char> prev;

  prev[start] = '$';
  
  std::queue<char> q;
  q.push(start);

  while (!q.empty()) {
    char from = q.front();
    q.pop();
    for (auto &to : graph[from]) {
      if (distance[to] == -1) {
        q.push(to);
        distance[to] = distance[from] + 1; 
        prev[to] = from;
      }
    }
  }

  std::cout << distance[finish] << '\n';
  char current = finish;
  std::string path = {current};
  while (prev[current] != '$') {
    path.push_back(prev[current]);
    current = prev[current];
  }

  std::cout << path << '\n';
}
