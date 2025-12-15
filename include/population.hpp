#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include "gaconfig.hpp"
#include "individual.hpp"

/**
 * @class Population
 * @brief Represents the population of binary genotypes in this genetic algorithm library.
 */
class Population {
    public:
        // CONSTRUCTORS
        /**
         * @brief Default constructor. Initializes an empty population.
         */
        Population();
        
        /**
         * @brief Constructor that generates a new population.
         * @param config Configuration variable from GAConfig class.
         */
        Population(GAConfig& config);

        // UTILS
        /**
         * @brief Prints the current generation.
         */
        void printPopulation();
    private:
        // POPULATION REPRESENTATION
        std::vector<Individual> individuals;            /// Vector of individuals from the population.

        // POPULATION INFORMATION
        Individual bestIndividual;                      /// Stores the best individual of the population for elitism.

        // POPULATION CONFIGURATION
        size_t populationSize;                          /// Quantity of individuals in a population.
};

#endif