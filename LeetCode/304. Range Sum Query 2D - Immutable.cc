class NumMatrix {
public:

    vector<vector<int>> lookup;
    int x;
    int y;
    
    NumMatrix(vector<vector<int>> &matrix) {
        x = 0;
        y = 0;
        
        int rows = matrix.size();
        x = rows;
        
        if(rows == 0)
        {
            return;
        }
        
        int cols = matrix[rows - 1].size();
        y = cols;
        
        lookup.resize(rows);
        
        for(int i = 0; i < rows; i ++)
        {
            vector<int> row; 
            row.resize(cols);
            
            int runningSum = 0;
            for(int j = 0; j < cols; j ++)
            {
                runningSum += matrix[i] [j];
                row[j] = runningSum;
            }
            
            lookup[i] = row;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int totalSum = 0;
        
        if(col1 == 0)
        {
            for(int i = row1; i <= row2; i ++)
            {
                totalSum += lookup[i][col2];
            }
            
            return totalSum;
        }
        
        for(int i = row1; i <= row2; i ++)
        {
            totalSum += lookup[i][col2] - lookup[i][col1 - 1];
        }
        
        return totalSum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);