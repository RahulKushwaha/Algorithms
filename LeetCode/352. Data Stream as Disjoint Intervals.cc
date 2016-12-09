/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    set<int> nums;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        nums.insert(val);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> output;
        if(nums.size() == 0)
        {
            return output;
        }
        
        int startVal = *(nums.begin());
        int lastVal = startVal;
        
        for(set<int>::iterator itr = nums.begin(); ; itr ++)
        {
            if(itr != nums.end())
            {
                if(*itr == lastVal + 1 || *itr == lastVal)
                {
                    lastVal = *itr;
                    continue;
                }
            }
            
            Interval interval(startVal, lastVal);
            output.push_back(interval);
            
            if(itr == nums.end())
            {
                break;
            }
                        
            startVal = *itr;
            lastVal = *itr;
        }
        
        return output;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */