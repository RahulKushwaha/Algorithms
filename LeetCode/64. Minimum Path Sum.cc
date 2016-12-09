class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }
        
        for(int i = 1; i < grid.size(); i ++)
        {
            grid[i][0] += grid[i - 1][0];
        }
        
        for(int i = 1; i < grid[0].size(); i ++)
        {
            grid[0][i] += grid[0][i - 1];
        }
        
        for(int i = 1; i < grid.size(); i ++)
        {
            int limit = grid[i].size(); 
            for(int j = 1; j < limit; j ++)
            {
                grid[i][j] += (grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1]);
            }
        }
        
        return grid[grid.size() - 1][grid[grid.size() - 1].size() - 1];
    }
};