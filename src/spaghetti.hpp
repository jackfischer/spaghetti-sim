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
        int unseen_spaghetti;

        void join_ends(int a, int b) {
            const int spaghetti = a / 2;
            const int offset = a % 2;
            int& end = (offset == 0) ? bowl[spaghetti].left : bowl[spaghetti].right;
            end = b;
        }

        void find_unseen() {
            while (!bowl[unseen_spaghetti].seen)
                unseen_spaghetti++;
        }


    public:
        Bowl(int n) : bowl(n), ends(2*n), unseen_spaghetti(0) {
            for (int i = 0; i < 2*n; i++)
                ends[i] = i;
        }

        int simulate(std::default_random_engine & generator) {
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

            //Count loops
            int current_end = 0;
            int loops = 0;
            for (size_t count = 0; count < bowl.size() + 1; count++) {
                Spaghetti & s = bowl[current_end / 2];
                if (s.seen == true) { //End of a loop
                    loops++;
                    find_unseen();
                    current_end = 2 * unseen_spaghetti;
                } else { //Middle of a loop
                    s.seen = true;
                    current_end = (current_end % 2 == 0) ? s.right : s.left;
                }
            }
            //if (loops == 1)
            //    std::cout << "DEBUG loops: " << loops << std::endl;
            return loops;
            //return (loops == 1);
            //std::cout << "legacy seen: " << legacy_seen << " loops: " << loops << std::endl;
            //return (legacy_seen == (loops == 1));
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
