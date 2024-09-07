#include <limits>
#include <iostream>
#include <cstdint>
#include <vector>

std::vector<int> findAllIndex2(const int arr[], int target, int index, int size) {

    std::vector<int> list;

    if (index == size) {
        return list; 
    }

    if (arr[index] == target) {
        list.push_back(index);
    }

    std::vector<int> ansFromBelowCalls = findAllIndex2(arr, target, index + 1, size);

    list.insert(list.end(), ansFromBelowCalls.begin(), ansFromBelowCalls.end());

    return list;
}

int main(int argc, char **argv){

    const int arr[6] = {1,2,4,5,4,6};

    std::vector<int> vec = findAllIndex2(arr, 4, 0, 6);
    for (const auto &i : vec) { std::cout << i ;}
}
