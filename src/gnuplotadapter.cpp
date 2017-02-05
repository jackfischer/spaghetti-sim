#include <cstdio>
#include <string>
#include <vector>

#include <iostream>

class GnuPlotAdapter {

    private:
        FILE * gnuplotpipe;

    public:
        GnuPlotAdapter() : gnuplotpipe(popen("gnuplot", "w")) {
            std::vector<const char *> setup = {
                "set term dumb 79 25",
                "set title 'p(single loop) vs n'",
            };
            for (const char * cmd : setup)
                fprintf(gnuplotpipe, "%s\n", cmd);
            //fflush(gnuplotpipe);
        }

        void plot(std::vector<float> & data) {
            fprintf(gnuplotpipe, "plot '-' pt '#' \n");
            for (size_t x = 0; x < data.size(); x++)
                fprintf(gnuplotpipe, "%lu %f\n", x, data[x]);
            fprintf(gnuplotpipe, "e\n");
            //fflush(gnuplotpipe);
        }

        ~GnuPlotAdapter() {
            pclose(gnuplotpipe);
        }
};


