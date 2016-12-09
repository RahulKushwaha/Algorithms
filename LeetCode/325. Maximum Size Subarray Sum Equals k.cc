class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        
        int length = nums.size();
        
        int currentSum = 0;
        int ans = 0;
        
        for(int i = 0; i < length; i ++)
        {
            currentSum += nums[i];
            if(currentSum == k)
            {
                ans = max(ans, i + 1);
            }
            else
            {
                unordered_map<int, int>::iterator itr = lookup.find(currentSum - k);
                if(itr != lookup.end())
                {
                    ans = max(ans, i - itr->second);
                }
            }
            
            unordered_map<int, int>::iterator itr = lookup.find(currentSum);
            if(itr == lookup.end())
            {
                lookup.insert(pair<int, int>(currentSum, i));
            }
        }
        
        return ans;
    }
};