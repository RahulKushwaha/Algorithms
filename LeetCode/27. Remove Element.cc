class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int j = -1;
        for(int i = 0; i < size; i ++)
        {
            if(nums[i] != val)
            {
                j ++;
                nums[j] = nums[i];
            }
        }

        return j + 1;
    }
};