#include <climits>
#include <experimental/iterator>
#include <iostream>
#include <string>

#include "../containers/queue/queue.h"
#include "../containers/stack/stack.h"
#include "../graph/includes/s21_graph.h"
#include "../graph_algorithms/includes/BF.h"
#include "../graph_algorithms/includes/Genetic.h"
#include "../graph_algorithms/includes/navi.h"
#include "../graph_algorithms/includes/s21_graph_algorithms.h"

void showInterface() {
  std::cout << "1. Loading source graph from file" << std::endl;
  std::cout << "2. Traversal of the graph in width with the output of the "
               "traversal result to the console"
            << std::endl;
  std::cout << "3. Traversal of the graph in depth with the output of the "
               "traversal result to the console"
            << std::endl;
  std::cout << "4. Search for the shortest path between arbitrary two vertices "
               "and output the result to the console"
            << std::endl;
  std::cout
      << "5. Search for the shortest paths between all pairs of vertices in a "
         "graph with the output of the resulting matrix to the console"
      << std::endl;
  std::cout << "6. Search for the minimum spanning tree in the graph with the "
               "output of the resulting adjacency matrix to the console"
            << std::endl;
  std::cout << "7. Solving the traveling salesman problem with the output of "
               "the resulting route and its length to the console"
            << std::endl;
  std::cout << "8. Exit" << std::endl;
  std::cout << "9. !BONUS PART! Comparison of methods for solving the "
               "traveling salesman problem"
            << std::endl;
}

bool isNumeric(std::string const &str) {
  auto it = str.begin();
  while (it != str.end() && std::isdigit(*it)) {
    it++;
  }
  return !str.empty() && it == str.end();
}

static void caseTwo(s21::Graph &graph, int start_vertex,
                    s21::GraphAlgorithms &graphAlgorithms) {
  if (graph.getGraph() == nullptr) {
    std::cout << "Graph not found" << std::endl;
    return;
  }
  std::string input;
  std::cout << "Input start vertex" << std::endl;
  std::cin >> input;
  if (!isNumeric(input)) {
    std::cout << "Incorrect input" << std::endl;
    return;
  }
  start_vertex = std::atoi(const_cast<char *>(input.c_str()));
  if (start_vertex > graph.getSize() || start_vertex < 1) {
    std::cout << "Incorrect input" << std::endl;
    return;
  }
  int *result = graphAlgorithms.breadthFirstSearch(graph, start_vertex);
  for (int i = 0; i < graphAlgorithms.result_size; i++) {
    std::cout << result[i] << " ";
  }
  delete result;
  std::cout << std::endl;
}

static void caseThree(s21::Graph &graph, int start_vertex,
                      s21::GraphAlgorithms &graphAlgorithms) {
  if (graph.getGraph() == nullptr) {
    std::cout << "Graph not found" << std::endl;
    return;
  }
  std::string input;
  std::cout << "Input start vertex" << std::endl;
  std::cin >> input;
  if (!isNumeric(input)) {
    std::cout << "Incorrect input" << std::endl;
    return;
  }
  start_vertex = std::atoi(const_cast<char *>(input.c_str()));
  if (start_vertex > graph.getSize() || start_vertex < 1) {
    std::cout << "Incorrect input" << std::endl;
    return;
  }
  int *result = graphAlgorithms.depthFirstSearch(graph, start_vertex);
  for (int i = 0; i < graphAlgorithms.result_size; i++) {
    std::cout << result[i] << " ";
  }
  delete result;
  std::cout << std::endl;
}

static void caseFour(s21::Graph &graph, int start_vertex, int end_vertex,
                     s21::GraphAlgorithms &graphAlgorithms) {
  if (graph.getGraph() == nullptr) {
    std::cout << "Graph not found" << std::endl;
    return;
  }
  std::string input;
  std::cout << "Input start vertex" << std::endl;
  std::cin >> input;
  if (!isNumeric(input)) {
    std::cout << "Incorrect input" << std::endl;
    return;
  }
  start_vertex = std::atoi(const_cast<char *>(input.c_str()));
  std::cout << "Input end vertex" << std::endl;
  std::cin >> input;
  if (!isNumeric(input)) {
    std::cout << "Incorrect input" << std::endl;
    return;
  }
  end_vertex = std::atoi(const_cast<char *>(input.c_str()));
  if (start_vertex > graph.getSize() || start_vertex < 1 ||
      end_vertex > graph.getSize() || end_vertex < 1) {
    std::cout << "Incorrect input" << std::endl;
    return;
  }
  int shortest_path = graphAlgorithms.getShortestPathBetweenVertices(
      graph, start_vertex, end_vertex);
  if (shortest_path < 0 || shortest_path == INT_MAX)
    std::cout << "Path not found. Reduce the weight of graph edges so that "
                 "their sum does not exceed INT_MAX!"
              << std::endl;
  else
    std::cout << "Shortest path = " << shortest_path << std::endl;
}

static void caseFive(s21::Graph &graph, s21::GraphAlgorithms &graphAlgorithms) {
  if (graph.getGraph() == nullptr) {
    std::cout << "Graph not found" << std::endl;
    return;
  }
  int **matrix = graphAlgorithms.getShortestPathsBetweenAllVertices(graph);
  if (matrix == nullptr)
    std::cout << "Path not found. Reduce the weight of graph edges so that "
                 "their sum does not exceed INT_MAX!"
              << std::endl;
  else {
    for (int i = 0; i < graph.getSize(); i++) {
      for (int j = 0; j < graph.getSize(); j++) {
        std::cout << matrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
    for (int i = 0; i < graph.getSize(); i++) {
      delete matrix[i];
    }
    delete matrix;
  }
}

static void caseSix(s21::Graph &graph, s21::GraphAlgorithms &graphAlgorithms) {
  if (graph.getGraph() == nullptr) {
    std::cout << "Graph not found" << std::endl;
    return;
  }
  std::vector<std::vector<int> > matrix =
      graphAlgorithms.GetLeastSpanningTree(graph);
  for (int i = 0; i < graph.getSize(); i++) {
    for (int j = 0; j < graph.getSize(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

static void caseSeven(s21::Graph &graph,
                      s21::GraphAlgorithms &graphAlgorithms) {
  if (graph.getGraph() == nullptr) {
    std::cout << "Graph not found" << std::endl;
    return;
  }
  s21::TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graph);
  std::copy(result.vertices.begin(), result.vertices.end(),
            std::experimental::make_ostream_joiner(std::cout, " "));
  std::cout << "\n" << result.distance << std::endl;
}

static void caseNine(s21::Graph &graph, s21::GraphAlgorithms &graphAlgorithms) {
  if (graph.getGraph() == nullptr) {
    std::cout << "Graph not found" << std::endl;
    return;
  }
  std::string str;
  std::cin >> str;
  int N = 0;
  try {
    N = std::stoi(str);
  } catch (const std::exception &) {
    std::cout << "Caught Invalid Argument Exception" << std::endl;
    return;
  }
  unsigned int start_time = clock();
  for (int i = 0; i < N; i++) {
    s21::TsmResult result =
        graphAlgorithms.solveTravelingSalesmanProblem(graph);
  }
  unsigned int end_time = clock();
  std::cout << "TSP : " << ((float)(end_time - start_time)) / 1000 << " sec"
            << std::endl;
  start_time = clock();
  for (int i = 0; i < N; i++) graphAlgorithms.runGeneticAlgoritm(graph);
  end_time = clock();
  std::cout << "Genetic : " << ((float)(end_time - start_time)) / 1000 << " sec"
            << std::endl;
  start_time = clock();
  for (int i = 0; i < N; i++) graphAlgorithms.runBFAlgoritm(graph);
  end_time = clock();
  std::cout << "Brute force: " << ((float)(end_time - start_time)) / 1000
            << " sec" << std::endl;
}

int main() {
  s21::Graph *graph = new s21::Graph();
  s21::GraphAlgorithms graphAlgorithms;
  char variant = '0';
  int start_vertex = 0;
  int end_vertex = 0;
  std::string path = "";
  while (variant != '8') {
    showInterface();
    std::cin >> variant;
    switch (variant) {
      case '1': {
        std::cout << "Input path to file" << std::endl;
        std::cin >> path;
        graph->LoadGraphFromFile(path);
        break;
      }
      case '2': {
        caseTwo(*graph, start_vertex, graphAlgorithms);
        break;
      }
      case '3': {
        caseThree(*graph, start_vertex, graphAlgorithms);
        break;
      }
      case '4': {
        caseFour(*graph, start_vertex, end_vertex, graphAlgorithms);
        break;
      }
      case '5': {
        caseFive(*graph, graphAlgorithms);
        break;
      }
      case '6': {
        caseSix(*graph, graphAlgorithms);
        break;
      }
      case '7': {
        caseSeven(*graph, graphAlgorithms);
        break;
      }
      case '8': {
        delete graph;
        return 0;
      }
      case '9': {
        caseNine(*graph, graphAlgorithms);
        break;
      }
      default: {
        std::cout << "Incorrect input" << std::endl;
        break;
      }
    }
  }
  return 0;
}
