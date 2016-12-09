class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        
        if(nums.size() == 1)
        {
            return 1;
        }
        
        vector<int> lookup;
        lookup.resize(nums.size());
        
        lookup[0] = 1;
        for(int i = 1; i < nums.size(); i ++)
        {
            int max = INT_MIN;
            for(int j = 0; j < i; j ++)
            {
                if(nums[j] < nums[i])
                {
                    if(lookup[j] > max)
                    {
                        max = lookup[j];
                    }
                }
            }
            
            if(max == INT_MIN)
            {
                lookup[i] = 1;
            }
            else
            {
                lookup[i] = max + 1;
            }
        }
        
        int max = INT_MIN;
        for(int i = 0; i < lookup.size(); i ++)
        {
            if(lookup[i] > max)
            {
                max = lookup[i];
            }
        }
        
        return max;
    }
};