class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        int j = 0;
        for(int i = 0; i < length; i ++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j ++;
            }
        }
    }
};