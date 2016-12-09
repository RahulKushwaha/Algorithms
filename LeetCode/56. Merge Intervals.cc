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
 vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0)
        {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), compare);
        int j = 0;
        for(int i = 1; i < intervals.size(); i ++)
        {
            Interval& currentInterval = intervals[i];
            Interval& lastInterval = intervals[j];
            if(currentInterval.start <= lastInterval.end)
            {
                lastInterval.end = currentInterval.end > lastInterval.end? currentInterval.end : lastInterval.end;
            }
            else
            {
                j ++;
                intervals[j] = currentInterval;
            }
        }

         intervals.resize(j + 1);
         
         return intervals;
    }
};