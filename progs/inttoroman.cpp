#include <iostream>
#include <string>
#include <map>

using std::string;
class solution {

public:
    int y = 0;
    solution()= default;

    static string intToRoman(int num) {
        string ans;

        std::map<int, string> mp = 
        {
            {1, "I"}, {4, "IV"}, {5,"V"}, {9, "IX"}, {10, "X"}, {40, "XL"},{50, "L"},{90, "XC"},{100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},{1000, "M"}
        };
        while (num > 0) {
            std::map<int, string>::iterator it;
            it = mp.find(num);
            if (it != mp.end()) {
                ans+= it->second;
                num-= it->first;
            } else {
               it = prev(mp.lower_bound(num)); 
                   ans+= it->second;
                   num-= it->first;
               }
            }
        return ans;
    }
};

std::string dtor(int num) {

        static std::map<int, string> mp = 
        {
            {1, "I"}, {4, "IV"}, {5,"V"}, {9, "IX"}, {10, "X"}, {40, "XL"},{50, "L"},{90, "XC"},{100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},{1000, "M"}
        };
        
        auto get_solution = [&](auto&& ff, auto num, auto it) -> std::string {
            if ((it = mp.find(num)) != mp.end()) {
                 
            }
        };
        std::map<int,string>::iterator it;
        std::string sol = get_solution(get_solution,num, it);


}

int main() {
    std::cout << solution::intToRoman(4569);

}

