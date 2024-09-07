#include <iostream>

void print(int row, int col) {
    if (row == 0) { 
        return;
    }

    if (col < row) {
        print(row, col + 1);
        std::cout << "*";
    } else {
        print(row - 1, 0);
        std::cout << std::endl;
    }
}
int main(int argc, char **argv){

    print(4,0);

    return 0;
}
