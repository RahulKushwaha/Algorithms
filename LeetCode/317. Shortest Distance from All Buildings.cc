class Solution {
public:

    int bfs(vector<vector<int>>& grid, int **dp, int** building, int rows, int cols, int i, int j, bool** visited)
    {
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        q1.push(pair<int, int>(i, j));
        
        visited[i][j] = true;
        int depth = 0;
        
        queue<pair<int, int>>* current = &q1;
        queue<pair<int, int>>* next = &q2;
        int count = 0;
        
        while(current->empty() == false)
        {
            pair<int, int> top = current->front();
            int x = top.first; 
            int y = top.second;
            
            building[x][y] ++;
            
            if(x + 1 < rows)
            {
                if(grid[x + 1][y] == 0 && visited[x + 1][y] == false)
                {
                    next->push(pair<int, int>(x + 1, y));
                    //cout<<(x + 1)<<" "<<(y)<<endl;
                    visited[x + 1][y] = true;
                }
            }
            
            if(y + 1 < cols)
            {
                if(grid[x][y + 1] == 0 && visited[x][y + 1] == false)
                {
                    next->push(pair<int, int>(x, y + 1));
                    //cout<<(x)<<" "<<(y + 1)<<endl;
                    visited[x][y + 1] = true;
                }
            }
            
            if(x - 1 >= 0)
            {
                if(grid[x - 1][y] == 0 && visited[x - 1][y] == false)
                {
                    next->push(pair<int, int>(x - 1, y));
                    //cout<<(x - 1)<<" "<<(y)<<endl;
                    visited[x - 1][y] = true;
                }
            }

            if(y - 1 >= 0)
            {
                if(grid[x][y - 1] == 0 && visited[x][y - 1] == false)
                {
                    next->push(pair<int, int>(x, y - 1));
                    //cout<<(x)<<" "<<(y - 1)<<endl;
                    visited[x][y - 1] = true;
                }
            }
            
            current->pop();
            dp[top.first][top.second] += depth;
            count ++;
            
            if(current->empty())
            {
                if(current == &q1)
                {
                    current = &q2;
                    next = &q1;
                }
                else
                {
                    current = &q1;
                    next = &q2;
                }
                
                depth ++;
            }
        }
        
        return count;
    }
    
    void resetVisited(bool ** visited, int rows, int cols)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j ++)
            {
                visited[i][j] = false;
            }
        }
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0)
        {
            return 0;
        }
        
        int cols = grid[rows - 1].size();
        int buildingsCount = 0;
        
        int **dp;
        bool ** visited;
        int ** building;
        
        dp = new int*[rows];
        visited = new bool*[rows];
        building = new int*[rows];
        for(int i = 0; i < rows; i ++)
        {
            dp[i] = new int[cols];
            visited[i] = new bool[cols];
            building[i] = new int[cols];
            for(int j = 0; j < cols; j ++)
            {
                dp[i][j] = 0;
                building[i][j] = 0;
                if(grid[i][j] == 1)
                {
                    buildingsCount ++;
                }
            }
        }
        
        int count = -1;
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(grid[i][j] == 1)
                {
                    resetVisited(visited, rows, cols);
                    bfs(grid, dp, building, rows, cols, i, j, visited);
                }
            }
        }
        
        int minimal = INT_MAX;
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(building[i][j] == buildingsCount && grid[i][j] == 0 && dp[i][j] < minimal)
                {
                    minimal = dp[i][j];
                }
            }
        }
        
        return (minimal == INT_MAX) ? -1 : minimal;
    }
};