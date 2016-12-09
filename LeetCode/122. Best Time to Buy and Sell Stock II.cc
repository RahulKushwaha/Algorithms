class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        
        int length = prices.size();
        if(length > 0)
        {
            int * input = &prices[0];
            
            for(int i = 1; i < length; i ++)
            {
                if(input[i] > input[i - 1])
                {
                    total += input[i] - input[i - 1];
                }
            }
        }
        
        return total;
    }
};