#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

#include "bulksim.hpp"
#include "gnuplotadapter.hpp"


int main() {

    const int maxbowlsize = 50;
    const int numtrials = 10000;

    std::vector<float> expectedloops;
    expectedloops.reserve(maxbowlsize);
    std::vector<float> psingleloops;
    psingleloops.reserve(maxbowlsize);

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    //Create and run a bulk simulation for each bowl size
    for (int bowlsize = 1; bowlsize <= maxbowlsize; bowlsize++) {
        BulkSim bulk(bowlsize, numtrials);
        std::cout << "n: " << bowlsize;
        bulk.run_trials();

        float eloops = (float) bulk.total_loops / (float) numtrials;
        //float eloops = eloops * (float) bowlsize;
        expectedloops.push_back(eloops);
        std::cout << "\tE(loops): "<< std::setprecision(3) << std::setfill('0') << eloops;

        float psingleloop = (float) bulk.total_singles / (float) numtrials;
        psingleloops.push_back(psingleloop);
        std::cout << "\tp(single): " << psingleloop << std::endl;
    }

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Time elapsed (s): " << elapsed_seconds.count() << std::endl;

    GnuPlotAdapter gnuplot;
    gnuplot.set_title("p(single loop) vs n");
    gnuplot.set_data(psingleloops);
    gnuplot.plot();

    gnuplot.set_title("E(num loops) vs n");
    gnuplot.set_data(expectedloops);
    gnuplot.plot();

}

