#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        vector<string> result;
        for (int i = 0; i < n; i++) {
            vector<string> lefts = generateParenthesis(i);
            vector<string> rights = generateParenthesis(n - 1 - i);
            for (const auto &left : lefts) {
                for (const auto &right : rights) {
                    result.push_back("(" + left + ")" + right);
                }
            }
        }
        return result;
    }
};
