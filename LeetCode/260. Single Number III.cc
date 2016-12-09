class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalLength = nums.size();
        vector<int> output;
        
        if(totalLength == 0)
        {
            return output;
        }
        
        int sum = 0;
        
        for(int i = 0; i < totalLength; i++)
        {
            sum ^= nums[i];
        }
        
        int a = 0, b = 0;
        // Get the last set bit of the sum.
        // This bit can be used to differentiate between the two numbers.
        sum = sum & (~(sum - 1));
        
        for(int i = 0; i < totalLength; i ++)
        {
            if((nums[i] & sum) == 0)
            {
                a ^= nums[i];
            }
            else
            {
                b ^= nums[i];
            }
        }
        
        output.push_back(a);
        output.push_back(b);
        
        return output;
    }
};