class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        if(size == 0 )
        {
            return - 1;
        }
        
        int runningXOR = nums[0];
        for(int i = 1; i < size; i ++)
        {
            runningXOR ^= nums[i] ^ i;
        }
        
        return runningXOR ^ size;
    }
};