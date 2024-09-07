#include <iostream>


void print(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j;
        for (j = i - 1; j >= 0 && array[j] > key; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = key;
    }
}

int main(int argc, char **argv){
    
    int array[8] = {2,3,4,1,6,5,7,8};
    int size = sizeof(array) / sizeof(array[0]);
    print(array, size);
    
    for (const auto & i : array) { std::cout << i << " ";}
    


    return 0;
}
