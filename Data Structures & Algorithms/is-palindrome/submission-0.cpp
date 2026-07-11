#include <string>
#include <algorithm>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string cleaned_s;
        for (char c: s) {
            if (std::isalnum(c)) {
                cleaned_s += std::tolower(c);
            }
        }
        std::string reversed_s = cleaned_s;
        std::reverse(reversed_s.begin(), reversed_s.end());
        return cleaned_s == reversed_s;
    }
};