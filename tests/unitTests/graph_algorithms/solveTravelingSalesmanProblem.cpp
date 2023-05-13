#include <gtest/gtest.h>

#include "../../../src/graph/includes/s21_graph.h"
#include "../../../src/graph_algorithms/includes/s21_graph_algorithms.h"
#include <climits>
#include <string>
#include <experimental/iterator>
#include <iostream>

TEST(SolveTravelingSalesmanProblem, Solve1) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  s21::TsmResult result =
      graphAlgorithms.solveTravelingSalesmanProblem(*graph);
  int orig = 9;
    ASSERT_TRUE(result.distance == orig);
    delete graph;
}

TEST(SolveTravelingSalesmanProblem, Solve2) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapTwo.txt";
  graph->LoadGraphFromFile(path);
  s21::TsmResult result =
      graphAlgorithms.solveTravelingSalesmanProblem(*graph);
    ASSERT_TRUE(result.distance < 45);
    delete graph;
}

TEST(SolveTravelingSalesmanProblem, Solve3) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  s21::TsmResult result =
      graphAlgorithms.solveTravelingSalesmanProblem(*graph);
    ASSERT_TRUE(result.distance == -1);
    delete graph;
}

