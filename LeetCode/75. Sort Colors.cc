class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0;
        int k = nums.size() - 1;
        int i = 0;
        
        for(int i = 0; i <= k;)
        {
            if(nums[i] == 2)
            {
                swap(nums[k --], nums[i]);
            }
            else if(nums[i] == 0)
            {
                swap(nums[i ++], nums[j++]);
            }
            else
            {
                i ++;
            }
        }
    }
};