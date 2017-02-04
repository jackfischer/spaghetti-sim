#include "spaghetti.cpp"

#include <ctime>
#include <iostream>

int main() {
    const int num_spaghettis = 3;
    Bowl bowl(num_spaghettis);

    std::mt19937 generator(static_cast<uint32_t>(time(0)));
    bool cycle = bowl.simulate(generator);

    std::cout << cycle << std::endl;

    //debug
    //bowl.print_bowl();
}




