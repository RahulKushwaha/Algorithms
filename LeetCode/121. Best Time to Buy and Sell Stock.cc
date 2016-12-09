class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
        {
            return 0;
        }
        
        int max = prices[prices.size() - 1];
        int maxProfit = 0;
        for(int i = prices.size() - 1; i >= 0; i --)
        {
            if(prices[i] > max)
            {
                max = prices[i];
            }
            else if(max - prices[i] > maxProfit)
            {
                maxProfit = max - prices[i];
            }
        }
        
        return maxProfit;
    }
};