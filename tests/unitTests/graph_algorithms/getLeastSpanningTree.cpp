#include <gtest/gtest.h>

#include "../../../src/graph/includes/s21_graph.h"
#include "../../../src/graph_algorithms/includes/s21_graph_algorithms.h"

TEST(getLeastSpanningTree, Tree1) {
    s21::Graph *graph = new s21::Graph();
    s21::GraphAlgorithms graphAlgorithms;
    std::string path = "unitTests/graph/test_graphs/fileWithNormalMap.txt";
    graph->LoadGraphFromFile(path);
    std::vector<std::vector<int> > result = graphAlgorithms.GetLeastSpanningTree(*graph);
    int orig[5][5] = {{0, 2, 3, 0, 0},
                    {5, 0, 0, 2, 1},
                    {1, 0, 0, 0, 0},
                    {0, 4, 0, 0, 0},
                    {0, 2, 0, 0, 0}};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            ASSERT_TRUE(result[i][j] == orig[i][j]);  
        }
    }
    delete graph;
}

TEST(getLeastSpanningTree, Tree2) {
    s21::Graph *graph = new s21::Graph();
    s21::GraphAlgorithms graphAlgorithms;
    std::string path = "unitTests/graph/test_graphs/fileWithNormalMapTwo.txt";
    graph->LoadGraphFromFile(path);
    std::vector<std::vector<int> > result = graphAlgorithms.GetLeastSpanningTree(*graph);
    int orig[10][10] = {  {0, 2, 0, 4, 0, 0, 0, 0, 0, 0}, 
                        {33, 0, 2, 0, 0, 0, 0, 0, 0, 0}, 
                        {0, 56, 0, 0, 0, 0, 2, 0, 0, 0}, 
                        {54, 0, 0, 0, 0, 0, 0, 0, 1, 3}, 
                        {0, 0, 0, 0, 0, 0, 0, 0, 2, 0}, 
                        {0, 0, 0, 0, 0, 0, 0, 2, 88, 0}, 
                        {0, 0, 4, 0, 0, 0, 0, 0, 0, 0}, 
                        {0, 0, 0, 0, 0, 35, 0, 0, 0, 0}, 
                        {0, 0, 0, 7, 3, 3, 0, 0, 0, 0}, 
                        {0, 0, 0, 43, 0, 0, 0, 0, 0, 0}};
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            ASSERT_TRUE(result[i][j] == orig[i][j]);  
        }
    }
    delete graph;
}

TEST(getLeastSpanningTree, Tree3) {
    s21::Graph *graph = new s21::Graph();
    s21::GraphAlgorithms graphAlgorithms;
    std::string path = "unitTests/graph/test_graphs/fileWithNormalMapThree.txt";
    graph->LoadGraphFromFile(path);
    std::vector<std::vector<int> > result = graphAlgorithms.GetLeastSpanningTree(*graph);
    int orig[4][4] = {{0, 1, 0, 1},
                    {1, 0, 1, 0},
                    {0, 1, 0, 0},
                    {1, 0, 0, 0}};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ASSERT_TRUE(result[i][j] == orig[i][j]);  
        }
    }
    delete graph;
}