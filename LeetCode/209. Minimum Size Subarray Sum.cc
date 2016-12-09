class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int length = nums.size();
        
        if(length == 0)
        {
            return 0;
        }
        
        int startIndex = 0;
        int endIndex = 0;
        int runningSum = nums[0];
        int minLength = INT_MAX;
        
        while(endIndex != length - 1)
        {
            while(endIndex + 1 < length && runningSum < s)
            {
                runningSum += nums[endIndex + 1];
                endIndex ++ ;
            }
            
            while(runningSum >= s)
            {
                if(endIndex - startIndex + 1 < minLength)
                {
                    minLength = endIndex - startIndex + 1;
                }
                
                runningSum -= nums[startIndex];
                startIndex ++;
            }
        }
        
        return minLength == INT_MAX ? 0 : minLength;
    }
};