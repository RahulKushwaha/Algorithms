class NumMatrix {
public:
    int ** bit;
    int ** grid;
    int row;
    int col;
    
    NumMatrix(vector<vector<int>> &matrix) {
        row = matrix.size();
        if(row == 0)
        {
            return;
        }
        
        col = matrix[row - 1].size();
        
        bit = new int*[row];
        for(int i = 0; i < row; i ++)
        {
            bit[i] = new int[col + 1];
            for(int j = 0; j <= col; j ++)
            {
                bit[i][j] = 0;
            }
        }
        
        
        grid = new int*[row];
        for(int i = 0; i < row; i ++)
        {
            grid[i] = new int[col];
            for(int j = 0; j < col; j ++)
            {
                grid[i][j] = 0;
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int i, int j, int val) {
        if(i >= row)
        {
            return ;
        }
        
        int diff = val - grid[i][j];
        grid[i][j] = val;
        
        j ++;
        int * gridRow = bit[i];
        while(j <= col)
        {
            gridRow[j] += diff;
            j = j + (j & (- j));
        }
    }
    
    int getSum(int i, int j)
    {
        int total = 0;
        j ++;
        
        int * gridRow = bit[i];
        while(j != 0)
        {
            total += gridRow[j];
            j = j - (j & (-j));
        }
        
        return total;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = 0;
        for(int i = row1; i <= row2 && i < row; i ++)
        {
            total += getSum(i, col2) - getSum(i, col1 - 1);
        }
        
        return total;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);