/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval& x, Interval& y)
{
    if(x.start == y.start)
    {
        return x.end < y.end;
    }

    return x.start < y.start;
}
 
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() == 0)
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), compare);
        int j = 0;
        int output = 0;
        for(int i = 1; i < intervals.size(); i ++)
        {
            Interval& currentInterval = intervals[i];
            Interval& lastInterval = intervals[j];
            if(currentInterval.start < lastInterval.end)
            {
                output ++;
                if(currentInterval.end < lastInterval.end)
                {
                    j = i;
                }
            }
            else
            {
                j = i;
            }
        }
        
        return output;
    }
};