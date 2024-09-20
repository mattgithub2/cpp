#include <numeric>
#include <vector>
#include <iostream>

struct multiply {
    int operator()(int x, int y) {
        return x * y;
    }
};
int main(int argc, char **argv){

    std::vector v = {1,2,3,4};
    std::cout << std::accumulate(v.begin(), v.end(), 0) << '\n';

    std::cout << std::accumulate(v.begin(), v.end(), 1, std::modulus<int>());;

    return 0;
}
