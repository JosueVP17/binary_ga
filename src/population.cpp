#include "../include/population.hpp"
#include "../include/gaconfig.hpp"

// =============================================
// CONSTRUCTORS
// =============================================

Population::Population() {
    this->populationSize = 0;
}

Population::Population(GAConfig& config) {
    this->populationSize = config.getPopulationSize();

    this->individuals.resize(this->populationSize);

    for(size_t i = 0; i < this->populationSize; i++) {
        this->individuals[i] = Individual(config);
    }
}

// =============================================
// UTILS
// =============================================

void Population::printPopulation() {
    std::cout << "Index\tIndividuals\tDecoded\tFitness\n";

    for(size_t i = 0; i < this->populationSize; i++) {
        std::vector<double> decoded = individuals[i].decodeParameters();

        std::cout << i+1 << "\t" << this->individuals[i] << "\t";

        for(size_t p = 0; p < decoded.size(); p++) {
            std::cout << decoded[p] << " ";
        }

        // Pending implementation of evaluation of fitness
        std::cout << "\t...\n";
    }
}