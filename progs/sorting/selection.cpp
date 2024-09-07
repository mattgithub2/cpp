#include <iostream>
#include <utility>


void sort(int array[], int n) {
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(array[minIndex], array[i]);
        }
    }
}
int main(int argc, char **argv){
    
    int array[10] = {2,3,6,1,9,8,7,5,4,10};

    int size = sizeof(array) / sizeof(int);
    sort(array, size);
    for (const auto &i : array) {
        std::cout << i << " ";
    }


    return 0;
}
