#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>

/* 
 * @Brief: Removes a word from a string
 * @Param: word Source string
 * @Param: remove the substring which will get removed from source
 * @param pos position of the first index in word
 *
 * @return the new string
 */

std::string removeWordInString(std::string word, std::string remove, int pos) {
    std::string newWord;
    if (pos == (int)word.length()) {
        return newWord;
    }
    newWord+= word[pos];
    
    newWord+= removeWordInString(word, remove,pos + 1);

    return (newWord.substr(0,remove.length()) == remove) ? newWord.substr(5, newWord.length() - 1) : newWord;
}

std::vector<std::string> subsets(std::string p, std::string up) {


    if (up.empty()) { 

        std::vector<std::string> sets;
        sets.push_back(p);
        return sets;
    }

    char ch = up[0];

    std::vector<std::string> left = subsets(p +ch, up.substr(1,up.length() - 1));
    std::vector<std::string> right = subsets(p, up.substr(1,up.length() - 1));
         

    left.insert(left.end(), right.begin(), right.end());
    return left;
}
    

int main(int argc, char **argv){
    
    // std::string word = "applehelloappleshushappleshush!";
    // std::string newString = removeWordInString(word, "apple", 0);
    // std::cout << newString; 
    // std::vector<std::string> vec = subsets("", "abc");
    // for (int i = 0; i < (int)vec.size(); i++) {
    //     std::cout << vec[i] << " ";
    // }
    
    return 0;
}
