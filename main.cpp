#include <iostream>
#include "s21_graph_algorithms.h"
#include "s21_graph.h"

void showInterface(){
    std::cout<< "1. Loading source graph from file" << std::endl;
    std::cout<< "2. Traversal of the graph in width with the output of the traversal result to the console" << std::endl;
    std::cout<< "3. Traversal of the graph in depth with the output of the traversal result to the console"<< std::endl;
    std::cout<< "4. Search for the shortest path between arbitrary two vertices and output the result to the console" << std::endl;
    std::cout<< "5. Search for the shortest paths between all pairs of vertices in a graph with the output of the resulting matrix to the console" << std::endl;
    std::cout<< "6. Search for the minimum spanning tree in the graph with the output of the resulting adjacency matrix to the console" << std::endl;
    std::cout<< "7. Solving the traveling salesman problem with the output of the resulting route and its length to the console" << std::endl;
    std::cout<< "8. Exit" << std::endl;
}

int main() {

    Graph graph;
    GraphAlgorithms graphAlgorithms;
    char variant = '0';
    int start_vertex = 0;
    int end_vertex = 0;
    std::string path = "";
    while (variant != '8') {
        showInterface();
        std::cin >> variant;
        switch (variant) {
            case '1': {
                std::cout << "Input path to file"<< std::endl;
                std::cin >> path;
                graph.loadGraphFromFile(path);
                break;
            }
            case '2': {
                if (graph.getGraph() == nullptr)
                {
                    std::cout << "Graph not found"<< std::endl;
                    break;
                }
                std::cout << "Input start vertex"<< std::endl;
                std::cin >> start_vertex;
                if (start_vertex > graph.getSize() || start_vertex < 1)
                {
                    std::cout << "Incorrect input"<< std::endl;
                    break;
                }
                int* result = graphAlgorithms.breadthFirstSearch(graph, start_vertex - 1);
                for (int i = 0; i < graphAlgorithms.result_size; i++) {
                    std::cout << result[i] << " ";
                }
                std::cout << std:: endl;
                break;
            }
            case '3': {
                if (graph.getGraph() == nullptr)
                {
                    std::cout << "Graph not found"<< std::endl;
                    break;
                }
                std::cout << "Input start vertex"<< std::endl;
                std::cin >> start_vertex;
                if (start_vertex > graph.getSize() || start_vertex < 1)
                {
                    std::cout << "Incorrect input"<< std::endl;
                    break;
                }
                int* result = graphAlgorithms.depthFirstSearch(graph, start_vertex - 1);
                for (int i = 0; i < graphAlgorithms.result_size; i++) {
                    std::cout << result[i] << " ";
                }
                std::cout << std:: endl;
                break;
            }
            case '4': {
                if (graph.getGraph() == nullptr)
                {
                    std::cout << "Graph not found"<< std::endl;
                    break;
                }
                std::cout << "Input start vertex"<< std::endl;
                std::cin >> start_vertex;
                std::cout << "Input end vertex"<< std::endl;
                std::cin >> end_vertex;
                if (start_vertex > graph.getSize() || start_vertex < 1 || end_vertex > graph.getSize() || end_vertex < 1)
                {
                    std::cout << "Incorrect input"<< std::endl;
                    break;
                }
                int shortest_path = graphAlgorithms.getShortestPathBetweenVertices(graph,0, 3);
                if (shortest_path < 0 || shortest_path == INT_MAX)
                    std::cout << "Path not found. Reduce the weight of graph edges so that their sum does not exceed INT_MAX!"
                              << std::endl;
                else
                    std::cout << "Shortest path = " << shortest_path << std::endl;
                break;
            }
            case '5': {
                if (graph.getGraph() == nullptr)
                {
                    std::cout << "Graph not found"<< std::endl;
                    break;
                }
                int **matrix = graphAlgorithms.getShortestPathsBetweenAllVertices(graph);
                if (matrix == nullptr)
                    std::cout << "Path not found. Reduce the weight of graph edges so that their sum does not exceed INT_MAX!"
                              << std::endl;
                else {
                    for (int i = 0; i < graph.getSize(); i++) {
                        for (int j = 0; j < graph.getSize(); j++) {
                            std::cout << matrix[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                }
                break;
            }
            case '6': {
                if (graph.getGraph() == nullptr)
                {
                    std::cout << "Graph not found"<< std::endl;
                    break;
                }

                break;
            }
            case '7': {
                if (graph.getGraph() == nullptr)
                {
                    std::cout << "Graph not found"<< std::endl;
                    break;
                }

                break;
            }
            case '8':
                return 0;
            default:
                std::cout << "Incorrect input"<< std::endl;
        }
    }
}
