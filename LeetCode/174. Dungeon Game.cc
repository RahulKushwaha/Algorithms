class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int rows = dungeon.size();
        
        if(rows == 0)
        {
            return 0;
        }
        
        int cols = dungeon[rows - 1].size();
        int dp[rows + 1][cols + 1];
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                dp[i][j] = 0;
            }
        }
        
        for(int j = 0; j <= cols; j ++)
        {
            dp[rows][j] = INT_MAX;
        }
        
        for(int i = 0; i <= rows; i ++)
        {
            dp[i][cols] = INT_MAX;
        }
        
        dp[rows][cols - 1] = 0;
        dp[rows - 1][cols] = 0;
        
        for(int i = rows - 1; i >= 0; i --)
        {
            for(int j = cols - 1; j >= 0; j --)
            {
                dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 0);
            }
        }
        
        return dp[0][0] + 1;
    }
};