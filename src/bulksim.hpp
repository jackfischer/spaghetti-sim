#ifndef BULKSIM_H
#define BULKSIM_H

#include <ctime>
#include <random>

#include "spaghetti.hpp"

class BulkSim {
    private:
        Bowl bowl;
        const int trials;
        std::mt19937 generator;


    public:
        BulkSim(int bowlsize, int trials) :
            bowl(bowlsize), trials(trials),
            generator(static_cast<uint32_t>(time(0))) { }

        float run_trials() {
            int successes = 0;
            for (int trial = 0; trial < trials; trial++) {
                if (bowl.simulate(generator))
                    successes++;
                bowl.reset();
            }

            return (float) successes / (float) trials;
        }

};

#endif //BULKSIM_H
