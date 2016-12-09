/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int getInsertPosition(vector<Interval>& intervals, int target)
    {
        int l = 0;
        int h = intervals.size() - 1;
        
        while(l <= h)
        {
            int mid = ((h - l) / 2) + l;
            if(intervals[mid].end <= target)
            {
                l = mid + 1;
                if(l == h)
                {
                    break;
                }
            }
            else
            {
                h = mid - 1;
            }
        }
        
        return l;
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int length = intervals.size();
        
        int position = getInsertPosition(intervals, newInterval.start);

        if(length == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        if(position != length && ((intervals[position].start == newInterval.start && intervals[position].end < newInterval.end) ||
            intervals[position].start < newInterval.start))
        {
            intervals.insert(intervals.begin() + position + 1, newInterval);
        }
        else if(position == length)
        {
            intervals.push_back(newInterval);
        }
        else
        {
            intervals.insert(intervals.begin() + position, newInterval);
        }
        
        return merge(intervals);
    }
    
 vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0)
        {
            return intervals;
        }
        
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