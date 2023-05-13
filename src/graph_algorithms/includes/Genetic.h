#ifndef GENETIC_H
#define GENETIC_H

#include "../../graph/includes/s21_graph.h"

namespace s21 {
const int POPULATION_SIZE = 50;
const int GENERATIONS = 50;
const double MUTATION_RATE = 0.1;

struct Individual {
  std::vector<int> route;
  double fitness;

  Individual(int num_cities) {
    route.resize(num_cities);
    for (int i = 0; i < num_cities; ++i) {
      route[i] = i;
    }
  }
};

void calculate_fitness(Individual &ind,
                       const std::vector<std::vector<double>> &matrix);
std::vector<Individual> generate_population(int num_cities);
Individual selection(const std::vector<Individual> &population);
Individual crossover(const Individual &parent1, const Individual &parent2);
void mutate(Individual &ind);
void geneticAlgoritm(Graph &graph);
}  // namespace s21
#endif
