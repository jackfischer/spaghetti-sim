#include "bulksim.cpp"

#include <iostream>

int main() {

    BulkSim bs(2, 1000);
    float rate = bs.run_trials();
    std::cout << rate << std::endl;

}


