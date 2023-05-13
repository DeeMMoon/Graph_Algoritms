
#ifndef GRAPH_S21_GRAPH_ALGORITHMS_H
#define GRAPH_S21_GRAPH_ALGORITHMS_H

#include <iostream>
#include <vector>

#include "../../containers/queue/queue.h"
#include "../../containers/stack/stack.h"
#include "../../graph/includes/s21_graph.h"
#include "BF.h"
#include "Genetic.h"
#include "navi.h"

namespace s21 {

class GraphAlgorithms {
 public:
  int result_size;
  int *depthFirstSearch(Graph &graph, int startVertex);
  int *breadthFirstSearch(Graph &graph, int startVertex);
  int getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
  int **getShortestPathsBetweenAllVertices(Graph &graph);
  std::vector<std::vector<int>> GetLeastSpanningTree(Graph &graph);
  TsmResult solveTravelingSalesmanProblem(Graph &graph);
  void runGeneticAlgoritm(Graph &graph);
  void runBFAlgoritm(Graph &graph);

 private:
  bool isVisited(int *visited, int size, int vertex);
  bool checkMatrix(int **matrix, int size);
  long getMatrixSum(int **matrix, int size);
};

}  // namespace s21

#endif
