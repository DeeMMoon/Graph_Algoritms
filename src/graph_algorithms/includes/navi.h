#ifndef NAVI_H
#define NAVI_H

#include <vector>

#include "../../graph/includes/s21_graph.h"

namespace s21 {

#define INIT_PHEROMON 0.5
#define ALPHA 1
#define BETA 1
#define ITERATION 300
#define EVAPORATE 0.8

struct TsmResult {
  std::vector<int> vertices;
  double distance;
};

struct Data {
  double **pheromon;
  int size;
  int distance;
  std::vector<int> best_route;
  int **died_route;
};

struct verticePair {
  int first_num;
  int second_num;
  int *first;
  int *second;
};

TsmResult Solve(Graph &graph);

}  // namespace s21

#endif  // !NABI_H
