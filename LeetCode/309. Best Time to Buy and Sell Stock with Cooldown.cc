class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        
        if(length == 0 || length == 1)
        {
            return 0;
        }
        
        int dp[length] = {0};
        for(int i = 1; i < length; i ++)
        {
            int cost = 0;
            for(int j = 0; j < i; j ++)
            {
                cost = max(cost, prices[i] - prices[j] + (j - 2 >= 0 ? dp[j - 2] : 0));
            }
            
            cost = max(cost, dp[i - 1]);
            
            dp[i] = cost;
        }
        
        return dp[length - 1];
    }
};