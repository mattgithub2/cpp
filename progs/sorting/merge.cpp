#include <iostream>
#include <utility>
#include <cstdint>
#include <vector>

void mergesort(int array[], int n);
void mergesort(int array[],int start, int end);
void merge(int array[], int start, int mid, int end);

int main(int argc, char **argv){

    int array[10] = {2,7,5,1,3,4,6,8,9,10};
    uint16_t size = sizeof(array) / sizeof(array[0]);

    mergesort(array, size);
    for (const auto &i : array) {
        std::cout << i << " ";
    }

    return 0;
}

// Wrapper Function (called in main)
void mergesort(int array[], int n) {
    mergesort(array, 0, n - 1);
}
// Recursive function
void mergesort(int array[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(array, start, mid);
        mergesort(array, mid + 1, end);

        merge(array, start, mid, end);
    }
}

// Sorting happens here
void merge(int array[], int start, int mid, int end) {

    std::vector<int> temp(end - start + 1);

    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (array[i] < array[j]) {
            temp[k] = array[i];
            i++;
        } else {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = array[i];
        i++;
        k++;
    } while (j <= end) {
        temp[k] = array[j];
        j++;
        k++;
    }
    
    for (int i = 0; i < temp.size(); i++) {
        array[start + i] = temp[i];
    }
}

















