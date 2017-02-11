#include <iostream>
#include <vector>

#include "bulksim.hpp"
#include "gnuplotadapter.hpp"


int main() {

    const int maxbowlsize = 50;
    const int numtrials = 10000;

    std::vector<float> results;

    for (int bowlsize = 1; bowlsize <= maxbowlsize; bowlsize++) {
        BulkSim bulk(bowlsize, numtrials);
        auto rate = bulk.run_trials();
        std::cout << bowlsize << " " << rate << std::endl;
        results.push_back(rate);
    }

    GnuPlotAdapter gnuplot;
    gnuplot.plot(results);

}

