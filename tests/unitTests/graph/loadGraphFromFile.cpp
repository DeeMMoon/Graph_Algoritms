#include <gtest/gtest.h>

#include "../../../src/graph/includes/s21_graph.h"
#include "../../../src/graph_algorithms/includes/s21_graph_algorithms.h"

TEST(loadGraphFromFile, empty) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/emptyFile.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, diff) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithDifferentParameterAndMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, emptyLines) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithEmptyLinesMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, mixSpaces) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithMixSpaceMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_TRUE(graph != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, negMap) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithNegativeMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, normalOne) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_TRUE(graph != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, normalTwo) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapTwo.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_TRUE(graph != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, withoutMap) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithParamAndWithoutMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, wrongParam) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithWrongParam.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, unweighted) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithWrongUnweightedMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, weight) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithWrongWeightedMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}

TEST(loadGraphFromFile, zero) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileZeroMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->getGraph() != nullptr);
  delete graph;
}