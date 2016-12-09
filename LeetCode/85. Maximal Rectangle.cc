class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        
        if(rows == 0)
        {
            return 0;
        }
        
        int cols = matrix[rows - 1].size();
        
        vector<vector<int>> grid;
        int ans = 0;
        for(int i = 0; i < rows; i ++)
        {
            vector<int> row;
            row.resize(cols, 0);
            grid.push_back(row);
            for(int j = 0; j < cols; j ++)
            {
                if(matrix[i][j] == '1')
                {
                    int count = 0;
                    if(i - 1 >= 0 && matrix[i - 1][j] == '1')
                    {
                        count += grid[i - 1][j];
                    }
                    
                    grid[i][j] = count + 1;
                }
            }
            
            ans = max(ans, largestRectangleArea(grid[i]));
        }
        
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        
        if(length == 0)
        {
            return 0;
        }
        
        heights.push_back(INT_MIN);
        
        stack<int> elements;
        int maxArea = 0;
        int i = 0;
        for(; i <= length; )
        {
            if(elements.empty())
            {
                elements.push(i++);
            }
            else
            {
                if(heights[elements.top()] <= heights[i])
                {
                    elements.push(i++);
                }
                else
                {
                    int area = INT_MIN;
                    int top;
                    while(elements.empty() == false && heights[elements.top()] > heights[i])
                    {
                        top = elements.top();
                        elements.pop();
                        int base = elements.empty() ? i : i - elements.top() - 1;
                        int currentArea = heights[top] * base;
                        if(currentArea > maxArea)
                        {
                            maxArea = currentArea;
                        }
                    }
                    
                    if(elements.empty())
                    {
                        int currentArea = heights[top] * i;
                        if(currentArea > maxArea)
                        {
                            maxArea = currentArea;
                        }
                    }
                    
                    elements.push(i++);
                }
            }
        }
        
        return maxArea;
    }
};