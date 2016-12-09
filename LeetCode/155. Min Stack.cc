class MinStack {
public:
    stack<int> min; 
    stack<int> nums;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        nums.push(x);
        
        if(min.empty())
        {
            min.push(x);    
        }
        else
        {
            if(min.top() > x)
            {
                min.push(x);
            }
            else
            {
                min.push(min.top());
            }
        }
    }
    
    void pop() {
        min.pop();
        nums.pop();
    }
    
    int top() {
        
        return nums.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */