#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <stdexcept>

/**
 * @class Individual
 * @brief Represents an individual in this genetic algorithm library with a binary genotype.
 */
class Individual {
    public:
        // CONSTRUCTORS
        /**
         * @brief Default constructor. Initializes a empty individual.
         */
        Individual();

        /**
         * @brief Constructor that generates a random individual.
         * @param geneLength Total length of binary cromosome.
         * @param n_parameters Number of parameters.
         * @param parameterLengths Vector with the length in bits for each parameter.
         * @param parameterRanges Vector with the ranges [min, max] for each parameter.
         */
        Individual(size_t geneLength, size_t n_parameters, std::vector<size_t> parameterLengths, std::vector<std::pair<double, double>> parameterRanges);

        // GENETIC MANIPULATION
        /**
         * @brief Mutates the individual based on a certain probability.
         * @param probMutation Probability of bit mutation in the range [0, 1].
         */
        void mutate(double probMutation);

        // GETTERS
        /**
         * @brief Gets the fitness value of the individual.
         * @return Actual fitness value.
         */
        double getFitness() const;

        // SETTERS
        /**
         * @brief Sets the fitness value of the individual.
         * @param fitness New fitness value.
         */
        void setFitness(double fitness);

        // UTILS
        friend std::ostream& operator<<(std::ostream& os, const Individual& ind);
        
    private:
        // GENETIC REPRESENTATION
        std::vector<bool> individual;   ///< Binary representation of the cromosome.

        // INDIVIDUAL INFORMATION
        double fitness;                 ///< Fitness value of the individual.

        // INDIVIDUAL CONFIGURATION
        size_t geneLength;                                          ///< Total length of the individual.
        size_t n_parameters;                                        ///< Number of parameters to optimize.
        std::vector<size_t> parameterLengths;                       ///< Length of each parameter in bits.
        std::vector<std::pair<double, double>> parameterRanges;     ///< Pair values of range for each parameter.
};

/**
 * @brief Overloading of insertion operator to print individual.
 * Shows "Empty ind" if the individual does not have genes, or a "0" and "1" sequence representing its genes values.
 */
std::ostream& operator<<(std::ostream& os, const Individual& ind);

#endif