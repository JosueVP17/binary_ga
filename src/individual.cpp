#include "../include/individual.hpp"

// =============================================
// CONSTRUCTORS
// =============================================

Individual::Individual() {
    this->fitness = 0;
    this->geneLength = 0;
    this->n_parameters = 0;
}

Individual::Individual(GAConfig& config){
    this->geneLength = config.getGeneLength();
    this->n_parameters = config.getNumParameters();
    this->parameterLengths = config.getParameterLengths();
    this->parameterRanges = config.getParameterRanges();
    this->fitness = 0.0;
    this->individual.resize(this->geneLength);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dist(0.5);

    for(size_t i = 0; i < this->geneLength; i++) {
        this->individual[i] = dist(gen);
    }
}

// =============================================
// GENETIC MANIPULATION
// =============================================

void Individual::crossover(Individual& other, double probCross) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution dist(0.0, 1.0);

    if(dist(gen) < probCross) {
        std::uniform_int_distribution<int> intDist(0, this->geneLength - 1);
        size_t point = intDist(gen);
        std::cout << point << std::endl;

        std::vector<bool> ind1_copy(this->individual);

        for(size_t i = point; i < this->geneLength; i++) {
            this->individual[i] = other.individual[i];
            other.individual[i] = ind1_copy[i];
        }
    }
}

void Individual::mutate(double probMutation) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for(size_t i = 0; i < this->geneLength; i++) {
        if(dist(gen) < probMutation) {
            this->individual[i] = !this->individual[i];
        }
    }
}

// =============================================
// GETTERS
// =============================================

std::vector<double> Individual::decodeParameters() {
    std::vector<double> deco;
    size_t currentBit = 0;

    for(size_t i = 0; i < this->n_parameters; i++) {
        size_t numberBit = 0;

        for(size_t j = 0; j < this->parameterLengths[i]; j++) {
            if(this->individual[currentBit + j]) {
                numberBit += pow(2, this->parameterLengths[i] - j - 1);
            }
        }

        currentBit += this->parameterLengths[i];

        double step = (this->parameterRanges[i].second - this->parameterRanges[i].first) / (pow(2, this->parameterLengths[i]) - 1);
        deco.push_back(this->parameterRanges[i].first + numberBit * step);
    }

    return deco;
}

double Individual::getFitness() const {
    return this->fitness;
}

// =============================================
// SETTERS
// =============================================

void Individual::setFitness(double fitness) {
    this->fitness = fitness;
}

// =============================================
// UTILS
// =============================================

std::ostream& operator<<(std::ostream& os, const Individual& ind) {
    if(ind.geneLength == 0) {
        os << "Empty ind";
        return os;
    }

    for(size_t i = 0; i < ind.geneLength; i++) {
        if(ind.individual[i] == false) os << "0";
        else os << "1";
    }

    return os;
}