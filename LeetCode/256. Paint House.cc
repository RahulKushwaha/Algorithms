int min(int a, int b)
{
    return a < b ? a : b;
}

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        int houses = costs.size();
        if(houses == 0)
        {
            return 0;
        }
        
        for(int i = 1; i < houses; i ++)
        {
            for(int j = 0; j < 3; j ++)
            {
                switch(j)
                {
                    case 0: 
                    costs[i][j] += min(costs[i - 1][j + 1], costs[i - 1][j + 2]);
                    break;
                    
                    case 1: 
                    costs[i][j] += min(costs[i - 1][j - 1], costs[i - 1][j + 1]);
                    break;
                    
                    case 2: 
                    costs[i][j] += min(costs[i - 1][j - 1], costs[i - 1][j - 2]);
                    break;
                }
            }
        }
        
        int totalCost = INT_MAX;
        for(int j = 0; j < 3; j ++)
        {
            totalCost = min(totalCost, costs[houses - 1][j]);
        }
        
        return totalCost;
    }
};