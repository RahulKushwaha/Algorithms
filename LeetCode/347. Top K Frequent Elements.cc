bool compare(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;    
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        if(nums.size() == 0)
        {
            return output;
        }
        
        unordered_map<int, int> freq;
        
        for(int i  = 0; i < nums.size(); i ++)
        {
            if(freq.find(nums[i]) == freq.end())
            {
                freq[nums[i]] = 1;
            }
            else
            {
                freq[nums[i]] ++;
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> pq (compare);
        
        for(unordered_map<int, int>::iterator itr = freq.begin(); itr != freq.end(); itr ++)
        {
            pq.push(pair<int, int>(itr->second, itr->first));
        }
        
        int counter = 0;
        while(pq.empty() != true && counter < k)
        {
            pair<int, int> top = pq.top();
            //cout<<top.first<<" "<<top.second<<endl;
            output.push_back(top.second);
            pq.pop();
            counter ++;
        }
        
        return output;
    }
};