class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
        {
            return 0;
        }
        
        bool flag = false;
        int j = 0;
        
        int * input = &nums[0];
        
        for(int i = 1; i < length; i ++)
        {
            if(nums[j] != nums[i])
            {
                j ++;
                input[j] = input[i];
                flag = false;
            }
            else
            {
                if(flag == false)
                {
                    flag = true;
                    j++;
                    input[j] = input[i];
                }
            }
        }
        
        return j + 1;
    }
};