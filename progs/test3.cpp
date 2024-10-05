#include <vector>
#include <iostream>
#include <numeric>
#include <map>
#include <string>
#include <functional>
#include <execution>



int main(int argc, char **argv){

    auto print_container = [](const auto& container) {
        std::ranges::for_each(container, [](const auto& elem){
                std::cout << elem << ' ';
                });
        std::cout << "\n\n";
    };
    
    std::vector v1 = {1,2,3,4,5};
    std::vector v2 = {6,7,8,9,10};

    // int x = std::reduce(std::next(v1.begin()),v1.end(), *v1.begin(), std::minus()); 
    
    // Testing inner_product
    int x = std::inner_product(v1.begin(), v1.end(), v2.begin(),0);
    
    std::cout << x << "\n";

    // Testing std::rotate
    std::rotate(v1.begin(), v1.begin() + 3, v1.end());
    print_container(v1);

    // Testing stable_partition
    std::vector v3 = {1,0,1,0,1,0,1,0};
    std::stable_partition(v3.begin(),v3.end(), [](const auto &element) {
                return (element > 0);
            });
    print_container(v3);

    std::vector v4 = {1,0,1,0,1,0,1,1,1}; // zeros in the middle
    auto v4_mid = v4.begin() + v4.size() / 2;

    
    std::stable_partition(v4.begin(), v4_mid, [](const auto& elem) {
                return elem != 0;
            });
    std::stable_partition(v4_mid, v4.end(), [](const auto& elem){
                return elem == 0;
            });
    print_container(v4);


    return 0;
}
