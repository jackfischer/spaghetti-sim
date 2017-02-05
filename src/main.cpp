#include "bulksim.cpp"
#include "gnuplotadapter.cpp"

#include <iostream>
#include <vector>

int main() {

    const int maxbowlsize = 13;
    const int numtrials = 10000;

    std::vector<float> results;

    for (int bowlsize = 1; bowlsize <= maxbowlsize; bowlsize++) {
        BulkSim bulk(bowlsize, numtrials);
        float rate = bulk.run_trials();
        std::cout << bowlsize << " " << rate << std::endl;
        results.push_back(rate);
    }

    GnuPlotAdapter gnuplot;
    gnuplot.plot(results);

}

