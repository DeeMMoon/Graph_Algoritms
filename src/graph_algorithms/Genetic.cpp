#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

#include "includes/s21_graph_algorithms.h"

namespace s21 {
void calculate_fitness(Individual &ind,
                       const std::vector<std::vector<double>> &matrix) {
  double total_distance = 0;
  for (unsigned int i = 0; i < ind.route.size() - 1; ++i) {
    total_distance += matrix[ind.route[i]][ind.route[i + 1]];
  }
  total_distance += matrix[ind.route.back()][ind.route.front()];
  ind.fitness = 1.0 / total_distance;
}

std::vector<Individual> generate_population(int num_cities) {
  std::vector<Individual> population;
  for (int i = 0; i < POPULATION_SIZE; ++i) {
    Individual ind(num_cities);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ind.route.begin(), ind.route.end(), g);
    population.push_back(ind);
  }
  return population;
}

Individual selection(const std::vector<Individual> &population) {
  int idx1 = rand() % population.size();
  int idx2 = rand() % population.size();

  if (population[idx1].fitness > population[idx2].fitness) {
    return population[idx1];
  } else {
    return population[idx2];
  }
}

Individual crossover(const Individual &parent1, const Individual &parent2) {
  int num_cities = parent1.route.size();
  int start = rand() % num_cities;
  int end = rand() % num_cities;

  if (start > end) std::swap(start, end);

  std::vector<int> child_route(num_cities, -1);
  for (int i = start; i <= end; ++i) {
    child_route[i] = parent1.route[i];
  }

  int pos = 0;
  for (int i = 0; i < num_cities; ++i) {
    if (std::find(child_route.begin(), child_route.end(), parent2.route[i]) ==
        child_route.end()) {
      if (pos == start) pos = end + 1;
      child_route[pos++] = parent2.route[i];
    }
  }

  Individual child(num_cities);
  child.route = child_route;
  return child;
}

void mutate(Individual &ind) {
  int num_cities = ind.route.size();
  for (int i = 0; i < num_cities; ++i) {
    if ((rand() / double(RAND_MAX)) < MUTATION_RATE) {
      int j = rand() % num_cities;
      std::swap(ind.route[i], ind.route[j]);
    }
  }
}

void geneticAlgoritm(Graph &graph) {
  int num_cities = graph.getSize();

  std::vector<std::vector<double>> matrix(num_cities,
                                          std::vector<double>(num_cities));
  for (int i = 0; i < num_cities; ++i) {
    for (int j = 0; j < num_cities; ++j) {
      matrix[i][j] = graph.getGraph()[i][j];
    }
  }

  std::vector<Individual> population = generate_population(num_cities);

  for (Individual &ind : population) {
    calculate_fitness(ind, matrix);
  }

  for (int generation = 0; generation < GENERATIONS; ++generation) {
    std::vector<Individual> new_population;

    for (int i = 0; i < POPULATION_SIZE; ++i) {
      Individual parent1 = selection(population);
      Individual parent2 = selection(population);
      Individual child = crossover(parent1, parent2);
      mutate(child);
      calculate_fitness(child, matrix);
      new_population.push_back(child);
    }

    population = new_population;
  }

  Individual best =
      *std::max_element(population.begin(), population.end(),
                        [](const Individual &a, const Individual &b) {
                          return a.fitness < b.fitness;
                        });
}
}  // namespace s21
