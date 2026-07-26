class Solution {
public:
    bool isValid(string s) {
        int n  = s.size();
        stack<int> chars;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                chars.push(s[i]);
            } else if(s[i] == ')') {
                if(chars.empty() || chars.top() != '(') return false;
                chars.pop();
            } if(s[i] == '{') {
                chars.push(s[i]);
            } else if(s[i] == '}') {
                if(chars.empty() || chars.top() != '{') return false;
                chars.pop();
            } if(s[i] == '[') {
                chars.push(s[i]);
            } else if(s[i] == ']') {
                if(chars.empty() || chars.top() != '[') return false;
                chars.pop();
            } 
        }

        return chars.empty();
    }
};
