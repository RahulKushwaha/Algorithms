class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output;
        if(n == 0)
        {
            return output;
        }

        int rows = n;
        int cols = n;
        int counter = 1;
        
        for(int i = 0; i < rows; i ++)
        {
            vector<int> col;
            col.resize(cols);
            output.push_back(col);
        }
        
        for(int i = 0; i <= n / 2; i ++)
        {
            for(int a = i; a < cols - i - 1; a ++)
            {
                output[i][a] = counter++;
            }
            
            for(int a = i; a < rows - i - 1; a ++)
            {
                output[a][cols - i - 1] = counter ++;
            }
            
            for(int a = cols - i - 1; a > i; a --)
            {
                output[rows - i - 1][a] = counter ++;
            }
            
            for(int a = rows - i - 1; a > i; a--)
            {
                output[a][i] = counter ++;
            }
        }
        
        if(n % 2 != 0)
        {
            output[n / 2][n / 2] = counter;
        }
        
        return output;
    }
};