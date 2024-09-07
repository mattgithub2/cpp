#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
class Data {
public:
    struct equipment {
        double radius;
        size_t size;
        equipment(double radius = 0.0) : radius(radius) { }
    }; 
    
    double total_area();

private:
    std::vector<equipment> pipes;
    std::vector<equipment> hoses;
};

int main(int argc, char **argv){

    


    return 0;
}
// Multi step function
// double Data::total_area() {
//     double value = 0;
//
//     // step 1: pipe area
//     for (int i = 0; i < pipes.size(); ++i) {
//         value+= pipes[i].radius * pipes[i].radius * M_PI;
//     }
//     // step 2: hoses area
//     for (int i = 0; i < pipes.size(); ++i) {
//         value+= hoses[i].radius * hoses[i].radius * M_PI;
//     }
//     return value;
// }
//
constexpr double area(const double r) { return r * r * M_PI; }

double Data::total_area() {
    const auto accumulate_area = [](const auto lhs, const auto rhs) {
        return lhs + area(rhs);
    };
    const auto total_area = [&](const auto &container) {
        return std::accumulate(begin(container), end(container), 0.0, accumulate_area);
    };
    return total_area(pipes) + total_area(hoses); 
}
