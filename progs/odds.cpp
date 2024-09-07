#include <iostream>

int main(int argc, char **argv){
    double x = 0.04;
    size_t count = 0;
    while (x < 1.00) {
        ++count;
        x /= .60;
    }

    std::cout << count;
    return 0;
}
