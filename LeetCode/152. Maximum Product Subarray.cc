class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
        {
            return 0;
        }
        
        int * input = &nums[0];
        int minNegativeProduct = 1;
        int runningProduct = 1;
        int result = INT_MIN;
        
        for(int i = 0; i < length; i ++)
        {
            int num = *input++;
            if(num == 0)
            {
                result = max(result, 0);
                runningProduct = 1;
                minNegativeProduct = 1;
            }
            else
            {
                runningProduct *= num;
                
                if(runningProduct < 0)
                {
                    result = max(result, runningProduct / minNegativeProduct);
                }
                else
                {
                    result = max(result, runningProduct);    
                }
                
                if(runningProduct < 0 && minNegativeProduct == 1)
                {
                    minNegativeProduct = runningProduct;
                }
            }
        }
        
        return result;
    }
};