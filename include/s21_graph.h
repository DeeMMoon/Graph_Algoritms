#ifndef GRAPH_S21_GRAPH_H
#define GRAPH_S21_GRAPH_H

#include <string.h>
#include <iostream>


class Graph{
private:
    int     size;
    int**   graph;
public:
    int**   loadGraphFromFile(std::string filename);
    int     exportGraphToDot(std::string filename);
    int     getSize();
    int**   getGraph();
};
#endif
