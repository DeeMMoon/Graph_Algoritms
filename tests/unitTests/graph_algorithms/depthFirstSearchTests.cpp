#include <gtest/gtest.h>

#include "../../../src/graph/includes/s21_graph.h"
#include "../../../src/graph_algorithms/includes/s21_graph_algorithms.h"

TEST(DepthFirstSearchTests, DFS1) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 1);
  int orig[5] = {1, 5, 4, 3, 2};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(DepthFirstSearchTests, DFS2) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 2);
  int orig[5] = {2, 5, 4, 3, 1};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(DepthFirstSearchTests, DFS3) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 3);
  int orig[5] = {3, 5, 4, 2, 1};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(DepthFirstSearchTests, DFS4) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 4);
  int orig[5] = {4, 5, 3, 2, 1};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(DepthFirstSearchTests, DFS5) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 5);
  int orig[5] = {5, 4, 3, 2, 1};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}

TEST(DepthFirstSearchTests, NewDFS1) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 1);
  int orig[5] = {1, 4, 2, 3};
  for(int i = 0; i < 4; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(DepthFirstSearchTests, NewDFS2) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 2);
  int orig[5] = {2, 3, 1, 4};
  for(int i = 0; i < 4; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(DepthFirstSearchTests, NewDFS3) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 3);
  int orig[5] = {3, 2, 1, 4};
  for(int i = 0; i < 4; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(DepthFirstSearchTests, NewDFS4) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.depthFirstSearch(*graph, 4);
  int orig[5] = {4, 1, 2, 3};
  for(int i = 0; i < 4; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}