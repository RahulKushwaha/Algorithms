class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int rows = image.size();
        
        if(rows == 0)
        {
            return 0;
        }
        
        int cols = image[rows - 1].size();
        
        int left = INT_MAX, right = INT_MIN, top = INT_MAX, bottom = INT_MIN;
        
        for(int i = 0; i < rows; i ++)
        { 
            vector<char>& row = image[i];
            char * col = &row[0];
            for(int j = 0; j < cols; j ++)
            {
                if(*col == '1')
                {
                    top = min(top, i);
                    left = min(left, j);
                    right = max(right, j);
                    bottom = max(bottom, i);
                }
                
                col ++;
            }
        }
        
        return (bottom - top + 1) * (right - left + 1);
    }
};