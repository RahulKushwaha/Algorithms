class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int length = nums.size();
        
        for(int i = 1; i < length; i ++)
        {
            if(i % 2 == 0)
            {
                if(nums[i] > nums[i - 1])
                {
                    swap(nums[i], nums[i - 1]);
                }
            }
            else
            {
                if(nums[i] < nums[i - 1])
                {
                    swap(nums[i], nums[i - 1]);
                }
            }
        }
    }
};