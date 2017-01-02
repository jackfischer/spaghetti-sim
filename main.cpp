#include <algorithm>
#include <iostream>
#include <vector>

class Spaghetti {
    public:
        int left;
        int right;
        bool seen;

        Spaghetti() : left(-1), right(-1), seen(false) {
            std::cout << "constructor" <<std::endl;
        }

};


class Bowl {
    public:
        std::vector<Spaghetti> bowl;
        std::vector<int> ends;

        Bowl(int n) : bowl(n) , ends(2*n) {
            for (int i = 0; i < 2*n; i++)
                ends[i] = i;
            std::random_shuffle(ends.begin(), ends.end());
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
};


int main() {
    const int num_spaghettis = 10;
    Bowl bowl(num_spaghettis);

    std::cout << bowl.bowl.size() <<std::endl;
    bowl.print_ends();
}




