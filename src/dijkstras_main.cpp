#include "dijkstras.h"
int main() {
  Graph g;
  file_to_graph("./small.txt", g);
  vector<int> previous;
  vector<int> result = dijkstra_shortest_path(g, 0, previous);
  for (int i = 0;i < result.size(); ++ i){
  vector<int> path = extract_shortest_path(result, previous, i);
  print_path(path, result[i]);
}
return 1;
}