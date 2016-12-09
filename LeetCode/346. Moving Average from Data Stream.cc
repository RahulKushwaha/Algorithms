class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int limit; 
    int sum;
    
    MovingAverage(int size) {
        limit = size; 
        sum = 0;
    }
    
    double next(int val) {
        if(q.size() == limit)
        {
            sum -= q.front();
            q.pop();
        }
        
        sum += val;
        q.push(val);
        
        double result = (double)sum / (double)q.size();
        return result;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */