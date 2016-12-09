class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
        {
            return 0;
        }
        
        int lastRow = triangle.size() - 1;
        
        if(lastRow == 0)
        {
            return triangle[0][0];
        }
        
        for(int i = 1; i < triangle.size();i ++)
        {
            for(int j = 0; j < triangle[i].size(); j ++)
            {
                cout<<i<<" "<<j<<endl;
                if(j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else if (j == triangle[i].size() - 1)
                {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else
                {
                    triangle[i][j] += triangle[i - 1][j] < triangle[i - 1][j - 1] ?  triangle[i - 1][j] : triangle[i - 1][j - 1];
                }
            }
        }
        
        int min = INT_MAX;
        
        for(int i = 0; i < triangle[lastRow].size(); i ++)
        {
            if(triangle[lastRow][i] < min)
            {
                min = triangle[lastRow][i];
            }
        }
        
        return min;
    }
};