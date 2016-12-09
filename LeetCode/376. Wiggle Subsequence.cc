class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int length = nums.size();
        if(length <= 1)
        {
            return length;    
        }
        
        int dpI[length];
        int dpD[length];
        
        int ans = 0;
        
        for(int i = 0; i < length; i ++)
        {
            dpD[i] = dpI[i] = 1;
            for(int j = 0; j < i; j ++)
            {
                if(nums[i] > nums[j])
                {
                    dpI[i] = max(dpI[i], 1 + dpD[j]);
                }
                else if(nums[i] < nums[j])
                {
                    dpD[i] = max(dpD[i], 1 + dpI[j]);
                }
            }
            
            ans = max(dpD[i], dpI[i]);
        }
        
        return ans;
    }
};