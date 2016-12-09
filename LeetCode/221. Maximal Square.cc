int min(int a, int b)
{
    return a < b ? a : b;
}

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        if(rowSize ==  0)
        {
            return 0;
        }
        
        int colSize = matrix[rowSize - 1].size();
        
        vector<vector<int>> grid;
        for(int i = 0; i < rowSize; i ++)
        {
            vector<int> row; 
            row.resize(colSize);
            grid.push_back(row);
            
            for(int j = 0; j < colSize; j ++)
            {
                grid[i][j] = matrix[i][j] == '0' ? 0 : 1;
            }
        }
        
        for(int i = 1; i < rowSize; i ++)
        {
            for(int j = 1; j < colSize; j ++)
            {
                if(grid[i][j])
                {
                    grid[i][j] = min(min(grid[i - 1][j], grid[i][j - 1]), grid[i - 1][j - 1]) + 1;
                }
            }
        }
        
        int max = 0;
        
        for(int i = 0; i < rowSize; i ++)
        {
            for(int j = 0; j < colSize; j ++)
            {
                if(grid[i][j] > max)
                {
                    max = grid[i][j];
                }
            }
        }
        
        return max * max;
    }
};