#include <algorithm>
#include <iostream>
#include <vector>

class Spaghetti {
    public:
        int left;
        int right;
        bool seen;

        Spaghetti() : left(-1), right(-1) { }

};


class Bowl {

    private:
        void join_ends(int a, int b) {
            int spaghetti = a / 2;
            int offset = a % 2;
            int& end = (offset == 0) ? bowl[spaghetti].left : bowl[spaghetti].right;
            end = b;
        }


    public:
        std::vector<Spaghetti> bowl;
        std::vector<int> ends;

        Bowl(int n) : bowl(n) , ends(2*n) {
            for (int i = 0; i < 2*n; i++)
                ends[i] = i;
        }

        void to_string() {
            for (Spaghetti s : bowl) {
                std::cout << " " << s.left << " " << s.right <<std::endl;
            }
        }

        void print_ends() {
            for (int i : ends)
                std::cout << i << " ";
            std::cout << std::endl;
        }


        bool simulate() {
            //Randomize end vector
            std::random_shuffle(ends.begin(), ends.end());

            //Perform connections
            for (size_t i = 0; i < ends.size(); i+=2) {
                int a = ends[i];
                int b = ends[i+1];
                join_ends(a, b);
                join_ends(b, a); //TODO only perform for outgoing (lower) spaghetti link
            }

            //Test cycle
            int spaghetti = 0;
            for (size_t _ = 0; _ < bowl.size(); _++) {
                if (bowl[spaghetti].seen == true)
                    return false;
                else
                    bowl[spaghetti].seen = true;
                spaghetti = bowl[spaghetti].right;
            }
            
            return true;
        }


};

