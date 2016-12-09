/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval& a, Interval& b)
{
    if(a.start == b.start)
    {
        return a.end < b.end;
    }
    
    return a.start < b.start;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int length = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        
        for(int i = 1; i < length; i ++)
        {
            Interval& a = intervals[i - 1];
            Interval& b = intervals[i];
            
            if(a.start == b.start || b.start < a.end)
            {
                return false;
            }
        }
        
        return true;
    }
};