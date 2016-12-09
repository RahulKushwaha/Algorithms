vector<pair<int, int>> directionOffsets {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& edges)
    {
        for(vector<pair<int, int>>::iterator itr = directionOffsets.begin(); itr != directionOffsets.end(); itr ++)
        {
            int i = x + itr->first;
            int j = y + itr->second;
            
            if(i >= rows || j >= cols || i < 0 || j < 0 || grid[i][j] == 0)
            {
                // The number of edges you discover during DFS can be summed up to give the total perimeter.
                edges ++;
                continue;
            }
            
            if(visited[i][j] == false)
            {
                visited[i][j] = true;
                dfs(grid, visited, i, j, edges);
            }
        }
    }
    
    int rows, cols;
    
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        if(rows == 0)
        {
            return 0;
        }
        
        cols = grid[0].size();
        
        if(cols == 0)
        {
            return 0;
        }
        
        vector<vector<bool>> visited (rows, vector<bool>(cols, false));
        
        int output = 0;
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(grid[i][j])
                {
                    visited[i][j] = true;
                    dfs(grid, visited, i, j, output);
                    return output;
                }
            }
        }
        
        return 0;
    }
};