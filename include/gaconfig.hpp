#ifndef GA_CONFIG_HPP
#define GA_CONFIG_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

class GAConfig {
    public:
        // CONSTRUCTOR CLASS FOR GACONFIG
        /**
         * @brief Prepares the configuration for the algorithm by setters functions.
         */
        class Builder;

        // GETTERS
        
        double getGeneLength();
        size_t getNumParameters();
        std::vector<size_t> getParameterLengths();
        std::vector<std::pair<double, double>> getParameterRanges();
        double getCrossoverRate();
        double getMutationRate();
        size_t getPopulationSize();
        size_t getNumGenerations();

    private:
        // INDIVIDUAL
        size_t geneLength;                                          /// Total length of the individual.
        size_t n_parameters;                                        /// Number of parameters to optimize.
        std::vector<size_t> parameterLengths;                       /// Length of each parameter in bits.
        std::vector<std::pair<double, double>> parameterRanges;     /// Pair values of range for each parameter.
        double probCross;                                           /// Probability of crossover in the range [0, 1].
        double probMutation;                                        /// Probability of bit mutation in the range [0, 1].

        // POPULATION
        size_t populationSize;                                      /// Quantity of individuals in a population.
        size_t numGenerations;                                      /// Number of generations of the algorithm.
};

class GAConfig::Builder {
    public:
        // DEFAULT CONSTRUCTOR
        /**
         * @brief Constructor for the algorithm configuration.
         * @attention In each creation it needs to be concatenated the build() function in order to return
         * GAConfig object. Example: GAConfig config = Builder().build();
         * Default parameters are:
         * @param probCross 0.9
         * @param probMutation 0.01
         * @param populationSize 100
         * @param numGenerations 200
         */
        Builder();

        // SETTERS
        /**
         * @brief Sets the total length of the individual genotype in bits.
         */
        Builder& setGeneLength(size_t length);

        /**
         * @brief Sets the number of parameters to optimize.
         */
        Builder& setNumParameters(size_t number);

        /**
         * @brief Sets the length of each parameter in bits.
         */
        Builder& setParameterLengths(std::vector<size_t> lengths);

        /**
         * @brief Sets the pair values of range for each parameter.
         */
        Builder& setParameterRanges(std::vector<std::pair<double, double>> ranges);

        /**
         * @brief Sets the probability of crossover in the range [0, 1].
         */
        Builder& setCrossoverRate(double rate);

        /**
         * @brief Sets the probability of bit mutation in the range [0, 1].
         */
        Builder& setMutationRate(double rate);

        /**
         * @brief Sets the quantity of individuals in a population.
         */
        Builder& setPopulationSize(size_t size);

        /**
         * @brief Sets the number of generations of the algorithm.
         */
        Builder& setNumGenerations(size_t number);

        /**
         * @brief Returns a GAConfig object in order to initialize binary GA. Example: GAConfig config = Builder().build();
         */
        GAConfig build();

    private:
        // INDIVIDUAL
        size_t geneLength;                                          /// Builder: Total length of the individual.
        size_t n_parameters;                                        /// Builder: Number of parameters to optimize.
        std::vector<size_t> parameterLengths;                       /// Builder: Length of each parameter in bits.
        std::vector<std::pair<double, double>> parameterRanges;     /// Builder: Pair values of range for each parameter.
        double probCross;                                           /// Builder: Probability of crossover in the range [0, 1].
        double probMutation;                                        /// Builder: Probability of bit mutation in the range [0, 1].

        // POPULATION
        size_t populationSize;                                      /// Builder: Quantity of individuals in a population.
        size_t numGenerations;                                      /// Builder: Number of generations of the algorithm.
};

#endif