
#ifndef GRAPH_S21_GRAPH_ALGORITHMS_H
#define GRAPH_S21_GRAPH_ALGORITHMS_H

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "s21_graph.h"

class GraphAlgorithms{
public:
    int result_size;
    int *depthFirstSearch(Graph &graph, int startVertex);
    int *breadthFirstSearch(Graph &graph, int startVertex);
    int getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
    int **getShortestPathsBetweenAllVertices(Graph &graph);

private:
    bool isVisited(int *visited, int size, int vertex);
    bool checkMatrix(int **matrix, int size);
    long getMatrixSum(int **matrix, int size);
};

#endif
