class MinStack {
public:

    stack<int> nums;
    stack<int> mins;
    int currMin;

    MinStack() {
        currMin = INT_MAX;
    }
    
    void push(int val) {
        nums.push(val);
        if(mins.empty())
            mins.push(val);
        else 
            mins.push(min(val, mins.top()));
    }
    
    void pop() {
        nums.pop();
        mins.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
