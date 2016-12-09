class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output;
        if(n == 0)
        {
            return output;
        }

        output.resize(n, vector<int> (n));
        
        int rows = n;
        int cols = n;
        int counter = 1;
        
        int i = 0, j = 0;
        rows --;
        cols --;
        
        while(true)
        {
            for(int y = j; y <= cols; y ++)
            {
                output[i][y] = counter ++;
            }
            
            i ++;
            
            if( rows < i)
            {
                break;
            }

            for(int x = i; x <= rows; x ++)
            {
                output[x][cols] = counter ++;
            }
            
            cols --;
            
            if(cols < j)
            {
                break;
            }
            
            for(int y = cols; y >= j; y --)
            {
                output[rows][y] = counter ++;
            }
            
            rows --;
            
            if( rows < i)
            {
                break;
            }
            
            for(int x = rows; x >= i; x--)
            {
                output[x][j] = counter ++;
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