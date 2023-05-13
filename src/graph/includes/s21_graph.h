#ifndef NAVI_SRC_GRAPH_S21_GRAPH_H_
#define NAVI_SRC_GRAPH_S21_GRAPH_H_

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "../../containers/queue/queue.h"

namespace s21 {
class Graph {
 private:
  int **graph;
  int size;

 public:
  Graph();
  ~Graph();
  explicit Graph(std::string fileName);
  int **LoadGraphFromFile(std::string fileName);
  int ExportGraphToDot(std::string fileName);
  int getSize();
  int **getGraph();
};

}  // namespace s21

#endif  // NAVI_SRC_GRAPH_S21_GRAPH_H_
