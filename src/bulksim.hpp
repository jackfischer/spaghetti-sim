#ifndef BULKSIM_H
#define BULKSIM_H

#include <ctime>
#include <random>

#include "spaghetti.hpp"

class BulkSim {
    private:
        Bowl bowl;
        const int trials;
        std::default_random_engine generator;


    public:
        int total_loops;
        int total_singles;

        BulkSim(int bowlsize, int trials) :
            bowl(bowlsize), trials(trials),
            generator(static_cast<uint32_t>(time(0))),
            total_loops(0), total_singles(0) { }

        void run_trials() {
            for (int trial = 0; trial < trials; trial++) {
                int loops = bowl.simulate(generator);
                total_loops += loops;
                if (loops == 1) {
                    total_singles++;
                }
                bowl.reset();
            }
        }

};

#endif //BULKSIM_H
