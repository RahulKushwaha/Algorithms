class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        for(int i = 0; i < nums.size(); i ++)
        {
            unordered_map<int, int>::iterator itr = freq.find(nums[i]);
            if(itr == freq.end())
            {
                freq.insert(make_pair(nums[i], i));
            }
            else
            {
                if(i - itr->second <= k)
                {
                    return true;
                }
                
                itr->second = i;
            }
        }
        
        return false;
    }
};