#include <climits>
#include <cstring>
#include <fstream>
#include <ios>

#include "../graph_algorithms/includes/s21_graph_algorithms.h"
#include "../includes/s21_graph.h"

namespace s21 {
using std::cout;
using std::endl;

bool isOrientGraph(int **matrix, int size) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (matrix[i][j] != matrix[j][i]) return true;
    }
  }
  return false;
}

void printVertice(int num, std::ofstream &file) {
  file << static_cast<char>(97 + (num % 26));
  if (num < 26) return;
  file << std::to_string(num / 26);
}

void matrixToDotNotOrinet(int **matrix, int size, std::ofstream &file) {
  for (int i = 0; i < size; ++i) {
    printVertice(i, file);
    file << ";" << endl;
  }
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i; j < size; ++j) {
      if (matrix[i][j]) {
        printVertice(i, file);
        file << " -- ";
        printVertice(j, file);
        file << ";" << endl;
      }
    }
  }
}

void matrixToDotOrinet(int **matrix, int size, std::ofstream &file) {
  for (int i = 0; i < size; ++i) {
    printVertice(i, file);
    file << ";" << endl;
  }
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size; ++j) {
      if (matrix[i][j]) {
        printVertice(i, file);
        file << " -> ";
        printVertice(j, file);
        file << ";" << endl;
      }
    }
  }
}

void ft_free_graph(int **graph, int size) {
  int i = size;

  if (!graph) return;
  if (graph[0]) {
    while (--i >= 0) {
      delete[] graph[i];
    }
    delete[] graph;
  }
  graph = nullptr;
}

Graph::Graph() : graph(nullptr), size(0) {}

Graph::~Graph() { ft_free_graph(this->graph, this->size); }

bool ft_check_letters(std::string s) {
  for (size_t i = 0; i < s.length(); i++) {
    if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ') return (true);
  }
  return (false);
}

int ft_number_length(int n) {
  int size = 0;

  if (n == 0) return 1;
  while (n > 0) {
    n /= 10;
    size++;
  }
  return size;
}

int ft_space_len(std::string s) {
  int len = 0;
  int i = -1;

  while (s[++i] == ' ') len++;
  return len;
}

bool ft_check_len(std::string s, int size) {
  int count = 0;
  int i = 0;
  int n = -1;
  std::string buff;

  s = s.substr(ft_space_len(s), std::strlen(s.c_str()));
  while (s[i]) {
    n = std::atoi(s.c_str());
    s = s.substr(ft_number_length(n), std::strlen(s.c_str()));
    s = s.substr(ft_space_len(s), std::strlen(s.c_str()));
    count++;
  }
  if (count != size) return (true);
  return (false);
}

bool ft_check_file(std::string fileName) {
  std::ifstream file;
  std::string buffer;
  int size = 0;
  int constSize = 0;

  if (fileName.substr(fileName.find_last_of(".") + 1) != "txt") return (false);
  file.open(fileName);
  if (file.is_open()) {
    std::getline(file, buffer);
    size = std::atoi(buffer.c_str());
    if (size <= 0) {
      file.close();
      cout << "File size error\n" << endl;
      return false;
    }
    constSize = size;
    while (std::getline(file, buffer)) {
      size--;
      if (ft_check_letters(buffer) || ft_check_len(buffer, constSize))
        return false;
    }
    if (size != 0) {
      file.close();
      return false;
    }
    file.close();
  } else {
    return (false);
  }
  return (true);
}

int *ft_split(std::string buffer, int *graph) {
  int start = 0;
  int stop = buffer.find(" ");
  int i = 0;
  while (stop != -1) {
    if (std::strcmp(buffer.substr(start, stop - start).c_str(), "") != 0) {
      graph[i] = std::atoi(buffer.substr(start, stop - start).c_str());
      i++;
    }
    start = stop + 1;
    stop = buffer.find(" ", start);
  }
  if (std::strcmp(buffer.substr(start, stop - start).c_str(), "") != 0)
    graph[i] = std::atoi(buffer.substr(start, stop - start).c_str());
  return graph;
}

Graph::Graph(std::string fileName) : graph(nullptr), size(0) {
  this->LoadGraphFromFile(fileName);
}

int ft_check_arr(int *arr) {
  int i = 0;

  while (arr[i]) {
    std::cout << "arr[i] = " << arr[i] << std::endl;
    i++;
  }
  return i;
}

int **Graph::LoadGraphFromFile(std::string fileName) {
  std::ifstream file;
  std::string buffer;
  int column = 0;
  GraphAlgorithms algs;
  Graph test_graph;
  int *arr;

  if (!ft_check_file(fileName)) {
    cout << "File error\n" << endl;
    return nullptr;
  }
  file.open(fileName);
  if (this->graph) ft_free_graph(this->graph, this->size);
  this->size = 0;
  if (file.is_open()) {
    std::getline(file, buffer);
    this->size = std::atoi(buffer.c_str());
    this->graph = new int *[this->size];
    while (std::getline(file, buffer)) {
      this->graph[column] = new int[this->size];
      this->graph[column] = ft_split(buffer, this->graph[column]);
      column++;
    }
    file.close();
    test_graph.graph = this->graph;
    test_graph.size = this->size;
    arr = algs.breadthFirstSearch(test_graph, 1);
    if (algs.result_size != this->size) {
      std::cout << "This grahp is not connected\n" << std::endl;
      test_graph.graph = nullptr;
      delete[] arr;
      ft_free_graph(this->graph, this->size);
      this->graph = nullptr;
      return nullptr;
    }
    delete[] arr;
    test_graph.graph = nullptr;
  } else
    cout << "Cant open this file\n" << endl;
  return (this->graph);
}

int Graph::ExportGraphToDot(std::string fileName) {
  int **old_graph = nullptr;
  int old_size = 0;

  if (this->graph) {
    old_graph = this->graph;
    old_size = this->size;
  }
  if (!LoadGraphFromFile(fileName)) return 1;
  std::ofstream file;
  file.open(fileName.append(".dot"), std::ios::out | std::ios::trunc);
  if (!file.is_open()) {
    ft_free_graph(this->graph, this->size);
    this->graph = old_graph;
    this->size = old_size;
    cout << "Cant open file for write\n" << endl;
    return 1;
  }
  if (!isOrientGraph(this->graph, this->size))
    matrixToDotNotOrinet(this->graph, this->size, file);
  else
    matrixToDotOrinet(this->graph, this->size, file);
  file.close();
  ft_free_graph(this->graph, this->size);
  this->graph = old_graph;
  this->size = old_size;
  return 0;
}

int Graph::getSize() { return this->size; }

int **Graph::getGraph() { return this->graph; }

}  // namespace s21
