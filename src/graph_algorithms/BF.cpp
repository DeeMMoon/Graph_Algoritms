#include "./includes/BF.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#include "includes/s21_graph_algorithms.h"

namespace s21 {

int calculate_path_length(const std::vector<std::vector<int>> &adjacency_matrix,
                          const std::vector<int> &path) {
  int length = 0;
  for (size_t i = 0; i < path.size() - 1; ++i) {
    length += adjacency_matrix[path[i]][path[i + 1]];
  }
  length += adjacency_matrix[path.back()][path.front()];
  return length;
}

void BFAlgoritm(Graph &graph) {
  int n = graph.getSize();
  std::vector<std::vector<int>> adjacency_matrix(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      adjacency_matrix[i][j] = graph.getGraph()[i][j];
    }
  }

  std::vector<int> path(n);
  for (int i = 0; i < n; ++i) {
    path[i] = i;
  }

  int min_path_length = std::numeric_limits<int>::max();
  std::vector<int> optimal_path;

  do {
    int current_path_length = calculate_path_length(adjacency_matrix, path);
    if (current_path_length < min_path_length) {
      min_path_length = current_path_length;
      optimal_path = path;
    }
  } while (std::next_permutation(path.begin() + 1, path.end()));

  // std::cout << "Shortest distance:: " << min_path_length << std::endl;
}
}  // namespace s21
