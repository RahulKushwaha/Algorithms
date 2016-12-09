class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> denominations(amount + 1, 0);
        
        for(int i = 1; i <= amount; i ++)
        {
            int minDenominations = INT_MAX;
            for(int j = coins.size() - 1; j >= 0; j --)
            {
                int currentAmount = i - coins[j];
                if(currentAmount >= 0 && denominations[currentAmount] != INT_MAX)
                {
                    int currentDenominations = denominations[currentAmount] + 1;
                    if(currentDenominations < minDenominations)
                    {
                        minDenominations = currentDenominations;
                    }
                }
            }
            
            denominations[i] = minDenominations;
        }
        
        return denominations[amount] == INT_MAX ? - 1: denominations[amount];
    }
};