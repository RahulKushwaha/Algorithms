class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int length = prices.size();
        if(length == 0)
        {
            return 0;
        }
        
        int * input = &prices[0];
        if(length <= k)
        {
            int total = 0;
            for(int i = 1; i < length; i ++)
            {
                int diff = input[i] - input[i - 1];
                if(diff > 0)
                {
                    total += diff;
                }
            }
            
            return total;
        }
        
        int **dp;
        dp = new int*[length];
        for(int i = 0; i < length; i ++)
        {
            dp[i] = new int[k + 1];
            for(int l = 0; l <= k ; l ++)
            {
                dp[i][l] = 0;
            }
        }
        
        for(int l = 1; l <= k; l ++)
        {
            int diff = INT_MIN;
            for(int i = 1; i < length; i ++)
            {
                diff = max(dp[i - 1][l - 1] - input[i - 1], diff);
                dp[i][l] = max(dp[i - 1][l], input[i] + diff); 
            }
        }
        
        return dp[length - 1][k];
    }
};