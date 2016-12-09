class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();
        
        if(length == 0)
        {
            return -1;
        }
        
        if(length == 1)
        {
            return 0;
        }
        
        for(int i = 1; i < length - 1; i ++)
        {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                return i;
            }
        }
        
        if(nums[0] > nums[1])
        {
            return 0;
        }
        else if(nums[length - 1] > nums[length - 2])
        {
            return length - 1;
        }
        
        return -1;
    }
};