class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.size() == 0)
        {
            return result;
        }
        
        for(int i = 0; i < grid.size(); i ++)
        {
            for(int j = 0; j < grid[i].size(); j ++)
            {
                if(grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    result ++;
                    numIslands(grid, i, j);
                }
            }
        }
        
        return result;
    }
    
    bool next(vector<vector<char>>& grid, int i, int j, int& x, int& y)
    {
        int r = grid.size(); 
        int c = grid[grid.size() - 1].size();
        
        x = i; 
        y = j;
        bool result = false;
        
        if(i + 1 < r)
        {
            x = i + 1;
            y = j;
            if(grid[x][y] == '1')
            {
                return true;
            }
        }
        
        if(i - 1 >= 0)
        {
            x = i - 1; 
            y = j;
            if(grid[x][y] == '1')
            {
                return true;
            }
        }
        
        if(j - 1 >= 0)
        {
            x = i;
            y = j - 1;
            if(grid[x][y] == '1')
            {
                return true;
            }
        }
        
        if(j + 1 < c)
        {
            x = i;
            y = j + 1;
            if(grid[x][y] == '1')
            {
                return true;
            }
        }
        
        return false;
    }
    
    void numIslands(vector<vector<char>> & grid, int i, int j)
    {
        stack<pair<int, int>> elements;
        elements.push(pair<int, int>(i, j));
        grid[i][j] = '0';
        while(elements.empty() == false)
        {
            pair<int, int> top = elements.top();
            int x, y;
            if(next(grid, top.first, top.second, x, y))
            {
                grid[x][y] = '0';
                elements.push(pair<int, int>(x, y));
                continue;
            }
            
            grid[top.first][top.second] = '0';
            elements.pop();
        }
    }
};