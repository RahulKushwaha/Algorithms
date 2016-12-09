class Solution {
public:
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