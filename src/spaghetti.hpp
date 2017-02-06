#ifndef SPAGHETTI_H
#define SPAGHETTI_H

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

class Spaghetti {
    public:
        int left;
        int right;
        bool seen;
        Spaghetti() : left(-1), right(-1), seen(false) { }
};


class Bowl {

    private:
        std::vector<Spaghetti> bowl;
        std::vector<int> ends;

        void join_ends(int a, int b) {
            const int spaghetti = a / 2;
            const int offset = a % 2;
            int& end = (offset == 0) ? bowl[spaghetti].left : bowl[spaghetti].right;
            end = b;
        }


    public:
        Bowl(int n) : bowl(n), ends(2*n) {
            for (int i = 0; i < 2*n; i++)
                ends[i] = i;
        }

        bool simulate(std::mt19937 & generator) {
            //Randomize end vector
            std::shuffle(ends.begin(), ends.end(), generator);

            //Perform connections
            for (size_t i = 0; i < ends.size(); i+=2) {
                const int a = ends[i];
                const int b = ends[i+1];
                join_ends(a, b);
                join_ends(b, a);
                //TODO only perform for outgoing (lower) spaghetti link
            }

            //Test cycle
            int end_i = 0;
            for (size_t count = 0; count < bowl.size(); count++) {
                Spaghetti & s = bowl[end_i / 2];
                if (s.seen == true)
                    return false;
                s.seen = true;
                end_i = s.right;
            }
            return true;
        }

        void reset() {
            for (Spaghetti & s : bowl)
                s.seen = false;
        }

        void print_bowl() const {
            for (Spaghetti s : bowl)
                std::cout << " " << s.left << " " << s.right << std::endl;
        }

        void print_ends() const {
            for (int i : ends)
                std::cout << i << " ";
            std::cout << std::endl;
        }

};

#endif //SPAGHETTI_H
