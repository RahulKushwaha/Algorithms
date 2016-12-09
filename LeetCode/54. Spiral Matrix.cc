class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int rows = matrix.size();
        if(rows == 0)
        {
            return output;
        }
        
        int cols = matrix[rows - 1].size();
        
        int i = 0, j = 0;
        rows --;
        cols --;
        while(true)
        {
            for(int y = j; y <= cols; y ++)
            {
                output.push_back(matrix[i][y]);
            }
            
            i ++;
            
            if( rows < i)
            {
                break;
            }

            for(int x = i; x <= rows; x ++)
            {
                output.push_back(matrix[x][cols]);
            }
            
            cols --;
            
            if(cols < j)
            {
                break;
            }
            
            for(int y = cols; y >= j; y --)
            {
                output.push_back(matrix[rows][y]);
            }
            
            rows --;
            
            if( rows < i)
            {
                break;
            }
            
            for(int x = rows; x >= i; x--)
            {
                output.push_back(matrix[x][j]);
            }
            
            j ++;
            
            if(cols < j)
            {
                break;
            }
        }
        
        return output;
    }
};