#include "vector.h"
#include <iostream>

struct foo {

    int x;

    foo(int x = 0) : x(x) {}

    foo(const foo &rhs) {
        std::cout << "called\n";
        this->x = rhs.x;
    }

    foo& operator=(const foo &rhs) {
        std::cout << "called assignment";
        this->x = rhs.x;
        return *this;
    }
};
int main(int argc, char **argv){

    vector<int> v(vector<int>{1,2,3,4});
    vector<int> v2(vector<int>{1,2,3,4});

    v = vector<int>({1,2,3,4});

    foo f1(3), f2(4);
    // f1 = f2; // OK.
    

    f1 = foo(99); // You can pass r-values to operator= that wants an lvalue?
    foo f3(foo(1));

    std::cout << f1.x;

    // v = {1,2,3,4,5};

    for (const auto i : v) {
        std::cout << i << ", ";
    }
    return 0;
}
