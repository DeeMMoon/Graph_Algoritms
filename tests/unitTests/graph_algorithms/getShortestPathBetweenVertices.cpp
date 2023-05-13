#include <gtest/gtest.h>

#include "../../../src/graph/includes/s21_graph.h"
#include "../../../src/graph_algorithms/includes/s21_graph_algorithms.h"

TEST(GetShortestPathBetweenVertices, Short1) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 1, 2);
  int orig = 2;
  ASSERT_TRUE(result == orig);
  delete graph;
}
TEST(GetShortestPathBetweenVertices, Short2) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 2, 3);
  int orig = 3;
  ASSERT_TRUE(result == orig);
  delete graph;
}
TEST(GetShortestPathBetweenVertices, Short3) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 3, 1);
  int orig = 1;
  ASSERT_TRUE(result == orig);
  delete graph;
}
TEST(GetShortestPathBetweenVertices, Short4) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 3, 5);
  int orig = 3;
  ASSERT_TRUE(result == orig);
  delete graph;
}
TEST(GetShortestPathBetweenVertices, Short5) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 5, 2);
  int orig = 2;
  ASSERT_TRUE(result == orig);
  delete graph;
}

TEST(GetShortestPathBetweenVertices, NewShort1) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 1, 2);
  int orig = 1;
  ASSERT_TRUE(result == orig);
  delete graph;
}
TEST(GetShortestPathBetweenVertices, NewShort2) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 2, 3);
  int orig = 1;
  ASSERT_TRUE(result == orig);
  delete graph;
}
TEST(GetShortestPathBetweenVertices, NewShort3) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 3, 1);
  int orig = 2;
  ASSERT_TRUE(result == orig);
  delete graph;
}
TEST(GetShortestPathBetweenVertices, NewShort4) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 3, 4);
  int orig = 3;
  ASSERT_TRUE(result == orig);
  delete graph;
}
TEST(GetShortestPathBetweenVertices, NewShort5) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int result = graphAlgorithms.getShortestPathBetweenVertices(*graph, 4, 2);
  int orig = 2;
  ASSERT_TRUE(result == orig);
  delete graph;
}
