#ifndef GNUPLOTADAPTER_H
#define GNUPLOTADAPTER_H

#include <cstdio>
#include <vector>

class GnuPlotAdapter {

    private:
        FILE * gnuplotpipe;

    public:
        GnuPlotAdapter() : gnuplotpipe(popen("gnuplot", "w")) {
            fprintf(gnuplotpipe, "set term dumb 79 29\n");
        }

        void set_title(const char * title) {
            fprintf(gnuplotpipe, "set title '%s'\n", title);
        }

        void set_data(std::vector<float> & data) { //TODO add error bars
            fprintf(gnuplotpipe, "plot '-' pt '#' \n");
            for (size_t x = 0; x < data.size(); x++)
                fprintf(gnuplotpipe, "%lu %f\n", x + 1, data[x]);
            fprintf(gnuplotpipe, "e\n"); //declare end of data input
        }

        void plot() {
            fflush(gnuplotpipe);
        }

        ~GnuPlotAdapter() {
            pclose(gnuplotpipe);
        }

};

#endif //GNUPLOT_ADAPTER
