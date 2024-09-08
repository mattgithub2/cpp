#include <iostream>
#include <algorithm>
#include <vector>
#include <ostream>
struct foo {
    int x;

    foo(int x = 0) : x(x) { }
        
};

template <typename T>
void print(T arg) {
    std::cout << arg;
}
std::ostream& operator<<(std::ostream &os, const foo &l) {
    os << l.x << " ";

    return os;
}
int main(int argc, char **argv){

    foo *a = new foo[5];
    foo *ptr = a;
    int num  = 0;
    for (; ptr != a+5; ++ptr) {
        *ptr = foo(num); ++num;
    }

    std::for_each(a,a+5,[](foo elem){ 
            std::cout << elem;});
    
    std::cout << "\n";
    a[3].~foo();

    std::vector<int> v = {1,2,3,4};
    std::ranges::for_each(v,[](const int &elem){ 
            std::cout << elem;});

    std::invoke([] (){ std::cout << "HEllo"; });



    std::cout << "\n";

    auto print = [] (auto&&... args) {

        auto f = [](auto& ff, auto&& head, auto&&... tail) -> void {

            std::cout << head;
            if constexpr (sizeof...(tail)) {
                std::cout << "\n";
                ff(ff,std::forward<decltype(tail)>(tail)...);
            }
        };
        
        f(f, std::forward<decltype(args)>(args)...);

    };
    print(1, "Hello", "Theres no way this works");
    delete[] a;
    return 0;
}
