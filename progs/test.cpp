#include <iostream>
#include <string>

class Solution {
  public:
    int convertToSum(int n) {

        if (n <= 0) {
            return 0;
        }

        int num = (n % 10) + convertToSum(n / 10);
        
        return num;
    }
    int isDigitSumPalindrome(int n) {
        // code here
        std::string sum;
        sum+=(char)('0' + convertToSum(n));
        std::cout << sum;
        for (int i = 0, j = sum.length() - 1; i < j; i++, j--) {
            if (sum[i] != sum[j]) {
                return 0;
            }
        }
        return 1;
    }
};

int main() {
    Solution x;
    std::cout << x.isDigitSumPalindrome(98);
}
