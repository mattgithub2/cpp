#include <iostream>
#include <utility>
#include <vector>
#define NEWLINE std::cout << std::endl

template <class T, int N>
void bubble_sort(T (&array)[N], T i, T j, int end = N - 1) {
    if (end == 1) 
    { return; }

    if (j <= end) {
        if (array[i] > array[j])
            std::swap(array[i], array[j]);
        bubble_sort(array, i + 1, j + 1, end);
    } else {
        bubble_sort(array, 0, 1, end - 1);
    }
}
template <class T, int N>
int  linearSearch(T (&array)[N], T key, int i = 0) {
    if (i >= N) {
        return false;
    }

    return (array[i] == key) ? i : linearSearch(array, key, i + 1);
} 


template <class T, int N> int binarySearch(T (&array)[N], T key, int start = 0, int end = N - 1) {
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;

    if (array[mid] == key) {
        return mid;
    }
     
    if (array[mid] < key) {
        return binarySearch(array, key, mid + 1, end);
    } else {
        return binarySearch(array, key, start, mid - 1);
    }
    
}
std::vector<int> findall(std::vector<int> vec, int key, int i = 0) {
    std::vector<int> tv;
    if (i == static_cast<int>(vec.size())) {
        return {};
    }
    if (vec[i] == key) {
        tv.push_back(i);
    }
    std::vector<int> ttv = findall(vec, key, i + 1);

    tv.insert(tv.end(), ttv.begin(), ttv.end());

    return tv;
}

int main () {
    int array[7]  = {4,1,7,5,6,3,2};
    bubble_sort(array,0,1);
    for (const auto &i : array) {
        std::cout << i;
    }
    NEWLINE;
    std::cout << linearSearch(array, 3);
    NEWLINE;
    std::cout << binarySearch(array, 3);
    NEWLINE;

    std::vector<int> vec = {1,2,4,5,6,5};
    std::vector<int> ans = findall(vec, 5);
    for (const auto &i : ans) {std::cout << i << " " ;}
    return 0;
}
