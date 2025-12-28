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
    this->numElites = config.getNumElites();

    this->individuals.resize(this->populationSize);

    double bestFit = -INFINITY;

    for(size_t i = 0; i < this->populationSize; i++) {
        this->individuals[i] = Individual(config);
        this->individuals[i].setFitness(this->fitnessFunc->evaluate(individuals[i]));
    }

    selectElites();
}

// =============================================
// UTILS
// =============================================
void Population::selectElites() {
    std::vector<Individual> copy(individuals);

    std::partial_sort(
        copy.begin(),
        copy.begin() + this->numElites,
        copy.end(),
        [](const Individual& a, const Individual& b) {
            return a.getFitness() > b.getFitness();
        }
    );

    this->bestIndividuals.insert(
        bestIndividuals.end(),
        copy.begin(),
        copy.begin() + this->numElites
    );
}

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

    std::cout << "Best individual: " << this->bestIndividuals[0] << std::endl;
    std::cout << "Fitness: " << this->bestIndividuals[0].getFitness() << std::endl;
    decoded = bestIndividuals[0].decodeParameters();
    std::cout << "Parameters:" << std::endl;
    for(size_t p = 0; p < decoded.size(); p++) {
        std::cout << "P" << p << " = " << decoded[p] << std::endl;
    }
}