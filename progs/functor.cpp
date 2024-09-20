#include <iostream>
#include <vector>
#include <print>
#include <algorithm>
struct functor {
int sum;

functor(int sum = 0) : sum(sum) { }

auto operator()(int x) -> void {
    sum+=x;
}
void print_sum() const {
    std::cout << sum;
}

};
int main(int argc, char **argv){

    std::vector<int> v = {1,2,3,4};
    auto it = v.rbegin();
    std::cout << *(++it);

    std::print("\n{0} {1} {2}", 1,2,3);
    
    // temp.print_sum();
    return 0;
}
