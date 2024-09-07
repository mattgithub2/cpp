#include <iostream>

[[nodiscard]] int f(int x) {

    if (x > 0) {
        return f(x-1) * x;
    }
    return x;
}
int main(int argc, char **argv){

    std::cout << f(3);


    return 0;
}
