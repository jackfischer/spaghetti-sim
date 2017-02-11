#include <iostream>
#include <random>

#include "spaghetti.hpp"

int main() {
    Bowl bowl(4);
    std::default_random_engine generator;
    auto result = bowl.simulate(generator);

    std::cout << result<<std::endl;

}
