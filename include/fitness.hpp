#ifndef FITNESS_HPP
#define FITNESS_HPP

class Individual;

/**
 * @class Fitness
 * @brief Fitness base class for final user.
 */
class Fitness {
    public:
        virtual double evaluate(const Individual& i) const = 0;
        virtual ~Fitness() = default;
};

#endif