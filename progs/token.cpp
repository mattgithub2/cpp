#include <iostream>
#include <string>
#include <sstream>

#include <iostream>
#include <cstring>
int main(int argc, char **argv){

    // CPP Method
    std::string str = "Hello/This/is/a/test";

    std::stringstream ss(str);
    char delim = '/';
    std::string tmp;

    while (std::getline(ss, tmp, delim)) {
        ;
    }
    str=tmp;
    std::cout << str << "\n";
     
    // C method
    const char* path = "Hello/This/is/a/test";
    char * token = nullptr;
    char *Cstr;
    Cstr = new char[strlen(path) + 1];
    strcpy(Cstr, path);

    token = strtok(Cstr, "/");
    char *Last = token;

    while (token != nullptr) {
        Cstr = token;
        token = strtok(NULL, "/");
    }
    std::cout << Cstr << "\n";
    return 0;
}
