class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0 || size == 1)
        {
            return size;
        }
        
        int lastMin = 0;
        for(int i = 0; i < size; i ++)
        {
            if(nums[i] != nums[lastMin])
            {
                lastMin++;
                nums[lastMin] = nums[i];
            }
        }
        
        return lastMin + 1;
    }
};