#include <iostream>
#include <utility>
#include <cstdint>

void sort(int array[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j+1]);
                swapped =true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

void rec(int array[], int i, int j) {
    if (i == 0)
        return;

    if (j < i) {
        if (array[j] > array[j+1]) {
            std::swap(array[j], array[j+1]);
        }
        rec(array, i, j + 1);
    } 
    else {
        rec(array, i - 1, 0);
    }
}
void selection(int array[], int i, int j, int max) {

    if (i < 1)
        return;

    if (j >= 0) {
        if (array[j] > array[max]) {
            max = j;
        }
        selection(array, i, j - 1, max);

    } else {
        std::swap(array[i], array[max]);
        selection(array, i - 1, i - 2, i - 1);
    }
}

int main(int argc, char **argv){

    int array[8] = {2,6,3,1,4,5,7,8};
    uint16_t size = sizeof(array) / sizeof(array[0]);

    sort(array, size);

    for (const auto &i : array) { std::cout << i << ""; }
    std::cout << std::endl;

    std::cout << std::endl;

    int array2[8] = {2,6,3,1,4,5,7,8};
    selection(array2, size - 1, size - 2, size - 1);
    for (const auto &i : array2) { std::cout << i << ""; }
    return 0;
}
