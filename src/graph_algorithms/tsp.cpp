#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <random>
#include <vector>

#include "includes/s21_graph_algorithms.h"
namespace s21 {
static double **initPheromon(int size, double zero_value) {
  double **out;

  out = new double *[size];
  for (int i = 0; i < size; i++) {
    out[i] = new double[size];
    for (int j = 0; j < size; j++) {
      out[i][j] = zero_value;
    }
  }
  return out;
}

static void updateIntMatrix(int **matrix, int size, int value) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      matrix[i][j] = value;
    }
  }
}

static int **initTable(int size, double zero_value) {
  int **out;

  out = new int *[size];
  for (int i = 0; i < size; i++) {
    out[i] = new int[size];
    for (int j = 0; j < size; j++) {
      out[i][j] = zero_value;
    }
  }
  return out;
}

static void deleteTable(int size, int **matrix) {
  for (int i = 0; i < size; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

static void deletePheromon(int size, double **matrix) {
  for (int i = 0; i < size; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

static void evaporatePheromon(Graph &graph, Data &data,
                              std::vector<std::vector<int>> &routes,
                              std::vector<int> &startVertices,
                              int average_distance) {
  int **matrix = graph.getGraph();
  for (int i = 0; i < data.size; ++i) {
    for (int j = 0; j < data.size; ++j) {
      data.pheromon[i][j] = data.pheromon[i][j] * EVAPORATE;
    }
  }
  for (std::vector<int>::iterator it = startVertices.begin();
       it != startVertices.end(); it++) {
    for (int i = 0; i < data.size - 1; ++i) {
      data.pheromon[routes[*it][i]][routes[*it][i + 1]] +=
          average_distance / matrix[routes[*it][i]][routes[*it][i + 1]];
    }
    data.pheromon[routes[*it].back()][routes[*it][0]] +=
        average_distance / matrix[routes[*it].back()][routes[*it][0]];
  }
}

static int countDistance(Graph &graph, std::vector<int> &route) {
  int out = 0;
  int **matrix = graph.getGraph();

  for (std::size_t i = 0; i < route.size() - 1; ++i) {
    out += matrix[route[i]][route[i + 1]];
  }
  out += matrix[route.back()][route[0]];
  return out;
}

static std::vector<int> count_enabled_vertices(
    Graph &graph, Data &data, int dir, std::vector<int> &visited_vertices) {
  std::vector<int> enabled_vertives;
  int **matrix = graph.getGraph();

  for (int i = 0; i < data.size; ++i) {
    if (i == dir) continue;
    if (std::find(visited_vertices.begin(), visited_vertices.end(), i) !=
        visited_vertices.end())
      continue;
    if (matrix[dir][i] && data.died_route[dir][i])
      enabled_vertives.push_back(i);
  }

  return enabled_vertives;
}

static std::vector<double> count_probability(
    Graph &graph, Data &data, int dir, std::vector<int> &enabled_vertives) {
  std::vector<double> out;
  double sum_prob = 0;
  int **matrix = graph.getGraph();
  double first_var;
  double second_var;
  double var;

  for (std::size_t i = 0; i < enabled_vertives.size(); ++i) {
    first_var = std::pow(matrix[dir][enabled_vertives[i]], ALPHA);
    second_var = std::pow(data.pheromon[dir][enabled_vertives[i]], BETA);
    out.push_back(first_var * second_var);
  }
  for (std::size_t i = 0; i < out.size(); ++i) {
    sum_prob += out[i];
  }
  for (std::size_t i = 0; i < out.size(); ++i) {
    var = 0;
    for (std::size_t j = 0; j <= i; ++j) {
      var += out[j];
    }
    out[i] = var / sum_prob;
  }
  return out;
}

static int vertice_choice(double &random_double,
                          std::vector<int> &enabled_vertices,
                          std::vector<double> &probability) {
  for (std::size_t i = 0; i < enabled_vertices.size(); ++i) {
    if (random_double <= probability[i]) return enabled_vertices[i];
  }
  return enabled_vertices.back();
}

static int logic(int pos, Graph &graph, Data &data) {
  std::vector<int> enabled_vertices;
  std::vector<int> visited_vertices;
  std::vector<double> probability;
  int dir = pos;
  std::random_device rd;
  std::mt19937 e2(rd());
  std::uniform_real_distribution<> dist(0, 1);
  double random_double;

  updateIntMatrix(data.died_route, data.size, 1);
  while (visited_vertices.size() != static_cast<std::size_t>(data.size)) {
    if (visited_vertices.size() == static_cast<std::size_t>(data.size) - 1) {
      if (graph.getGraph()[dir][pos]) {
        visited_vertices.push_back(dir);
        continue;
      }
      data.died_route[visited_vertices.back()][dir] = 0;
      dir = visited_vertices.back();
      visited_vertices.pop_back();
      continue;
    }
    enabled_vertices =
        count_enabled_vertices(graph, data, dir, visited_vertices);
    if (enabled_vertices.size() == 0) {
      if (visited_vertices.size() == 0) return 1;
      data.died_route[visited_vertices.back()][dir] = 0;
      dir = visited_vertices.back();
      visited_vertices.pop_back();
      continue;
    }
    visited_vertices.push_back(dir);
    probability = count_probability(graph, data, dir, enabled_vertices);
    random_double = dist(e2);
    dir = vertice_choice(random_double, enabled_vertices, probability);
  }
  data.best_route = visited_vertices;
  return 0;
}

static int calcAverageDistance(int **matrix, int size) {
  int aver = 0;

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (i == j) continue;
      aver += matrix[i][j];
    }
  }
  return aver / (size * size - size);
}

TsmResult Solve(Graph &graph) {
  TsmResult out;
  Data data;
  std::vector<int> startVertices;
  int count_unreal = 0;
  int var_distance = 0;

  data.size = graph.getSize();
  if (data.size < 3) {
    out.distance = -1;
    return out;
  }
  data.pheromon = initPheromon(graph.getSize(), INIT_PHEROMON);
  data.died_route = initTable(data.size, 1);
  data.distance = INT_MAX;

  for (int i = 0; i < data.size; ++i) {
    startVertices.push_back(i);
  }
  int average_distance = calcAverageDistance(graph.getGraph(), data.size);
  std::vector<std::vector<int>> routes(data.size);
  for (int i = 0; i < ITERATION; ++i) {
    if (count_unreal == data.size) {
      out.vertices.clear();
      out.distance = -1;
      break;
    }
    for (std::vector<int>::iterator it = startVertices.begin();
         it != startVertices.end();) {
      if (logic(*it, graph, data)) {
        it = startVertices.erase(it);
        ++count_unreal;
      } else {
        if ((var_distance = countDistance(graph, data.best_route)) <
            data.distance) {
          data.distance = var_distance;
          out.distance = data.distance;
          out.vertices = data.best_route;
        }
        routes[*it] = data.best_route;
        ++it;
      }
    }
    evaporatePheromon(graph, data, routes, startVertices, average_distance);
  }

  deletePheromon(graph.getSize(), data.pheromon);
  deleteTable(graph.getSize(), data.died_route);
  return out;
}

}  // namespace s21
