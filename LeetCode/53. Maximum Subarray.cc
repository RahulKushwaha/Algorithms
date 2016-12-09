class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        int minSum = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        
        for(int i = 0; i < nums.size(); i ++)
        {
            sum += nums[i];
            if(sum > maxSum)
            {
                maxSum = sum;
            }
            
            if(minSum + sum < minSum)
            {
                minSum = sum;
                sum = 0;
            }
        }
        
        return maxSum;
    }
};