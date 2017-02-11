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
        bulk.run_trials();
        int loops = bulk.total_loops / numtrials; //div by bowlsize gives power?!?!?
        std::cout << "spaghettis: " << bowlsize << " avg loops: " << loops << std::endl;
        results.push_back(loops);
    }

    GnuPlotAdapter gnuplot;
    gnuplot.plot(results);

}

