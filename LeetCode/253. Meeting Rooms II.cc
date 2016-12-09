/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval& i, Interval& j)
{
    if(i.start == j.start)
    {
        return i.end < j.end;
    }
    
    return i.start < j.start;
}

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int length = intervals.size();
        if(length == 0)
        {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < length; i ++)
        {
            Interval& newInterval = intervals[i];
            while(pq.empty() == false && pq.top() <= newInterval.start)
            {
                pq.pop();
            }
            
            pq.push(newInterval.end);
            
            ans = max(ans, (int)pq.size());
        }
        
        return ans;
    }
};