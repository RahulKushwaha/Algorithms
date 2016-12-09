class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int length = nums.size();
        if(length == 0 || target == 0)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int dp[target + 1] = {0};
        dp[0] = 1;
        for(int i = nums[0]; i <= target; i ++)
        {
            for(int j = 0; j < length; j ++)
            {
                if(i - nums[j] >= 0)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        
        return dp[target];
    }
};