#include "../include/gaconfig.hpp"

// =============================================
// GACONFIG BUILDER
// =============================================

GAConfig::Builder::Builder() {
    this->probCross = 0.9;
    this->probMutation = 0.01;
    this->populationSize = 100;
    this->numGenerations = 200;
}

GAConfig::Builder& GAConfig::Builder::setGeneLength(size_t length) {
    if(length == 0) {
        throw std::length_error("Genotype length cannot be 0.");
    }

    this->geneLength = length;
    return *this;
}

GAConfig::Builder& GAConfig::Builder::setNumParameters(size_t number) {
    if(number == 0) {
        throw std::length_error("Number of parameters cannot be 0.");
    }

    this->n_parameters = number;
    return *this;
}

GAConfig::Builder& GAConfig::Builder::setParameterLengths(std::vector<size_t> lengths) {
    if(lengths.size() == 0) {
        throw std::length_error("The parameter lengths vector cannot be empty.");
    }

    if(this->geneLength == 0) {
        throw std::invalid_argument("You must set a genotype length.");
    }

    size_t totalLength = 0;
    for(size_t i = 0; i < this->geneLength; i++) {
        totalLength += parameterLengths[i];
    }

    if(totalLength != this->geneLength) {
        throw std::invalid_argument("Sum of parameter lengths must match with genotype length.");
    }

    this->parameterLengths = lengths;
    return *this;
}

GAConfig::Builder& GAConfig::Builder::setParameterRanges(std::vector<std::pair<double, double>> ranges) {
    if(ranges.size() == 0) {
        throw std::length_error("The parameter ranges vector cannot be empty.");
    }

    if(this->n_parameters == 0) {
        throw std::invalid_argument("You must set a number of parameters.");
    }

    for(size_t i = 0; i < this->n_parameters; i++) {
        if(ranges[i].first > ranges[i].second) {
            throw std::invalid_argument("Invalid parameter range at index " + std::to_string(i));
        }
    }

    this->parameterRanges = ranges;
    return *this;
}

GAConfig::Builder& GAConfig::Builder::setCrossoverRate(double rate) {
    if(rate < 0.0 || rate > 1.0) {
        throw std::invalid_argument("Probability of crossover must be between 0.0 and 1.0.");
    }

    this->probCross = rate;
    return *this;
}


GAConfig::Builder& GAConfig::Builder::setMutationRate(double rate) {
    if(rate < 0.0 || rate > 1.0) {
        throw std::invalid_argument("Probability of mutation must be between 0.0 and 1.0.");
    }

    this->probMutation = rate;
    return *this;
}


GAConfig::Builder& GAConfig::Builder::setPopulationSize(size_t size) {
    if(size <= 0) {
        throw std::invalid_argument("Population must be a value greater than zero.");
    }

    this->populationSize = size;
    return *this;
}

GAConfig::Builder& GAConfig::Builder::setNumGenerations(size_t number) {
    if(number <= 0) {
        throw std::invalid_argument("Number of generations must be a value greater than zero.");
    }

    this->numGenerations = number;
    return *this;
}

GAConfig GAConfig::Builder::build() {
    GAConfig config;

    config.geneLength = this->geneLength;
    config.n_parameters = this->n_parameters;
    config.parameterLengths = this->parameterLengths;
    config.parameterRanges = this->parameterRanges;
    config.probCross = this->probCross;
    config.populationSize = this->populationSize;
    config.numGenerations = this->numGenerations;

    return config;
}

// =============================================
// GETTERS
// =============================================

double GAConfig::getGeneLength() {
    return this->geneLength;
}

size_t GAConfig::getNumParameters() {
    return this->n_parameters;
}

std::vector<size_t> GAConfig::getParameterLengths() {
    return this->parameterLengths;
}

std::vector<std::pair<double, double>> GAConfig::getParameterRanges() {
    return this->parameterRanges;
}

double GAConfig::getCrossoverRate() {
    return this->probCross;
}

double GAConfig::getMutationRate() {
    return this->probMutation;
}

size_t GAConfig::getPopulationSize() {
    return this->populationSize;
}

size_t GAConfig::getNumGenerations() {
    return this->numGenerations;
}