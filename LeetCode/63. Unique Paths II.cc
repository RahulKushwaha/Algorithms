class Solution {
public:
    void print(vector<vector<int>>& grid)
    {
        for(int i = 0; i < grid.size(); i ++)
        {
            for(int j = 0; j < grid[grid.size() - 1].size(); j ++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"---------------"<<endl;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0)
        {
            return 0;
        }
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[obstacleGrid.size() - 1].size();
        
        for(int i = 0; i < row; i ++)
        {
            for(int j = 0; j < col; j ++)
            {
                if(obstacleGrid[i][j])
                {
                    obstacleGrid[i][j] = -1;
                }
            }
        }
        
        //print(obstacleGrid);
        
        for(int i = 0; i < row; i ++)
        {
            if(obstacleGrid[i][0] == 0)
            {
                obstacleGrid[i][0] = 1;
            }
            else
            {
                break;
            }
        }
        
        //print(obstacleGrid);
        
        for(int j = 0; j < col; j ++)
        {
            if(obstacleGrid[0][j] == 0)
            {
                obstacleGrid[0][j] = 1;
            }
            else if(obstacleGrid[0][j] == -1)
            {
                break;
            }
        }
        
        //print(obstacleGrid);
        
        for(int i = 1; i < row; i ++)
        {
            for(int j = 1; j < col; j ++)
            {
                if(obstacleGrid[i][j] == -1)
                {
                    continue;
                }
                
                int top = obstacleGrid[i][j - 1];
                int left = obstacleGrid[i - 1][j];
                if(top == -1 && left == -1)
                {
                    obstacleGrid[i][j] = 0;
                }
                else if(top == -1)
                {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j];
                }
                else if(left == -1)
                {
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1];
                }
                else
                {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
                
                //print(obstacleGrid);
            }
        }
        
        return obstacleGrid[row - 1][col - 1] == -1 ? 0 : obstacleGrid[row - 1][col - 1];
    }
};