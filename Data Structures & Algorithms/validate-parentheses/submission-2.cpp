class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // Odd length strings can't be valid
        
        stack<char> par;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                par.push(c); // Push opening parentheses onto the stack
            } else {
                // Check if the stack is empty before accessing its top
                if (par.empty()) return false;
                
                char top = par.top();
                if ((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '[')) {
                    return false; // Mismatched parentheses
                }
                par.pop(); // Pop the matching opening parenthesis
            }
        }
        return par.empty(); // Return true if the stack is empty
    }
};
