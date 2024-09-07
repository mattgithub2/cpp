#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::string;

class solution {

public:
    string s = "";
    solution() = default;

    int romantoInt(string s) {
        int solution = 0;

        std::unordered_map<char, int> mp = 
        {
            {'I', 1}, {'V',5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        for (int i = 0; i < (int)s.length(); i++) {
            std::unordered_map<char, int>::iterator it;


            bool sub = 0;
            switch (s[i]) {
                case 'I':
                    if (s[i + 1] == 'V' || s[i+1] == 'X') {
                        (s[i+1] == 'V') ? solution+=4 : solution+= 9;
                        i++; sub = 1;
                    }
                    break;
                case 'X':
                    if (s[i + 1] == 'L' || s[i+1] == 'C') {
                        (s[i+1] == 'L') ? solution+=40 : solution+= 90;
                        i++; sub = 1;
                    }
                    break;
                case 'C':
                    if (s[i + 1] == 'D' || s[i+1] == 'M') {
                        (s[i+1] == 'D') ? solution+=400 : solution+= 900;
                        i++; sub = 1;
                    }
                    break;
                default:
                    break;
            }

            if (sub == 0) {
                it = mp.find(s[i]);
                if (it != mp.end()) { 
                    solution+=it->second; 
                }
            }
        }

        return solution;
    }
};

int main() {

    solution x;
    x.s = "LVIII";
    int i = x.romantoInt(x.s);

    std::cout << i;

    return 0;
}

// If current char is 'I' and its not followed by another I or the last char; then
// we need to subtract one from the character infront
