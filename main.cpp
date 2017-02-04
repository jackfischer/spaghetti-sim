//#include "spaghetti.cpp"
#include "bulksim.cpp"

//#include <random>
//#include <ctime>
#include <iostream>

int main() {
    //const int num_spaghettis = 3;
    //Bowl bowl(num_spaghettis);

    //std::mt19937 generator(static_cast<uint32_t>(time(0)));
    //bool cycle = bowl.simulate(generator);

    BulkSim bs(1, 100);
    float rate = bs.run_trials();
    std::cout << rate << std::endl;

}


