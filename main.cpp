#include "spaghetti.cpp"

#include <iostream>

int main() {
    const int num_spaghettis = 1;
    Bowl bowl(num_spaghettis);

    bool cycle = bowl.simulate();

    std::cout << cycle << std::endl;
    bowl.to_string();
}




