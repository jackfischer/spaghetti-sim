#ifndef GNUPLOTADAPTER_H
#define GNUPLOTADAPTER_H

#include <cstdio>
#include <vector>

class GnuPlotAdapter {

    private:
        FILE * gnuplotpipe;

    public:
        GnuPlotAdapter() : gnuplotpipe(popen("gnuplot", "w")) {
            std::vector<const char *> setup = {
                "set term dumb 79 29",
                "set title 'p(single loop) vs n'",
                //"set xlabel 'n'",
                //"set ylabel 'p(loop)'"
            };
            for (const char * cmd : setup)
                fprintf(gnuplotpipe, "%s\n", cmd);
            fflush(gnuplotpipe);
        }

        void plot(std::vector<float> & data) {
            fprintf(gnuplotpipe, "plot '-' pt '#' \n");
            for (size_t x = 0; x < data.size(); x++)
                fprintf(gnuplotpipe, "%lu %f\n", x + 1, data[x]);
            fprintf(gnuplotpipe, "e\n"); //end points input
            fflush(gnuplotpipe);
        }

        ~GnuPlotAdapter() {
            pclose(gnuplotpipe);
        }
};

#endif //GNUPLOT_ADAPTER
