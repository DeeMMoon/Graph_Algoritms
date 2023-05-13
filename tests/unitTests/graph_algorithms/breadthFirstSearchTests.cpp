#include <gtest/gtest.h>

#include "../../../src/graph/includes/s21_graph.h"
#include "../../../src/graph_algorithms/includes/s21_graph_algorithms.h"

TEST(BreadthFirstSearch, BFS1) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 1);
  int orig[5] = {1, 2, 3, 4, 5};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(BreadthFirstSearch, BFS2) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 2);
  int orig[5] = {2, 1, 3, 4, 5};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(BreadthFirstSearch, BFS3) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 3);
  int orig[5] = {3, 1, 2, 4, 5};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(BreadthFirstSearch, BFS4) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 4);
  int orig[5] = {4, 1, 2, 3, 5};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(BreadthFirstSearch, BFS5) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 5);
  int orig[5] = {5, 1, 2, 3, 4};
  for(int i = 0; i < 5; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}

TEST(BreadthFirstSearch, NewBFS1) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 1);
  int orig[5] = {1, 2, 4, 3};
  for(int i = 0; i < 4; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(BreadthFirstSearch, NewBFS2) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 2);
  int orig[5] = {2, 1, 3, 4};
  for(int i = 0; i < 4; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(BreadthFirstSearch, NewBFS3) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 3);
  int orig[5] = {3, 2, 1, 4};
  for(int i = 0; i < 4; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}
TEST(BreadthFirstSearch, NewBFS4) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
  graph->LoadGraphFromFile(path);
  int *result = graphAlgorithms.breadthFirstSearch(*graph, 4);
  int orig[5] = {4, 1, 2, 3};
  for(int i = 0; i < 4; i++){
    ASSERT_TRUE(result[i] == orig[i]);
  }
  delete graph;
  delete result;
}

