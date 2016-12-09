class Solution {
public:
    int getMedian(vector<int>& input)
    {
        int length = input.size();
        
        sort(input.begin(), input.end());
        
        int mid = length / 2;
        
        if(length % 2 == 0)
        {
            if(input[mid - 1] + 1 == input[mid])
            {
                return input[mid];
            }
            else
            {
                return (input[mid - 1] + input[mid]) / 2;
            }
        }
        
        return input[mid];
    }
    
    int minTotalDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0)
        {
            return 0;
        }

        int cols = grid[rows - 1].size();
        
        if(cols == 0)
        {
            return 0;
        }
        
        vector<int> rowCoordinates;
        vector<int> colCoordinates;
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(grid[i][j])
                {
                    rowCoordinates.push_back(i);
                    colCoordinates.push_back(j);
                }
            }
        }
        
        int rowMedian = getMedian(rowCoordinates);
        int colMedian = getMedian(colCoordinates);
        
        int totalDistance = 0;
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(grid[i][j])
                {
                    totalDistance += abs(i - rowMedian);
                    totalDistance += abs(j - colMedian);
                }
            }
        }
        
        return totalDistance;
    }
};