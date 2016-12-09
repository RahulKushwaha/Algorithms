class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        
        if(nums.size() == 0)
        {
            return nums;
        }
        
        if(nums.size() == 1)
        {
            return nums;
        }
        
        output.resize(nums.size());
        
        int runningProduct = 1;
        output[0] = 1;
        
        for(int i = 1; i < nums.size(); i ++)
        {
            runningProduct *= nums[i - 1];
            output[i] = runningProduct;
        }
        
        runningProduct = 1;
        for(int i = nums.size() - 2; i >= 0; i --)
        {
            runningProduct *= nums[i + 1];
            output[i] *= runningProduct;
        }
        
        return output;
    }
};