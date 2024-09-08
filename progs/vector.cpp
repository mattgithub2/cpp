#include "vector.h"
#include <iostream>
#include <algorithm>
#include <vector>


template<typename vector, typename Tp = typename vector::value_type>
inline auto print_data(vector& vec) -> void {
    std::for_each(vec.begin(), vec.end(), [](Tp elem){
            std::cout << elem << " ";
            });
    std::cout << std::endl;
}
template <typename Tp>
inline auto print_size(const Tp& vec) -> void {
    std::cout << "size: " << vec.size() << " Cap: " << vec.capacity() << "\n";

}

struct foo {
    int x, y;

    foo(int x=0, int y=0) : x(x), y(y) { }
};

inline std::ostream& operator<<(std::ostream& os, const foo& rhs) {
    std::cout << rhs.x << " " << rhs.y;
    return os;
}

// void foo(int x,char...) {
//
// }
std::vector<int> create_range() {
    return {1,2,3,4,5};
}
const std::vector<int>& f(const std::vector<int> &v) {
    return v;
}

// const is an exception for what? can create lvalue references to r-value if lvalue is const
int main(int argc, char **argv){
    std::vector<int> vec{1,2,3,4};
    std::vector<int> vec2{5,6,7,8,9};
    auto mff = vec2.erase(vec2.begin() + 1);
    std::cout << "LOOK HERE:" << *mff;

    foo(1,1);
    // vector<int> vec2 = {5,6,7,8};
    // vector<int> vec3(vec2);
    // vector<int> test(10,10);
    // vec3 = std::move(test);
    // vector<int> vec4(vec3);

    // // std vector reserve test
    // std::vector<int> size_test{1,2,3,4};
    // size_test.push_back(5);
    // // size_test.reserve(16);
    // print_size(size_test);
    // print_data(size_test);
    // // std vector resize size = 5 cap = 16
    // size_test.resize(100);
    // print_size(size_test); print_data(size_test);
    //
    // std::cout << "\n Testing our vector resize() and reserve()\n";
    // vector<int> size_test2{1,2,3,4};
    // size_test2.push_back(5);
    // // size_test2.reserve(16);
    // // print_size(size_test2);
    // // print_data(size_test2);
    // size_test2.resize(3);
    // print_size(size_test2);
    // print_data(size_test2);
    // std::vector<int>::iterator it64 = size_test.begin();
    // std::cout << *it64;
    // // int* array1 = new int[4];
    // // for (size_t i = 0; i < 4; ++i) { array1[i] = i + 1; }
    // // int* array2 = array1;
    // // std::cout << array2[1];
    // //
    // //
    // // delete[] array1;
    // // array2 = nullptr;
    // std::cout << "\n\n";
    //
    // // Testing Reserve with more complex types.
    // // vector<vector<int>> tr = {{1,2,3},{1,2,3}};
    // // tr.reserve(4);
    // // vector<vector<int>>::iterator it = tr.begin();
        // // std::cout << (*it)[0];
    // // size_test2.at(0) = 1000;
    // // std::cout << size_test2[0];
    // // std::cout << "Size: " << vec3.size() << "\n";
    // // std::cout << "Cap: " << vec3.capacity() << "\n";
    // // std::for_each(vec3.begin(),vec3.end(), [](int elem){
    // //         std::cout << elem << " "; });
    //
    //  std::cout << "\nTesting reverse Iterator: \n";
    //  // vector<int>::reverse_iterator rit = vec2.rbegin();
    //  // std::cout << *rit;
    //
    //  // std::for_each(vec2.rbegin(), vec2.rend(), [](int elem) {
    //  //         std::cout << elem << " "; });
    //
    //  // const int *p = nullptr; // pointer 
    //  // int const *p2 = nullptr;
    //  // int *const p3 = nullptr;
    //  // const int* const p4  = nullptr;
    //  // int const *const p5 = nullptr;
    // std::vector<int> it_test = {1,2,3,4};
    // auto it = it_test.begin();
    // auto it2 = it - it;
    // it2+= 1;
    // it2-=1;
    
    int* x = new int[4];
    int* tmp = x;
    int* tmp2 = x + 2;

    for (int* aux = x; aux < x+4; ++aux) {
        *aux = 1;
        std::cout <<"Here: " << *aux;
    }
    tmp = x - 2;

    std::vector<int> test = {1,2,3,4};
    auto testit = test.emplace(test.end(), 51);


    std::cout << "TESTING:" ; print_size(test); print_data( test );
    std::cout << "testit: " << *testit;

    std::cout << "\nTest before: "; print_size(test); print_data(test);
    test.assign(3, 42);
    std::cout << "Test after: "; print_size(test); print_data(test);


    std::vector<int>::iterator it = test.begin();
    std::vector<int>::iterator it2 = test.begin() + 2;
    ptrdiff_t offset = it2 - it;
    std::cout << "OFFSET: " << offset;

    vector<int> emplace_test = {1,2,3,4};
    auto iterator = emplace_test.end();
    emplace_test.emplace(iterator, 42);
    std::cout << "\nEMPLACE_TEST\n"; print_size(emplace_test); print_data(emplace_test);


    vector<foo> stp = {foo(1,2), foo(3,4)};

    stp.emplace(stp.begin(),1,2);
    struct foo tester(42,43);
    *(stp.emplace(stp.begin(), tester)) = {999,888};
    stp.emplace_back(25000,50000);
    std::cout << "TESTING BACK(): " << stp.back();

    std::cout << "\nPRINTING FOO\n"; print_data(stp);

    // std::vector<int>::iterator it2(std::move(it));
    it = test.begin();
    std::cout << "HERE->" << *(it.base()) << "\n";
    vector<int> vec4 = {1,2,3,4};
      
    vector<int>::iterator it3 = vec4.begin();
    vector<int>::iterator it4(std::move(it3));
    std::cout << *it3;

    std::tuple<int,float,char> tp;
    // it3 = 2 + it3;
    // it3 = it3 + 2;

    // Testing valid operations

    // (it > it2) ? NULL : NULL;
    // (it < it2) ? NULL : NULL;
    // (it != test.end()) ? NULL:NULL; 
    // (itit2)?NULL:NULL;
    // std::cout << (it > it2);


    delete[] x;
     


    it+=3;

    int i, j,k;
    i = j = 1;
    std::cout << i;
    
    std::initializer_list<int> l = {1,2,3};
    
    i = i - 1 - 1;
    std::cout << "\n\n";
    vector<int> vector1 = {1,2,3,4};
    std::cout << *(vector1.rbegin()) <<'\n';
     
    vector1.insert(vector1.begin(), 99);
    // vector1.assign(10,42);
    std::cout << "After: "; print_size(vector1); print_data(vector1);
    std::cout << "\n\n\n\n\n\n";
    std::vector<int> testvec = {1,2,3,4};

    print_size(testvec);
    testvec.resize(5);
    print_size(testvec);
    std::cout << "\n\n\n";
    vector<int> swap1 = {1,2,3,4};
    vector<int> swap2 = {5,6,7,8,9};
    std::cout << "Before swap: \n"; print_size(swap1); print_data(swap1);
    std::cout << "Before swap: \n"; print_size(swap2); print_data(swap2);
    swap1.swap(swap2);
    std::cout << "After swap: \n"; print_size(swap1); print_data(swap1);
    std::cout << "After swap: \n"; print_size(swap2); print_data(swap2);


    for (auto it = swap2.rbegin(); it != swap2.rend(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout <<"\n\n\n";
    vector<int> erase_test = {5,6,7,8,9};
    auto dat = erase_test.erase(erase_test.begin() + 1);
     

    vector<foo> foob;
    auto f = [&foob](auto&& item){
        foob.push_back(std::forward<decltype(item)>(item));
    };
    
    f(foo(1,2));
    print_data(foob);
        // print_data(erase_test);
    // std::cout << *dat;

}
// Resize:
// adds to the size of the vector, adding default values to the back of the vector to occupy extra space.
// If the new size is less than the current size, the vector gets shrunk down by popping elements from the back
// If the new size is greater than the capacity, then the reserve gets called with current capacity * 2

// Reserve:
// allocates more capacity for the vector,
// If the new capacity is less than the current capacity, then nothing is done
// If the new capacity is greater than the current capacity, then we change the capacity to that amount
//
