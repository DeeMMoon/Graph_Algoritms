#include <climits>

#include "includes/s21_graph_algorithms.h"

namespace s21 {
int *GraphAlgorithms::breadthFirstSearch(Graph &matrix, int startVertex) {
  startVertex--;
  int **graph = matrix.getGraph();
  int size = matrix.getSize();
  Queue<int> queue;
  queue.queue();
  int visit_pos = 0;
  int j = 0;
  int i = 0;

  int *visited = new int[size];
  while (i < size) {
    visited[i] = -1;
    i++;
  }
  visited[visit_pos] = startVertex;
  visit_pos++;

  while (j < size) {
    if (graph[startVertex][j] != 0 && !isVisited(visited, size, j))
      queue.push(j);
    j++;
  }
  int visit;
  while (!queue.empty()) {
    j = 0;
    visit = queue.pop();
    if (!isVisited(visited, size, visit)) {
      visited[visit_pos] = visit;
      visit_pos++;
    }
    while (j < size) {
      if (graph[visit][j] != 0 && !isVisited(visited, size, j)) queue.push(j);
      j++;
    }
  }
  j = 0;
  while (visited[j] != -1 && j < size) j++;
  result_size = j;
  int *result = new int[j];
  for (int k = 0; k < j; k++) result[k] = visited[k] + 1;
  delete[] visited;
  return result;
}

int *GraphAlgorithms::depthFirstSearch(Graph &matrix, int startVertex) {
  startVertex--;
  int **graph = matrix.getGraph();
  int size = matrix.getSize();
  Stack<int> stack;
  stack.stack();
  int i = 0;
  int visit_pos = 0;
  int j = 0;
  int *visited = new int[size];
  while (i < size) {
    visited[i] = -1;
    i++;
  }
  visited[visit_pos] = startVertex;
  visit_pos++;
  while (j < size) {
    if (graph[startVertex][j] != 0 && !isVisited(visited, size, j))
      stack.push(j);
    j++;
  }
  int visit;
  while (!stack.empty()) {
    j = 0;
    visit = stack.pop();
    if (!isVisited(visited, size, visit)) {
      visited[visit_pos] = visit;
      visit_pos++;
    }
    while (j < size) {
      if (graph[visit][j] != 0 && !isVisited(visited, size, j)) stack.push(j);
      j++;
    }
  }
  j = 0;
  while (visited[j] != -1 && j < size) j++;
  result_size = j;
  int *result = new int[j];
  for (int k = 0; k < j; k++) result[k] = visited[k] + 1;
  delete[] visited;
  return result;
}

bool GraphAlgorithms::isVisited(int *visited, int size, int vertex) {
  int i = 0;
  while (i < size) {
    if (visited[i] == vertex) return true;
    i++;
  }
  return false;
}

int GraphAlgorithms::getShortestPathBetweenVertices(Graph &matrix, int vertex1,
                                                    int vertex2) {
  vertex1--;
  vertex2--;
  int **graph = matrix.getGraph();
  int size = matrix.getSize();
  int visited[size];
  int min_size[size];
  int tmp;
  int min;
  int min_index;
  for (int i = 0; i < size; i++) {
    visited[i] = 1;
    min_size[i] = INT_MAX;
  }
  min_size[vertex1] = 0;
  min_index = 0;
  while (min_index < INT_MAX) {
    min_index = INT_MAX;
    min = INT_MAX;
    for (int i = 0; i < size; i++) {
      if ((visited[i] == 1) && (min_size[i] < min)) {
        min = min_size[i];
        min_index = i;
      }
    }
    if (min_index != INT_MAX) {
      for (int i = 0; i < size; i++) {
        if (graph[min_index][i] > 0) {
          tmp = min + graph[min_index][i];
          if (tmp < min_size[i]) {
            min_size[i] = tmp;
          }
        }
      }
      visited[min_index] = 0;
    }
  }
  return min_size[vertex2];
}

int **GraphAlgorithms::getShortestPathsBetweenAllVertices(Graph &matrix) {
  int **graph = matrix.getGraph();
  int size = matrix.getSize();
  int **new_matrix;
  new_matrix = new int *[size];
  for (int i = 0; i < size; i++) {
    new_matrix[i] = new int[size];
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      new_matrix[i][j] = graph[i][j];
    }
  }
  if (!checkMatrix(new_matrix, size)) return nullptr;
  int max = getMatrixSum(new_matrix, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (new_matrix[i][j] == 0) new_matrix[i][j] = max;
    }
  }
  for (int k = 0; k < size; k++) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (new_matrix[i][j] >= new_matrix[i][k] + new_matrix[k][j])
          new_matrix[i][j] = new_matrix[i][k] + new_matrix[k][j];
      }
    }
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (new_matrix[i][j] == max || j == i) new_matrix[i][j] = 0;
    }
  }

  return (new_matrix);
}

long GraphAlgorithms::getMatrixSum(int **matrix, int size) {
  long value = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      value += matrix[i][j];
    }
  }
  return value;
}

bool GraphAlgorithms::checkMatrix(int **matrix, int size) {
  long value;
  value = getMatrixSum(matrix, size);
  if (value > INT_MAX) return false;
  return true;
}

std::vector<std::vector<int>> GraphAlgorithms::GetLeastSpanningTree(
    Graph &graph) {
  int count = graph.getSize();
  std::vector<bool> visited_vertex = std::vector<bool>(count);
  std::vector<int> path = std::vector<int>(count, -1);
  std::vector<int> min(count, INT_MAX);
  min[0] = 0;
  std::vector<std::vector<int>> tmp = std::vector<std::vector<int>>(count);
  std::vector<std::vector<int>> res(count, std::vector<int>(count));
  for (int i = 0; i < count; ++i) {
    for (int j = 0; j < count; ++j) {
      tmp[i].push_back(graph.getGraph()[i][j]);
      if (i != j && tmp[i][j] == 0) {
        tmp[i][j] = INT_MAX;
      }
    }
  }
  for (int i = 0; i < count; ++i) {
    int vert = -1;
    for (int j = 0; j < count; ++j) {
      if (!visited_vertex.at(j) && (vert == -1 || min[j] < min[vert])) {
        vert = j;
      }
    }
    if (min[vert] == INT_MAX) {
      std::cout << "Wrong graph";
      exit(0);
    }
    visited_vertex.at(vert) = true;
    if (path.at(vert) != -1) {
      res[path.at(vert)][vert] = tmp[path.at(vert)][vert];
      res[vert][path.at(vert)] = tmp[vert][path.at(vert)];
    }
    for (int k = 0; k < count; ++k) {
      if (tmp[vert][k] < min[k]) {
        min[k] = tmp[vert][k];
        path.at(k) = vert;
      }
    }
  }
  return res;
}

TsmResult GraphAlgorithms::solveTravelingSalesmanProblem(Graph &graph) {
  return Solve(graph);
}

void GraphAlgorithms::runGeneticAlgoritm(Graph &graph) {
  geneticAlgoritm(graph);
}
void GraphAlgorithms::runBFAlgoritm(Graph &graph) { BFAlgoritm(graph); }
}  // namespace s21
