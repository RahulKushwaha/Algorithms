class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int length = nums.size();
        
        if(length == 0)
        {
            return 0;
        }
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int * input = &nums[0];
        
        int dp[length + 2][length + 2] = {0};
        
        for(int i = 1; i <= length; i ++)
        {
            dp[i][i] = input[i - 1] * input[i] * input[i + 1];
        }

        for(int len = 1; len < length; len ++)
        {
            for(int i = 1; i + len <= length; i ++)
            {
                int j = i + len;
                int cost = 0;
                for(int k = i + 1; k <= j - 1; k ++)
                {
                    cost = max(cost, dp[i][k - 1] + dp[k + 1][j] + input[i - 1] * input[k] * input[j + 1]);
                }
                
                cost = max(cost, input[i - 1] * input[i] * input[j + 1] + dp[i + 1][j]);
                cost = max(cost, input[i - 1] * input[j] * input[j + 1] + dp[i][j - 1]);
                
                dp[i][j] = cost;
            }
        }

        return dp[1][length];
    }
};