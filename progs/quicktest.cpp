#include <iostream>
#include <utility>

void quick_sort(int array[], int n);
void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);


int main() {
    int array[6] = {2,6,1,3,4,5};
    quick_sort(array, 6);
    for (const auto &i : array) {
        std::cout << i << ' ';
    }
}

void quick_sort(int array[], int n) {
    quick_sort(array, 0, n - 1);
}
void quick_sort(int array[], int start, int end) {
    if (start < end) {
        
        int pivot = partition(array, start, end);

        quick_sort(array,start, pivot - 1);
        quick_sort(array,pivot+1, end);
    }
}
int partition(int array[], int start, int end) {

    int mid = (start + end) / 2;
    std::swap(array[start], array[mid]);

    int pivot_point = array[start];
    int pivot_index = start;
    int scan = start + 1;

    while (scan <= end) {
        if (array[scan] < pivot_point) {
            pivot_index++;
            std::swap(array[scan], array[pivot_index]);
        }
        scan++;
   }
    std::swap(array[start], array[pivot_index]);
    return pivot_index;
}
