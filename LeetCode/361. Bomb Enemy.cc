class Solution {
public:

    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rows = grid.size();
        
        if(rows == 0)
        {
            return 0;
        }
        
        int cols = grid[rows - 1].size();
        
        int dp[rows][cols];
        int dp1[rows][cols];
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(grid[i][j] == 'E')
                {
                    dp[i][j] = 1;
                    dp1[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                    dp1[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 1; j < cols; j ++)
            {
                if(grid[i][j] != 'W')
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }

            for(int j = cols - 2; j >= 0; j --)
            {
                if(grid[i][j] != 'W')
                {
                    dp[i][j] = max(dp[i][j + 1], dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
 
        for(int j = 0; j < cols; j ++)
        {
            for(int i = 1; i < rows; i ++)
            {
                if(grid[i][j] != 'W')
                {
                    dp1[i][j] += dp1[i - 1][j];
                }
            }
            
            for(int i = rows - 2; i >= 0; i --)
            {
                if(grid[i][j] != 'W')
                {
                    dp1[i][j] = max(dp1[i][j], dp1[i + 1][j]);
                }
                else
                {
                    dp1[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(grid[i][j] == '0')
                {
                    ans = max(ans, dp1[i][j] + dp[i][j]);
                }
                
                //cout<<(dp[i][j] + dp1[i][j])<<" ";
            }
            //cout<<endl;
        }
        
        return ans;
    }
};