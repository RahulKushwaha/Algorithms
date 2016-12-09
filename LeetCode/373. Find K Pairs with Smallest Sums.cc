typedef vector<int>::iterator I;
class Compare
{
    public:
    bool operator()(pair<int, pair<I, I>>& x, pair<int, pair<I, I>>& y)
    {
        return x.first > y.first;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int lengthA = nums1.size();
        int lengthB = nums2.size();
        vector<pair<int, int>> output;
        
        if(lengthA == 0 || lengthB == 0)
        {
            return output;
        }
        
        
        priority_queue<pair<int, pair<I, I>>, vector<pair<int, pair<I, I>>>, Compare> pq;
        
        vector<int>::iterator nums2Itr = nums2.begin();
        for(vector<int>::iterator itr = nums1.begin(); itr != nums1.end(); itr++)
        {
            pq.push(make_pair(*nums2Itr + *itr, make_pair(itr, nums2Itr)));
        }
        
        while(k != 0 && pq.empty() == false)
        {
            pair<int, pair<I, I>> top = pq.top();
            output.push_back(make_pair(*(top.second.first), *(top.second.second)));
            
            pq.pop();
            k --;
            top.second.second ++;
            if(top.second.second != nums2.end())
            {
                top.first = *top.second.first + *top.second.second;
                pq.push(top);
            }
        }
        
        return output;
    }
};