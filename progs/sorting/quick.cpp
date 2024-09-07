#include <iostream>
#include <utility>

void quicksort(int array[], int n);
void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);

int main(int argc, char **argv){

        


    return 0;
}
void quicksort(int array[], int n) {
    quicksort(array, 0, n - 1);
}
void quicksort(int array[], int start, int end) {
    if (start < end) {

        int pivot_point = partition(array, start,end);

        quicksort(array, start, pivot_point - 1);
        quicksort(array, pivot_point + 1, end);
    }
}
int partition(int array[], int start, int end) {

    int mid = (start + end) / 2;

    std::swap(array[start], array[mid]);

    int pivot_index = start;
    int pivot_value = array[start];

    int scan = start + 1;

    while (scan <= end) {

       if (array[scan] < pivot_value) {
            pivot_index++;
            std::swap(array[pivot_index], array[scan]);
        }
        scan++;
    }
    std::swap(array[start], array[pivot_index]);

    return pivot_index;
}
