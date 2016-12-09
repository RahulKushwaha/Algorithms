class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        if(nums.size() < 3)
        {
            return -1;
        }
        
        int runningXOR = nums[0];
        
        for(int i = 1; i < nums.size(); i ++)
        {
            runningXOR ^= nums[i];
        }
        
        return runningXOR;
    }
};