class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        if(length <= 1)
        {
            return 0;
        }
        
        int left = 0; 
        int right = length - 1;
        int ans = 0;
        
        while(left < right)
        {
            if(height[left] < height[right])
            {
                ans = max(ans, (height[left]) * (right - left));
                left ++;
            }
            else
            {
                ans = max(ans, (height[right]) * (right - left));
                right --;
            }
        }
        
        return ans;
    }
};