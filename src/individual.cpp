#include "../include/individual.hpp"

// =============================================
// CONSTRUCTORS
// =============================================

Individual::Individual() {
    this->fitness = 0;
    this->geneLength = 0;
    this->n_parameters = 0;
}

Individual::Individual(
    size_t geneLength,
    size_t n_parameters,
    std::vector<size_t> parameterLengths,
    std::vector<std::pair<double, double>> parameterRanges
){
    if(geneLength == 0) {
        throw std::length_error("geneLength cannot be 0.");
    }

    if(n_parameters == 0) {
        throw std::length_error("n_parameters cannot be 0.");
    }

    if(parameterLengths.size() == 0) {
        throw std::length_error("The vector parameterLengths can not be empty.");
    }

    if(parameterRanges.size() == 0) {
        throw std::length_error("The vector parameterRanges can not be empty.");
    }

    if(n_parameters != parameterLengths.size()) {
        throw std::invalid_argument("parameterLengths size must match n_parameters.");
    }

    if(n_parameters != parameterRanges.size()) {
        throw std::invalid_argument("parameterRanges size must match n_parameters.");
    }

    // Validation of parameter lengths
    size_t totalLength = 0;
    for(size_t i = 0; i < n_parameters; i++) {
        totalLength += parameterLengths[i];
    }
    if(totalLength != geneLength) {
        throw std::invalid_argument("Sum of parameterLengths must match with geneLength.");
    }

    // Validation of parameter ranges
    for(size_t i = 0; i < n_parameters; i++) {
        if(parameterRanges[i].first >= parameterRanges[i].second) {
            throw std::invalid_argument("Invalid parameter range at index " + std::to_string(i));
        }
    }
    
    this->geneLength = geneLength;
    this->n_parameters = n_parameters;
    this->fitness = 0.0;
    this->individual.resize(geneLength);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dist(0.5);

    for(size_t i = 0; i < geneLength; i++) {
        this->individual[i] = dist(gen);
    }
}

// =============================================
// GENETIC MANIPULATION
// =============================================

void Individual::mutate(double probMutation) {
    if(probMutation < 0.0 || probMutation > 1.0) {
        throw std::invalid_argument("Probability of mutation must be between 0.0 and 1.0.");
    }

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