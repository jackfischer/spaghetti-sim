#include "spaghetti.cpp"

#include <ctime>
#include <random>

class BulkSim {
    private:
        Bowl bowl;
        const int trials;
        const std::mt19937 generator;


    public:
        BulkSim(int bowlsize, int trials) :
            bowl(bowlsize), trials(trials), 
            generator(static_cast<uint32_t>(time(0))) { }

        float run_trials() {
            int successes = 0;
            for (int i = 0; i < trials; i++) {
                if (bowl.simulate(generator))
                    successes++;
                bowl.reset();
            }

            std::cout << "num success " << successes <<std::endl;
            return (float) successes / (float) trials;
        }

};

