class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.push(first+second);
            } else if(tokens[i] == "-") {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.push(first-second);
            } else if(tokens[i] == "*") {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.push(first*second);
            } else if(tokens[i] == "/") {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.push(first/second);
            } else {
                nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};
