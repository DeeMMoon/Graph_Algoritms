#include <gtest/gtest.h>

#include "../../../src/graph/includes/s21_graph.h"
#include "../../../src/graph_algorithms/includes/s21_graph_algorithms.h"

TEST(getShortestPathsBetweenAllVertices, ShortAll1) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
  graph->LoadGraphFromFile(path);
  int **result = graphAlgorithms.getShortestPathsBetweenAllVertices(*graph);
  int orig[5][5] = {{0, 2, 3, 4, 3},
                    {2, 0, 3, 2, 1},
                    {1, 2, 0, 4, 3},
                    {2, 3, 3, 0, 1},
                    {1, 2, 3, 4, 0}};
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      ASSERT_TRUE(result[i][j] == orig[i][j]);  
    }
  }
    for (int i = 0; i < 5; i++) {
      delete result[i];
    }
    delete result;
    delete graph;
}
TEST(getShortestPathsBetweenAllVertices, ShortAll2) {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  std::string path = "unitTests/graph/test_graphs/fileWithNormalMapTwo.txt";
  graph->LoadGraphFromFile(path);
  int **result = graphAlgorithms.getShortestPathsBetweenAllVertices(*graph);
  int orig[10][10] = {  {0, 2, 3, 4, 5, 6, 5, 8, 5, 7}, 
                        {6, 0, 2, 6, 8, 9, 4, 7, 7, 8}, 
                        {4, 6, 0, 8, 6, 7, 2, 9, 8, 6}, 
                        {6, 7, 2, 0, 4, 4, 4, 6, 1, 3}, 
                        {2, 4, 5, 6, 0, 5, 7, 4, 2, 7}, 
                        {4, 3, 5, 4, 2, 0, 5, 2, 4, 5}, 
                        {2, 4, 4, 6, 4, 8, 0, 8, 6, 7}, 
                        {2, 1, 3, 6, 7, 6, 5, 0, 7, 3}, 
                        {5, 6, 8, 7, 3, 3, 8, 5, 0, 8}, 
                        {6, 6, 8, 7, 5, 3, 4, 5, 7, 0}};
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      ASSERT_TRUE(result[i][j] == orig[i][j]);  
    }
  }
    for (int i = 0; i < 10; i++) {
      delete result[i];
    }
    delete result;
    delete graph;
}