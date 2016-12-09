class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> low;
    priority_queue<int, vector<int>, greater<int>> high;
    // Adds a number into the data structure.
    void addNum(int num) {
        if(low.size() == 0)
        {
            low.push(num);
            return;
        }

        if(num <= low.top())
        {
            low.push(num);
        }
        else
        {
            high.push(num);
        }
        
        int lowSize = low.size();
        int highSize = high.size();
        
        if(abs(lowSize - highSize) > 1)
        {
            if(lowSize > highSize)
            {
                high.push(low.top());
                low.pop();
            }
            else
            {
                low.push(high.top());
                high.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        
        int lowSize = low.size();
        int highSize = high.size();
        
        double result; 
        if(lowSize == highSize)
        {
            result = ((double)(low.top() + high.top())) / 2;
        }
        else if(lowSize > highSize)
        {
            result = low.top();
        }
        else
        {
            result = high.top();
        }
        
        return result;
        
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();