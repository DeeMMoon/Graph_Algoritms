
#include <gtest/gtest.h>

#include "../../../src/graph/includes/s21_graph.h"
#include "../../../src/graph_algorithms/includes/s21_graph_algorithms.h"

TEST(exportGraphToDot, empty) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/emptyFile.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, diff) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithDifferentParameterAndMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, emptyLines) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithEmptyLinesMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, mixSpaces) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithMixSpaceMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_TRUE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, negMap) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithNegativeMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, normalOne) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_TRUE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, normalTwo) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapTwo.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_TRUE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, withoutMap) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithParamAndWithoutMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, wrongParam) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithWrongParam.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, unweighted) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithWrongUnweightedMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, weight) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileWithWrongWeightedMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}

TEST(exportGraphToDot, zero) {
  s21::Graph *graph = new s21::Graph();
  std::string path = "unitTests/graph/test_graphs/fileZeroMap.txt";
  graph->LoadGraphFromFile(path);
  ASSERT_FALSE(graph->ExportGraphToDot(path) == 0);
  delete graph;
}