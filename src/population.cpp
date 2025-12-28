#include "../include/population.hpp"
#include "../include/gaconfig.hpp"
#include "../include/fitness.hpp"

// =============================================
// CONSTRUCTORS
// =============================================

Population::Population() {
    this->populationSize = 0;
}

Population::Population(const GAConfig& config) {
    this->populationSize = config.getPopulationSize();
    this->fitnessFunc = config.getFitnessFunc();

    this->individuals.resize(this->populationSize);

    double bestFit = -INFINITY;

    for(size_t i = 0; i < this->populationSize; i++) {
        this->individuals[i] = Individual(config);
        this->individuals[i].setFitness(this->fitnessFunc->evaluate(individuals[i]));

        if(this->individuals[i].getFitness() > bestFit) {
            this->bestIndividual = this->individuals[i];
            bestFit = this->individuals[i].getFitness();
        }
    }
}

// =============================================
// UTILS
// =============================================

void Population::printPopulation() {
    std::vector<double> decoded;

    std::cout << "Index\tIndividuals\tDecoded\t\t\tFitness\n";

    for(size_t i = 0; i < this->populationSize; i++) {
        decoded = individuals[i].decodeParameters();

        std::cout << i+1 << "\t" << this->individuals[i] << "\t";

        for(size_t p = 0; p < decoded.size(); p++) {
            std::cout << decoded[p];
            if (p < decoded.size() - 1) std::cout << ", ";
        }

        std::cout << "\t" << this->individuals[i].getFitness() << std::endl;
    }

    std::cout << "Best individual: " << this->bestIndividual << std::endl;
    std::cout << "Fitness: " << this->bestIndividual.getFitness() << std::endl;
    decoded = bestIndividual.decodeParameters();
    std::cout << "Parameters:" << std::endl;
    for(size_t p = 0; p < decoded.size(); p++) {
        std::cout << "P" << p << " = " << decoded[p] << std::endl;
    }
}