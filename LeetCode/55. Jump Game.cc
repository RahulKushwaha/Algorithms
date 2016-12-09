class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        
        if(length == 0)
        {
            return false;
        }
        if(length == 1)
        {
            return true;
        }
        
        int r = nums[0];
        int currentRange;
        for(int i = 1; i < length && r >= i; i ++)
        {
            currentRange = i + nums[i];
            if(currentRange > r)
            {
                r = currentRange;
            }
        }
        
        return r >= length - 1;
    }
};