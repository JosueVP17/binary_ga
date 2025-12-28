#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "individual.hpp"
#include "gaconfig.hpp"

class Fitness;

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
        Population(const GAConfig& config);

        /**
         * @brief Prints the current generation.
         */
        void printPopulation();
    private:
        // POPULATION REPRESENTATION
        std::vector<Individual> individuals;            /// Vector of individuals from the population.

        // POPULATION INFORMATION
        std::vector<Individual> bestIndividuals;        /// Stores the best individual of the population for elitism if activated.

        // POPULATION CONFIGURATION
        size_t numElites;
        size_t populationSize;                          /// Quantity of individuals in a population.

        // FITNESS
        Fitness* fitnessFunc;                           /// Fitness function provided by user.
        
        /**
         * @brief Gets the best N individuals from the population.
         */
        void selectElites();
};

#endif