#include <iostream>
#include <vector>

using namespace std;

void merge_sort(int array[], int n);
void merge_sort(int array[], int start, int end);
void merge(int array[], int start, int mid, int end);
int main() {
    int array[6] = {4,8,16,1,3,5};

    merge_sort(array,6);

    for (const auto &i : array) { std::cout << i << ' ';}
}


void merge_sort(int array[], int n) {
    merge_sort(array, 0, n -1);
}
void merge_sort(int array[], int start, int end) {

    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);

        merge(array, start, mid, end);

    }
}
void merge(int array[], int start, int mid, int end) {

    vector<int> vec(end - start + 1);

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (array[i] < array[j]) {
            vec[k] = array[i];
            i++;
        } else {
            vec[k] = array[j];
            j++;
        }
        ++k; 
    }
    while (i <= mid) {
        vec[k] = array[i];
        i++; k++;
    }
    while (j <= end) {
        vec[k] = array[j];
        j++; k++;
    }
    for (int i = 0; i < (int)vec.size(); i++) {
        array[start + i] = vec[i];
    }
}

