class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if(length == 1)
        {
            return nums[0];
        }
        else if(length >= 2)
        {
            int lastVal = nums[length - 1];
            nums[length - 1] = 0;
            
            int rob1 = robHelper(nums);
            
            nums[length - 1] = lastVal;
            nums[0] = 0;
            int rob2 = robHelper(nums);
            
            return rob1 > rob2 ? rob1 : rob2;
        }
        
        return 0;
    }
    
    int robHelper(vector<int>& nums) {
        int size = nums.size();
        int lastVal = 0; 
        int secondLastVal = 0;
        
        for(int i = 0; i < size; i ++)
        {
            int current = lastVal > secondLastVal + nums[i] ? lastVal : secondLastVal + nums[i];
            secondLastVal = lastVal;
            lastVal = current;
        }
        
        return lastVal;
    }
};