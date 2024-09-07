#include <iostream>
#include <cstdarg>

// Function using varargs
void print(std::ostream& out, size_t n, ...){

    va_list tail;
    va_start(tail, n);
    while (n--) {
        out << va_arg(tail,int) << ", ";
    }
    va_end(tail);
    out << '\n';
}

void printstuff() {
    std::cout << std::endl;
}

// Function using template packs (variadic template)
template <typename Tp, typename... Args>
void printstuff(Tp const& head, const Args&... tail) {
    std::cout << head;
    if (sizeof...(tail)) {
        std::cout << ", ";
    }
    printstuff(tail...);
}

int main(int argc, char **argv){
    
    printstuff(1, 1.0, 'c', "Hello");

    return 0;
}
